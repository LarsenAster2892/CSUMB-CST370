//********************************************************
// File Name   : Sample_Stack_Tester.cpp
//
// Author      : Clarence Mitchell
// Student ID  : Mitc5039
//
// Assignment  : Lab 2
// Abstract    : This labs adds the following additional funcitionality to 
//                the Stack sample code. 
//                 1) The ability to read a sequence of characters and reverse it
// Date Due    : January 19, 2016
// -----------------------------------------------------------
// Class       : CST370 - SPRING 2016
// Instructor  : Dr. Seetharam
// ********************************************************

/*---------------------------------------------------------------------
               Driver program to test the Stack class.
  ----------------------------------------------------------------------*/

#include <iostream>		// Standard IO
#include <string>		// Need for string input

using namespace std;

#include "Stack.h"

int main()
{
   Stack s;

   /*----------------------------------------------
    *
	*  The Following Code has been added for lab2a
	*
    *----------------------------------------------
	*/
   // Get string from user
   string userInput = "";
  
   cout << "\nEnter a string => ";
   getline(cin, userInput);

   cout << "You entered " << userInput << endl;

   //
   // check to make sure that user entered a string
   //
   if (!userInput.empty())
   {
	  //
	   // Loop through input string getting each char and push on stack
	   //
	   for (int strIdx = 0; strIdx < userInput.length(); strIdx++)
	   {
		   // push on stack
		   s.push(userInput[strIdx]);
	   } // End for
   } // End if


   //
   // -- now display string in reverse order
   //

   cout << "Reverse is ";
   while (!s.empty())
   {
     cout << s.top() ;
     s.pop();
   }
   cout << endl;

   //
   // -- End of Program
   //

 




}
