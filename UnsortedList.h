/**
 * @class UnsortedList
 * @details interface for a unsorted list ADT
 * @author Ryan Zurrin
 * @date 1/30/2021
 * @LastModified 2/12/2021
 */
 #pragma once
#ifndef UNSORTED_LIST_H
#define UNSORTED_LIST_H

#include "Node.h"
#include <iostream>
using namespace std;

class UnsortedList
{
public:
	UnsortedList(); //Constructor

	UnsortedList(int); //overloaded constructor

	~UnsortedList(); //Destructor

	void makeEmpty(); // empties the list

	bool isFull()const; // checks if list is full

	bool isEmpty()const; // checks if list is empty

	int getLength()const; // returns the length of the list

	bool find(int)const; // searches list for an item

	bool add(int); // adds an element to the list

	bool deleteItem(int); // deletes an item from the list

	void printList()const; //prints the elements on the list


protected:
	Node* head_; //pointer to start of list
	int qty_; // quantity of items in the list
	int max_; // max elements list can be

};// end of class
#endif


/// <summary>
/// Initializes a new instance of the <see cref="UnsortedList"/> class.
/// </summary>
inline UnsortedList::UnsortedList()
{
	head_ = NULL;
	qty_ = 0;
	max_ = INT_MAX;
}

/// <summary>
/// Initializes a new instance of the <see cref="UnsortedList"/> class.
/// </summary>
/// <param name="max_Size">The maximum size.</param>
inline UnsortedList::UnsortedList(int max_Size)
{
	head_ = NULL;
	qty_ = 0;
	max_ = max_Size;
}

/// <summary>
/// Determines whether this instance is full.
/// </summary>
/// <returns>
///   <c>true</c> if this instance is full; otherwise, <c>false</c>.
/// </returns>
inline bool UnsortedList::isFull()const
{
	if (qty_ == max_)
	{
		return true;
	}
	return false;
}

/// <summary>
/// Determines whether this instance is empty.
/// </summary>
/// <returns>
///   <c>true</c> if this instance is empty; otherwise, <c>false</c>.
/// </returns>
inline bool UnsortedList::isEmpty() const
{
	return (head_ == NULL);
}


/// <summary>
/// Gets the length.
/// </summary>
/// <returns>the length of list</returns>
inline int UnsortedList::getLength()const
{
	return qty_;
}

/// <summary>
/// Finds the specified value.
/// </summary>
/// <param name="item">The value.</param>
/// <returns>true if value is in list: else false</returns>
inline bool UnsortedList::find(int item) const
{
	for (Node* scanner = head_; scanner!= NULL; scanner = scanner->next)
		if (scanner->val == item)
		{
			return true;
		}
	return false;
}

/// <summary>
///  Empties List and all items are unallocated
/// </summary>
inline void UnsortedList::makeEmpty()
{
	Node* tempPtr;
	while (head_ != NULL) {
		tempPtr = head_;
		head_ = head_->next;
		delete tempPtr;
	}
	qty_ = 0;
}

/// <summary>
/// Adds the specified value.
/// </summary>
/// <param name="val">The value.</param>
/// <returns>true if item is added to list:
/// else false with error message.</returns>
inline bool UnsortedList::add(int val)
{
	Node* temp, *newNode;
	if (qty_ == max_)
	{
		return false;
	}
	newNode = new Node();
	if (newNode == NULL)
		return false;
	newNode->val = val;
	newNode->next = NULL;

	if (isEmpty())
	{
		head_ = newNode;
		qty_++;
		return true;
	}
	//else
	//{
		temp = head_;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newNode;
		qty_++;
		return true;
	//}
}

/// <summary>
/// Deletes the item.
/// </summary>
/// <param name="item">The item.</param>
/// <returns>true if item is deleted: else false with error message</returns>
inline bool UnsortedList::deleteItem(int item)
{
	bool finished = false;
	do{
		if(!find(item)){
			finished = true;
		}
		Node* temp, * curr;
		temp = head_;
		curr = head_;
		if (isEmpty()) {
			return false;
		}
		if (head_->val == item)
		{
			temp = head_;
			head_ = head_->next;
			delete temp;
			qty_--;
			return true;
		}

		while ((temp != NULL) && (temp->val != item))
		{
			curr = temp;
			temp = temp->next;
		}
		if (temp == NULL) {

			return false;  // Not found so return false
		}
		// Unlink the node from linked list
		curr->next = temp->next;
		// Free memory
		delete temp;
		qty_--;
	}while(!finished);
	return true;
}

/// <summary>
/// Prints the list.
/// </summary>
inline void UnsortedList::printList()const
{
	{
		Node* temp;

		cout << "\n\nItems in the Unsorted List\n";
		cout << "----------------------------------------------\n";
		cout << "Pos#\t\t\tData\n";
		cout << "----------------------------------------------\n";
		if (head_ == NULL)     // Report no items in the list
		{
			cout << " List is currently empty.\n";
		}
		else
		{
			temp = head_;
			int place = 1;
			while (temp != NULL)
			{
				cout << place << "\t\t\t" << temp->val << "\n";
				temp = temp->next;
				place++;
			}
		}
		cout << "----------------------------------------------\n";
	}
}

/// <summary>
/// Finalizes an instance of the <see cref="UnsortedList"/> class.
/// </summary>
/// Post: List is empty: all items have been unallocated
inline UnsortedList::~UnsortedList()
{
	makeEmpty();
}

