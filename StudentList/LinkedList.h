//****************************************************************************************************
//
//      File:                LinkedList.h
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
//			2.	  Node.h - Contains the Node structure
//			3.	  Student.h - Contains the Student structure
//
//****************************************************************************************************

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <new>
#include <fstream>
#include <iostream>

using namespace std;

#include "Node.h"

//****************************************************************************************************

using namespace std;

//****************************************************************************************************

template <typename TYPE>
class LinkedList
{
private:
	Node<TYPE>* front;
public:
	LinkedList();
	~LinkedList();
	bool insert(const TYPE& dataIn);
	bool remove(TYPE& dataOut);
	bool retrieve(TYPE& data) const;
	bool viewFront(TYPE& dataOut) const;
	bool viewBack(TYPE& dataOut) const;
	bool isEmpty() const;
	bool isFull() const;
	bool clearList();
	bool display() const;
	int getSize() const;
};

//****************************************************************************************************

template <typename TYPE>
LinkedList<TYPE>::LinkedList()
{
	front = nullptr;
}

//****************************************************************************************************

template <typename TYPE>
LinkedList<TYPE>::~LinkedList()
{
	Node<TYPE>* pTemp;

	while (pTemp != nullptr)
	{
		pTemp = front;
		front = pTemp->next;
		delete pTemp;
	}

	front = nullptr;
}

//****************************************************************************************************

template <typename TYPE>
bool LinkedList<TYPE>::insert(const TYPE& dataIn)
{
	bool successful = false;
	Node <TYPE>* pPrev = nullptr;
	Node <TYPE>* pAfter = front;

	while (pAfter != nullptr && pAfter->data < dataIn)
	{
		pPrev = pAfter;
		pAfter = pAfter->next;
	}

	Node<TYPE>* pNew = new(nothrow) Node<TYPE>(dataIn, pAfter);

	if (pNew != nullptr)
	{
		if (pPrev != nullptr)
		{
			pPrev->next = pNew;
		}
		else
		{
			front = pNew;
		}

		pNew->next = pAfter;
		successful = true;
	}

	return successful;
}

//****************************************************************************************************

template <typename TYPE>
bool LinkedList<TYPE>::remove(TYPE& dataOut)
{
	bool successful = false;
	Node<TYPE>* pTemp = front;
	Node<TYPE>* pPrev = nullptr;

	while (pTemp != nullptr && pTemp->data < dataOut)
	{
		pPrev = pTemp;
		pTemp = pTemp->next;
	}

	if (pTemp != nullptr && pTemp->data == dataOut)
	{
		dataOut = pTemp->data;

		if (pPrev != nullptr)
		{
			pPrev->next = pTemp->next;
		}
		else
		{
			front = pTemp->next;
		}

		delete pTemp;
		successful = true;
	}

	return successful;
}

//****************************************************************************************************

template <typename TYPE>
bool LinkedList<TYPE>::retrieve(TYPE& data) const
{
	bool successful = false;
	Node<TYPE>* pTemp = front;

	while (pTemp != nullptr && pTemp->data < data)
	{
		pTemp = pTemp->next;
	}

	if (pTemp != nullptr && pTemp->data == data)
	{
		successful = true;
		data = pTemp->data;
	}

	return successful;
}

//****************************************************************************************************

template <typename TYPE>
bool LinkedList<TYPE>::viewFront(TYPE& dataOut) const
{
	bool successful = false;
	Node<TYPE>* pTemp = front;

	if (pTemp != nullptr) 
	{
		successful = true;
		dataOut = pTemp->data;
	}

	return successful;
}

//****************************************************************************************************

template <typename TYPE>
bool LinkedList<TYPE>::viewBack(TYPE& dataOut) const
{
	bool successful = false;
	Node<TYPE>* pTemp = front;

	while (pTemp != nullptr && pTemp->next != nullptr)
	{
		pTemp = pTemp->next;
	}

	if (pTemp != nullptr)
	{
		dataOut = pTemp->data;
		successful = true;
	}

	return successful;
}

//****************************************************************************************************

template <typename TYPE>
bool LinkedList<TYPE>::isEmpty() const
{
	return (front == nullptr);
}

//****************************************************************************************************

template <typename TYPE>
bool LinkedList<TYPE>::isFull() const
{
	bool full = true;
	Node<TYPE>* pTemp = new (nothrow) Node<TYPE>;

	if (pTemp != nullptr)
	{
		full = false;
		delete pTemp;
	}

	return full;
}

//****************************************************************************************************

template <typename TYPE>
bool LinkedList<TYPE>::clearList()
{
	bool successful = false;
	Node<TYPE>* pTemp;

	while (front != nullptr)
	{
		pTemp = front;
		front = front->next;
		delete pTemp;
	}

	if (front == nullptr)
	{
		successful = true;
	}

	return successful;
}

//****************************************************************************************************

template <typename TYPE>
bool LinkedList<TYPE>::display() const
{
	bool successful = false;
	Node<TYPE>* pTemp = front;

	while (pTemp != nullptr)
	{
		cout << pTemp->data << " ";
		pTemp = pTemp->next;
		successful = true;
	}

	cout << endl;

	return successful;
}

//****************************************************************************************************

template <typename TYPE>
int LinkedList<TYPE>::getSize() const
{
	int size = 0;
	Node<TYPE>* pTemp = front;

	if (pTemp != nullptr)
	{
		while (pTemp != nullptr)
		{
			size++;
			pTemp = pTemp->next;
		}
	}

	return size;
}

//****************************************************************************************************

#endif