//********************************************************
// File Name   : searchRoutines.cpp
//
// Author      : Clarence Mitchell
// Student ID  : Mitc5039
//
// Assignment  : Lab 6
// Abstract    : This file contains sort routine functions
// Date Due    : February 16, 2016
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
#include "searchRoutines.h"
/**************************************
* LinearSearch
*    searches a array for value
*
* Return Value :
*	bool	- True if value found, else false
*
* PARAMETERS :
*  int Arrary	- Array of integers to be searched
*  int			- Size of input array
*  int          - Value to be searched for
*
* Precondition :
*	int Array has been defined and populated with values
*   int size has a value that states the size of the input array
*   int value has valid number to be searched for
*
* Postcondition :
*	bool value is return stating if search value was found
*
*****************************************/
//The search funtion
bool LinearSearch(int dataArray[], int arrSize, int searchKey)
{
	bool keyFound = false;

	//
	//  Loop from 0 to n-1 or found
	//
	for (int i = 0; i < arrSize; i++)
	{
		//
		// -- item found ?
		if (searchKey == dataArray[i])
		{
			keyFound = true;
			break;
		}// End if

	} // End for
	return keyFound;

} // end LinearSearch Function

  /**************************************
  * IterBinarySearch
  *    Iteratively searches a array for value
  *
  * Return Value :
  *	bool	- True if value found, else false
  *
  * PARAMETERS :
  *  int Arrary	- Array of integers to be searched
  *  int			- Size of input array
  *  int          - Value to be searched for
  *
  * Precondition :
  *	 int Array has been defined, populated with values, and is sorted in ascending order
  *   int size has a value that states the size of the input array
  *   int value has valid number to be searched for
  *
  * Postcondition :
  *	bool value is return stating if search value was found
  *
  *****************************************/
  // iterative
bool IterBinarySearch(int dataArray[], int arrSize, int searchKey)
{

	bool keyFound = false;
	int low = 0;
	int mid = 0;
	int high = arrSize - 1;

	//
	// Loop until item found or not found (low > high)
	//
	while (low <= high)
	{
		//
		// Find mid point
		mid = (low + high) / 2;

		if (searchKey < dataArray[mid])			// Item in left side (lower)
		{
			high = mid - 1;
		}
		else if (searchKey > dataArray[mid])	// Item in right side (higher)
		{
			low = mid + 1;
		} // end else if
		else                                   // Item found
		{
			keyFound = true;
			break;
		} // end if
	}
	return keyFound;
}
/**************************************
* RecursiveBinarySearch
*    Recursively searches a array for value
*
* Return Value :
*	bool	- True if value found, else false
*
* PARAMETERS :
*  int Arrary	- Array of integers to be searched
*  int			- lower Positon in input array
*  int			- Higher Positon in input array
*  int          - Value to be searched for
*
* Precondition :
*	int Array has been defined, populated with values, and is sorted in ascending order
*   int Lower Position has a value that is within 0 to array size
*   int Higher Positon has a value that is within 0 to array size
*   int value has valid number to be searched for
*
* Postcondition :
*	bool value is return stating if search value was found
*
*****************************************/

bool RecursiveBinarySearch(int dataArray[], int lowPos, int highPos, int searchKey)
{
	//
	// Check for Base (exit) condition
	//
	if (lowPos > highPos)
		return false;
	//
	// Find mid point
	int mid = (lowPos + highPos) / 2;

	//
	// if key in lower half recursively call with lower array
	// if key in upper half recursively call with upper arry
	// else return found
	//
	if (searchKey < dataArray[mid])
	{
		return RecursiveBinarySearch(dataArray, lowPos, mid - 1, searchKey);
	}
	else if (searchKey > dataArray[mid])
	{
		return RecursiveBinarySearch(dataArray, mid + 1, highPos, searchKey);
	}
	else
		return true;    // recursive exit condition
}

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