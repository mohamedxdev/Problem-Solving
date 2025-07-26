#include <iostream>
#include <string>

using namespace std;



bool IsLeapYear(short Year) {

	return ((Year % 4 == 0) && (Year % 100) != 0) || (Year % 400) == 0;
}

int NumberOfDaysOnMonth(short Year, short Month)
{
	if (Month <= 0 || Month > 12)
		return 0;
	if (Month == 2)
		return (IsLeapYear(Year)) ? 29 : 28;

	short arr31Days[7] = { 1,3,5,7,8,10,12 };

	for (short i = 1; i <= 7; i++)
	{
		if (arr31Days[i - 1] == Month)
			return 31;
	}

	return 30;

	
	
}
int NumberOfHours(short Year, short Month)
{
	return 24 * NumberOfDaysOnMonth(Year, Month);
}
int NumberOfMinutes(short Year, short Month)
{
	return 60 * NumberOfHours(Year, Month);
}
int NumberOfSeconds(short Year, short Month) 
{
	return 60* NumberOfMinutes(Year, Month);
}

short ReadYear() {

	short Year;
	cout << "Pleae enter a year to check? ";
	cin >> Year;

	return Year;
}
short ReadMonth()
{
	short Month;
	cout << "Please enter a month to check? ";
	cin >> Month;

	return Month;
}
int main() {


	short Year = ReadYear();
	short Month = ReadMonth();

	cout << "\nNumber of Days in Month    [" << Month << "] is " << NumberOfDaysOnMonth(Year,Month);
	cout << "\nNumber of Hours in Month   [" << Month << "] is " << NumberOfHours(Year,Month);
	cout << "\nNumber of Minutes in Month [" << Month << "] is " << NumberOfMinutes(Year,Month);
	cout << "\nNumber of Seconds in Month [" << Month << "] is " << NumberOfSeconds(Year,Month);


	system("pause>0");

	return 0;
}