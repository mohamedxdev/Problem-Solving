#include <iostream>
#include <string>

using namespace std;

struct stDate {
	short Day, Month, Year;
};

bool IsLeapYear(short Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}
short NumberOfDaysInMonth(short Month, short Year)
{
	if (Month < 1 || Month >12)
		return 0;

	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : days[Month - 1];


}



stDate DecreaseDateByOneDay(stDate Date)
{
	if (Date.Day ==1)
	{
		if (Date.Month == 1)
		{
			Date.Day = 31;
			Date.Month = 12;
			Date.Year--;
		}
		else {
			Date.Month--;
			Date.Day = NumberOfDaysInMonth(Date.Month,Date.Year);
		}
	}
	else {
		Date.Day--;
	}

	

	return Date;

}

stDate DecreaseDateByXDays(short Days, stDate Date)
{
	for (short i = 1; i <= Days; i++)
	{
		Date = DecreaseDateByOneDay(Date);
	}
	return Date;
}

stDate DecreaseDateByOneWeek(stDate Date)
{
	return Date = DecreaseDateByXDays(7, Date);
}
stDate DecreaseDateByXWeek(short week, stDate Date)
{
	for (short i = 1; i <= week; i++)
	{
		Date = DecreaseDateByOneWeek(Date);
	}
	return Date;
}

stDate DecreaseDateByOneMonth(stDate Date)
{
	if (Date.Month == 1)
	{
		Date.Day = 1;
		Date.Month = 12;
		Date.Year--;
	}
	Date.Month--;



	short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date.Month, Date.Year);

	if (Date.Day > NumberOfDaysInCurrentMonth)
	{
		Date.Day = NumberOfDaysInCurrentMonth;
	}

	return Date;
}
stDate DecreaseDateByXMonth(short Month, stDate Date)
{
	for (short i = 1; i <= Month; i++)
	{
		Date = DecreaseDateByOneMonth(Date);
	}
	return Date;
}

stDate DecreaseDatebyOneYear(stDate Date)
{
	Date.Year--;
	return Date;
}
stDate DecreaseDateByXYear(short Year, stDate Date)
{
	for (short i = 1; i <= Year; i++)
	{
		Date = DecreaseDatebyOneYear(Date);
	}
	return Date;
}
stDate DecreaseDateByXYearFaster(short Year, stDate Date)
{
	Date.Year -= Year;
	return Date;
}

stDate DecreaseDateByOneDecade(stDate Date)
{
	Date.Year -= 10;
	return Date;
}
stDate DecreaseDateByXDecades(short Decade, stDate Date)
{
	for (short i = 1; i <= Decade; i++)
	{
		Date = DecreaseDateByOneDecade(Date);
	}
	return Date;
}
stDate DecreaseDateByXDecadesFaster(short Decade, stDate Date)
{
	Date.Year -= Decade*10;
	return Date;
}

stDate DecreaseDateByOneCentury(stDate Date)
{
	Date.Year -= 100;
	return Date;
}
stDate DecreaseDateByOneMillennium(short Millennuim, stDate Date)
{
	Date.Year -= 1000;
	return Date;
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
	cout << "\nDay After:\n";

	Date = DecreaseDateByOneDay(Date);
	cout << "\n01-Subtracting one day is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = DecreaseDateByXDays(10, Date);
	cout << "\n02-Subtracting 10 days is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = DecreaseDateByOneWeek(Date);
	cout << "\n03-Subtracting 1 week is:  " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = DecreaseDateByXWeek(10, Date);
	cout << "\n04-Subtracting 10 weeks is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = DecreaseDateByOneMonth(Date);
	cout << "\n05-Subtracting 1 Month is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = DecreaseDateByXMonth(5, Date);
	cout << "\n06-Subtracting 5 Months is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = DecreaseDatebyOneYear(Date);
	cout << "\n07-Subtracting 1 Year is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = DecreaseDateByXYear(10, Date);
	cout << "\n08-Subtracting 10 Years is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = DecreaseDateByXYearFaster(10, Date);
	cout << "\n09-Subtracting 10 Years(faster) is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = DecreaseDateByOneDecade(Date);
	cout << "\n10-Subtracting one Decade is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = DecreaseDateByXDecades(10,Date);
	cout << "\n11-Subtracting 10 Decades is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = DecreaseDateByXDecadesFaster(10, Date);
	cout << "\n12-Subtracting 10 Decades(faster) is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = DecreaseDateByOneCentury(Date);
	cout << "\n13-Subtracting One Century is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = DecreaseDateByOneMillennium(10, Date);
	cout << "\n14-Subtracting One Millennuim is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	system("pause>0");

	return 0;
}