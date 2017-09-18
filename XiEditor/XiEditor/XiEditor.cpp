#include "XiEditor.h"
#include <iostream>
#include <cctype>
#include<conio.h>
#include<string>
using namespace std;
#include <fstream>


XiEditor::XiEditor() {
	// dynamic  allocate memory
	_arrayBuffer = new string[_numOfElement]; 
	_numOfElement = 0;
	
}

XiEditor::XiEditor(char * fileName)
{
	// open the file
	ifstream userFile;
	userFile.open(fileName);

	_currentLine = 0;
	_numOfElement = 0;
	string skipLine;

	// check if the file exit
	if (!userFile.is_open()) {
		cout << "This file does exist " << endl;

	// close file when the file cannot be located
		exit(EXIT_SUCCESS); 
	}

	// read the file till the end of the file
	while(!userFile.eof()) {
		getline(userFile, skipLine);
		_numOfElement++;
	}
	
	userFile.close();
	userFile.open(fileName);

	// dynamic  allocate memory
	_arrayBuffer = new string[_numOfElement]; 

	

	
	
	for (int i = 0; !userFile.eof(); i++)
		//reading the file
	{
		getline(userFile, _arrayBuffer[i]);
	}
	
	// close the file after reading it
	userFile.close(); 
}




void XiEditor::printLines() {
	//Print the number of lines within the file

	for (int j = 0; j < _numOfElement; j++) {
		if (j == _currentLine) {
			cout << "*";
			cout << _arrayBuffer[j] << endl;
			cout << " ";
			for (int i = 0; i < _currentPosition; i++) {
				cout << " ";
			}
			cout << "^" << endl;

		}
		else {
			cout << " ";
			cout << _arrayBuffer[j] << endl;
		}	
	}
}



void XiEditor::navigate() {

	char command;

	// get the user input from the keyboard using the _getch() function
	command = _getch();

	switch (command)

	{
		/* 
		   J = move down
		   K = move up
		   L = move right
		   H = move left
		   X = delete
		   dd = delete current line
		   U = undo 
		*/
	case 'j':
	case 'J':
		_currentLine += 1;
		break;


	case 'K':
	case 'k':
		_currentLine -= 1;
		break;

	case 'l':
	case 'L':
		_currentPosition += 1;
		break;

	case 'h':
	case 'H':
		_currentPosition -= 1;
		break;

    case 'x':
	case 'X':
		system("cls");
		deleteChar();
		break;

	case 'd':
	case'D':
		deleteCurrentLine();
		break;

	case 'u':
	case 'U':
		break;
	}
	outerBound();
}


void XiEditor::outerBound() {
	// outer  bound reset current = 0;
	if (_currentLine < 0) { 
		_currentLine = 0;
	}
	
	else if (_currentLine > _numOfElement - 1) {
		_currentLine = _numOfElement - 1;
	}

	else if (_currentPosition < 0 ) {
		  
		_currentPosition = 0;

	}

	else if (_currentPosition >= _arrayBuffer[_currentLine].length()) { // get the end of the string
		 // reset the buffer back to the end of the string
		_currentPosition = _arrayBuffer[_currentLine].length() - 1;

	}


	
}


void XiEditor::deleteChar() {
	_arrayBuffer[_currentLine].erase(_currentPosition,1);

}

void XiEditor::deleteCurrentLine() {
	char secondInput = _getch();
	if (secondInput == 'd' || secondInput == 'D') {
		_arrayBuffer[_currentLine].erase( 0);
		for (int i = _currentLine; i < _numOfElement; i++)
			_arrayBuffer[i] = _arrayBuffer[i + 1];
	
	}
	 
	
}


