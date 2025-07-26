#include <iostream>
#include <iomanip>

using namespace std;
int RandomNumber(int From, int To)
{
	int randnum;
	randnum = rand() % (To - From + 1) + From;
	
	return randnum;
}
void FillMatrixWtihRandomNumber(int arr[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			arr[i][j] = RandomNumber(1, 100);
		}
	}
}
void PrintMtrix(int arr[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			cout << setw(3) << arr[i][j] << "     ";
		}
		cout << endl;
	}
}
int ColsSum(int arr[3][3], short Rows, short Cols)
{
	int sum = 0;
	for (int i = 0; i < Rows; i++)
	{
		sum += arr[i][Cols];
	}
	return sum;
}
void SumMatixColsInArry(int arr[3][3], int arrsum[3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		arrsum[i] = ColsSum(arr, Rows, i);
	}
}
void PrintColsSumInArray(int arr[3], short length)
{
	for (int j = 0; j < length; j++)
	{
		cout << "Col " << j + 1 << " Sum = " << arr[j] << endl; 
	}
}
int main()
{
	srand((unsigned)time(NULL));
	int arr[3][3];
	int arrsum[3];

	FillMatrixWtihRandomNumber(arr, 3, 3);

	cout << "The following is 3x3 Random Matrix \n";
	PrintMtrix(arr, 3, 3);

	SumMatixColsInArry(arr, arrsum, 3, 3);
	cout << "The following are the sum of each col in the matrix\n";
	PrintColsSumInArray(arrsum, 3);
	

	

	system("pause>0");

}