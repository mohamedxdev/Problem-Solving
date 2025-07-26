
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
void PrintLetterPattern(int number)
{
	cout << endl;
	for (int i = 65; i <= number + 65 - 1; i++)
	{
		for (int j = 65; j <= i; j++)
		{
			cout << char(i);
		}
		cout << endl;
	}
}
int main()
{
	PrintLetterPattern(Readpositivenunber("Please enter a number"));
}