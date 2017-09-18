//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

// Listing 14-3.

/** ADT queue: Link-based implementation.
@file LinkedQueue.h */
#ifndef LINKED_QUEUE_
#define LINKED_QUEUE_
#include "QueueInterface.h"
#include "Node.h"
#include "PrecondViolatedExcept.h"
#include <memory>

template<class ItemType>
class LinkedQueue : public QueueInterface<ItemType>
{
private:
	// The queue is implemented as a chain of linked nodes that has
	// two external pointers, a head pointer for the front of the queue
	// and a tail pointer for the back of the queue.
	std::shared_ptr<Node<ItemType>> frontPtr;
	std::shared_ptr<Node<ItemType>> backPtr;
public:
	LinkedQueue();
	LinkedQueue(const LinkedQueue& aQueue);
	~LinkedQueue();

	bool isEmpty() const;
	bool enqueue(const ItemType& newEntry);
	bool dequeue();

	/** @throw  PrecondViolatedExcept if the queue is empty */
	ItemType peekFront() const throw(PrecondViolatedExcept);
}; // end LinkedQueue
#include "LinkedQueue.cpp"



   //  Created by Frank M. Carrano and Timothy M. Henry.
   //  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

   // Listing 14-4.

   /** ADT queue: Circular array-based implementation.
   @file ArrayQueue.h */

#ifndef ARRAY_QUEUE_
#define ARRAY_QUEUE_
#include "QueueInterface.h"
#include "PrecondViolatedExcept.h"

template<class ItemType>
class ArrayQueue : public QueueInterface<ItemType>
{
private:
	static const int DEFAULT_CAPACITY = 50;
	ItemType items[DEFAULT_CAPACITY]; // Array of queue items
	int      front;                   // Index to front of queue
	int      back;                    // Index to back of queue
	int      count;                   // Number of items currently in the queue

public:
	ArrayQueue();
	// Copy constructor and destructor supplied by compiler
	bool isEmpty() const;
	bool enqueue(const ItemType& newEntry);
	bool dequeue();

	/** @throw  PrecondViolatedExcept if queue is empty. */
	ItemType peekFront() const throw(PrecondViolatedExcept);
}; // end ArrayQueue
#include "ArrayQueue.cpp"
#endif