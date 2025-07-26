#include <iostream>
#include <string>
using namespace std;
int RandomNumber(int From, int To)
{
	int randnum = rand() % (To - From + 1) + From;
	return randnum;
}
void FillMatrixWithOrderedNumbers(int Matrix[3][3], short Rows, short Cols)
{
	short Counter = 0;
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			
			Matrix[i][j] = RandomNumber(1, 10);
		}
	}
}
void PrintMatrix(int Matrix[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			printf(" %0*d ", 2, Matrix[i][j]);
		}
		cout << "\n";
	}
}
bool AreTypicalMatrices(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (Matrix1[i][j] != Matrix2[i][j])
				return false; 
		}
	}
	return true;
}
int main()
{
	srand((unsigned)time(NULL));

	int Matrix1[3][3], Matrix2[3][3];

	FillMatrixWithOrderedNumbers(Matrix1, 3, 3);
	FillMatrixWithOrderedNumbers(Matrix2, 3, 3);
	cout << "Matrix1:\n";
	PrintMatrix(Matrix1, 3, 3);

	cout << "\nMatrix1:\n";
	PrintMatrix(Matrix2, 3, 3);
	
	if (AreTypicalMatrices(Matrix1, Matrix2, 3, 3))
		cout << "\nYes,They are Typical\n";
	else
		cout << "\nNo,They are not Typical\n";
	
	
	system("pause>0");
}