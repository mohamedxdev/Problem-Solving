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

enDateCompare CompareDates(stDate Date1, stDate Date2)
{
	if (IsDate1BeforeDate2(Date1, Date2))
		return enDateCompare::Before;
	if (IsDate1EqualDate2(Date1, Date2))
		return enDateCompare::Equal;

	return enDateCompare::After;
}

bool IsOverLap(stPeriod Period1, stPeriod Period2)
{
	if (CompareDates(Period2.EndDate, Period1.StartDate) == 
		enDateCompare::Before 
		|| 
		CompareDates(Period2.StartDate, Period1.EndDate) ==
		enDateCompare::After
		)
		return false;
	else
		return true;
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
stPeriod ReadFullPeriod() {

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
	stPeriod Period1 = ReadFullPeriod();
	cout << "\nEnter Period 2:\n";
	stPeriod Period2 = ReadFullPeriod();

	
	if (IsOverLap(Period1, Period2))
		cout << "\nYes, Periods Overlap\n";
	else
		cout << "\nNo, Periods do not Overlap\n";

	
	


	system("pause>0");
	return 0;
}