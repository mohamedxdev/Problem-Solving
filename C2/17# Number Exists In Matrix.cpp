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
bool IsNumberExists(int matrix[3][3], short number, short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (matrix[i][j] == number)
				return true;
		}
	}
	return false;
}
int main()
{
	short number = 0;
	int Matrix[3][3] = { {77,5,12},{22,20,1},{1,0,9} };
	cout << "Matrix1:\n";
	PrintMatrix(Matrix, 3, 3);

	cout << "\nplease enter the number to look for in matrix? ";
	cin >> number;

	if (IsNumberExists(Matrix, number, 3, 3))
		cout << "Yes it's there";
	else
		cout << "No it's not there";

	
	system("pause>0");
}