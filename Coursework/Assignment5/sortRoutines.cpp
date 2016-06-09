//********************************************************
// File Name   : sortRoutines.cpp
//
// Author      : Clarence Mitchell
// Student ID  : Mitc5039
//
// Assignment  : Assignment 5
// Abstract    : This file contains sort routine functions
// Date Due    : February 9, 2016
// -----------------------------------------------------------
// Class       : CST370 - SPRING 2016
// Instructor  : Dr. Seetharam
// ********************************************************

//
// --- INCLUDES -----
//
//--- Standard Stuff  ----
#include <iostream>
#include <algorithm>    // std::max

using namespace std;

//
// --- INCLUDES ---
//
#include "sortRoutines.h"
/**************************************
 * SelectionSort
 *    sorts array using selection sort
 *
 * Return Value :
 *	none
 *
 * PARAMETERS :
 *  int Arrary	- Array of integers to be sorted
 *  int			- Size of input array
 *
 * Precondition :
 *	int Array has been defined and populated with values
 *   int size has a value that states the size of the input array
 *
 * Postcondition :
 *	int Array is sorted in ascending order
 *
 *****************************************/
void SelectionSort(int inputArr[], int arrSize)
{
	//
	// local variables used in function
	//
	int smallPos,											//position of smallest element
		smallestElement;									//value of smallest element


															//
															//  Find the smallest element in inputArr[i] ... inputArr[arrSize]
															//
	for (int i = 0; i < arrSize - 1; i++)
	{
		smallPos = i;							// set smallest position  to the current index 
		smallestElement = inputArr[smallPos];   // set value of the smallest data element

		for (int j = i + 1; j < arrSize; j++)
		{

			if (inputArr[j] < inputArr[smallPos])	// smaller value found
			{
				//  set position and value of new smaller value
				smallPos = j;
				smallestElement = inputArr[smallPos];

			} // end of if

		}  // end of for

		   //if smallPos no longer equals i than a smaller value has been found, so it swap 
		if (smallPos != i)
		{
			inputArr[smallPos] = inputArr[i];
			inputArr[i] = smallestElement;
		}
	}
}


void SelectionSortK(int inputArr[],  const int arrSize, const int k)
{
	//
	// local variables used in function
	//
	int smallPos,											//position of smallest element
		smallestElement;									//value of smallest element


	//
	//  Find the smallest element in inputArr[i] ... inputArr[arrSize]
	//
	for (int i = 0; i < k; i++)
	{
		smallPos = i;							// set smallest position  to the current index 
		smallestElement = inputArr[smallPos];   // set value of the smallest data element

		for (int j = i + 1; j < arrSize; j++)
		{

			if (inputArr[j] < inputArr[smallPos])	// smaller value found
			{
				//  set position and value of new smaller value
				smallPos = j;
				smallestElement = inputArr[smallPos];

			} // end of if

		}  // end of for

		   //if smallPos no longer equals i than a smaller value has been found, so it swap 
		if (smallPos != i)
		{
			inputArr[smallPos] = inputArr[i];
			inputArr[i] = smallestElement;
		} // end if

	} // end for


} // end SelectionSortK


/**************************************
* displayValues
*    displays the values in int array
*
* Return Value :
*	none
*
* PARAMETERS :
*  output stream	- pointer to ouput stream
*  int Arrary       - Array of integers to print out
*  int			    - Size of input array
*
* Precondition :
*   output stream has been defined and is open
*	int Array has been defined and populated with values
*   int size has a value that states the size of the input array
*
* Postcondition :
*	elements in the int Array displayed in the output stream
*
*****************************************/
//--- Definition of display()
const void displayValues(ostream & out, int inputArr[], int arrSize)
{
	for (int i = 0; i < arrSize - 1; i++)
		out << inputArr[i] << " ";
	out << endl;
}
/**************************************
* getUserKValue
*    gets a K value from the user that state number of elements to sort and return
*
* Return Value :
*	int		value entered by user
*
* PARAMETERS :
*  int			    - Size of input array
*
* Precondition :
*   int size has a value that states the size of the input array
*
* Postcondition :
*	a valid value between 1 and arraysize is returned
*
*****************************************/
int getUserKValue(int arrSize)
{
	int userInputValue;

	cout << "Enter the number of elements to return ( between 1 and " << arrSize << " ):";
	cin >> userInputValue;

	while ((userInputValue <= 0) || (userInputValue > arrSize))
	{
		cerr << "Invalid input value.";
		cout << "Please enter a value between 1 and " << arrSize << " :";
		cin >> userInputValue;

	}

	return userInputValue;
}

