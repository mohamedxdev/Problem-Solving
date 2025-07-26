#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int randomnumbers(int from, int to)
{
	int random = rand() % (to - from + 1) + from;
	return random;
}
void FillArrayWithRandomNumbers(int arr[100], int &arrlength)
{
	cout << "Please enter number of elements?" << endl;
	cin >> arrlength;
	for (int i = 0; i <= arrlength - 1; i++)
	{
		arr[i] = randomnumbers(-100, 100);
	}
}
void PrintArray(int arr[100], int arrlength)
{
	for (int i = 0; i <= arrlength - 1; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
int PositveNumberCount(int arr[100], int arrlength)
{
	int count = 0;
	for (int i = 0; i <= arrlength - 1; i++)
	{
		if (arr[i] >= 0)
			count++;
	}
	return count;
}

int main()
{
	int arr[100], arrlength;
	srand((unsigned)time(NULL));
	
	FillArrayWithRandomNumbers(arr, arrlength);

	cout << "Array Elements: ";
	PrintArray(arr, arrlength);

	cout << "\nPositive numbers count is: " << PositveNumberCount(arr, arrlength);
	return 0;


}