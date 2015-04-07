#include <cstdio>
#include <cstring>
#include <cctype>
#include <list>

#ifndef __WIN32							// except windows
	#define getchar getchar_unlocked	// use getchar_unlocked
	#define putchar putchar_unlocked	// and putchar_unlocked
#endif

using namespace std;

list<char> cs;					// container for all char
char cc;						// char buffer

/**
 * Function isspace
 * 
 * [Is character belongs to whitespace (space, tab, newline)]
 * 
 * @param char c
 * @return boolean
 */
bool isspace(char c) { return cc == ' ' || cc == '\n' || cc == '\t'; }


/********************* MAIN PROGRAM *************************/

int main() {
	freopen("output", "r", stdin);
	while ((cc = getchar()) != EOF) {
		if (isspace(cc) || isalpha(cc) || cc == '*' || cc == '!')
			cs.push_back(cc);
	}
	fclose(stdin);
	freopen("output", "w", stdout);
	for (char& c : cs)
		putchar(c);
	fclose(stdout);
}

// Copyright (C) 2015 Afrizal Fikri