#include <iostream>
#include <string>

using namespace std;

bool IsLeapYear(short Year)
{
	if (Year % 400 == 0) {
		return true;
	}
	else if (Year % 100 == 0) {
		return false;
	}
	else if (Year % 4 == 0) {
		return true;
	}
	else {
		return false;
	}

	
}

	
short ReadYear()
{
	short Number;
	cout << "Enter a year? ";
	cin >> Number;

	return Number;
}
int main() {
	short Year = ReadYear();

	if (IsLeapYear(Year))
	{
		cout << "\nIt's a leap year";
	}
	else {
		cout << "\nIt's not a leap year";
	}
	system("pause>0");

	return 0;
}