#include<iostream>
#include<string>
#include"LinkedStack.h"
#include"LinkedQueue.h"

using namespace std;


bool isPalindrome(string str) {

	
	LinkedQueue<char>* aQueue = new LinkedQueue<char>();
	LinkedStack<char>* aStack = new LinkedStack<char>();

	size_t length = str.size();
	for (size_t i = 0; i < length; i++)
	{
		char nextChar = str[i];
		aQueue->enqueue(nextChar);
		aStack->push(nextChar);
	}

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
	string input;
	cout << "Enter a Palindrome" << endl;
	cin >> input;
	if (isPalindrome(input) == 1) {
		cout << "is a palindrome" << endl;
	}
	else {
		cout << "is not a palindrome" << endl;
	}
	
	system("pause");
	return 0;
}

