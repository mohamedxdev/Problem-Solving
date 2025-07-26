#include <iostream>
#include <string>

using namespace std;


bool IsLeapYear(short Year) {

	return(Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInMonth(short Month, short Year)
{
	if (Month < 1 || Month>12)
		return 0;

	short  NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	return(Month == 2) ? (IsLeapYear ? 29 : 28) : NumberOfDays[Month - 1];
}


short ReadYear() {
	short Year;
	cout << "\nPlease enter a year to check ";
	cin >> Year;

	return Year;
}
short ReadMonth()
{
	short Month;
	cout << "\nPlease enter a month to check? ";
	cin >> Month;

	return Month;
}
int main()
{
	short Year = ReadYear();
	short Month = ReadMonth();

	cout << "\nNumber Of Days in Month [" << Year << "] is " << NumberOfDaysInMonth(Month,Year);
	


	system("pause>0");

	return 0;
}