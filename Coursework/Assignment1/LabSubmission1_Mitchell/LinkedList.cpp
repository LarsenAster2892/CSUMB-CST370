//********************************************************
// File Name   : LinkedList.cpp
//
// Author      : Clarence Mitchell
// Student ID  : Mitc5039
//
// Assignment  : Lab 1
// Abstract    : This file contains Class member functions
// Date Due    : January 12, 2016
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

#include "LinkedList.h"

//-- Default constructor
LinkedList::LinkedList()
{ 
	mySize = 0;
	first = NULL;
}

//-- Definition of the copy constructor
LinkedList::LinkedList(const LinkedList & origList)
{
	mySize = origList.mySize;
	first = NULL;
	
	if (mySize == 0) 
		return;

	Node * origPtr, * lastPtr;
	first = new Node(origList.first->data); // copy first node
	lastPtr = first;
	origPtr = origList.first->next;
	while (origPtr != NULL)
	{
		lastPtr->next = new Node(origPtr->data);
		origPtr = origPtr->next;
		lastPtr = lastPtr->next;
	}
}


//-- Definition of the destructor
LinkedList::~LinkedList()
{
	Node * prev = first;
	Node * ptr;

	while (prev != NULL)
	{
		ptr = prev->next;
		delete prev;
		prev = ptr;
	}
}


//-- Definition of insert()
void LinkedList::insert(ElementType dataVal, int index)
{
	if (index < 0 || index > mySize)
	{
		cerr << "Illegal location to insert -- " << index << endl;
		return;
	}

	mySize++;
	Node * newPtr = new Node(dataVal);
	Node * predPtr = first;
	if (index == 0)
	{
		newPtr->next = first;
		first = newPtr;
	}
	else
	{
		for(int i = 1; i < index; i++)
			predPtr = predPtr->next;
		newPtr->next = predPtr->next;
		predPtr->next = newPtr;
	}
}


//-- Definition of erase()
void LinkedList::erase(int index)
{
	if (index < 0 || index >= mySize)
	{
		cerr << "Illegal location to delete -- " << index << endl;
		return;
	}

	mySize--;
	Node * ptr;
	Node * predPtr = first;
	if (index == 0)
	{
		ptr = first;
		first = ptr->next;
		delete ptr;
	}
	else
	{
		for(int i = 1; i < index; i++)
			predPtr = predPtr->next;
		ptr = predPtr->next;
		predPtr->next = ptr->next;
		delete ptr;
	}
}



//-- Definition of display()
void LinkedList::display(ostream & out) const
{
	Node * ptr = first;
	while (ptr != 0)
	{
		out << ptr->data << " ";
		ptr = ptr->next;
	}
}

/**************************************
 * maxItem
 *    Interates through the LinkedList
 *    and finds the data item with the maximum
 *
 * Return Value :
 *	ElementType - Sum of data items
 *
 * PARAMETERS :
 *	none
 *
 *
 * Precondition :
 *	The linkList has been defined
 *   and has 0 to many values
 *
 * Postcondition :
 *	Return value max data item
 *
 *****************************************/

ElementType LinkedList::maxItem()
{
	// -- Local variables
	Node * ptr = first;				// Pointer to current node
	ElementType maxValue = -1;		// located maximum value

	// check if empty list
	if ((mySize < 1) || (first == NULL))
	{
		cerr << "MaxItem Err: list is Empty " << endl;
	}
	else
	{
		maxValue = ptr->data;
		while (ptr != 0)
		{
			maxValue = (maxValue < ptr->data) ? ptr->data : maxValue;
			ptr = ptr->next;
		}

	}

	return (maxValue);

}

/**************************************
* isAscedingOrder
*    Interates through the LinkedList
*    and finds the data item with the maximum
*
* Return Value :
*	Bool - true if linkedList data items are in ascending order
*        - false if not in ascending order
*
* PARAMETERS :
*	none
*
*
* Precondition :
*	The linkList has been defined
*   and has 0 to many values
*
* Postcondition :
*	Returned bool value
*
*****************************************/

bool LinkedList::isAscedingOrder()
{
	// -- Local variables
	Node * ptr = first;				// Pointer to current node
	bool returnValue = true;		// default value of false
	ElementType priorValue = -1;	// located maximum value
									// check if empty list or has only 1 item
	if ((mySize < 2) || (first == NULL))
	{
		returnValue = true;
	}
	else
	{
		// set the prior value to the current node's data (results in true in compare)
		priorValue = ptr->data;

		//
		//  Loop through until reach the end or find data not in sequence (returnValue is to false)
		//
		while ((ptr != 0) && (returnValue))	
		{
			returnValue = (priorValue <= ptr->data);
			ptr = ptr->next;
		}

	}

	return (returnValue);

}
