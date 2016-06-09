/*---------------------------------------------------------------------
                  Driver program to test the Queue class.
  ----------------------------------------------------------------------*/

  //********************************************************
  // File Name   : Sample_Stack_Tester.cpp
  //
  // Author      : Clarence Mitchell
  // Student ID  : Mitc5039
  //
  // Assignment  : Lab 3
  // Abstract    : This labs adds the following additional funcitionality to 
  //                the Queue sample code. 
  //                The ability to reads a document containing footNotes indicated by {}
  //                and collect them in a queue, then print them out on the screen
  // Date Due    : January 26, 2016
  // -----------------------------------------------------------
  // Class       : CST370 - SPRING 2016
  // Instructor  : Dr. Seetharam
  // ********************************************************
  /*---------------------------------------------------------------------
  Driver program to test the Stack class.
  ----------------------------------------------------------------------*/
#include <fstream>			// file handling
#include <iostream>			// standard I/O
#include <string>			// string handling
using namespace std;
	
#include "Queue.h"

//
// Constants 
//
const char startDelimitor = '{';
const char endDelimitor = '}';

int main()
{
	Queue footNotes;							// Queue for footnotes
	Queue processLines;							// Queue for process lines after removing footnotes
	string inputLine, outputLine, footNote;		// file input, output and found footnote			
	ifstream myfile("sample.txt");				// input file 
	int startPos, endPos;						// Starting and Ending of end not delimiters
	//
	// check if succesful open
	//
	if (myfile.is_open())
	{
		//
		//  Process file lines
		//
		cout << "Input file contents:" << endl;

		while (getline(myfile, inputLine))
		{
			
			cout << inputLine << '\n';
			outputLine = inputLine;
			//
			// check to make sure that user entered a string
			//
			if (!inputLine.empty())
			{

				startPos = endPos = 0;

				for (startPos = outputLine.find(startDelimitor);					// find the first position or end of string
					startPos != std::string::npos;								// while not end of string
					startPos = outputLine.find(startDelimitor, startPos))	// skip last position found and look for next position
				{
					endPos = outputLine.find(endDelimitor, startPos + 1);
					if ((endPos != std::string::npos))				// end Delimiter found
					{
						//
						// now that found footnote get a substr of it and enqueue it
						//
						footNote = outputLine.substr(startPos, endPos - startPos + 1);
						footNotes.enqueue(footNote);
						// --- used for testing ....
						// cout << " end note:" << footNote << endl;
						outputLine.erase(startPos, endPos - startPos + 1);

					} 
					else
					{
						// if ill-formed the move to next position to avoid find starting brace again...
						++startPos;
					}// end if enPos found	
				} // end for




			} // End if inputLine empty
			processLines.enqueue(outputLine);


		}
		myfile.close();
		
		//
		//  Now output all the processed lines
		//
		//
		// NOTE: I could have used the queue display here but I choose to use a loop using front and dequeue
		//       
		//
		cout << "\nProcessed file contents:" << endl;
		while (!processLines.empty())
		{
			cout << processLines.front() << endl;
			processLines.dequeue();
		}

		//
		//  output all queued footNotes
		//
		cout << endl;
		cout << ((footNotes.empty()) ? "No footNotes found" : "The following footNotes were found:") << endl;

		//
		// NOTE: I could have used the queue display here but I choose to use a loop using front and dequeue
		//       
		//
		while (!footNotes.empty())
		{
			cout << footNotes.front() << endl;
			footNotes.dequeue();
		}
	}

	else
	{
		cerr << "ERROR: Unable to open file" << endl;

	}
		

	return 0;

}
