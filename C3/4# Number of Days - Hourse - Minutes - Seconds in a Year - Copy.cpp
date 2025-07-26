#include <iostream>
#include <string>

using namespace std;



bool IsLeapYear(short Year) {

	return ((Year % 4 == 0) && (Year % 100) != 0) || (Year % 400) == 0;
}

int NumberOfDays(short Year)
{
	
	return (IsLeapYear(Year)) ? 366: 365;
}
int NumberOfHours(short Year)
{
	return 24 * NumberOfDays(Year);
}
int NumberOfMinutes(short Year)
{
	return 60 * NumberOfHours(Year);
}
int NumberOfSeconds(short Year)
{
	return 60* NumberOfMinutes(Year);
}

short ReadYear() {

	short Year;
	cout << "Pleae enter a year to check? ";
	cin >> Year;

	return Year;
}
int main() {


	short Year = ReadYear();

	cout << "\nNumber of Days in Year    [" << Year << "] is " << NumberOfDays(Year);
	cout << "\nNumber of Hours in Year   [" << Year << "] is " << NumberOfHours(Year);
	cout << "\nNumber of Minutes in Year [" << Year << "] is " << NumberOfMinutes(Year);
	cout << "\nNumber of Seconds in Year [" << Year << "] is " << NumberOfSeconds(Year);


	system("pause>0");

	return 0;
}