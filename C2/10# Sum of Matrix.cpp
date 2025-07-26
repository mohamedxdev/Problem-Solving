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
int SumOfTheMatrix(int Matrix[3][3], short Rows, short Cols)
{
	short sum = 0;
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			sum += Matrix[i][j];
		}
	}
	return sum;
}

int main()
{
	srand((unsigned)time(NULL));
	int Matrix[3][3];
	FillMatrixWithOrderedNumbers(Matrix, 3, 3);
	cout << "\nThe following is a 3x3 ordered matrix:\n";
	PrintMatrix(Matrix, 3, 3);
	cout << "\nSum of Matrix1 is: " << SumOfTheMatrix(Matrix, 3, 3);
	
	
	system("pause>0");
}