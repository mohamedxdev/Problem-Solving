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
int main()
{
	//int Matrix[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
	int Matrix[3][3] = { {7,5,3},{1,7,3},{4,7,7} };
	short number;

	cout << "Matrix1:\n";
	PrintMatrix(Matrix, 3, 3);

	cout << "\nEnter the number to count in matrix?: ";
	cin >> number;

	int count = CountNumberInMatrix(Matrix, number, 3, 3);
	printf("Number %d count in matrix is %d", number,count );
	
	system("pause>0");
}