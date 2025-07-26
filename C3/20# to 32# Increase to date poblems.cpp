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
bool IsLastDayInMonth(stDate Date)
{
	return (Date.Day == NumberOfDaysInMonth(Date.Month, Date.Year));
}
bool IsLastMonthInYear(stDate Date)
{
	return (Date.Month == 12);
}

stDate IncreaseDateByOneDay(stDate Date)
{
	if (IsLastDayInMonth(Date))
	{
		if (IsLastMonthInYear(Date))
		{
			Date.Day = 1;
			Date.Month = 1;
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
stDate IncreaseDateByXDays(short Days, stDate Date)
{
	for (short i = 1; i <= Days; i++)
	{
		Date = IncreaseDateByOneDay(Date);
	}
	return Date;
}

stDate IncreaseDateByOneWeek(stDate Date)
{
	return Date = IncreaseDateByXDays(7, Date);
}
stDate IncreaseDateByXWeek(short week, stDate Date)
{
	for (short i = 1; i <= week; i++)
	{
		Date = IncreaseDateByOneWeek(Date);
	}
	return Date;
}

stDate IncraseDateByOneMonth(stDate Date)
{
	return Date = IncreaseDateByXDays(NumberOfDaysInMonth(Date.Month,Date.Year), Date);
}
stDate IncreaseDateByXMonth(short Month, stDate Date)
{
	for (short i = 1; i <= Month; i++)
	{
		Date = IncraseDateByOneMonth(Date);
	}
	return Date;
}

stDate IncreaseDatebyOneYear(stDate Date)
{
	Date.Year++;
	return Date;
}
stDate IncreaseDateByXYear(short Year, stDate Date)
{
	for (short i = 1; i <= Year; i++)
	{
		Date = IncreaseDatebyOneYear(Date);
	}
	return Date;
}
stDate IncreaseDateByXYearFaster(short Year, stDate Date)
{
	Date.Year += Year;
	return Date;
}

stDate IncreseDateByOneDecade(stDate Date)
{
	Date.Year += 10;
	return Date;
}
stDate IncreaseDateByXDecades(short Decade, stDate Date)
{
	for (short i = 1; i <= Decade; i++)
	{
		Date = IncreseDateByOneDecade(Date);
	}
	return Date;
}
stDate IncreaseDateByXDecadesFaster(short Decade, stDate Date)
{
	Date.Year += Decade*10;
	return Date;
}

stDate IncreaseDateByOneCentury(stDate Date)
{
	Date.Year += 100;
	return Date;
}
stDate IncreaseDateByOneMillennium(short Millennuim, stDate Date)
{
	Date.Year += 1000;
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

	Date = IncreaseDateByOneDay(Date);
	cout << "\n01-Adding one day is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = IncreaseDateByXDays(10, Date);
	cout << "\n02-Adding 10 days is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = IncreaseDateByOneWeek(Date);
	cout << "\n03-Adding 1 week is:  " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = IncreaseDateByXWeek(10, Date);
	cout << "\n04-Adding 10 weeks is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = IncraseDateByOneMonth(Date);
	cout << "\n05-Adding 1 Month is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = IncreaseDateByXMonth(5, Date);
	cout << "\n06-Adding 5 Months is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = IncreaseDatebyOneYear(Date);
	cout << "\n07-Adding 1 Year is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = IncreaseDateByXYear(10, Date);
	cout << "\n08-Adding 10 Years is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = IncreaseDateByXYearFaster(10, Date);
	cout << "\n09-Adding 10 Years(faster) is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = IncreseDateByOneDecade(Date);
	cout << "\n10-Adding one Decade is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = IncreaseDateByXDecades(10,Date);
	cout << "\n11-Adding 10 Decades is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = IncreaseDateByXDecadesFaster(10, Date);
	cout << "\n12-Adding 10 Decades(faster) is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = IncreaseDateByOneCentury(Date);
	cout << "\n13-Adding One Century is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = IncreaseDateByOneMillennium(10, Date);
	cout << "\n14-Adding One Millennuim is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	system("pause>0");

	return 0;
}