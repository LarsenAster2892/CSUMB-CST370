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
#include "coolSortRoutines.h"

/**************************************
* coolSort
*    This routines is a modified version of the insertion sort that
*    takes an array of sequence of steps that are descreasing and ending in 1.
*    It also takes an array of numbers to be sorted and use the sequence to
*    create a subset of numbers from the array that start at arbitrary element
*    and include every Hth element using insertion sort.
*
* Return Value :
*	none
*
* PARAMETERS :
*  int Arrary	- Array of integers to be sorted
*  int		    - Size of input array
*  int Arrary	- Array of sequence integers to be used for sequence sorting
*  int		    - Size of sequence int array
*
* Precondition :
*	int Array has been defined, populated with values
*   int size has a value that states the size of the input array
*	int Sequence Array has been defined, populated with values, and is sorted in descending order
*   int Sequence size has a value that states the size of the input sequence array
*
* Postcondition :
*	dataArray is sortedd
*
*****************************************/

void coolSort(int dataArray[], int arrSize, int hSeq[], int hSeqSize)
{
	int seqNum;
	int currVal;
	int posIndex;

	//
	// Loop through sequence numbers
	//
	for (int hSeqNum = 0; hSeqNum < hSeqSize; hSeqNum++)
	{
		//
		// get current sequence numbert to use for insertion sort
		seqNum = hSeq[hSeqNum];				
		
		//
		//  Since we are skipping ahead for seqnum, 
		//  we must loop through the first series of numbers up to the seqnum
		//  example if seqnum is 5 the loop for 0 to 4 
		//
		for (int i = 0; i < seqNum; i++)
		{
			//
			// This inner loop is now just the insertion sort routine (as per video)
			// however instead subtract or adding 1, we subtract or add seqnum
			//
			for (int j = i; j < arrSize; j += seqNum)
			{
				currVal = dataArray[j];
				posIndex = j;

				while ((posIndex > i) && dataArray[posIndex - seqNum] > currVal)
				{
					dataArray[posIndex] = dataArray[posIndex - seqNum];
					posIndex = posIndex - seqNum;
				} // end while

				dataArray[posIndex] = currVal;
			} // end for j
		} // end i 
	} // end for hseqnum
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
	for (int i = 0; i <= arrSize - 1; i++)
		out << inputArr[i] << " ";
	out << endl;
}