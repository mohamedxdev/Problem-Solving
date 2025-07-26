#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int randomnumber(int from, int to)
{
	int random = rand() % (to - from + 1) + from;
	return random;
}
void FillArrayWithRandomNumber(int arr[100], int &arrlength)
{
	cout << "Please enter number of elements: " << endl;
	cin >> arrlength;
	for (int i = 0; i <= arrlength -1; i++)
	{
		arr[i] = randomnumber(1, 100);
	}
}
void printarray(int arr[100], int arrlength)
{
	for (int i = 0; i <= arrlength -1 ; i++)
	{
		cout << arr[i] << " ";
	}
}
int readnumber()
{
	int number;
	cout << "\n\nPlease enter a number to search for?\n";
	cin >> number;
	return number;
}
int  FindNumberPositioninArray(int number, int arr[100], int arrlength)
{
	int count;
	for (int i = 0; i <= arrlength - 1; i++)
	{
		if (arr[i] == number)
		{
			return i;
		}
	}
	return -1;

}
bool IsNumberInInArray(int number, int arr[100], int arrlength)
{
	return FindNumberPositioninArray(number, arr, arrlength) != -1;
}
int main()
{
	srand((unsigned)time(NULL));
	int arr[100], arrlength;
	FillArrayWithRandomNumber(arr, arrlength);
	cout << "Array 1 elements: " << endl;
	printarray(arr, arrlength);
	int number = readnumber();
	cout << "\nNumber You are looking for is: " << number << endl;
	
	if (!IsNumberInInArray(number,arr,arrlength))
	{
		cout << "The number is not found :-(";
	}
	else {
		cout << "Yes, it's found";
	}
	return 0;

}