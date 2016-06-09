//********************************************************
// File Name   : LinkedList.cpp
//
// Author      : Clarence Mitchell
// Student ID  : Mitc5039
//
// Assignment  : Assignment 1
// Abstract    : This file contains LinkedList Class member functions
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

//
// --- INCLUDES ---
//
#include "LinkedList.h"

//
//---------------------------------------------------
//            CONSTRUCTORS
//---------------------------------------------------
//
//-- Default constructor
//
/**************************************
 * Precondition :
 *	none
 *
 * Postcondition :
 *	LinkedList is initialized to empty
 *
 *****************************************/
LinkedList::LinkedList()
{ 
	mySize = 0;
	first = NULL;
} // End Default Constructor

//
//-- Constructor for string 
//
/**************************************
 * Precondition :
 *	none  (note if string is empty 
 *          this is same as empty constructor)
 *
 * Postcondition :
 *	LinkedList is initialized to string
 *
 *****************************************/
LinkedList::LinkedList(string stringInput)
{
	//
	// Initialize class private items
	//  NOTE: This must be done before calling class function method insert below...
	//
	mySize = 0;
	first = NULL;

	//
	// Loop through input string getting each char and insert into linked list
	//
	for (int strIdx = 0; strIdx < stringInput.length(); strIdx++)
	{
		// pass uppercase string to insert method
		LinkedList::insert(toupper(stringInput[strIdx]), strIdx );
	} // End for
		
} // end constructor


//
//-- Definition of the copy constructor
//
/**************************************
 * Precondition :
 *	original linkedlist is defined
 *
 * Postcondition :
 *	New LinkedList is initialized to original
 *
 *****************************************/
LinkedList::LinkedList(const LinkedList & origList)
{
	mySize = origList.mySize;
	first = NULL;
	
	//
	//  exit if empty list to copy
	if (mySize == 0) 
		return;
	//
	// Local Node Pointers
	Node * origPtr, * lastPtr;
	//
	//  copy the first Node 
	//
	first = new Node(origList.first->data); 
	lastPtr = first;
	origPtr = origList.first->next;
	
	//
	// Loop through original list and copy data to new list via new nodes
	//
	while (origPtr != NULL)
	{
		lastPtr->next = new Node(origPtr->data);
		origPtr = origPtr->next;
		lastPtr = lastPtr->next;
	} // End While not null

} // End copy constructor

//
//---------------------------------------------------
//            DESTRUCTOR
//---------------------------------------------------
//
//-- Definition of the destructor
/**************************************
 * Precondition :
 *	none since only called  on cleanup
 *
 * Postcondition :
 *	LinkedList node have been freed/deleted
 *
 *****************************************/
LinkedList::~LinkedList()
{
	Node * prev = first;
	Node * ptr;
	//
	// Loop through and delete all nodes
	//
	while (prev != NULL)
	{
		ptr = prev->next;
		delete prev;
		prev = ptr;
	} // End while
} // End Destructor

//
//---------------------------------------------------
//            CLASS METHODS
//---------------------------------------------------
//
/**************************************
 * insert
 *    insert Node at location
 *
 * Return Value :
 *	none
 *
 * PARAMETERS :
 *  ElementType	- Data to insert
 *  int			- Location where Node is to be inserted
 *
 * Precondition :
 *	The linkList has been defined
 *   index has value
 *   dataVal has a value
 *
 * Postcondition :
 *	Node is inserted at index or
 *   Error message was displayed
 *
 *****************************************/
//-- Definition of insert()
void LinkedList::insert(ElementType dataVal, int index)
{
	//
	//  Check if valid index
	//
	if (index < 0 || index > mySize)  
	{
		cerr << "Illegal location to insert -- " << index << endl;
		return;
	} // End if

	mySize++;
	Node * newPtr = new Node(dataVal);
	Node * predPtr = first;

	if (index == 0)				// If First Node?
	{
		newPtr->next = first;
		first = newPtr;
	}
	else
	{							// Not the First Node
		for(int i = 1; i < index; i++)
			predPtr = predPtr->next;
		newPtr->next = predPtr->next;
		predPtr->next = newPtr;
	} // End of if else

} // End insert method

