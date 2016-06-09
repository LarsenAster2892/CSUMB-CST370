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
   Stack s1, s2;

   //
   //  --- Array is used to load Stack 1
   //    The following are test case(s)
   //int stack1Nums[] = { 1, 5, 3, -3, 4, 8, 10, -5 };
   //int stack1Nums[] = { 1, 5, -4, 6, 2 };
   //int stack1Nums[] = { -1, -4, -4, 6, 6, 9 };
   //int stack1Nums[] = {1};
   int stack1Nums[] = { 1, 5, 3, -3, 4, 8, 10, -5 };				// load array 
   int arraySize = sizeof(stack1Nums) / sizeof(stack1Nums[0]);		// Get array size 

   //
   // --- Temporary Number variables
   int currenNumber;

   cout << "\nPushing set up numbers onto Stack 1" << endl;

   //
   // -- Load Stack 1 with numbers 
   //
   for (int i = 0; i < arraySize; i++)
		s1.push(stack1Nums[i]);
   
   cout << "\nStack 1 contents:\n";
   s1.display(cout);
   
   //---------------------------------------
   //  Now begin Sort
   //--------------------------------------
   cout << "\nBeginning Sort...." << endl;

   //
   // While Stack 1 is not empty
   //
   while (!s1.empty())
   {
	   //
	   // Remove Top value in Stack 1 into CurrentNumber
	   //
	   currenNumber = s1.top();
	   s1.pop();

	   //
	   // While Stack 2 is not empty and the Top value > CurrentNumber
	   //
	   while ((!s2.empty()) && (s2.top() < currenNumber))
	   {
		   //
		   // Remove Stack 2 Top and push it on Stack 1
		   //
		   s1.push(s2.top());
		   s2.pop();
	   }

	   //
	   // Push CurrentNumber on to Stack 2
	   // 
	   s2.push(currenNumber);

   }

   //
   // --- Now Stack 2 has descending order so copy Stack 2 to Stack 1
   //
   while (!s2.empty())
   {
	   //
	   // Remove Stack 2 Top and push it on Stack 1
	   //
	   s1.push(s2.top());
	   s2.pop();
   }
	
   //---------------------------------------
   //  Now begin Sort
   //--------------------------------------
   cout << "\nEnd of  Sort....Displaying Stacks..." << endl;

   //
   // Now display both Stacks...
   //
   cout << "Stack 1 contents:\n";
   s1.display(cout);
   cout << "Stack 2 contents:\n";
   s2.display(cout);


	cout << endl;

	//
	// -- End of Program
	//

}
