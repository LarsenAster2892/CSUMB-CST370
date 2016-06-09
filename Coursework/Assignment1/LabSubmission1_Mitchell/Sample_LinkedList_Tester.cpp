//********************************************************
// File Name   : Sample_LinkedList_Tester.cpp
//
// Author      : Clarence Mitchell
// Student ID  : Mitc5039
//
// Assignment  : Lab 1
// Abstract    : This labs adds the following additional funcitionality to 
//                the linkedList sample code. 
//                 1) The ability to get the maximum data item
//                 2) A check that all items are in Ascending order
// Date Due    : January 12, 2016
// -----------------------------------------------------------
// Class       : CST370 - SPRING 2016
// Instructor  : Dr. Seetharam
// ********************************************************

//
// --- INCLUDES -----
//
#include <iostream>
using namespace std;

#include "LinkedList.h"

int main()
{
   // Test the class constructor
   LinkedList intList;
   cout << "Constructing intList\n";

  /*-------------------------------------
   * CST370 Lab 1 Problem a -- Modification
   *   Test 1 for empty list
   *------------------------------------*/
   cout << "Lab 1a TEST 1:" << endl;
   cout << "Max Item is : " << intList.maxItem() << endl;
   cout << endl;

  /*-------------------------------------
   * CST370 Lab 1 Problem b -- Modification
   *   Test 1 for empty list
   *------------------------------------*/
   cout << "Lab 1b TEST 1:" << endl;
   cout << "The linkedList items " << (intList.isAscedingOrder() ? "are ": "are not ") << "in Ascending order" << endl;
   cout << endl;

   // Test insert()
   intList.insert(100, 0);
   intList.display(cout);
   cout << endl;

  /*-------------------------------------
   * CST370 Lab 1 Problem a -- Modification
   *   Test 2 for 1 entry in list
   *------------------------------------*/
   cout << "Lab 1a TEST 2:" << endl;
   cout << "Max Item is : " << intList.maxItem() << endl;
   cout << endl;

  /*-------------------------------------
   * CST370 Lab 1 Problem b -- Modification
   *   Test 2 for 1 entry in list
   *------------------------------------*/
   cout << "Lab 1b TEST 2:" << endl;
   cout << "The linkedList items " << (intList.isAscedingOrder() ? "are " : "are not ") << "in Ascending order" << endl;
   cout << endl;

   intList.insert(200, 0);
   intList.display(cout);
   cout << endl;
   
   intList.insert(300, 1);
   intList.display(cout);
   cout << endl;
   
   intList.insert(400, 1);
   intList.display(cout);
   cout << endl;
   
   intList.insert(500, 3);
   intList.display(cout);
   cout << endl;


   /*-------------------------------------
   * CST370 Lab 1 Problem a-- Modification
   *   Test 3 for max item in list > 1 in size
   *------------------------------------*/
   cout << "Lab 1a TEST 3:" << endl;
   cout << "Max Item is : " << intList.maxItem() << endl;
   cout << endl;

  /*-------------------------------------
   * CST370 Lab 1 Problem b -- Modification
   *   Test 3 for 1 entry in list
   *------------------------------------*/
   cout << "Lab 1b TEST 3:" << endl;
   cout << "The linkedList items " << (intList.isAscedingOrder() ? "are " : "are not ") << "in Ascending order" << endl;
   cout << endl;

   // Test destructor
   {
      LinkedList anotherList;
      for (int i = 0; i < 10; i++)
      {
	anotherList.insert(100*i, i);
      }
      cout << "\nThis is another list\n";
      anotherList.display(cout);

     /*-------------------------------------
	  * CST370 Lab 1 -- Modification
	  *   Test 4 for max item in another list > 1 in size
	  *------------------------------------*/
	  cout << "\nLab 1a TEST 4:" << endl;
	  cout << "Max Item is : " << anotherList.maxItem() << endl;
	  cout << endl;

	 /*-------------------------------------
	  * CST370 Lab 1 Problem b -- Modification
	  *   Test 4 for 1 entry in list
	  *------------------------------------*/
	  cout << "Lab 1b TEST 4:" << endl;
	  cout << "The linkedList items " << (anotherList.isAscedingOrder() ? "are " : "are not ") << "in Ascending order" << endl;
	  cout << endl;

   }

 

   // Test erase
   intList.erase(1);
   intList.erase(1);
   cout << "\n\nTwo items are erased from the first list\n";
   intList.display(cout);
   cout << endl;


}