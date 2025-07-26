#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int RandomNumber(int From, int To)
{
	int RandNum = rand() % (To - From + 1) + From;
	return RandNum;
}
void FillArrayWithRandomNumber(int arr[100], int& arrlength)
{
	cout << "PLease enter a  number!" << endl;
	cin >> arrlength;
	for (int i = 0; i <= arrlength - 1; i++)
	{
		arr[i] = RandomNumber(1, 100);
	}
}
void AddArrayElements(int number, int arr[100], int& arrlength)
{
	arrlength++;
	arr[arrlength - 1] = number;
}
void CopyOnlyOddNumberInArray(int arr[100],int arr2[100],int arrlength,int &arr2length)
{
	for (int i = 0; i <= arrlength - 1; i++)
	{
		if (arr[i] % 2 != 0)
		{
			AddArrayElements(arr[i], arr2, arr2length);
		}
	}
}
void PrintArray(int arr[100], int arrlength)
{
	for (int i = 0; i <= arrlength - 1; i++)
	{
		cout << arr[i] << " ";
	}
}
int main()
{
	int arr[100], arrlength = 0, arr2length = 0;
	FillArrayWithRandomNumber(arr, arrlength);

	int arr2[100];
	CopyOnlyOddNumberInArray(arr, arr2, arrlength, arr2length);

	cout << "\nArray 1 elements: " << endl;
	PrintArray(arr, arrlength);

	cout << "\nArray 2 after copy " << endl;
	PrintArray(arr2, arrlength);
	
}
