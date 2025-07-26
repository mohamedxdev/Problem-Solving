#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
int readPositiveNumber(string message)
{
	int number;
	do {
		cout << message << endl;
		cin >> number;
	} while (number <= 0);
	return number;
}
int randomnumber(int from, int to)
{
	int randnum = rand() % (to - from + 1) - from;
	return randnum;
}
void FillArraywithOrdernumbers(int arr1[100], int &arrlength)
{
	for (int i = 0; i <= arrlength - 1; i++)
	{
		arr1[i] = i+1;
		
	}
}
void FillArraywithrandomNumbers(int arr[100], int& arrlength)
{
	for (int i = 0; i <= arrlength - 1; i++)
	{
		arr[i] = randomnumber(1, arrlength);
	}
}
void printArray(int arr1[100], int arrlength)
{
	for (int i = 0; i <= arrlength - 1; i++)
	{
		cout << arr1[i] << " ";
	}
}
int main()
{
	srand((unsigned)time(NULL));
	int arr1[100];
	int arrlength = readPositiveNumber("PLease enter number of elements: ");
	FillArraywithOrdernumbers(arr1, arrlength);
	
	cout << "\n Array elements before shuffle: " << endl;
	printArray(arr1, arrlength);
	FillArraywithrandomNumbers(arr1, arrlength);
	cout << "\n Array elements After shuffle: " << endl;
	printArray(arr1, arrlength);
}
