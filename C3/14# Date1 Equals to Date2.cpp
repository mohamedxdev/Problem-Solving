#include <iostream>
#include <string>

using namespace std;

struct sDate {
	
	short Year, Month, Days;
};

bool IsDate1EqualsThanDate2(sDate Date1, sDate Date2)
{
	
	return  (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Days == Date2.Days) ? true : false) : false) : false;
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
	
	
	if (IsDate1EqualsThanDate2(Date1, Date2))
		cout << "\nYes, Date1 is Equals to Date2";
	else
		cout << "\nNo, Date1 is not Equals to Date2";


	

	system("pause>0");

	return 0;





}