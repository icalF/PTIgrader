#include <cstdio>
#include <cstring>
#include <dirent.h>
#include <iostream>
#include <string>
#include <sstream>
#include <sys/types.h>
#include <vector>
#include <map>

#include "lib/libsandbox/sandbox.h"
#include "lib/SimpleJSON/JSON.h"

using namespace std;

vector<string> files;                     // source files
vector<string> testcases;                 // testcase files
vector<string> answers;                   // answer files
vector< vector<string> > modules;         // module list
char s[8192];                             // temporary cstring variable; for input buffer or whatever else

/**
 * Procedure set_quota
 * [Set quota for runtime]
 */
void set_quota(sandbox_t* sbox)
{
  sbox->task.quota[S_QUOTA_WALLCLOCK] = 1000;   // 1 sec execution limit
  sbox->task.quota[S_QUOTA_CPU] = 500;          // 0.5 sec cpu burst
  sbox->task.quota[S_QUOTA_MEMORY] = 25000;     // 25 MB memory limit
}

/**
 * Function parse
 * [Parse string towards delimiter char]
 * 
 * @param string s
 * @param char delim
 * @return vector<string>
 */
vector<string> parse(const string& s, char delim) 
{
  stringstream ss(s);                       // make stream from string
  string tmp;
  vector<string> v;

  while (getline(ss, tmp, delim))           // read all string from stream separated by delim
  {
    v.push_back(tmp);                       // push each to v
  }
  return v;
}

/**
 * Function getext
 * [Function to get extension from filename]
 * 
 * @param string& filename
 * @return string
 */
string getext(const string& filename)
{
  int pos;  
  pos = filename.find_last_of('.');   // get substring after last occurence of dot
  
  if (pos == -1) return "";
  else return filename.substr(pos + 1, -1);
}

/**
 * Procedure getdir
 * [Append all file list to container]
 * 
 * @param string dir
 * @param vector<string>& files
 */
void getdir (const string& dir, vector<string>& files)
{
  struct dirent* dirp;
  DIR* dp;
  
  files.clear();
    
  if ((dp = opendir(dir.c_str())) == NULL)        // if directory empty pass
    return;

  while ((dirp = readdir(dp)) != NULL) {          // while not all files yet listed
    if (strcmp(dirp->d_name, ".")                 // if file is not . and ..
      && strcmp(dirp->d_name, "..")
      && getext(dirp->d_name) == "cpp")
      files.push_back(string(dirp->d_name));      // append filename to container
  }
  
  closedir(dp);
}

/**
 * Function nimof
 * [Parse student ID from namefile]
 * 
 * @param string file
 * @return int
 */
int nimof (const string& file) 
{
  return stoi( file.substr( 4, 8 ) );     // convert digits after B0X_ to integer
}

/**
 * Function findinside
 * [Count all occurences of keyword in source file]
 * 
 * @param string file
 * @param string key
 * @return int
 */
int findinside (const string& file, const string& key)
{
  FILE* f = fopen(file.c_str(), "r"); 
  string st;
  int counter = 0, pos;
  
  while (fscanf(f, "%s", s) != EOF) {     // read all lines in file
    st = string(s);
    pos = 0;
    while ((pos = st.find(key, pos))      // while key found
      != string::npos) {
      counter++;                          // add counter
      pos++;                              // begin search after first previous character
    }
  }
  
  return counter;
}

/**
 * Procedure pushFromFile
 * [Push all line from file to vector of string]
 * 
 * @param v vector<string>&
 * @param f FILE*
 */
void pushFromFile(vector<string>& v, FILE* f)
{
  while (fgets(s, sizeof(s), f) != NULL)      // get all line from file
  {
    v.push_back(s);
  }
  fclose(f);
}

/**
 * Procedure test
 * [Test the output file with expected answer and output functionality score]
 *
 * @return JSON test score
 */
