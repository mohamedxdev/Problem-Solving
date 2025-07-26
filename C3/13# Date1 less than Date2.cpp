#include <iostream>
#include <string>

using namespace std;

struct sDate {
	
	short Year, Month, Days;
};

bool IsDate1LessThanDate2(sDate Date1, sDate Date2)
{
	
	return  (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Days < Date2.Days : false)) : false);
	
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

int main() {


	sDate Date1 = ReadFullDate();
	sDate Date2 = ReadFullDate();
	
	
	if (IsDate1LessThanDate2(Date1, Date2))
		cout << "\nYes, Date1 is Less than Date2";
	else
		cout << "\nNo, Date1 is not Less Than Date2";


	

	system("pause>0");

	return 0;





}