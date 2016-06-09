
//********************************************************
// File Name   : Lab6_Tester.cpp
//
// Author      : Clarence Mitchell
// Student ID  : Mitc5039
//
// Assignment  : Lab 6
// Abstract    : This assignment implements the search algorithms covered in class: 
//               1) Linear Search 
//               2) Iterative Binary Search
//               3) Recursive Binary Search
// Date Due    : February 16, 2016
// -----------------------------------------------------------
// Class       : CST370 - SPRING 2016
// Instructor  : Dr. Seetharam
// ********************************************************
/*---------------------------------------------------------------------
Driver program to test Lab 6.
----------------------------------------------------------------------*/

#include <iostream>			// standard I/O
#include <string>			// string handling
using namespace std;
//
//  include function headers
//

#include "searchRoutines.h"

//
// Constants 
//
int main()
{
	//
	//  -- Define arrays to sort
	//
	//
	// array for part A
	int dataNumsA[] = { 4, 6, 8, 15, 20, 22, 10, 3, 9, 2 };				// load array part 1
	int arraySizeA = sizeof(dataNumsA) / sizeof(dataNumsA[0]);
	//
	// array for part B
	int dataNumsB[] = {2, 3, 4, 6, 8, 9, 10, 15, 20, 22};				// load array part 2
	int arraySizeB = sizeof(dataNumsB) / sizeof(dataNumsB[0]);

	//
	// array for part C
	int dataNumsC[] = { 2, 3, 4, 6, 8, 9, 10, 15, 20, 22 };				// load array part 3
	int arraySizeC = sizeof(dataNumsC) / sizeof(dataNumsC[0]);


	//
	// Search variables
	//
	bool valueFound = false;											// Search return
	int searchNumber = 0;												// input from user

																		//
																		// Define the median position
	float medianPos = 0.0;												// position of median
	int origMedianValue = 0;											// value of median in original list
	int newMedianValue = 0;												// value of median in sorted list

	//******************************************************
	//
	// Part A of Lab - Linear Search
	//
	//******************************************************
	cout << "-- Start part A of Lab 6 ---" << endl;

	//
	// Get a value from the user to search for in Array
	//
	cout << "-- Begining Part A - Linear Search" << endl;
	cout << endl;
	cout << "Array prior to searching " << endl;
	displayValues(cout, dataNumsA, arraySizeA);

	cout << "\nEnter value to search for->";
	cin >> searchNumber;

	valueFound = LinearSearch(dataNumsA, arraySizeA, searchNumber);
	cout << "\nThe value of " << searchNumber << " is " << (valueFound ? "found" : "NOT found") << " in the array" << endl;
	cout << endl;


	//******************************************************
	//
	// Part B of Lab Iterative Binary Search
	//
	//******************************************************
	//
	// Get a value from the user to search for in Array
	//
	cout << endl;
	cout << "\n-- Begining Part B - Iterative Binary Search" << endl;
	cout << endl;
	cout << "Array prior to searching " << endl;
	displayValues(cout, dataNumsB, arraySizeB);

	cout << "\nEnter value to search for->";
	cin >> searchNumber;

	valueFound = IterBinarySearch(dataNumsB, arraySizeB, searchNumber);
	cout << "\nThe value of " << searchNumber << " is " << (valueFound ? "found" : "NOT found") << " in the array" << endl;
	cout << endl;



	//******************************************************
	//
	// Part C of Lab  - Recursive Binary Search
	//
	//******************************************************

	//
	// Get a value from the user to search for in Array
	//
	cout << endl;
	cout << "\n-- Begining Part C - Recursive Binary Search" << endl;
	cout << endl;
	cout << "Array prior to searching " << endl;
	displayValues(cout, dataNumsC, arraySizeC);

	cout << "\nEnter value to search for->";
	cin >> searchNumber;

	valueFound = RecursiveBinarySearch(dataNumsC, 0, arraySizeC, searchNumber);
	cout << "\nThe value of " << searchNumber << " is " << (valueFound ? "found" : "NOT found") << " in the array" << endl;
	cout << endl;

	//
	// -- End of Program
	//
	cout << "--- End of Program ----" << endl;

} // End Program