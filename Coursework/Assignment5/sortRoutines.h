/********************************************************
// File Name   : sortRoutines.h
//
// Author      : Clarence Mitchell
// Student ID  : Mitc5039
//
// Assignment  : Assignment 5
// Abstract    : This file contains the function Headers
// Date Due    : February 9, 2016
// -----------------------------------------------------------
// Class       : CST370 - SPRING 2016
// Instructor  : Dr. Seetharam
// ********************************************************
//
// --- INCLUDES -----
//
/*-- sortRoutines.h ---------------------------------------------------------------

This header file defines the functions used for the sort routine.

SelectionSort:  Selection Sort routine
SelectionSortK: Modified selection sort for K elements
getUserKValue:  gets a value from the user to display the K number of elements
display:        Displays all the array elements

--------------------------------------------------------------------------*/

#include <iostream>
#include <string>		// String routines

#ifndef SORTFUNCTIONS
#define SORTFUNCTIONS
//
//  Define program functions;
//
/*------------------------------------------------------------------------
SelectionSort

Precondition:  arr has been defined and populated
			   n has a value that is size of arr	
Postcondition: arr is sorted using selection sort
-----------------------------------------------------------------------*/
void SelectionSort(int arr[], int n);									// Selection Sort routine

/*------------------------------------------------------------------------
SelectionSortK

Precondition:  arr has been defined and populated
			    n has a value that is size of arr
				k has a value that is within 1 to n 
Postcondition: arr is sorted to the k value using selection sort
-----------------------------------------------------------------------*/
void SelectionSortK(int arr[], const int n, const int k);				// Selection Sort routine using K element return

const void displayValues(ostream & out, int inputArr[], int arrSize);	// display array

/*------------------------------------------------------------------------
getUserKValue

Precondition:  arrSize has been defined an has a value greater than 0
Postcondition: value entered by user that is between 1 and arrSize is returned
-----------------------------------------------------------------------*/
int getUserKValue(int arrSize);											// get K value from user

#endif