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
short CountNumberInMatrix(int Matrix[3][3], short number, short Rows, short Cols)
{
	short counter = 0;
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (Matrix[i][j] == number)
				counter++;
		}
	}
	return counter;
}
bool IsSparceMatrix(int Matrix[3][3], short Rows, short Cols)
{
	short MatrixSize = Rows * Cols;
	return(CountNumberInMatrix(Matrix, 0, 3, 3) >= (MatrixSize / 2));	
}
int main()
{
	//int Matrix[3][3] = { {1,0,3},{4,5,0},{7,8,9} };
	int Matrix[3][3] = { {0,0,12},{0,0,1},{0,0,9} };
	cout << "Matrix1:\n";
	PrintMatrix(Matrix, 3, 3);

	if (IsSparceMatrix(Matrix,3,3))
		cout << "yes: it's Sparce";
	else
		cout << "No: it's not Sparce";
	system("pause>0");
}