/**************************************
 * erase
 *    Erase Node at location
 *
 * Return Value :
 *	none
 *
 * PARAMETERS :
 *  int	   - Location of Node to erase
 *
 * Precondition :
 *	The linkList has been defined
 *   index has value
 *
 * Postcondition :
 *	Node at index is erased or
 *   Error message was displayed
 *
 *****************************************/
//-- Definition of erase()
void LinkedList::erase(int index)
{
	//
	//  Check if index is valid
	//
	if (index < 0 || index >= mySize)
	{
		cerr << "Illegal location to delete -- " << index << endl;
		return;
	} // End if illegal location

	//
	// Check if first Node 
	// 
	mySize--;
	Node * ptr;
	Node * predPtr = first;
	if (index == 0)				// First Node?
	{
		ptr = first;
		first = ptr->next;
		delete ptr;
	} 
	else
	{							// Not First Node
		for(int i = 1; i < index; i++)
			predPtr = predPtr->next;
		ptr = predPtr->next;
		predPtr->next = ptr->next;
		delete ptr;
	} // End of if else
} // End of erase method



/**************************************
 * display
 *    Iterates through the LinkedList
 *    displaying each node's data
 *
 * Return Value :
 *	none
 *
 * PARAMETERS :
 *   ostream - output stream
 *
 * Precondition :
 *	The linkList has been defined
 *   out has value and is open stream
 *
 * Postcondition :
 *	displayed all Node data within the linkedList
 *
 *****************************************/
//-- Definition of display()
void LinkedList::display(ostream & out) const
{
	Node * ptr = first;
	while (ptr != 0)		// while not end of list
	{
		out << ptr->data << " ";
		ptr = ptr->next;
	} // End of while
} // End of display method

/**************************************
 * findSubStrings
 *    Iterates through the LinkedList
 *    and finds the data item with the maximum
 *
 * Return Value :
 *	ElementType - Sum of data items
 *
 * PARAMETERS :
 *	char	- Starting Substring Char
 *  char    - Ending Substring Char
 *  ostream - output stream
 *
 * Precondition :
 *	The linkList has been defined
 *  startChar has value
 *  endChar has value
 *  out has value and is open stream
 *
 * Postcondition :
 *	displayed all substrings within the linkedList
 *  that has startChar and endChar
 *
 *****************************************/
 //-- Definition of findSubStrings
void LinkedList::findSubStrings(char startChar, char endChar, ostream & out) const
{
	Node * ptr = first;
	Node * currPtr = ptr;
	string currStr = "";
	int subStringCount = 0;


	//
	// The following is a three loop process.
	//   The outer most loops through the Linked List looking for starting char
	//    Once a starting char has been found the inner loops start
	//     The 1st inner loop is used to control the fact that there may be more than 1 end char value in the list
	//     This is also where the complete string is outputted  (if the end char is found) at the end of the loop
	//          The 2nd inner loop is used to actually gather the data items
	//             until the end char or end of link list
	//       Once the 2nd inner loop has finished either an end char has been found or the end of the linked list
	//       if it is not the end of the linked list then the process continues to the next node
	//       just after the last end char node
	//        
	// NOTE THIS COULD HAVE BEEN DONE USING RECURSION BUT WOULD BE FAR MORE COMPLEXED TO UNDERSTAND
	//
	while (ptr != nullptr)
	{
		//
		//  look for startChar or skip
		//
		if ( ptr->data == startChar)
		{
			//
			// Now found startchar, set current pointer position and current string value 
			//
			currPtr = ptr;
			currStr = "";

			//
			// move through the linked list using currPtr while ptr remains pointing to startChar
			//
			while (currPtr != nullptr)
			{
				//
				//  now go through and append data to currStr until end of list or substring end found
				//
				while ((currPtr != nullptr) && (currPtr->data != endChar))
				{
					currStr += currPtr->data;
					currPtr = currPtr->next;
				} // End while not endChar

				//
				// If we did not reach end of list but end substring char 
				//     add that char and output string and increment total count
				//
				//
				if (currPtr != nullptr)
				{
					currStr += currPtr->data;
					
					out << "SubString "
						<< ++subStringCount 
						<< ":" 
						<< currStr 
						<< endl;

					currPtr = currPtr->next;  // move to next Node
				} // End if check for end

			} // End while not end list

		} // End if startChar

		ptr = ptr->next;
	} // End while not end of list outter loop
	//
	// out final total
	//
	out << "Total " << subStringCount << " substrings" << endl;
} // End findStubString




