//********************************************************
// File Name   : Linked_List_Tester.cpp
//
// Author      : Clarence Mitchell
// Student ID  : Mitc5039
//
// Assignment  : Assignment 1
// Abstract    : This Assignment prompts the user for a string
//               then creates a char linked list from it.  Then it
//               displays the number starts that start with A and end with B
//               that are contained in the linked list 
// Date Due    : January 12, 2016
// -----------------------------------------------------------
// Class       : CST370 - SPRING 2016
// Instructor  : Dr. Seetharam
// ********************************************************

//
// --- INCLUDES -----
//
#include <iostream>
using namespace std;

#include "LinkedList.h"

int main()
{
	// Get string from user
	string userInput = "";

	cout << "Enter a string:";
	getline(cin, userInput);
   
	//
	// check to make sure that user entered a string
	//
	if (!userInput.empty())
	{
		// create linkedList
		LinkedList charList(userInput);

		// find all substrings in string
		charList.findSubStrings('A', 'B', cout);
	} // End if
	
	cout << endl;
	//
	// -- End of Program
	//
	cout << "--- End of Program ----" << endl;

} // End Program