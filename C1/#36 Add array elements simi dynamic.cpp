#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int readnumber()
{
	int number;
	cout << "Please enter a number  ";
	cin >> number;

	return number;
}
void AddArrayElements(int arr[100], int& arrlength, int number)
{
	arrlength++;
	arr[arrlength - 1] = number;
}
void InputUserNumberInArray(int arr[100], int& arrlength)
{
	bool AddMore = true;

	do {

		AddArrayElements(arr, arrlength, readnumber());
		cout << "\n Do you want to add more number [0] No/ [1] yes  ";
		cin >> AddMore;
	} while (AddMore);
}
void printarray(int arr[100], int arrlength)
{
	for (int i = 0; i <= arrlength - 1; i++)
	{
		cout << arr[i] << " ";
	}
}
int main()
{

	int arr[100], arrlength = 0;
	InputUserNumberInArray(arr, arrlength);

	cout << "\nArray length: " << arrlength << endl;
	cout << "Array elements: ";
	printarray(arr, arrlength);
	return 0;
	}
