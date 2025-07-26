#include <iostream>
#include <string>

using namespace std;

struct sDate {
	
	short Year, Month, Days;
};

bool IsLeapYear(short Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInMonth(short Month, short Year)
{
	if (Month < 1 || Month> 12)
		return 0;
	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : days[Month - 1];
}

bool IsLastDayInMonth(sDate Date)
{
	return (Date.Days == NumberOfDaysInMonth(Date.Month, Date.Year));
}
bool IsLastMontInYear(short Month)
{
	return (Month == 12);
}

short ReadYear() {

	short Year;
	cout << "\nPlease enter a year? ";
	cin >> Year;

	return Year;
}
short ReadMonth() {

	short Month;
	cout << "\nPlease enter a Month? ";
	cin >> Month;

	return Month;
}
short ReadDay()
{
	short Day;
	cout << "\nPlease enter a Day? ";
	cin >> Day;

	return Day;
}
sDate ReadFullDate() {

	sDate Date;
	Date.Days = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();

	return Date;
}

int main() {


	sDate Date = ReadFullDate();
	
	
	
	if (IsLastDayInMonth(Date))
		cout << "\nYes, Day is last Day  in Month";
	else
		cout << "\nNo, Day is not last Day in Month";


	if (IsLastMontInYear(Date.Month))
		cout << "\nYes, Month is last Month  in Year";
	else
		cout << "\nNo, Month is not last Month in Year";


	

	system("pause>0");

	return 0;





}