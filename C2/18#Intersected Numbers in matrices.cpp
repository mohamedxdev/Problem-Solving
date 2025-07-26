#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
void PrintMatrix(int Matrix[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			cout << setw(3) << Matrix[i][j] << "     ";
		}
		cout << "\n";
	}
}
bool IsNumberExists(int Matrix[3][3], short number, short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (Matrix[i][j] == number)
				return true;
		}
	}
	return false;
}
void PrintIntersectedNumber(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols)
{
	int number;
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			number = Matrix1[i][j];
			if (IsNumberExists(Matrix2, number, Rows, Cols))
				cout << setw(3) << number << "     ";
		}
	}
}

int main()
{
	
	int Matrix1[3][3] = { {77,5,12},{22,20,1},{1,0,9} };
	int Matrix2[3][3] = { {5,80,90},{22,77,1},{10,8,33} };
	cout << "Matrix1:\n";
	PrintMatrix(Matrix1, 3, 3);
	cout << "Matrix2:\n";
	PrintMatrix(Matrix2, 3, 3);
	cout << "\nIntersected Numbers are: \n\n ";
	PrintIntersectedNumber(Matrix1, Matrix2, 3, 3);

	

	

	
	system("pause>0");
}