#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;



#include <iostream>
#include <string>
using namespace std;
int readpositivenumber(string message)
{
	int number;
	do {
		cout << message << endl;
		cin >> number;
	} while (number <= 0);
	return number;
}
void readarray(int arr[100], int& arrlength)
{
	cout << "PLease enter the number of Elements \n";
	cin >> arrlength;

	cout << "Enter array Elements\n";
	for (int i = 0; i < arrlength; i++)
	{
		cout << "Element [" << i + 1 << "]: ";
		cin >> arr[i];
	}
}
void Printarray(int arr[100], int arrlength)
{
	for (int i = 0; i < arrlength; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
int TimesRepeated(int number, int arr[100], int arrlength)
{
	int count = 0;
	for (int i = 0; i <= arrlength - 1; i++)
	{
		if (number == arr[i])
			count++;
	}
	return count;
}
int main()
{
	int arr[100], arrlength, numbertocheck;
	readarray(arr, arrlength);

	numbertocheck = readpositivenumber("Enter the number Your want to check: ");

	cout << "\n original array: ";
	Printarray(arr, arrlength);

	cout << numbertocheck << " is repeated ";
	cout << TimesRepeated(numbertocheck, arr, arrlength) << " Times ";

	return 0;
}