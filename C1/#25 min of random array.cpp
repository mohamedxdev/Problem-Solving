#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
int randomnumber(int from, int to)
{
	int randnum = rand() % (to - from + 1) + from;
	return randnum;
}
void fillrandomnumberinarray(int arr[100], int &arrlength)
{
	cout << "Please enter number \n";
	cin >> arrlength;
	for (int i = 0; i <= arrlength -1; i++)
	{
		arr[i] = randomnumber(1, 100);
	}
}
void PrintArray(int arr[100], int arrlength)
{
	for (int i = 0; i <= arrlength - 1; i++)
	{
		cout << arr[i] << " ";
	}
}
int minnumberinarray(int arr[100], int arrlength)
{
	int min = 0;
	min = arr[0];
	for (int i = 0; i <= arrlength - 1; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}
	return min;
}
int main()
{
	srand((unsigned)time(NULL));
	int arr[100], arrlength;
	fillrandomnumberinarray(arr, arrlength);
	cout << "\nArray numbers: ";
	PrintArray(arr, arrlength);
	cout << "\nMinimum number in array is: ";
	cout << minnumberinarray(arr, arrlength);
}