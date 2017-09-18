#include <iostream>
using namespace std;

int main() {
	int matrix[4][3] = {
		{-1,7,1},
		{ 3,4,-1 },
		{ 1,3,5 },
		{ 6,-3,1 }

	};

	int  i, j, sum;
	for (i = 0; i < 4; i++) {

		sum = 0;
		for(j =0; j < 3; j++)
		sum += matrix[i][j];
		cout << "sum # " << i + 1 << " = " << sum << endl;
	}


	system("pause");
	return 0;
}