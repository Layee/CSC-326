#include "StackInterface.h"
#include "ArrayStack.h"
#include "LinkedStack.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;


void StackTester(StackInterface<string>* StackPtr)
{
	std::cout << "isEmpty: returns " << StackPtr->isEmpty()
		<< "; should be 1 (true)" << std::endl;
	std::string items[] = { "one", "two", "three", "four", "five", "one" };
	std::cout << "Add 6 items to the Stack: " << std::endl;
	for (int i = 0; i < 6; i++)
	{
		StackPtr->push(items[i]);
	} // end for


	std::cout << "isEmpty: returns " << StackPtr->isEmpty()
		<< "; should be 0 (false)" << std::endl;

	std::cout << "Try to add another entry: add(\"extra\") returns "
		<< StackPtr->push("extra") << std::endl;

	cout << "Contents of stack (backwards):" << endl;
	while (!StackPtr->isEmpty()) {
		string item = StackPtr->peek();
		StackPtr->pop();
		cout << item << endl;
	}


} // end StackTester

void stackTester(StackInterface<int>* StackPtr)
{
	std::cout << "isEmpty: returns " << StackPtr->isEmpty()
		<< "; should be 1 (true)" << std::endl;
	int items[] = { 2, 4, 6, 8, 10, 12 };
	cout << "Add 6 items to the Stack: " << std::endl;
	for (int i = 0; i < 6; i++)
	{
		StackPtr->push(items[i]);
	} // end for


	std::cout << "isEmpty: returns " << StackPtr->isEmpty()
		<< "; should be 0 (false)" << std::endl;

	std::cout << "Try to add another entry: add(2) returns "
		<< StackPtr->push(2) << std::endl;

	while (!StackPtr->isEmpty()) {
		int item = StackPtr->peek();
		StackPtr->pop();
		cout << item << endl;
	}
} // end StackTester


int main()
{
	StackInterface<std::string> *StackPtr = nullptr;
	char userChoice;
	std::cout << "Enter 'A' to test the array-based implementation\n"
		<< " or 'L' to test the link-based implementation: ";
	std::cin >> userChoice;
	if (toupper(userChoice) == 'A')
	{
		StackPtr = new ArrayStack<string>();
		std::cout << "Testing the Array-Based Stack:" << std::endl;
	}
	else
	{
		StackPtr = new LinkedStack<string>();
		std::cout << "Testing the Link-Based Stack:" << std::endl;
	} // end if

	std::cout << "The initial Stack is empty." << std::endl;
	StackTester(StackPtr);
	delete StackPtr;
	StackPtr = nullptr;
	std::cout << "All done!" << std::endl;

	//drsturm
	{
		StackInterface<int> *StackPtr = nullptr;
		char userChoice;
		std::cout << "Enter 'A' to test the array-based implementation\n"
			<< " or 'L' to test the link-based implementation: ";
		std::cin >> userChoice;
		if (toupper(userChoice) == 'A')
		{
			StackPtr = new ArrayStack<int>();
			std::cout << "Testing the Array-Based Stack:" << std::endl;
		}
		else
		{
			StackPtr = new LinkedStack<int>();
			std::cout << "Testing the Link-Based Stack:" << std::endl;
		} // end if

		std::cout << "The initial Stack is empty." << std::endl;
		stackTester(StackPtr);
		delete StackPtr;
		StackPtr = nullptr;
		std::cout << "All done!" << std::endl;
	}

	system("pause");
	return 0;
} // end main