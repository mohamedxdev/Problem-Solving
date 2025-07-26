
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
bool IsPalindromeMatrix(int Matrix[3][3], short Rows,short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols/2; j++)
		{
			if (Matrix[i][j] != Matrix[i][Cols - j - 1])
				return false;
		}
	}
	return true;
}


int main()
{
	
	int Matrix1[3][3] = { {1,2,1},{5,5,5},{7,3,7} };
	//int Matrix2[3][3] = { {5,80,90},{22,77,1},{10,8,33} };
	cout << "Matrix1:\n";
	PrintMatrix(Matrix1, 3, 3);
	
	if (IsPalindromeMatrix(Matrix1, 3, 3))
		cout << "\nYes Matrix is Palindrome" << endl;
	else
		cout << "\nNo Matrix is not Palindrome" << endl; 

	system("pause>0");
}