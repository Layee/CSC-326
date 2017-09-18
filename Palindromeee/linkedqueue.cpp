//LinkedQueue.cpp

#include "LinkedQueue.h"

template<class ItemType>
LinkedQueue<ItemType>::LinkedQueue() : frontPtr(nullptr), backPtr(nullptr)
{
}  // end default constructor

template<class ItemType>
LinkedQueue<ItemType>::LinkedQueue(const LinkedQueue<ItemType>& aQueue)
{
	// Point to nodes in original chain
	Node<ItemType>* origChainPtr = aQueue.frontPtr;

	if (origChainPtr == nullptr)
		frontPtr = nullptr;  // Original queue is empty
	else
	{
		// Copy first node
		frontPtr = new Node<ItemType>();
		topPtr->setItem(origChainPtr->getItem());

		// Point to first node in new chain
		Node<ItemType>* newChainPtr = frontpPtr;

		// Advance original-chain pointer
		origChainPtr = origChainPtr->getNext();

		// Copy remaining nodes
		while (origChainPtr != nullptr)
		{
			// Get next item from original chain
			ItemType nextItem = origChainPtr->getItem();

			// Create a new node containing the next item
			Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);

			// Link new node to end of new chain
			newChainPtr->setNext(newNodePtr);

			// Advance pointer to new last node
			newChainPtr = newChainPtr->getNext();

			// Advance original-chain pointer
			origChainPtr = origChainPtr->getNext();
		}  // end while

		newChainPtr->setNext(nullptr);           // Flag end of chain
	}  // end if
}  // end copy constructor

template<class ItemType>
LinkedQueue<ItemType>::~LinkedQueue()
{
	// Pop until queue is empty
	while (!isEmpty())
		dequeue();
}  // end destructor

template<class ItemType>
bool LinkedQueue<ItemType>::enqueue(const ItemType& newEntry)
{
	//auto newNodePtr = std::make_shared<Node<ItemType>>(newEntry
	Node<ItemType> * newNodePtr = new Node<ItemType> (newEntry);

	// Insert the new node
	if (isEmpty())
		frontPtr = newNodePtr;        // The queue was empty
	else
		backPtr -> setNext(newNodePtr); // The queue was not empty

	backPtr = newNodePtr;            // New node is at back
	return true;
}  // end enqueue

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
			frontPtr = nullptr;
			backPtr = nullptr;
		}
		else
			frontPtr = frontPtr -> getNext();

		// Maintain an accurate reference count for first node
		nodeToDeletePtr -> setNext(nullptr);

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
		throw PrecondViolatedExcept("peekFront() called with empty queue");

	// Queue is not empty; return front
	return frontPtr -> getItem();
}  // end peekFront
   // End of implementation file.