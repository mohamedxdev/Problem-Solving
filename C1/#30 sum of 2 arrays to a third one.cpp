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
void fillRandomNumberInArray(int arr1[100], int &arrlength)
{
	
	for (int i = 0; i <= arrlength - 1; i++)
	{
		arr1[i] = randomnumber(1, 100);
	}
}
void printarray(int arr1[100], int arrlength)
{
	for (int i = 0; i <= arrlength - 1; i++)
	{
		cout << arr1[i] << " ";
	}

}
void sumof2arrays(int arr1[100], int arr2[100], int arrsum[100], int arrlength)
{
	for (int i = 0; i <= arrlength - 1; i++)
	{
		arrsum[i] = arr1[i] + arr2[i];
	}
	
}
int main()
{
	srand((unsigned)time(NULL));
	int arr1[100], arr2[100], arrlength, arrsum[100];
	arrlength = readPositiveNumber("PLease enter number of elements: ");

	fillRandomNumberInArray(arr1, arrlength);
	fillRandomNumberInArray(arr2, arrlength);
	sumof2arrays(arr1, arr2, arrsum, arrlength);
	

	cout << "\n Array1 elements: " << endl;
	printarray(arr1, arrlength);
	cout << "\n Array2 elements: " << endl;
	printarray(arr2, arrlength);
	cout << "\n Sum of 2 arrays: " << endl;
	printarray(arrsum, arrlength);
}


