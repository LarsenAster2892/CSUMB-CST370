/********************************************************
// File Name   : searchRoutines.h
//
// Author      : Clarence Mitchell
// Student ID  : Mitc5039
//
// Assignment  : Lab 6
// Abstract    : This file contains the function Headers
// Date Due    : February 16, 2016
// -----------------------------------------------------------
// Class       : CST370 - SPRING 2016
// Instructor  : Dr. Seetharam
// ********************************************************
//
// --- INCLUDES -----
//
/*-- searchRoutines.h ---------------------------------------------------------------

This header file defines the functions used for the sort routine.

LinearSearch:			Sequential search
InterBinarySearch:		Binary Search using iterative method
RecursiveBinarySearch:  Binary Search using recursivel method
display:				Displays all the array elements

--------------------------------------------------------------------------*/

#include <iostream>
#include <string>		// String routines

#ifndef SEARCHFUNCTIONS
#define SEARCHFUNCTIONS
//
//  Define program functions;
//
/*------------------------------------------------------------------------
LinearSearch

Precondition:  dataArray has been defined and populated
			   arrSize has a value that is size of arr
			   searchkey has a value
Postcondition: true is return if searchKey is found else false
-----------------------------------------------------------------------*/
bool LinearSearch(int dataArray[], int arrSize, int searchKey);


/*------------------------------------------------------------------------
IterBinarySearch

Precondition:  dataArray has been defined and populated
               arrSize has a value that is size of arr
               searchkey has a value
Postcondition: true is return if searchKey is found else false
-----------------------------------------------------------------------*/
bool IterBinarySearch(int dataArray[], int arrSize, int searchKey);

/*------------------------------------------------------------------------
RecursiveBinarySearch

Precondition:  dataArray has been defined and populated
               lowPos has a value that is size 0 to array size - 1
			   highPos has a value that is size 0 to array size
			   searchkey has a value
Postcondition: true is return if searchKey is found else false
-----------------------------------------------------------------------*/
bool RecursiveBinarySearch(int dataArray[], int lowPos, int highPos, int searchKey);

/*------------------------------------------------------------------------
display array

Precondition:  inputArr has been defined and populated
arrSize has a value that is size of arr
out is a valid output stream and has been opened
Postcondition: output stream contains values from inputArr
-----------------------------------------------------------------------*/
const void displayValues(ostream & out, int inputArr[], int arrSize);

#endif
