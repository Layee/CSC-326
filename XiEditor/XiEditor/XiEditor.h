#pragma once
#include <string>
#include "commandPlus.h"
using namespace std;
class XiEditor
{
public:
	XiEditor();
	XiEditor(char *);
	void printLines();
	void navigate();
	void  outerBound();
	void deleteChar();
	void deleteCurrentLine();

	//~XiEditor();


private:
	string * _arrayBuffer;
	int _capacity;
	int _numOfElement;
	int _currentLine;
	int _currentPosition;


};


