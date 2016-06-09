
//********************************************************
// File Name   : Sample_BST_tester.cpp
//
// Author      : Clarence Mitchell
// Student ID  : Mitc5039
//
// Assignment  : Assignment 7
// Abstract    : This assignment implements the Binary Search Tree functions: 
//               1) A recursive search 
//               2) inorder traversal algorithm 
//				 3)	preorder traversal algorithm
//				 4)	node count algorithm
// Date Due    : February 23, 2016
// -----------------------------------------------------------
// Class       : CST370 - SPRING 2016
// Instructor  : Dr. Seetharam
// ********************************************************
/*------------------------------------------------------------------
/*----- treetester.cpp -----------------------------------------------------
                Program for testing BST.
 ------------------------------------------------------------------------*/
#include <iostream>
using namespace std;

#include "BST.h"



int main()
{
   // Testing Constructor and empty()
   BST intBST;            // test the class constructor
   cout << "Constructing empty BST\n";
   cout << "BST " << (intBST.empty() ? "is" : "is not") << " empty\n";

   // Testing insert
   cout << "\nNow insert a bunch of integers into the BST."
           "\nTry items not in the BST and some that are in it:\n";
   int number;
   for (;;)
   {
      cout << "Item to insert (-999 to stop): ";
      cin >> number;
	  if (number == -999) break;
      intBST.insert(number);
   }
   cout << "BST " << (intBST.empty() ? "is" : "is not") << " empty\n";

   // Testing search()
   cout << "\n\nNow testing the search() operation."
           "\nTry both items in the BST and some not in it:\n";
   for (;;)
   {
      cout << "Item to find (-999 to stop): ";
      cin >> number;
      if (number == -999) break;
      cout << (intBST.search(number) ? "Found" : "Not found") << endl;
   } 

   //
   //  Traverse the tree inorder (sorted)
   //
   cout << endl;
   cout << "Inorder traversal" << endl;
   intBST.inOrder();

   //
   //  Traverse the tree preOrder
   //
   cout << endl;
   cout << "Preorder traversal" << endl;
   intBST.preOrder();

   //
   //  Count the nodes in the tree
   //
   cout << endl;
   cout << "There are " << intBST.nodeCount() << " nodes in the BST " << endl;
  
   //
   // -- End of Program
   //
   cout << "\n--- End of Program ----" << endl;

} // End of program
