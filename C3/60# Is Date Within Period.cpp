#include <iostream>
#include <string>

using namespace std;

struct stDate {

	short Days, Month, Year;
};
struct stPeriod {
	
	stDate StartDate;
	stDate EndDate;
};
enum enDateCompare {

	Before = -1, Equal = 0, After = 1
};

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
	return  (Date1.Year < Date2.Year) ?
		true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ?
			true : (Date1.Month == Date2.Month ? Date1.Days < Date2.Days : false)) : false);
}
bool IsDate1EqualDate2(stDate Date1, stDate Date2)
{
	return  (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Days == Date2.Days) ?
		true : false) : false) : false;
}
bool IsDate1AfterDate2(stDate Date1, stDate Date2)
{
	return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
}


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
bool IsLastDayInMonth(stDate Date)
{
	return (Date.Days == NumberOfDaysInMonth(Date.Month, Date.Year));
}
bool IsLastMonthInYear(short Month)
{
	return (Month) == 12;
}

stDate IncreaseDateByOneDay(stDate Date)
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

enDateCompare CompareDates(stDate Date1, stDate Date2)
{
	if (IsDate1BeforeDate2(Date1, Date2))
		return enDateCompare::Before;
	if (IsDate1EqualDate2(Date1, Date2))
		return enDateCompare::Equal;

	return enDateCompare::After;
}
bool IsDateWithinPeriod(stDate Date, stPeriod Period)
{
	return !(CompareDates(Date, Period.StartDate) == enDateCompare::Before
		||
		CompareDates(Date, Period.EndDate) == enDateCompare::After);
		
	
}

short ReadDay(){

	short Day;
	cout << "\nPlease enter a Day? ";
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
stPeriod ReadPeriod() {

	stPeriod Period;
	cout << "Enter Start Date:\n";
	Period.StartDate = ReadFullDate();
	cout << "\nEnter End Date:\n";
	Period.EndDate = ReadFullDate();

	return Period;
}


int main()
{
	cout << "\nEnter Period 1:\n";
	stPeriod Period1 = ReadPeriod();
	cout << "\nEnter Date To Check:\n";
	stDate DateTocheck = ReadFullDate();
	
	if (IsDateWithinPeriod(DateTocheck, Period1))
		cout << "\nYes, Date is within period\n";
	else
		cout << "\nNo, Date is NOT within period\n";

	



	system("pause>0");
	return 0;
}