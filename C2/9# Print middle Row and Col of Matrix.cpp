#include<iostream>
#include<iomanip>

using namespace std;

int RandomNumber(int From, int To)
{
	int randnum = rand() % (To - From + 1) + From;
	return randnum;
}
void FillMatrixWithRandomNumbers(int Matrix[3][3], short Rows, short Cols)
{
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
		cout << endl;
	}
}
void PrintTheMiddleRow(int Matrix[3][3],short Row, short Cols)
{
	short MiddleRow = Row / 2;
	for (int j = 0; j < Cols; j++)
	{
		printf(" %0*d ", 2, Matrix[MiddleRow][j]);
	}
}
void PrintTheMiddleRCol(int Matrix[3][3], short Rows, short Cols )
{
	short MiddleRow = Cols/ 2;

	for (int i = 0; i < Rows; i++)
	{
		printf(" %0*d ", 2, Matrix[i][MiddleRow]);
	}
}

int main()
{
	srand((unsigned)time(NULL));
	int Matrix1[3][3];
	FillMatrixWithRandomNumbers(Matrix1, 3, 3);
	cout << "Matrix 1 : \n";
	PrintMatrix(Matrix1, 3, 3);
	cout << "\nMiddle Row of Matrix1 is:\n ";
	PrintTheMiddleRow(Matrix1, 3,3);
	cout << "\nMiddle Col of Matrix1 is:\n ";
	PrintTheMiddleRCol(Matrix1, 3,3);

	system("pause>0");


}