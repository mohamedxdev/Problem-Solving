#include <iostream>	
#include <iomanip>

using namespace std;

void PrintMatrix(int Matrix[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			printf(" %0.2d   ", Matrix[i][j]);
		}
		cout << endl; 
	}

}
bool IsIdentityMatrix(int Matrix[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			if (i == j && Matrix[i][j] != 1)
				return false;

			else if (i != j && Matrix[i][j] != 0)
				return false;

		}
	}
	return true;
}

int main()
{
	srand((unsigned)time(NULL));
	//int Matrix1[3][3] = { 1,0,0,0,1,0,0,0,1 };
	int Matrix1[3][3] = { 1,3,0,0,1,0,0,0,1 };
	
	
	cout << "\n Matrix1:\n";
	PrintMatrix(Matrix1, 3, 3);

	if (IsIdentityMatrix(Matrix1, 3, 3))
		cout << "\nYes it's identity Matrix\n";
	else
		cout << "\nno it's not an identity Matrix\n";

	system("pause>0");


}