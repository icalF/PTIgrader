#include <cassert>
#include <fstream>
#include <iostream>
#include <iterator>
#include <regex>
#include <string>

using namespace std;

/********************* MAIN PROGRAM *************************/

int main(int argc, char** argv) 
{
  assert(argc == 2);          // param is only 1
  ifstream infile ("output");

  string param(argv[0]);      // regex parameter from user request
  regex filter(param);        // create regex from param
  
  string input(istreambuf_iterator<char>(infile), {});      // create filestream string
  string result = regex_replace(input, filter, "");         // erase all matched regex
  infile.close();

  ofstream outfile("output", ios_base::out | ios_base::trunc);
  outfile << result;
  outfile.close();
}

// Copyright (C) 2015 Afrizal Fikri