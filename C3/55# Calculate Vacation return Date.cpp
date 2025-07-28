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

short DayOfWeekOrder(short Year,short Month,short Days)
{
	short a, y, m;
	a = (14 - Month) / 12;
	y = Year - a;
	m = Month + (12 * a) - 2;

	return (Days + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m)) / 12) % 7;
}
short DayOfWeekOrder(stDate Date)
{
	return DayOfWeekOrder(Date.Year, Date.Month, Date.Days);
}

string DayShortName(short DayOfWeekOrder)
{

	string arrDayname[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };

	return arrDayname[DayOfWeekOrder];
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

stDate CalculateVacationReturnDate(stDate DateFrom, short VacationDays)
{
	short WeekEndCounter = 0;

	while (IsWeekend(DateFrom))
	{
		DateFrom = IncreaseDateByOneDay(DateFrom);
	}

	for (short i = 1; i <= VacationDays + WeekEndCounter; i++)
	{
		if (IsWeekend(DateFrom))
			WeekEndCounter++;

		DateFrom = IncreaseDateByOneDay(DateFrom);
	}
	while (IsWeekend(DateFrom))
	{
		DateFrom = IncreaseDateByOneDay(DateFrom);
	}

	return DateFrom;

	
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

short ReadVacationDays()
{
	short Days;
	cout << "\nPlease enter vacation days? ";
	cin >> Days;
	return Days;
}
int main()
{
	cout << "\nVacation Starts:\n";
	stDate DateFrom = ReadFullDate();
	short VacationDays = ReadVacationDays();

	stDate ReturnDate = CalculateVacationReturnDate(DateFrom, VacationDays);
	
	cout << "\n\nReturn Date: " << DayShortName(DayOfWeekOrder(ReturnDate)) << " , "
		<< ReturnDate.Days << "/" << ReturnDate.Month << "/" << ReturnDate.Year << endl;
	

	


	system("pause>0");
	return 0;
}