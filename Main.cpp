#include "CommandParser.h"
#include "BinarySearchTree.h"
#include "Definitions.h"

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	CommandParser parser; //New command parser; to be used while the program is running

	BinarySearchTree bst; //A new BST to be used while the program is running

	while (unsigned short command = parser.parseCommand()) //Parse command, which is converted to an integer; terminates when a 0 is received from the parser
	{
		if (command != 4) //If we are just traversing, we do not need a FN
		{
			unsigned long long FN; //FN container
			cin >> FN; //Read in the student FN

			if (command == 1) //Insert a student record into the BST
			{
				//Containers for the student first & last name
				char first_name[257];
				char last_name[257];

				cin >> first_name >> last_name;

				//New student
				Student s;
				s.FN = FN;
				strcpy(s.first_name, first_name);
				strcpy(s.last_name, last_name);

				bst.insert(s); //Insert the student into the BST

				cout << RECORD_INSERTED << endl; //Print the result of the operation
			}
			else if (command == 2) //Delete a student record from the BST
			{
				//Pass a new student with the given FN, so that they may be removed from the BST
				//Print a message corresponding to whether or not the operation was succcessful
				if (bst.remove(Student({ FN, { '\0' }, { '\0' } })))
					cout << RECORD_DELETED << endl;
				else
					cout << RECORD_NOT_FOUND << endl;
			}
			else if (command == 3) //Find a student record in the BST
			{
				Student s = bst.find(FN); //Get the student from the BST

				//The BST has returned a blank student, so the operation failed
				//ULLONG_MAX > 2^50 as defined by the operating limits of the input and as such, no real student may have this FN
				if (s.FN == ULLONG_MAX) 
					cout << RECORD_NOT_FOUND << endl;
				else //The operation was successful; print the student data
					printStudentData(s);
			}
		}
		else //Traverse the BST in order
		{
			//Container for the student records return by the BST in order
			vector<Student> records = bst.traverseTreeInOrder();

			//Print all of the records in order
			for (size_t i = 0; i < records.size(); i++) 
			{
				cout << records[i].FN;

				//Do not print the ", " delimiter for the last student record
				if (i + 1 != records.size())
					cout << ", ";
			}

			//End the line; This occurs even if the BST is empty and no records were retuned
			cout << endl;
		}
	}

    return 0;
}

