//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

	   //  Created by Frank M. Carrano and Timothy M. Henry.
	   //  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.
#include "LinkedQueue.h"
#include"QueueInterface.h"
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



	return result;
}  // end dequeue



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




template<class ItemType>
bool LinkedQueue<ItemType>::isEmpty() const
{
	return frontPtr == NULL && backPtr == NULL;
}  // end isEmpty

template<class ItemType>
ItemType LinkedQueue<ItemType>::peekFront() const throw(PrecondViolatedExcept)
{
	// Enforce precondition
	if (isEmpty())
		throw PrecondViolatedExcept("peek