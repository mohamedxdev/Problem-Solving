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
	if (Month < 1 || Month >12)
		return 0;

	short Days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : Days[Month - 1];
}

short NumberOfDaysFromTheBeginningOfTheYear(short Days, short Month, short Year)
{
	short TotalDays = 0;

	for (short i = 1; i <= Month - 1; i++)
	{
		TotalDays += NumberOfDaysInMonth(i, Year);
	}
	TotalDays += Days;

	return TotalDays;
}

sDate DateAddDays(short Days, sDate Date) {

	short RemainingDays = Days +
		NumberOfDaysFromTheBeginningOfTheYear(Date.Days, Date.Month, Date.Year);

	short MonthDate = 0;
	Date.Month = 1;
	while (true)
	{
		MonthDate = NumberOfDaysInMonth(Date.Month, Date.Year);

		if (RemainingDays > MonthDate)
		{
			RemainingDays -= MonthDate;
			Date.Month++;

			if (Date.Month > 12)
			{
				Date.Month = 1;
				Date.Year++;
			}
		}
		else {
			Date.Days = RemainingDays;
			break;	
		}
	}
	return Date;
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
short ReadDaysToAdd() {
	
	short days;
	cout << "\nHow many days to add? ";
	cin >> days;
	return days;
}


int main() {


	sDate Date = ReadFullDate();
	short Days = ReadDaysToAdd();

	Date = DateAddDays(Days, Date);


	cout << "Date after adding [" <<  Days  << "] is : " << Date.Days << "/" << Date.Month << "/" << Date.Year;

	system("pause>0");

	return 0;





}