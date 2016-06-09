
//********************************************************
// File Name   : Assignment6_Sort2_Tester.cpp
//
// Author      : Clarence Mitchell
// Student ID  : Mitc5039
//
// Assignment  : Assignment 6
// Abstract    : This assignment implements the coolSort algorithm (CoolSort) that: 
//               1) Contains step sequence of decreasingnumbers that ends at 1, 
//                  and the first element of the sequence is less than the number of elements in an array
//               2) Then it sorts sub-arrays that start at arbitrary element 
//					and include every Hth element using insertion sort
// Date Due    : February 16, 2016
// -----------------------------------------------------------
// Class       : CST370 - SPRING 2016
// Instructor  : Dr. Seetharam
// ********************************************************
/*---------------------------------------------------------------------
Driver program to test Assignment 6.
----------------------------------------------------------------------*/

#include <iostream>			// standard I/O
#include <string>			// string handling
using namespace std;
//
//  include function headers
//

#include "coolSortRoutines.h"

//
// Constants 
//

int main()
{
	//
	//  -- Define arrays to sort
	//
	//int dataNums[] = { 62, 83, 18, 53, 07, 17, 95, 86, 47, 69, 25, 28 };				// load array for 1st run
	int dataNums[] = { 2, 5, 6, 4, 10, 9, 8, 1, 10, 5 };				// load array for 1st run
	int arraySize = sizeof(dataNums) / sizeof(dataNums[0]);

	int hSeqNums[] = { 5, 3, 1 };										// load sequence numbers for 1st run
	int hArraySize = sizeof(hSeqNums) / sizeof(hSeqNums[0]);
	//
	// array for part 2
	int dataNums2[] = { 2, 5, 9, 4, 10, 7, 8, 1, 11, 5 };				// load array part 2
	int arraySize2 = sizeof(dataNums2) / sizeof(dataNums2[0]);
	
	int hSeqNums2[] = { 5, 2, 1 };										// load sequence numbers for 2nd run
	int hArraySize2 = sizeof(hSeqNums2) / sizeof(hSeqNums2[0]);

	//******************************************************
	//
	// 1st Run 
	//
	//******************************************************
	cout << "-- Start Assignment 6 ---" << endl;
	cout << "\n-- Test 1  ---" << endl;
	cout << "Array prior to sorting " << endl;
	displayValues(cout, dataNums, arraySize);
	cout << "\nsequence number prior to sorting " << endl;
	displayValues(cout, hSeqNums, hArraySize);

	//
	// Perform coolSort
	//
	cout << "\nSorting Array " << endl;
	coolSort(dataNums, arraySize, hSeqNums, hArraySize);

	cout << "\nArray after sorting" << endl;
	displayValues(cout, dataNums, arraySize);

	//******************************************************
	//
	// 2nd Run 
	//
	//******************************************************

	cout << "\n-- Test 2  ---" << endl;
	cout << "Array prior to sorting " << endl;
	displayValues(cout, dataNums2, arraySize2);
	cout << "\nsequence number prior to sorting " << endl;
	displayValues(cout, hSeqNums2, hArraySize2);

	//
	// Perform coolSort
	//
	cout << "\nSorting Array " << endl;
	coolSort(dataNums2, arraySize2, hSeqNums2, hArraySize2);


	cout << "\nArray after sorting" << endl;
	displayValues(cout, dataNums2, arraySize2);

	//
	// -- End of Program
	//
	cout << "\n--- End of Program ----" << endl;

} // End Program

