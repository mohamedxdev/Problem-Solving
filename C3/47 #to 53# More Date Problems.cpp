#include <iostream>
#include <string>

using namespace std;

struct stDate {
	short Day, Month, Year;
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
bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{ 
	return  (Date1.Year < Date2.Year) ?
		true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ?
		true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false); 
}
bool IsLastDayInMonth(stDate Date)
{
	return (Date.Day == NumberOfDaysInMonth(Date.Month, Date.Year));
}
bool IsLastMonthInYear(short Month)
{
	return (Month == 12); 
}
stDate IncreaseDateByOneDay(stDate Date) 
{ 
	if (IsLastDayInMonth(Date)) 
	{ 
		if (IsLastMonthInYear(Date.Month))
		{
			Date.Month = 1;
			Date.Day = 1;
			Date.Year++;
		} 
		else { 
			Date.Day = 1;
			Date.Month++;
		} 
	} 
	else {
		Date.Day++;
	} 
	return Date;
}
int GetDifferenceInDays(stDate Date1, stDate Date2, bool IncludeEndDay = false)
{ 
	int Days = 0;
	while (IsDate1BeforeDate2(Date1, Date2))
	{
		Days++;
		Date1 = IncreaseDateByOneDay(Date1);
	} 
	return IncludeEndDay ? ++Days : Days;
}

short DayOfWeekOrder(stDate Date)
{
	short a, y, m;
	a = (14 - Date.Month) / 12;
	y = Date.Year - a;
	m = Date.Month + (12 * a) - 2;

	return (Date.Day+ y + (y / 4) - (y / 100) + (y / 400) + ((31 * m)) / 12) % 7;
}
string DayShortName(stDate Date)
{

	string arrDayname[] = {"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};

	return arrDayname[DayOfWeekOrder(Date)];
}



bool IsEndOfWeek(stDate Date)
{
	return DayOfWeekOrder(Date) == 6;


}
bool IsWeekend(stDate Date)
{
	return (DayOfWeekOrder(Date) == 5 || DayOfWeekOrder(Date) == 6);
}
bool IsBusinessDay(stDate Date)
{
	return !IsWeekend(Date);
}



short DaysUntilTheEndOfWeek(stDate Date)
{
	return 6 - DayOfWeekOrder(Date);
}
short DaysUntilTheEndOfMonth(stDate Date)
{
	stDate EndOfMontDate;

	EndOfMontDate.Day = NumberOfDaysInMonth(Date.Month, Date.Year);
	EndOfMontDate.Month = Date.Month;
	EndOfMontDate.Year = Date.Year;

	return GetDifferenceInDays(Date, EndOfMontDate, true);
}
short DaysUntilTheEndOfYear(stDate Date)
{
	stDate EndOfYearDate;
	EndOfYearDate.Day = 31;
	EndOfYearDate.Month = 12;
	EndOfYearDate.Year = Date.Year;
	
	return GetDifferenceInDays(Date, EndOfYearDate, true);

}
short ReadDay()
{
	short Day;
	cout << "Please enter a Day? ";
	cin >> Day;
	return Day;
}
short ReadMonth()
{
	short Month;
	cout << "Please enter a Month? ";
	cin >> Month;
	return Month;
}
short ReadYear()
{
	short Year;
	cout << "Please ente a Year? ";
	cin >> Year;
	return Year;
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

	cout << "\nToday  is " << DayShortName(Date) << ", "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year;

	cout << "\n\nIs it End of week?";
	cout << "\n" << (IsEndOfWeek(Date) ? "Yes, it's the end of the week." : "No, it's not the end of the week.");

	cout << "\n\nIs it week end?";
	cout << "\n" << (IsWeekend(Date) ? "Yes it's a week end." : "No, it's not a week end.");

	cout << "\n\nIs it Business Day?";
	cout << "\n" << (IsBusinessDay(Date) ? "Yes it's a Business Day." : "No, it's not a Business Day");

	cout << "\n\nDays Until end of week: " << DaysUntilTheEndOfWeek(Date) << " Day(s)";
	cout << "\nDays Until end of Month: " << DaysUntilTheEndOfMonth(Date) << " Day(s)";
	cout << "\nDays Until end of Year: " << DaysUntilTheEndOfYear(Date) << " Day(s)";

	system("pause>0");
	return 0;
}