#include <iostream>
#include <string>
using namespace std;

int main()
{
	char choice;
	bool run = true; //@stefaanv
	while (run)
	{
		// Make your calculation
		cout << "Would you like to perform other calculation?(Y/N)" << endl;
		cin >> choice;
		if (choice == 'N' || choice == 'n') {
			run = false;
		}
	}
	return 0;
}