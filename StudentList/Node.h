//****************************************************************************************************
//
//      File:                Node.h
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
//		    1.    StudentList.cpp - contains the main function as well as other methods
//			2.	  LinkedList.h - Contains the LinkedList class
//			3.	  Student.h - Contains the Student structure
//
//****************************************************************************************************

#ifndef NODE_H
#define NODE_H

//****************************************************************************************************

template <typename TYPE>
struct Node
{
	TYPE data;
	Node<TYPE>* next;
	Node();
	Node(TYPE d, Node<TYPE>* n = nullptr);
};

//****************************************************************************************************

template <typename TYPE>
Node<TYPE>::Node()
{
	data = 0;
	next = nullptr;
}

//****************************************************************************************************

template <typename TYPE>
Node<TYPE>::Node(TYPE d, Node<TYPE>* n)
{
	data = d;
	next = n;
}

//****************************************************************************************************

#endif