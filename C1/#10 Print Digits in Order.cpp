
#include <iostream>
#include <cmath>
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
int ReverseNumber(int number)
{
	int remainder = 0, number2 = 0;
	while (number > 0)
	{
		remainder = number % 10;
		number = number / 10;
		number2 = number2 * 10 + remainder;
	}
	return number2;
}
void PrintNumber(int number)
{
	cout << endl;
	int remainder = 0;
	while (number > 0)
	{
		remainder = number % 10;
		number = number / 10;
		cout << remainder << endl;
	}
}
int main()
{
	PrintNumber(ReverseNumber(readpositivenumber("Please enter a number!!")));
		return 0;
}
