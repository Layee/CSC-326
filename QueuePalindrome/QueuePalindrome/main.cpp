#include "LinkedQueue.h"
#include "LinkedStack.h"
#include <iostream>
using namespace std;

bool palindrome(string userStr) {
	LinkedQueue<char> * queue = new LinkedQueue<char>;
	LinkedStack<char> *  Stack = new LinkedStack<char>;

	int lengthSize = userStr.size();

	for (int i = 0; i < lengthSize; i++) {
		queue->enqueue(userStr[i]);
		Stack->push(userStr[i]);
	}

	bool character = true;

	while (queue->isEmpty() && character) {
		char front = queue->peekFront();
		char top = Stack->peek();

		if (front == top) {
			queue->dequeue();
			Stack->pop();
		}
		else character = false;
	}

	return character;
}

int main() {
	string Str = "Able was I ere I saw Elba";
	Str = "racecar";
	cout << Str << (palindrome(Str)) << "is not a palindrome" << endl;
}