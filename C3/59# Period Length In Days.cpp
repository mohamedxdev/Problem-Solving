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

short GetDifferenceInDays(stDate Date1, stDate Date2, bool IncludeEnday = false)
{
	int Days = 0;

	while (IsDate1BeforeDate2(Date1, Date2))
	{
		Days++;
		Date1 = IncreaseDateByOneDay(Date1);
		
	}
	return IncludeEnday ? ++Days : Days;
}

short PeriodLengthInDays(stPeriod Period1, bool IncludeEnday = false)
{
	return GetDifferenceInDays(Period1.StartDate, Period1.EndDate, IncludeEnday);
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
	
	cout << "\nPeriod Length is: " << PeriodLengthInDays(Period1);
	cout << "\nPeriod Length (Including End Date is: " << PeriodLengthInDays(Period1, true);
	



	system("pause>0");
	return 0;
}