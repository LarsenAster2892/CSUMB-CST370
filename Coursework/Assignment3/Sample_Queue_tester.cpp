/*---------------------------------------------------------------------
                  Driver program to test the Assignment class.
  ----------------------------------------------------------------------*/

  //********************************************************
  // File Name   : Sample_Stack_Tester.cpp
  //
  // Author      : Clarence Mitchell
  // Student ID  : Mitc5039
  //
  // Assignment  : Assignment 3
  // Abstract    : This assignment does the following: 
  //               Reads a string of characters, pushing each character onto a stack as it is read
  //               and simultaneously adding it to a queue. When the end of the string is encountered, it
  //               determine if the string is a palindrome.
  // Date Due    : January 26, 2016
  // -----------------------------------------------------------
  // Class       : CST370 - SPRING 2016
  // Instructor  : Dr. Seetharam
  // ********************************************************
  /*---------------------------------------------------------------------
  Driver program to test the Stack class.
  ----------------------------------------------------------------------*/
//#include <fstream>			// file handling
#include <iostream>			// standard I/O
#include <string>			// string handling
using namespace std;
	
#include "Queue.h"
#include "Stack.h"

//
// Constants 
//
const char endOfLine = '\n';


int main()
{
	Queue	lettersQueue;							// Queue for letters
	Stack	lettersStack;							// Stack for letters
	char	userInput;								// Input from user
	string	origInput="";								// original user input
	bool	isPalindrome;							// Check for Palindrome

	cout << "Enter a string to test for a Palindrome =>";
	userInput = getchar();
	while ((userInput  != endOfLine) && (!isspace(userInput)))
	{
		lettersQueue.enqueue((int)toupper(userInput));
		lettersStack.push((int)toupper(userInput));
		origInput += userInput;
		userInput = getchar();
	}

	isPalindrome = true;
	while ((!lettersQueue.empty()) &&  (isPalindrome))
	{
		if (lettersQueue.front() != lettersStack.top())
			isPalindrome = false;
		lettersQueue.dequeue();
		lettersStack.pop();
	}
	cout << endl;
	cout << "The word "<< origInput << (isPalindrome ? " is a " : " is NOT a ") << "palindorome" << endl;
	return 0;

}
