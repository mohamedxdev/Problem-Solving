
#include <iostream>
#include <cmath>
#include <string>
using namespace std;
int Readpositivenunber(string message)
{
	int number;
	do {
		cout << message << endl;
		cin >> number;
	} while (number <= 0);
	return number;
}
void PrintInvertedNumberPattern(int number)
{
	cout << endl;
	for (int i = number; i >= 1; i--)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << i;
		}
		cout << endl;
	}
}
int main()
{
	PrintInvertedNumberPattern(Readpositivenunber("Please enter a number"));
}