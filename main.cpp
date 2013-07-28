#include <iostream>
#include <fstream>
#include "hashtable.h"

#ifdef _WIN32
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#endif

using namespace std;

void testMessage(char* msg, bool testResult)
{
	cout << msg << ": ";
	if (testResult)
	{
		cout << "success!" << endl;
	}
	else
	{
		cout << "fail." << endl;
	}
}

// A utility function to read the dialog elements from the data file.  Each response 
// takes two lines in the data file.  The first line is a string ID and the second 
// line is the text for the dialog element.  The maximum ID length is 15 bytes. The 
// maximum dialog element length is 2047 bytes.  

void testHashTable(char* filename)
{
	const int MAX_ID_LENGTH = 16;
	const int MAX_DIAG_LENGTH = 2048;

	HashTable ht;
	char testId1[MAX_ID_LENGTH] = "";
	char badId1[MAX_ID_LENGTH] = "BADKEY000";
	const DialogElement* testElement;	
	bool testResult;

	try
	{
		ifstream infile;
		infile.open(filename);

		char tmpId[MAX_ID_LENGTH];
		char tmpDialogElement[MAX_DIAG_LENGTH]; // tmp storage to hold the line.
		int count = 0;

		while (!infile.eof())
		{
			// Read the id and response lines from the file.
			infile.getline(tmpId,MAX_ID_LENGTH);
			infile.getline(tmpDialogElement,MAX_DIAG_LENGTH);

			if (strcmp(tmpId,"") != 0 && strcmp(tmpDialogElement,"") != 0)
			{
				ht.put(DialogElement(tmpId,tmpDialogElement));
				if (count == 0)
				{
					strcpy(testId1,tmpId);
				}
				count++;
				if (strcmp(tmpId,badId1)==0)
				{
					cout << "WARNING!!! An element in the dialog file matches the badkey ID.  Unittests may fail." << endl;
				}
			}
		};

		infile.close();
	}
	catch (exception ex)
	{
		cout << "Error reading the command file." << endl;
	}

	cout << "Dumping the hashtable to check that all the elements are there and in the right place." << endl;
	ht.dumpTable(cout,false);

	if (strcmp(testId1,"") != 0)
	{
		cout << "Getting an element." << endl;
		testElement = ht.get(testId1);
		cout << *testElement;

		testElement = ht.get(badId1);
		testMessage("Getting a non-existant element",testElement == NULL);

		testResult = ht.remove(testId1);
		testMessage("Attempting to remove an element",testResult);

		testResult = ht.remove(badId1);
		testMessage("Attempting to remove a non-existant element",!testResult);

		testElement = ht.get(testId1);
		testMessage("Checking to see if removed element is still there",testElement == NULL);
	}

}


int main(int argc,char** argv) {

	char* dialogFile = "dialog_1.txt";
	if (argc == 2)
	{
		dialogFile = argv[1];
	}

	testHashTable(dialogFile);

#ifdef _WIN32
	if (_CrtDumpMemoryLeaks()) {
		cout << "Memory leaks!" << endl;
	}
#endif

	return 0;
}
