 #include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
int readpsoitivenumber(string message)
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
	int random = rand() % (to - from + 1) + from;
	return random;
}
void FillArrayWithRandomNumber(int arr[100], int &arrlength)
{
	cout << "Please enter number of elements\n";
	cin >> arrlength;
	for (int i = 0; i <= arrlength - 1; i++)
	{
		arr[i] = randomnumber(1, 100);
	}
}
void CopyArrayInReverseOrder(int arr[100], int arr2[100],int arrlength)
{
	for (int i = 0; i <= arrlength -1; i++)
	{
		arr2[i] = arr[arrlength - 1 - i];
	}

}
void printarray(int arr[100], int arrlength)
{
	for (int i = 0; i <= arrlength -1 ; i++)
		cout << arr[i] << " ";
}
int main() {
	srand((unsigned)time(NULL));
	int arr[100], arr2[100], arrlength;

	FillArrayWithRandomNumber(arr, arrlength);
	CopyArrayInReverseOrder(arr,arr2, arrlength);

	cout << "\nArray 1 elements:\n";
	printarray(arr, arrlength);
	cout << "\nArray 2 elements after copying array 1 in reversed order:\n";
	printarray(arr2, arrlength);

}
