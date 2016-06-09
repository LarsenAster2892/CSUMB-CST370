//********************************************************
// File Name   : LinkedList.h
//
// Author      : Clarence Mitchell
// Student ID  : Mitc5039
//
// Assignment  : Assignment 1
// Abstract    : This file contains the LinkedList class Headers
// Date Due    : January 12, 2016
// -----------------------------------------------------------
// Class       : CST370 - SPRING 2016
// Instructor  : Dr. Seetharam
// ********************************************************
//
// --- INCLUDES -----
//

//----- LinkedList.h -----
#ifndef LINKEDLIST
#define LINKEDLIST

#include <iostream>
#include <string>
using namespace std;

typedef char ElementType;

class LinkedList
{ 
//
//---------------------------------------------------
//            PUBLIC DATA AND METHODS
//---------------------------------------------------
//
public:
	
	/************** Class Constructors & Destructor ************************/
	LinkedList();								// constructor
	LinkedList(string stringValue);				// constructor for string
	~LinkedList();								// destructor
	LinkedList(const LinkedList & original);	// copy constructor

	/************** Input/Output *******************************************/
	void display(ostream & out) const;			// display LinkedList
	/*--------------------------------------------------------------------
		Display the contensts of this LinkedList.
		Precondition: ostream out is open
		Postcondition: Elements of this LinkedList have been output to out.
	--------------------------------------------------------------------*/


	/************** Other Function Members  ********************************/
	void insert(ElementType item, int pos);				// insert single element function
	void erase(int pos);								// erase element at position

	void findSubStrings(char startChar,	char endChar, ostream & out) const; // finds all substrings 
																			// starting with startChar 
																			// and ending with endChar

	

//
//---------------------------------------------------
//            PRIVATE DATA, METHODS & CLASSES
//---------------------------------------------------
//
//
private:
	//------------------------------------------------
	//   Private Classes
	//------------------------------------------------
	/**************************************
	* Node
	*    This is a private class that contains
	*    data and pointer to next node
	*
	*****************************************/
	
	class Node
	{
	public:
		ElementType data;
		Node * next;
		//------ Node OPERATIONS
		//-- Default constrctor: initializes next member to
		Node()
			: next(NULL)
		{ }
		//-- Explicit-value constructor: initializes data member to dataValue
		//-- and next member to 0
		Node(ElementType dataValue)
			: data(dataValue), next(NULL)
		{ }
	}; // End of Node Class
	
	//-------------------------------------------
	// Private Data Items
	//-------------------------------------------

	Node * first;
	int mySize;
}; // End of Class

#endif