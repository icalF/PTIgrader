#include <sys/types.h>
#include <dirent.h>
#include <vector>
#include <map>
#include <cstring>
#include <string>
#include <iostream>
#include <cstdio>

using namespace std;

vector<string> files = vector<string>();
vector<string> testcases = vector<string>();
vector<string> answers = vector<string>();
vector<string> modules = vector<string>();
char s[1024];
string prefix;

string getext (const string& filename)
{
	int pos;	
	pos = filename.find_last_of('.');
	
	if (pos == -1) return "";
	else return filename.substr(pos, -1);
}

void getdir (const string& dir, vector<string>& files)
{
	struct dirent* dirp;
	DIR* dp;
	
	files.clear();
    
	if ((dp  = opendir(dir.c_str())) == NULL) return;
 
	while ((dirp = readdir(dp)) != NULL) {
		if (strcmp(dirp->d_name, ".") && strcmp(dirp->d_name, ".."))
			files.push_back(string(dirp->d_name));
	}
	
	closedir(dp);
}

int nimof (const string& file) 
{
	int pos = file.find(prefix);
	if (pos == -1) return -1;
	return stoi( file.substr( pos, 8 ) );
}

int findinside (const string& file, const string& key)
{
	FILE* f = fopen(file.c_str(), "r");
	string st;
	int counter = 0, pos;
	
	while (fscanf(f, "%s", s) != EOF) {
		st = string(s);
		pos = 0;
		while ((pos = st.find(key, pos)) != string::npos) {
			counter++;
			pos++;
		}
	}
	
	return counter;
}

void test ()
{
	FILE* f;
	vector<int> kunci;
	vector<int> jawaban;
	char* com = s;
	int tmp, skor = 0, total = 0;
	
	for (int i = 0; i < answers.size(); ++i)
	{
		kunci.clear();
		jawaban.clear();
		
		string ans = answers[i];
		string testcase = testcases[i];
		
		f = fopen(("ans/" + ans).c_str(), "r");
		while (fscanf(f, "%d", &tmp) != EOF)
		{
			kunci.push_back(tmp);
		}
		fclose(f);
		
		total += kunci.size();
		
		strcpy(com, "./lol < case/");
		strcat(com, testcase.c_str());
		strcat(com, " > output");
		if (system(com)) continue;		// runtime error
		
		system("./norm");	// normalize output

		f = fopen("output", "r");
		while (fscanf(f, "%d", &tmp) != EOF)
		{
			jawaban.push_back(tmp);
		}	
		fclose(f);
		
		for (int j = 0; j < jawaban.size() && j < kunci.size(); ++j) {
			skor += kunci[j] == jawaban[j];
		}
	}
	
	printf("  %2d/%2d", skor, total);
}

bool headercheck (const string& file)
{
	return findinside(file, to_string(nimof(file)));
}

void modulecheck (const string& file)
{
	int counter = 0;
	
	for (string& mod : modules) {
		counter += (findinside(file, mod) > 0);
	}
	
	printf("   %2d/%2d", counter, modules.size());
}

int main()
{
	cin >> prefix;
	
	getdir(string("."), files);
	getdir(string("ans"), answers);
	getdir(string("case"), testcases);
	
	FILE* f = fopen("bin/modulelist.txt", "r");
	while (fscanf(f, "%s", s) != EOF) {
		modules.push_back(string(s));
	}
	fclose(f);
	
	puts("     NIM  Compile  Score  Header  Module");
    
	for (string& file : files) 
	{
		if (file.find(".cpp") == -1) continue;
		
		printf("%8d", nimof(file));
		
		char* com = s;
		strcpy(com, "g++ -o lol ");
		strcat(com, file.c_str());
		
		// skor 1 = compile
		if (system(com) == 0) {
			printf("  Success");

			// skor 2 = output
			test();			// scoring
		} else {
			printf("    Error");
			printf("  %2d/%2d", 0, 0);
		}
		
		// skor 3 = header
		printf(headercheck(file) ? "   Exist" : " Lost :(");
		
		// skor 4 = materi modul
		modulecheck(file);
		
		puts("");
	}
	
	return 0;
}