JSONValue *test ()
{
  FILE* f;
  vector<string> kunci;
  vector<string> jawaban;
  int skor = 0, total = 0;
  sandbox_t sbox;
  
  for (int i = 0; i < answers.size(); ++i)      // for each answer and testcase
  {
    kunci.clear();
    jawaban.clear();
    
    string ans = answers[i];
    string testcase = testcases[i];
    
    pushFromFile(kunci, fopen(("../ans/" + ans).c_str(), "r"));
    
    total += kunci.size();
    
    strcpy(s, "../case/");
    strcat(s, testcase.c_str());              

    const char* comm[] = {"./main", "<", s, "> output", NULL, };
    sandbox_init(&sbox, comm);
    sandbox_execute(&sbox);
    sandbox_fini(&sbox);

    if (sbox.result != S_RESULT_OK)             // if runtime error skip scoring
      continue;
    
    // system("./norm");                           // normalize output

    pushFromFile(jawaban, fopen("output", "r"));
    
    for (int j = 0; j < jawaban.size() && j < kunci.size(); ++j)  // for all output
    {                                           
      skor += kunci[j] == jawaban[j];                             // check whether equal to answer
    }
  }
  
  JSONObject grade;
  grade[L"Accepted"] = new JSONValue((double)skor);
  grade[L"Total"] = new JSONValue((double)total);
  
  return new JSONValue(grade);
}

/**
 * Function headercheck
 * [Check header exist or not in source file]
 * 
 * @param string file
 * @return boolean
 */
bool headercheck (const string& file)
{
  return findinside("../cpp/"+file, to_string(nimof(file)));
}

/**
 * Function modulecheck
 * [Find all module existence in source file and output module score]
 * 
 * @param string file
 * @return JSON module score
 */
JSONValue *modulecheck (const string& file)
{
  int counter = 0;
  
  for (vector<string>& mods : modules) {
    bool exist = false;
    for (string& s : mods) {                  // if there exist an s
      exist |= (findinside("../cpp/"+file, s) > 0);     // exist set true
    }
    counter += exist;                         // counter add if exist
  }
  
  JSONObject module;
  module[L"Exists"] = new JSONValue((double)counter);
  module[L"Expected"] = new JSONValue((double)modules.size());
  
  return new JSONValue(module);
}


/********************* MAIN PROGRAM *************************/

int main(int argc, char** argv)
{
  getdir(string("../cpp"), files);                 // list all source files
  getdir(string("../ans"), answers);               // list all answer files
  getdir(string("../case"), testcases);            // list all testcase files
  
  FILE* f = fopen("../modulelist.txt", "r");
  while (f != NULL && fgets(s, sizeof(s), f) != NULL) {      // list all modules
    modules.push_back(parse(string(s), '|'));
  }
  fclose(f);
  
  wprintf(L"Content-type:application/json\r\n\r\n");

  JSONArray resAll;
  JSONObject result;
  JSONValue *val;
    
  for (string& file : files) 
  {    
    result[L"NIM"] = new JSONValue((double)nimof(file));      // add SID number
    
    char* com = s;
    strcpy(com, "g++ -o main ../cpp/");
    strcat(com, file.c_str());
    
    // clean up
    delete result[L"Compile"];
    delete result[L"Score"];
    
    // score 1 = compile
    if (system(com) == 0) {                               // if compilation return normal
      result[L"Compile"] = new JSONValue(L"Success");     // status success

      // score 2 = output
      result[L"Score"] = test();                          // run functionality testing
    } else {
      result[L"Compile"] = new JSONValue(L"Error");       // status error

      // and score set to 0 automatically
      result[L"Score"] = JSON::Parse(L"{\                  
        \"Accepted\" : 0,\
        \"Total\" : 0\
      }");           
    }

    // score 3 = header
    // check header existence
    result[L"Header"] = new JSONValue(headercheck(file) ? L"Exist" : L"Lost");
    
    // score 4 = module
    // check program module
    result[L"Module"] = modulecheck(file);

    val = new JSONValue(result);    
    resAll.push_back(val);
  }

  val = new JSONValue(resAll);
  wprintf(val->Stringify().c_str());
  
  return 0;
}

// Copyright (C) 2015 Afrizal Fikri