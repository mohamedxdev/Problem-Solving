#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
int randomNumber(int from, int to)
{
	int randnum = rand() % (to - from + 1) + from;
	return randnum;
}
void FillArraywithrandomNumber(int arr[100],int &arrlength)
{
	cout << "Please enter number \n";
	cin >> arrlength;
	for (int i = 0; i <= arrlength - 1; i++)
	{
		arr[i] = randomNumber(1, 100);
	}
}
int  maxnumberinarray(int arr[100], int& arrlength)
{
	int max = 0;
	for (int i = 0; i <= arrlength - 1; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];

		}
	}
	return max;
}
void PrintArray(int arr[100], int arrlength)
{
	for (int i = 0; i <= arrlength -1; i++)
	{
		cout << arr[i] << " ";
	}
}
int main()
{
	srand((unsigned)time(NULL));
	int arr[100], arrlength;
	FillArraywithrandomNumber(arr, arrlength);

	cout << "\n Array numbers: ";
	PrintArray(arr, arrlength);
	cout << "\n max number i: ";
	cout << maxnumberinarray(arr, arrlength);
	return 0;
}