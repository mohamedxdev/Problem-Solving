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
short TotalDaysFromTheBeginningOfYear(sDate Date)
{
	short TotalDays = 0;

	for (short i = 1; i <= Date.Month - 1; i++)
	{
		TotalDays += NumberOfDaysInMonth(i, Date.Year);
	}
	TotalDays += Date.Days;

	return TotalDays;
}



bool IsLastDayInMonth(sDate Date)
{
	return (Date.Days == NumberOfDaysInMonth(Date.Month, Date.Year));
}
bool IsLastMonthInYear(short Month)
{
	return (Month) == 12;
}
bool IsDate1BeforeDate2(sDate Date1, sDate Date2)
{

	return  (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Days < Date2.Days : false)) : false);

}
sDate IncreaseDateByOneDay(sDate Date)
{
	if (IsLastDayInMonth(Date))
	{
		if (IsLastMonthInYear(Date.Month))
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



void SwapDates(sDate& Date1, sDate& Date2)
{
	sDate TempDate;

	TempDate.Year = Date1.Year;
	TempDate.Month = Date1.Month;
	TempDate.Days = Date1.Days;

	Date1.Year = Date2.Year;
	Date1.Month = Date2.Month;
	Date1.Days = Date2.Days;

	Date2.Year = TempDate.Year;
	Date2.Month = TempDate.Month;
	Date2.Days = TempDate.Days;


}
short GetDifferenceInDays(sDate Date1, sDate Date2, bool IncludeEnday = false)
{
	int Days = 0;
	short SawpFlagValue = 1;

	if (!IsDate1BeforeDate2(Date1, Date2))
	{
		SwapDates(Date1, Date2);
		SawpFlagValue = -1;
	}


	while (IsDate1BeforeDate2(Date1, Date2))
	{
		Days++;
		Date1 = IncreaseDateByOneDay(Date1);
	}

	return IncludeEnday ? ++Days * SawpFlagValue : Days * SawpFlagValue;
}




short ReadYear() {

	short Year;
	cout << "Please enter a year? ";
	cin >> Year;

	return Year;
}
short ReadMonth() {

	short Month;
	cout << "Please enter a Month? ";
	cin >> Month;

	return Month;
}
short ReadDay()
{
	short Day;
	cout << "\n\nPlease enter a Day? ";
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


	sDate Date1 = ReadFullDate();
	sDate Date2 = ReadFullDate();



	cout << "\nDifference is : " << GetDifferenceInDays(Date1, Date2) << " Day(s)";
	cout << "\nDifference (Include End Day) is: " << GetDifferenceInDays(Date1, Date2, true) << " Day(s)";






	system("pause>0");

	return 0;





}