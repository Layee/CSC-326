#include<iostream>
#include<string>
#include"LinkedStack.h"
#include"LinkedQueue.h"

using namespace std;

// Tests whether a given string is a palindrome .
bool isPalindrome(string str) {

	// Create an empty queue and an empty stack
	LinkedQueue<char>* aQueue = new LinkedQueue<char>();
	LinkedStack<char>* aStack = new LinkedStack<char>();
	// Add each character of the string to both the queue and the stack
	size_t length = str.size();
	for (size_t i = 0; i < length; i++)
	{
		char nextChar = str[i];
		aQueue->enqueue(nextChar);
		aStack->push(nextChar);
	}
	// Compare the queue characters with the stack characters
	bool charactersAreEqual = true;
	while (!aQueue->isEmpty() && charactersAreEqual)
	{
		char queueFront = aQueue->peekFront();
		char stackTop = aStack->peek();
		if (queueFront == stackTop)
		{
			aQueue->dequeue();
			aStack->pop();
		}
		else
			charactersAreEqual = false;
	}
	return charactersAreEqual;
}


int main() {
	string str = "Able was I ere I saw Elba";  //won't recognize as palindrome because of blanks and capitalization
	str = "racecar";
	cout << str << (isPalindrome(str) ? " is a palindrome" : " is not a palindrome") << endl;
}

