// Linked List Dequeue 

//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

template<class ItemType>
bool LinkedQueue<ItemType>::dequeue()
{
	bool result = false;
	if (!isEmpty())
	{
		// Queue is not empty; remove front
		auto nodeToDeletePtr = frontPtr;
		if (frontPtr == backPtr)
		{  // Special case: one node in queue
		   // Set frontPtr and backPtr to nullptr
			frontPtr.reset();
			backPtr.reset();
		}
		else
			frontPtr = frontPtr–>getNext();

		// Maintain an accurate reference count for first node
		nodeToDeletePtr –>setNext(nullptr);

		// Removed node will be deallocated when method ends
		result = true;
	}  // end if

	return result;
}  // end dequeue



   //  Created by Frank M. Carrano and Timothy M. Henry.
   //  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

template<class ItemType>
bool LinkedQueue<ItemType>::enqueue(const ItemType& newEntry)
{
	auto newNodePtr = std::make_shared<Node<ItemType>>(newEntry);

	// Insert the new node
	if (isEmpty())
		frontPtr = newNodePtr;        // The queue was empty
	else
		backPtr–>setNext(newNodePtr); // The queue was not empty

	backPtr = newNodePtr;            // New node is at back
	return true;
}  // end enqueue





   

   /** ADT queue: Circular array-based implementation.
   @file ArrayQueue.cpp */

#include "ArrayQueue.h"  // Header file

template<class ItemType>
ArrayQueue<ItemType>::ArrayQueue()
	: front(0), back(DEFAULT_CAPACITY − 1), count(0)
{
}  // end default constructor

template<class ItemType>
bool ArrayQueue<ItemType>::isEmpty() const
{
	return count == 0;
}  // end isEmpty

template<class ItemType>
bool ArrayQueue<ItemType>::enqueue(const ItemType& newEntry)
{
	bool result = false;
	if (count < DEFAULT_CAPACITY)
	{
		// Queue has room for another item
		back = (back + 1) % DEFAULT_CAPACITY;
		items[back] = newEntry;
		count++;
		result = true;
	}  // end if

	return result;
}  // end enqueue

template<class ItemType>
bool ArrayQueue<ItemType>::dequeue()
{
	bool result = false;
	if (!isEmpty())
	{
		front = (front + 1) % DEFAULT_CAPACITY;
		count––;
		result = true;
	}  // end if

	return result;
}  // end dequeue

template<class ItemType>
ItemType ArrayQueue<ItemType>::peekFront() const throw(PrecondViolatedExcept)
{
	// Enforce precondition
	if (isEmpty())
		throw PrecondViolatedExcept("peekFront() called with empty queue");

	// Queue is not empty; return front
	return items[front];
}  // end peekFront
   // End of implementation file.