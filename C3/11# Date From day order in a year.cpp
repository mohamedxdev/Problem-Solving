#include <iostream>
#include <string>

using namespace std;

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

short TotalDaysFromTheBeginningOfYear(short Days, short Month, short Year)
{
	short TotalDays = 0;

	for (short i = 1; i <= Month - 1; i++)
	{
		TotalDays += NumberOfDaysInMonth(i, Year);
	}
	TotalDays += Days;

	return TotalDays;
}

struct sDate {
	
	short Year, Month, Days;
};

sDate GetDateFromDayOrderInYear(short DaysOrderInyear, short Year)
{
	sDate Date;
	short RemainingDays = DaysOrderInyear;
	short MonthDate = 0;
	Date.Year = Year;
	Date.Month = 1;

	while (true) {

		MonthDate = NumberOfDaysInMonth(Date.Month, Year);

		if (RemainingDays > MonthDate)
		{
			RemainingDays -= MonthDate;
			Date.Month++;
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
int main() {


	short Day = ReadDay();
	short Month = ReadMonth();
	short Year = ReadYear();
	short DaysOrderInYear = TotalDaysFromTheBeginningOfYear(Day, Month, Year);

	cout << "\nNumber of Days From the beginning of year is "
		<< DaysOrderInYear << "\n\n";

	sDate Date;
	Date = GetDateFromDayOrderInYear(DaysOrderInYear,Year);

	cout << "Date for [" << DaysOrderInYear << "] is : " << Date.Days << "/" << Date.Month << "/" << Date.Year;

	system("pause>0");

	return 0;





}