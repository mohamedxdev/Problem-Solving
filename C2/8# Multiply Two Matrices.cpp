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
void MulitpleTwoMatrix(int Matrix1[3][3], int Matrix2[3][3], int MatrixMultiple[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			MatrixMultiple[i][j] = Matrix1[i][j] * Matrix2[i][j];
		}
	}
}

int main()
{
	srand((unsigned)time(NULL));
	int Matrix1[3][3], Matrix2[3][3], MatrixMultiple[3][3];
	FillMatrixWithRandomNumbers(Matrix1, 3, 3);
	FillMatrixWithRandomNumbers(Matrix2, 3, 3);
	cout << "Matrix1:\n";
	PrintMatrix(Matrix1, 3, 3);
	cout << "\nMatrix2:\n";
	PrintMatrix(Matrix2, 3, 3);
	MulitpleTwoMatrix(Matrix1, Matrix2, MatrixMultiple, 3, 3);
	cout << "\nResult:\n";
	PrintMatrix(MatrixMultiple, 3, 3);

	system("pause>0");


}