//********************************************************
// File Name   : Sample_Stack_Tester.cpp
//
// Author      : Clarence Mitchell
// Student ID  : Mitc5039
//
// Assignment  : Lab 2b
// Abstract    : This labs adds the following additional funcitionality to 
//                the Stack sample code. 
//                 1) The ability to read a number and convert it to binary
// Date Due    : January 19, 2016
// -----------------------------------------------------------
// Class       : CST370 - SPRING 2016
// Instructor  : Dr. Seetharam
// ********************************************************
/*---------------------------------------------------------------------
               Driver program to test the Stack class.
  ----------------------------------------------------------------------*/

#include <iostream>
using namespace std;

#include "Stack.h"

int main()
{
   Stack binaryNumStack;
    int userNum;
	//
	// Get number from user
	//
	cout << "Enter a number : ";
	cin >> userNum;

	//
	// Check for positive number
	//  If negative display message and exit
	//
	if (userNum < 0)
	{
		cerr << "*** Negative Number ***\n"
			" Number must be positive\n";
		exit(1);
	}
	
	//
	// Echo Decimal version of number
	//

	cout << "Decimal: " << userNum << endl;

	/*
	 *
	 *  Now begin converting the number to binary ----
	 *
	 */
	unsigned number = userNum;		// Assign user input to number for conversion
	unsigned remainder;

	//
	//  While 
	//
	if (number == 0)
	{
		binaryNumStack.push(number);
	}
	else
	{
		while (number != 0)
		{
			remainder = number % 2;
			binaryNumStack.push(remainder);
			number /= 2;
		}
	}

	//
	// -- Display Binary version of number
	//
	cout << "Binary: ";

	while (!binaryNumStack.empty())
	{
		remainder = binaryNumStack.top();
		binaryNumStack.pop();
		cout << remainder;
	}

	cout << endl;

	//
	// -- End of Program
	//

}
