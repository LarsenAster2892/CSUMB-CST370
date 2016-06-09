/********************************************************
// File Name   : coolSortRoutines.h
//
// Author      : Clarence Mitchell
// Student ID  : Mitc5039
//
// Assignment  : Assignment 6
// Abstract    : This file contains the function Headers
// Date Due    : February 16, 2016
// -----------------------------------------------------------
// Class       : CST370 - SPRING 2016
// Instructor  : Dr. Seetharam
// ********************************************************
//
// --- INCLUDES -----
//
/*-- coolSortRoutines.h ---------------------------------------------------------------

This header file defines the functions used for the sort routine.

coolSort:				Modified Insertion Sort routine for sequence numbers

display:				Displays all the array elements

--------------------------------------------------------------------------*/

#include <iostream>
#include <string>		// String routines

#ifndef COOLSORTFUNCTIONS
#define COOLSORTFUNCTIONS
//
//  Define program functions;
//
/*------------------------------------------------------------------------
coolSort

Precondition:   dataArray has been defined and populated
				
				arrSize has a value that is size of arr
				
				hSeq has been defined and populated, 
				   and is in descending order ending with 1
				   and the first element of the sequence is less than arrSize
				
				hSeqSize has a value that is size of hSeq

Postcondition: dataArray is sorted
-----------------------------------------------------------------------*/
void coolSort(int dataArray[], int arrSize, int hSeq[], int hSeqSize);


/*------------------------------------------------------------------------
displayValues

Precondition:  inputArr has been defined and populated
               arrSize has a value that is size of arr
               out is a valid output stream and has been opened
Postcondition: output stream contains values from inputArr
-----------------------------------------------------------------------*/
const void displayValues(ostream & out, int inputArr[], int arrSize);

#endif

