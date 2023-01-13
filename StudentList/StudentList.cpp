//****************************************************************************************************
//
//      File:                StudentList.cpp
//
//      Student:             Leon Krugliakov
//
//      Assignment:          Program #4
//
//      Course Name:         Data Structures I
//
//      Course Number:       COSC 3050 - 10
//
//      Due:                 September 21, 2020
//
//
//      This program creates a list of students and reads thier data in from a file
//		then the program prompts the user to input, delete, search or display
//		things from the list of students.
//
//      Other files required:
//		    1.    Node.h - contains the Node structure
//			2.	  LinkedList.h - Contains the LinkedList class
//			3.	  Student.h - Contains the Student structure
//
//****************************************************************************************************

#include <iostream>
#include <fstream>
#include <string>
#include "Student.h"
#include "LinkedList.h"

//****************************************************************************************************

using namespace std;

//****************************************************************************************************

char getChoice();
void process(LinkedList<Student>&);
void buildList(LinkedList<Student>&);
void displayStudents(const LinkedList<Student>& );
void countStudents(const LinkedList<Student>& );
void removeStudent(LinkedList<Student>&);
void findStudent(const LinkedList<Student>& );

//****************************************************************************************************

int main()
{
	LinkedList<Student> studentList;

	buildList(studentList);

	process(studentList);

	studentList.clearList();

	return 0;
}

//****************************************************************************************************

char getChoice() 
{
	char answer;
	bool valid = false;

	while (!valid) 
	{
		cin >> answer;

		switch (toupper(answer)) 
		{
		case 'A':
			valid = true;
			break;
		case 'B':
			valid = true;
			break;
		case 'C':
			valid = true;
			break;
		case 'D':
			valid = true;
			break;
		case 'Q':
			valid = true;
			break;
		default:
			valid = false;
			cout << "You have entered an incompatible input. Please try again." << endl;
		}
	}

	return toupper(answer);
}

//****************************************************************************************************

void process(LinkedList<Student>& students)
{
	char answer = 'a';

	while (toupper(answer) != 'Q')
	{
		cout << string(50, '*') << endl;
		cout << "A. Search for a student in the list" << endl << "B. Remove a student from the list" << endl
			<< "C. Count the number of students in the list" << endl << "D. Display the list in forward order" <<
			endl << "Q. Quit" << endl << "Please enter a choice: ";

		answer = getChoice();

		switch (answer) 
		{
		case 'A':
			findStudent(students);
			break;
		case 'B':
			removeStudent(students);
			break;
		case 'C':
			countStudents(students);
			break;
		case 'D':
			displayStudents(students);
			break;
		case 'Q':
			cout << "Program ended.";
			break;
		default:
			cout << "Something went wrong." << endl;
			break;
		}
		
	}
}

//****************************************************************************************************

void buildList(LinkedList<Student>& students) 
{
	string line;
	ifstream myFile("studentFile1.txt");
	Student stu[100];
	int counter = 0;


	if (myFile.is_open())
	{
		
		while (myFile >> stu[counter])
		{
			if (students.insert(stu[counter]) == false) 
			{
				cout << "Insertion error." << endl;
			}

			counter++;
		}
	}
	else
	{
		cout << "Unable to open file";
	}

	myFile.close();
}

//****************************************************************************************************

void displayStudents(const LinkedList<Student>&  students)
{
	cout << "Display all student's information" << endl;

	if (!(students.display())) 
	{
		cout << "There was an error displaying the list of students! Do better!" << endl;
	}
}

//****************************************************************************************************

void countStudents(const LinkedList<Student>&  students)
{
	cout << "Count the number of students in the list" << endl << "There are currently " <<
		students.getSize() << " students in the list." << endl << endl;
}

//****************************************************************************************************

void removeStudent(LinkedList<Student>& students) 
{
	int id;
	Student tempS;

	cout << "Enter student's information for removel" << endl << 
		"Please enter student ID number: ";
	cin >> id;
	
	tempS.id = id;

	if (students.remove(tempS)) 
	{
		cout << id << endl << "Student removed." << endl << endl;
	}
	else 
	{
		cout << "There has been an error with removing the student." << endl << endl;
	}
}

//****************************************************************************************************

void findStudent(const LinkedList<Student>&  students)
{
	int id;
	Student tempS;

	cout << "Search for a student in the list" << endl << "Please enter the student's ID number: ";
	cin >> id;

	tempS.id = id;

	if (students.retrieve(tempS)) 
	{
		cout << tempS << endl << endl;
	}
	else 
	{
		cout << "Student not found." << endl << endl;
	}
}

//****************************************************************************************************

/*
**************************************************
A. Search for a student in the list
B. Remove a student from the list
C. Count the number of students in the list
D. Display the list in forward order
Q. Quit
Please enter a choice: D
Display all student's information

9743: Johnson, James L
ENGR 3.15

10236: Andrews, Peter J
CPSC 2.78

15755: VandenVander, Vanessa V
HIST 3.74

17424: Nakamura, Toky O
SOCI 1.95

18264: Lucky, Lucy L
HIST 2.29

24237: Euler, Lennie L
MATH 3.83

31631: Aristotle, Alice A
PHIL 3.1

**************************************************
A. Search for a student in the list
B. Remove a student from the list
C. Count the number of students in the list
D. Display the list in forward order
Q. Quit
Please enter a choice: C
Count the number of students in the list
There are currently 7 students in the list.

**************************************************
A. Search for a student in the list
B. Remove a student from the list
C. Count the number of students in the list
D. Display the list in forward order
Q. Quit
Please enter a choice: B
Enter student's information for removel
Please enter student ID number: 9743
9743
Student removed.

**************************************************
A. Search for a student in the list
B. Remove a student from the list
C. Count the number of students in the list
D. Display the list in forward order
Q. Quit
Please enter a choice: C
Count the number of students in the list
There are currently 6 students in the list.

**************************************************
A. Search for a student in the list
B. Remove a student from the list
C. Count the number of students in the list
D. Display the list in forward order
Q. Quit
Please enter a choice: A
Search for a student in the list
Please enter the student's ID number: 9743
Student not found.

**************************************************
A. Search for a student in the list
B. Remove a student from the list
C. Count the number of students in the list
D. Display the list in forward order
Q. Quit
Please enter a choice: A
Search for a student in the list
Please enter the student's ID number: 31631

31631: Aristotle, Alice A
PHIL 3.1


**************************************************
A. Search for a student in the list
B. Remove a student from the list
C. Count the number of students in the list
D. Display the list in forward order
Q. Quit
Please enter a choice: Q
*/