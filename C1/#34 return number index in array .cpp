#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int randomnumber(int from, int to)
{
	int random = rand() % (to - from + 1) + from;
	return random;
}
void fillarraywithranndomnumber(int arr[100], int &arrlength)
{
	cout << "Please enter number of elements:\n ";
	cin >> arrlength;
	for (int i = 0; i <= arrlength - 1; i++)
	{
		arr[i] = randomnumber(1, 100);
	}
}
void printarrray(int arr[100], int arrlength)
{
	for (int i = 0; i <= arrlength - 1; i++)
	{
		cout << arr[i] << " ";
	}

}
int readnumber()
{
	int number;
	cout << "Please enter a number you are looking for:\n";
	cin >> number;
	return number;
}
int FindNumberPositionInArray(int number, int arr[100], int arrlength)
{
	for (int i = 0; i <= arrlength - 1; i++)
	{
		if (arr[i] == number)
			return i;
	}
	return -1;
}
int main()
{
	srand((unsigned)time(NULL));
	int arr[100], arrlength;

	fillarraywithranndomnumber(arr, arrlength);

	cout << "\nArray 1 elements:\n";
	printarrray(arr, arrlength);

	int number = readnumber();
	cout << "The number you are looking for is: ";
	cout << number;
	int numberfound = FindNumberPositionInArray(number, arr, arrlength);
	if (numberfound == -1)
	{
		cout << "\nThe number is not found :-(";
	}
	else
	{
		cout << "\nThe number found at position: " << numberfound << endl;
		cout << "The number found it's order: " << numberfound + 1 << endl;
	}



	

}