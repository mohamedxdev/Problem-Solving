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
int MaxNumberInMatrix(int Matrix[3][3], short Rows, short Cols)
{
	short Max = 0;
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (Matrix[i][j] > Max)
				Max = Matrix[i][j];
		}
	}
	return Max;
}
int MinNumberInMatrix(int Matrix[3][3], short Rows, short Cols)
{
	short Min = Matrix[0][0];
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (Matrix[i][j] < Min)
				Min = Matrix[i][j];
		}
	}
	return Min;
}

int main()
{
	
	int Matrix1[3][3] = { {77,5,12},{22,20,6},{14,3,9} };
	//int Matrix2[3][3] = { {5,80,90},{22,77,1},{10,8,33} };
	cout << "Matrix1:\n";
	PrintMatrix(Matrix1, 3, 3);
	cout << "\nMinumum number is: " << MinNumberInMatrix(Matrix1, 3, 3) << endl;
	cout << "\nMax number is: " << MaxNumberInMatrix(Matrix1, 3, 3) << endl; 
	
	system("pause>0");
}