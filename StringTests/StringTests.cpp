// StringTests.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#pragma warning(disable : 4996)

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char string1[] = "The quick brown dog jumps over the lazy fox";
char string2[] = "The QUICK brown dog jumps over the lazy fox";

int main()
{
	char string[80];

	// If you change the previous line to
	//   char string[20];
	// strcpy and strcat will happily overrun the string
	// buffer.  See the examples for strncpy and strncat
	// for safer string handling.

	strcpy(string, "Hello world from "); // C4996
	// Note: strcpy is deprecated; use strcpy_s instead
	strcat(string, "strcpy ");           // C4996
	// Note: strcat is deprecated; use strcat_s instead
	strcat(string, "and ");              // C4996
	strcat(string, "strcat!");           // C4996
	printf("String = %s\n", string);

	char tmp[20];
	int result;

	// Case sensitive
	printf("Compare strings:\n   %s\n   %s\n\n", string1, string2);
	result = strcmp(string1, string2);
	if (result > 0)
		strcpy(tmp, "greater than");
	else if (result < 0)
		strcpy(tmp, "less than");
	else
		strcpy(tmp, "equal to");
	printf("   strcmp:   String 1 is %s string 2\n", tmp);

	// Case insensitive (could use equivalent _stricmp)
	result = _stricmp(string1, string2);
	if (result > 0)
		strcpy(tmp, "greater than");
	else if (result < 0)
		strcpy(tmp, "less than");
	else
		strcpy(tmp, "equal to");
	printf("   _stricmp:  String 1 is %s string 2\n", tmp);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
