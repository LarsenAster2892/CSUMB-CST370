
//********************************************************
// File Name   : Sample_Stack_Tester.cpp
//
// Author      : Clarence Mitchell
// Student ID  : Mitc5039
//
// Assignment  : Assignment 5
// Abstract    : This assignment implements the sorting algorithms covered in class: 
//               1) It implements the simple selection sort algorithm
//               2) Then uses a modified version of the selection sort algorithm
//                  to sort the first k elements of the array
//               3) Last it determines the median value of the input array
// Date Due    : February 9, 2016
// -----------------------------------------------------------
// Class       : CST370 - SPRING 2016
// Instructor  : Dr. Seetharam
// ********************************************************
/*---------------------------------------------------------------------
Driver program to test Assignment 5.
----------------------------------------------------------------------*/

#include <iostream>			// standard I/O
#include <string>			// string handling
using namespace std;
//
//  include function headers
//

#include "sortRoutines.h"

//
// Constants 
//

int main()
{
	//
	//  -- Define arrays to sort
	//
	int dataNums[] = { 4, 6, 8, 15, 20, 22, 10, 3, 9, 2 };				// load array part 1
	int arraySize = sizeof(dataNums) / sizeof(dataNums[0]);
	//
	// array for part 2
	int dataNums2[] = { 4, 6, 8, 15, 20, 22, 10, 3, 9, 2 };				// load array part 2
	int arraySize2 = sizeof(dataNums2) / sizeof(dataNums2[0]);

	//
	// array for part 2
	int dataNums3[] = { 4, 6, 8, 15, 20, 22, 10, 3, 9, 2 };				// load array part 3
	int arraySize3 = sizeof(dataNums3) / sizeof(dataNums3[0]);

	// Define user input
	int userKInput = 0;													// input from user

	//
	// Define the median position
	float medianPos = 0.0;												// position of median
	int origMedianValue = 0;											// value of median in original list
	int newMedianValue = 0;												// value of median in sorted list

	//******************************************************
	//
	// Part 1 of assignment 
	//
	//******************************************************
	cout << "-- Start part 1 of Assignment 5 ---" << endl;
	cout << "Array prior to sorting " << endl;
	displayValues(cout, dataNums, arraySize);

	//
	// Perform Selection Sort
	//
	SelectionSort(dataNums, arraySize);

	cout << "\nSorting Array " << endl;
	cout << "\nArray after sorting" << endl;
	displayValues(cout, dataNums, arraySize);
	
	//******************************************************
	//
	// Part 2 of assignment 
	//
	//******************************************************
	cout << "\n" << endl;
	cout << "-- Start part 2 of Assignment 5 ---" << endl;
	cout << "Array prior to sorting " << endl;
	displayValues(cout, dataNums2, arraySize2);

	userKInput = getUserKValue(arraySize2);
	
	//
	// Perform Selection Sort
	//
	SelectionSortK(dataNums2, arraySize2, userKInput);

	cout << "\nSorting Array " << endl;
	cout << "\nArray after sorting to the "<< userKInput << " element " << endl;
	displayValues(cout, dataNums2, userKInput+1);

	//******************************************************
	//
	// Part 3 of assignment 
	//
	//******************************************************
	cout << "\n" << endl;
	cout << "-- Start part 3 of Assignment 5 ---" << endl;
	cout << "Array prior to sorting " << endl;
	displayValues(cout, dataNums3, arraySize3);

	medianPos = (int)(arraySize3  / 2 + 0.5 );						// round up to next value 
	origMedianValue = dataNums3[(int)medianPos- 1];					// find median value in original list
	
	//
	// Perform Selection Sort
	//
	SelectionSortK(dataNums3, arraySize3, (int)medianPos + 1);		// sort values to K (median) position
	newMedianValue = dataNums3[(int)medianPos - 1];					// find median value in sorted list

	cout << "\nSorting Array " << endl;
	cout << "\nArray after sorting to the " << medianPos << " element " << endl;
	displayValues(cout, dataNums3, medianPos + 1);

	cout << "\nOriginal Median was " << origMedianValue << endl;
	cout << "\nSorted Median is " << newMedianValue << endl;


	cout << endl;
	//
	// -- End of Program
	//
	cout << "--- End of Program ----" << endl;

} // End Program

