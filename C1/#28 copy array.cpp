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
void copyarray(int arr[100],int arr2[100],int arrlength)
{
	for (int i = 0; i <= arrlength - 1; i++)
	{
		arr2[i] = arr[i];
	}
}

int main()
{
	srand((unsigned)time(NULL));
	int arr[100], arrlength;

	fillrandomnumberinarray(arr, arrlength);
	int arr2[100];
	copyarray(arr, arr2, arrlength);

	cout << "\n Array 1 elements: ";
	PrintArray(arr, arrlength);
	cout << "\n Array 2 elements: ";
	PrintArray(arr2, arrlength);
	
}