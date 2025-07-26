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
bool IsScalarMatrix(int Matrix[3][3], short Rows, short Cols)
{
	short FirstDiagElemement = Matrix[0][0];
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (i == j && Matrix[i][j] != FirstDiagElemement)
				return false;
			else if (i != j && Matrix[i][j] != 0)
				return false;
		}
	}
	return true;

}
int main()
{
	//int Matrix[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
	int Matrix[3][3] = { {7,0,0},{0,7,0},{0,0,7} };
	cout << "Matrix1:\n";
	PrintMatrix(Matrix, 3, 3);
	if (IsScalarMatrix(Matrix, 3, 3))
		cout << "\nyes,it's a scalar Matrix";
	else
		cout << "\nno,it's not a scalar Matrix";

	system("pause>0");
}