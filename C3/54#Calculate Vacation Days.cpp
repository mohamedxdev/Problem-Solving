#include <iostream>
#include <string>

using namespace std;

struct stDate {

	short Days, Month, Year;
};

bool IsLeapYear(short Year)
{
	return ((Year % 4) == 0) && (Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInMonth(short Month, short Year)
{
	if (Month < 1 || Month>12)
		return 0;
	
	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : days[Month - 1];
}

short DayOfWeekOrder(stDate Date)
{
	short a, y, m;
	a = (14 - Date.Month) / 12;
	y = Date.Year - a;
	m = Date.Month + (12 * a) - 2;

	return (Date.Days + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m)) / 12) % 7;
}

string DayShortName(stDate Date)
{

	string arrDayname[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };

	return arrDayname[DayOfWeekOrder(Date)];
}

bool IsLastDayInMonth(stDate Date) {

	return (Date.Days == NumberOfDaysInMonth(Date.Month, Date.Year));
}
bool IsLastDayInYear(short Month)
{

	return (Month == 12);
}
bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
	return  (Date1.Year < Date2.Year) ?
		true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ?
			true : (Date1.Month == Date2.Month ? Date1.Days < Date2.Days : false)) : false);
}
bool IsWeekend(stDate Date)
{
	return (DayOfWeekOrder(Date) == 5 || DayOfWeekOrder(Date) == 6);
}
bool IsBusinessDay(stDate Date)
{
	return !IsWeekend(Date);
}
stDate IncreaseDateByOneDay(stDate Date)
{
	if (IsLastDayInMonth(Date))
	{
		if (IsLastDayInYear(Date.Month))
		{
			Date.Days = 1;
			Date.Month = 1;
			Date.Year++;
		}
		else {
			Date.Days = 1;
			Date.Month++;
		}

	}
	else {
		Date.Days++;
	}
	return Date;
}

short CalculateVacationDays(stDate DateFrom, stDate DateTo)
{
	int Days = 0;
	while (IsDate1BeforeDate2(DateFrom, DateTo))
	{
		if (IsBusinessDay(DateFrom))
			Days++;

		DateFrom = IncreaseDateByOneDay(DateFrom);

	}
	return Days;
}



short ReadDay(){

	short Day;
	cout << "Please enter a Day? ";
	cin >> Day;
	return Day;

}
short ReadMonth() {

	short Month;
	cout << "PLease enter a Month? ";
	cin >> Month;
	return Month;
}
short ReadYear() {

	short Year;
	cout << "Please enter a Year? ";
	cin >> Year;
	return Year;

}
stDate ReadFullDate()
{
	stDate Date;
	Date.Days = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();

	return Date;
}

int main()
{
	cout << "\nVacation Starts:\n";
	stDate DateFrom = ReadFullDate();
	cout << "\nVacation Ends:\n";
	stDate DateTo = ReadFullDate();

	cout << "\nVacation From: " << DayShortName(DateFrom) << ","
		 << DateFrom.Days << "/" << DateFrom.Month << "/" << DateFrom.Year;
	cout << "\nVacation To: " << DayShortName(DateTo) << ","
		<< DateTo.Days << "/" << DateTo.Month << "/" << DateTo.Year;

	cout << "\n\n\nActual Vacation Days is: " << CalculateVacationDays(DateFrom, DateTo);


	system("pause>0");
	return 0;
}
