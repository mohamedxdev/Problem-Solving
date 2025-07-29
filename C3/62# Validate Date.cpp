#include <iostream>	
#include <string>

using namespace std;

bool IsLeapYear(short Year)
{
	return ((Year % 4) == 0) && (Year % 100 != 0) || (Year % 400 == 0);

}
int NumberOfDaysInMonth(short Month, short Year)
{
	if (Month < 1 || Month >12)
		return 0;

	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : days[Month - 1];
}

struct stDate {

	short Day, Month, Year;
};
short ReadDay()
{
	short Day;
	cout << "\nPlease enter Day? ";
	cin >> Day;

	return Day;
}
short ReadMonth()
{
	short Month;
	cout << "Please enter Month? ";
	cin >> Month;
	
	return Month;
}
short ReadYear()
{
	short Year;
	cout << "Please enter Year? ";
	cin >> Year;

	return Year;
}

bool IsValidDate(stDate Date)
{

	if (Date.Day < 1 || Date.Day >31)
		return false;

	if (Date.Month < 1 || Date.Month >12)
		return false;

	if (Date.Month == 2)
	{
		if (IsLeapYear(Date.Year))
		{
			if (Date.Day > 29)
				return false;
		}
		else
		{
			if (Date.Day > 28)
				return false;
		}
	}
	
	short DaysInMonth = NumberOfDaysInMonth(Date.Month, Date.Year);
	if (Date.Day > DaysInMonth)
		return false;

	return true;
	

}
stDate ReadFullDate()
{
	stDate Date;
	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();

	return Date;
}

int main()
{
	stDate Date = ReadFullDate();

	if (IsValidDate(Date))
		cout << "\nYes Date is a Valide Date";
	else
		cout << "\nNo Date is no a valide Date";

}