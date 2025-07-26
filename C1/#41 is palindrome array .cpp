#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void FillArray(int arr[100], int& length)
{
	length = 6;
	arr[0] = 10;
	arr[1] = 20;
	arr[2] = 30;
	arr[3] = 30;
	arr[4] = 20;
	arr[5] = 10;
}
void PrintArray(int arr[100], int length)
{
	for (int i = 0; i <= length - 1; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";

}
bool IsPalindromArray(int arr[100], int length)
{
	for (int i = 0; i <= length - 1; i++)
	{
		if (arr[i] != arr[length - i - 1])
			return false;
	}
	return true;
}
int main()
{
	int arr[100], length = 0;
	FillArray(arr, length);
	cout << "Array Elements:" << endl;
	PrintArray(arr, length);

	if (IsPalindromArray(arr, length))
		cout << "\nYes it's Palindrome Array";
	else
		cout << "No it's not Palindrome Array";
}