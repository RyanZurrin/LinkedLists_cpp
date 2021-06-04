/**
 * @class SortedList
 * @details interface for a sorted list ADT
 * @author Ryan Zurrin
 * @date 2/10/2021
 * @LastModified 2/12/2021
 */
 #pragma once

#ifndef SORTED_LIST_H
#define SORTED_LIST_H
#include "Node.h"
#include <iostream>
using namespace std;

class SortedList
{
public:
	SortedList(); //Constructor

	SortedList(int); //overloaded constructor

	~SortedList(); //Destructor

	void makeEmpty(); // empties the list

	bool isFull()const; // checks if list is full

	bool isEmpty()const; // checks if list is empty

	int getLength()const; // returns the length of the list

	bool find(int)const; // searches list for an item

	bool add(int); // adds an element to the list

	bool deleteItem(int); // deletes an item from the list

	void printList()const; //prints the elements in the list

protected:
	Node* head_; //pointer to start of list
	int qty_; // quantity of items in the list
	int max_; // max elements list can be

};

#endif


inline SortedList::SortedList()
{
	head_ = NULL;
	qty_ = 0;
	max_ = INT_MAX;
}

/// <summary>
/// Initializes a new instance of the <see cref="UnsortedList"/> class.
/// </summary>
/// <param name="max_Size">The maximum size.</param>
inline SortedList::SortedList(int max_Size)
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
inline bool SortedList::isFull()const
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
inline bool SortedList::isEmpty() const
{
	return (head_ == NULL);
}

/// <summary>
///  Empties List and all items are unallocated
/// </summary>
inline void SortedList::makeEmpty()
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
/// Gets the length.
/// </summary>
/// <returns>the length of list</returns>
inline int SortedList::getLength()const
{
	return qty_;
}

/// <summary>
/// Finds the specified value.
/// </summary>
/// <param name="item">The value.</param>
/// <returns>true if value is in list: else false</returns>
inline bool SortedList::find(int item) const
{
	for (Node* scan = head_; scan != NULL; scan = scan->next)
	{
		if (scan->val > item)
		{
			return false;
		}
		if (scan->val == item)
		{
			return true;
		}
	}
	return false;
}

/// <summary>
/// Adds the specified value.
/// </summary>
/// <param name="item">The value.</param>
/// <returns>true if item is added to list:
/// else false with error message.</returns>
inline bool SortedList::add(int item)
{
	Node* temp;

	if (qty_ == max_)
	{
		return false;
	}
	if (isEmpty())
	{
		head_ = new Node;
		head_->val = item;
		head_->next = NULL;
		qty_++;
		return true;
	}
	if (head_->val > item)
	{
		temp = new Node;
		temp->val = item;
		temp->next = head_;
		head_ = temp;
		qty_++;
		return true;
	}
	else if (head_->val < item)
	{
		for (Node* scan = head_; scan != NULL; scan = scan->next)
		{
			//if (scan->val == item)
			//{
			//	return false;
		//	}
			if ((scan->next == NULL) || (scan->next->val > item))
			{
				temp = new Node;
				temp->val = item;
				temp->next = scan->next;
				scan->next = temp;
				qty_++;
				return true;
			}
		}
	}
	return false;
}

/// <summary>
/// Deletes the item.
/// </summary>
/// <param name="item">The item.</param>
/// <returns>true if item is deleted: else false with error message</returns>
inline bool SortedList::deleteItem(int item)
{
	Node* temp;

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
	for (Node* scan = head_; scan->next != NULL; scan = scan->next)
	{
		if (scan->val > item)
		{
			return false;
		}
		if (scan->next->val == item)
		{
			// Unlink the node from linked list
			temp = scan->next;
			scan->next = temp->next;
			// Free memory
			delete temp;
			qty_--;
			return true;
		}
	}
	return false;
}

/// <summary>
/// Prints the list.
/// </summary>
inline void SortedList::printList()const
{
	{
		Node* temp;

		cout << "\n\nItems in the Sorted List\n";
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
		cout << "---------------------------------------------\n";
	}
}

/// <summary>
/// Finalizes an instance of the <see cref="UnsortedList"/> class.
/// </summary>
/// Post: List is empty: all items have been unallocated
inline SortedList::~SortedList()
{
	makeEmpty();
}

