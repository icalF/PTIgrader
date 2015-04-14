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
 * List of character's predicate
 *
 * Grouping similiar character to simplify filtering
 * WARNING : READ CAREFULLY EACH PREDICATE FUNCTION BELOW BEFORE EDITTING FILTER
 */


/**
 * BUILTIN FUNCTION
 * 
 * isupper(c)
 * Valid only if c is uppercase alphabetic (A-Z)
 *
 * islower(c)
 * Valid only if c is lowercase alphabetic (a-z)
 * 
 * isalpha(c)
 * Valid only if c is alphabetic (lowercase or uppercase)
 *
 * isalnum(c)
 * Valid only if c is alphabetic or numeric digit (0-9)
 */


/**
 * NON BUILTIN FUNCTION
 */

/**
 * Function isspace
 * 
 * [Is character belongs to whitespace (space, tab, newline)]
 * 
 * @param	char c
 * @return	boolean
 */
bool isspace(char c) { return c == ' ' || c == '\n' || c == '\t'; }

/**
 * Function isinteger
 * 
 * [Is character belongs to decimal number (digit 0-9 and minus)]
 * @param	char c
 * @return	boolean 
 */
bool isinteger(char c) { return c == '-' || isdigit(c); }

/**
 * Function isdecimal
 * 
 * [Is character belongs to decimal number (integer and comma)]
 * @param	char c
 * @return	boolean
 */
bool isdecimal(char c) { return c == ',' || isinteger(c); }

/**
 * Function isanother
 * 
 * [Permitted character another than provided predicate]
 * @param	char c
 * @return	boolean
 */
bool isanother(char c)
{
	char s[] = "*$.";					// <--- LIST OF PERMITTED CHARACTERS
	return strchr(s, c) != NULL;
}

/********************* MAIN PROGRAM *************************/

int main() {
	freopen("output", "r", stdin);

	while ((cc = getchar()) != EOF) {		// for all character outputted
		if (isspace(cc) || isalnum(cc) 		// <--- EDIT FILTER HERE
			|| isanother(cc))				// <--- another predicate. LOOK PREDICATE SPECIFICATION ABOVE
			cs.push_back(cc);				// push matched characters
	}

	fclose(stdin);
	freopen("output", "w", stdout);

	for (char& c : cs)			// rewrite file with filtered chars
		putchar(c);

	fclose(stdout);
}

// Copyright (C) 2015 Afrizal Fikri