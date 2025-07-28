#include <iostream>
#include <string>

using namespace std;

struct stDate {

	short Days, Month, Year;
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

short ReadDay(){

	short Day;
	cout << "Please enter a Day? ";
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


int main()
{
	cout << "\nEnter Date1:\n";
	stDate Date1 = ReadFullDate();

	cout << "\nEnter Date2:\n";
	stDate Date2 = ReadFullDate();


	if (IsDate1AfterDate2(Date1, Date2))
		cout << "\nYes, Date1 is After Date2";
	else
		cout << "\nNo, Date1 is not After Date2";

	


	system("pause>0");
	return 0;
}