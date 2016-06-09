//********************************************************
// File Name   : BST.cpp
//
// Author      : Clarence Mitchell
// Student ID  : Mitc5039
//
// Assignment  : Assignment 7
// Abstract    : This file contains BST routine functions
// Date Due    : February 23, 2016
// -----------------------------------------------------------
// Class       : CST370 - SPRING 2016
// Instructor  : Dr. Seetharam
// ********************************************************

#include <iostream>
#include <iomanip>

using namespace std;

#include "BST.h"

//--- Definition of constructor
BST::BST()
: myRoot(0)
{}

bool BST::empty() const
{ return myRoot == 0; }


bool BST::search(const int & item) const
{
   BinNode * locptr = myRoot;
   //
   // -- CM Modified to call recursive searh to find item
   //   See bottom of file for rsearch code...
   //
   bool found = rsearch(myRoot, item);

   //
   //  -- CM commented out the following iterative code
   //
   //while (!found && locptr != 0)
   //{
   //   if (item < locptr->data)       // descend left
   //     locptr = locptr->left;
   //   else if (locptr->data < item)  // descend right
   //     locptr = locptr->right;
   //   else                           // item found
   //     found = true;
   //}
   return found;
}


void BST::insert(const int & item)
{
   BinNode * locptr = myRoot;   // search pointer
   BinNode * parent = 0;        // pointer to parent of current node
   bool found = false;     // indicates if item already in BST
   while (!found && locptr != 0)
   {
      parent = locptr;
      if (item < locptr->data)       // descend left
         locptr = locptr->left;
      else if (locptr->data < item)  // descend right
         locptr = locptr->right;
      else                           // item found
         found = true;
   }
   if (!found)
   {                                 // construct node containing item
      locptr = new BinNode(item);  
      if (parent == 0)               // empty tree
         myRoot = locptr;
      else if (item < parent->data )  // insert to left of parent
         parent->left = locptr;
      else                           // insert to right of parent
         parent->right = locptr;
   }
   else
      cout << "Item already in the tree\n";
}

//=======================================================================
//
// ---   Routines added for assignment
//
//=======================================================================
/*------------------------------------------------------------------------
rsearch  - Recursive search

Precondition:  nodePtr points to a node in a BST or null  
               item has value to search for
Postcondition: true is return if item is found else false
-----------------------------------------------------------------------*/

bool BST::rsearch(BinNode * nodePtr, const int & item) const
{
	if (nodePtr == 0)					// is the tree/subtree empty then not found
		return false;

	if (nodePtr->data == item)			// at the right data item then found
		return true;

	if (nodePtr->data > item)			// Search item less than current data item then Look to left tree/subtree		
	{
		rsearch(nodePtr->left, item);	// recursive call using left subtree
	}
	else                               // greater than current data item then Look to right tree/subtree
	{
		rsearch(nodePtr->right, item);	// recursive call using right subtree
	} // end if

} // end rsearch

/*------------------------------------------------------------------------
inOrder  - Print the tree in-order by traversing in the following order: 
       1. left sub-tree
       2. root
       3.  right sub-tree

Precondition:  BST has been defined
Postcondition: Subtree with root pointed to by nodePtr has been printed

Note: Calls recursive routine rinOrder
-----------------------------------------------------------------------*/
void BST::inOrder() const
{

	if (myRoot != 0)			// BST is not empty
	{
		rinOrder(myRoot);
	}
	else
	{
		cout << "BST is empty" << endl;
	} // end if

	cout << endl;

} // end inOrder

/*------------------------------------------------------------------------
rinOrder  - recursive inOrder traversal 
          1. left sub-tree
		  2. root
		  3.  right sub-tree

Precondition:  nodePtr points to a node in a BST or null
Postcondition: Subtree with root pointed to by nodePtr has been printed
-----------------------------------------------------------------------*/
void BST::rinOrder(BinNode * nodePtr) const 
{
	
	if (nodePtr != 0) {
		rinOrder(nodePtr->left);
		cout << nodePtr->data << " ";
		rinOrder(nodePtr->right);
	} // end if

} // end rinOrder

/*------------------------------------------------------------------------
preOrder  - Print the tree in-order by traversing in the following order:
	1. root
	2. left sub-tree
	3.  right sub-tree

Precondition:  BST has been defined
Postcondition: Subtree with root pointed to by nodePtr has been printed

Note: Calls recursive routine rpreOrder
-----------------------------------------------------------------------*/
void BST::preOrder() const
{
	
	if (myRoot != 0)			// BST is not empty
	{
		rpreOrder(myRoot);
	}
	else
	{
		cout << "BST is empty" << endl;
	} // end if

	cout << endl;
} // end preOrder

/*------------------------------------------------------------------------
rpreOrder  - recursive inOrder traversal
	1. root
	2. left sub-tree
	3. right sub-tree

Precondition:  nodePtr points to a node in a BST or null
Postcondition: Subtree with root pointed to by nodePtr has been printed
-----------------------------------------------------------------------*/
void BST::rpreOrder(BinNode * nodePtr) const
{

	if (nodePtr != 0) {
		cout << nodePtr->data << " ";
		rpreOrder(nodePtr->left);
		rpreOrder(nodePtr->right);
	} // end if

} // end rpreOrder

/*------------------------------------------------------------------------
nodeCount  - Counts the number of nodes in the BST

Precondition:  BST has been defined
Postcondition: count of nodes in BST is returned

Note: Calls recursive routine rnodeCount()
-----------------------------------------------------------------------*/
int BST::nodeCount() 
{
	int rtnValue = 0;

	if (myRoot != 0)			// BST is not empty --  prevents extra push on stack.
	{
		rtnValue = rnodeCount(myRoot);
	} // end if

	return rtnValue;

} // end nodeCount

/*------------------------------------------------------------------------
rnodeCount  - Counts the number of nodes in the BST

Precondition:  nodePtr points to a node in a BST or null 
Postcondition: count of nodes in BST is returned
-----------------------------------------------------------------------*/
int BST::rnodeCount(BinNode * nodePtr) 
{
	if (nodePtr == 0)			// empty node
	{
		return 0;
	}
	else
	{
		//
		// return count of left nodes + count of right nodes + 1 (current node) 
		//
		return (rnodeCount(nodePtr->left) + rnodeCount(nodePtr->right)) + 1;
	} // End if


} // End rnodeCount

