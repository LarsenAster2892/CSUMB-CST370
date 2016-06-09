/********************************************************
// File Name   : BST.h
//
// Author      : Clarence Mitchell
// Student ID  : Mitc5039
//
// Assignment  : Assignment 7
// Abstract    : This file contains the function Headers
// Date Due    : February 23, 2016
// -----------------------------------------------------------
// Class       : CST370 - SPRING 2016
// Instructor  : Dr. Seetharam
// ********************************************************
//
*/
#include <iostream>
using namespace std;  

#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

class BST
{
 public:
  /***** Function Members *****/
  BST();
  bool empty() const;
  bool search(const int & item) const; 
  void insert(const int & item);
  

  /*------------------------------------------------------------------------
  inOrder  - Print the tree in-order by traversing in the following order:
	  1. left sub-tree
	  2. root
	  3. right sub-tree

  Precondition:  BST has been defined
  Postcondition: BST with root pointed to by myRoot has been printed

  Note: Calls recursive routine rinOrder
  -----------------------------------------------------------------------*/
  void inOrder() const;

  /*------------------------------------------------------------------------
  preOrder  - Print the tree in-order by traversing in the following order:
	  1. root
	  2. left sub-tree
	  3.  right sub-tree

  Precondition:  BST has been defined
  Postcondition: BST with root pointed to by myRoot has been printed

  Note: Calls recursive routine rpreOrder
  -----------------------------------------------------------------------*/
  void preOrder() const;


  /*------------------------------------------------------------------------
  nodeCount  - Counts the number of nodes in the BST

  Precondition:  BST has been defined
  Postcondition: count of nodes in BST is returned

  Note: Calls recursive routine rnodeCount()
  -----------------------------------------------------------------------*/
  int nodeCount();

 private:
  /***** Node class *****/
  class BinNode 
  {
   public:
    int data;
    BinNode * left;
    BinNode * right;

    // BinNode constructors
    // Default -- data part is default int value; both links are null.
    BinNode()
    : left(0), right(0)
    {}

    // Explicit Value -- data part contains item; both links are null.
    BinNode(int item)
    : data(item), left(0), right(0)
    {}
 
  };// end of class BinNode declaration
  
  /***** Data Members *****/
  BinNode * myRoot; 

  //===========================================================================
  //
  //**** private methods ******
  //
  //==========================================================================
  /*------------------------------------------------------------------------
  rsearch  - Recursive search

  Precondition:   item has value to search for
  Postcondition: true is return if item is found else false
  -----------------------------------------------------------------------*/
  bool rsearch(BinNode * rootPtr, const int & item) const;

  /*------------------------------------------------------------------------
  rinOrder  - Recursive inOrder traversal

  Precondition:  BST has been defined
  Postcondition: Subtree with root pointed to by nodePtr has been printed
  -----------------------------------------------------------------------*/
  void  rinOrder(BinNode * rootPtr) const;
  
  /*------------------------------------------------------------------------
  rpreOrder  - Recursive preOrder traversal

  Precondition:  BST has been defined
  Postcondition: Subtree with root pointed to by nodePtr has been printed
  -----------------------------------------------------------------------*/
  void  rpreOrder(BinNode * rootPtr) const;

   /*------------------------------------------------------------------------
   rnodeCount  - Recursively counts the number of nodes in the BST

   Precondition:  BST has been defined
   Postcondition: count of nodes in BST is returned
   -----------------------------------------------------------------------*/
	int rnodeCount(BinNode * rootPtr);

}; // end of class declaration


#endif
