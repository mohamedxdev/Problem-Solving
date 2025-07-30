#include <iostream>	
#include <string>
#include <vector>

using namespace std;


struct stDate {

	short Day, Month, Year;
};

vector<string> SplitString(string S1, string Delim)
{
	vector<string> Vstring;
	short pos = 0;
	string sword;

	while ((pos = S1.find(Delim)) != std::string::npos)
	{
		sword = S1.substr(0, pos);
		if (sword != "")
		{
			Vstring.push_back(sword);
		}
		S1.erase(0, pos + Delim.length());
	}
	if (S1 != "")
	{
		Vstring.push_back(S1);
	}
	return Vstring;
}
string ReplaceWordInString(string S1, string StringToReplace, string sRepalceTo)
{
	short pos = S1.find(StringToReplace);
	while (pos != std::string::npos)
	{
		S1 = S1.replace(pos, StringToReplace.length(), sRepalceTo);
		pos = S1.find(StringToReplace);
	}
	return S1;
} 
string DateToString(stDate Date)
{
	
	return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
}
stDate StringToDate(string S1, string Seperator = "/")
{
	vector<string> Vstring;
	stDate Date;
	Vstring = SplitString(S1, "/");
	
	Date.Day = stoi(Vstring[0]);
	Date.Month = stoi(Vstring[1]);
	Date.Year = stoi(Vstring[2]);

	return Date;
	
}
string FormatDate(stDate Date, string DateFormat = "dd/mm/yyyy")
{
	string FormattedDateString = "";
	FormattedDateString = ReplaceWordInString(DateFormat, "dd", to_string(Date.Day));
	FormattedDateString = ReplaceWordInString(FormattedDateString, "mm", to_string(Date.Month));
	FormattedDateString = ReplaceWordInString(FormattedDateString, "yyyy", to_string(Date.Year));

	return FormattedDateString;
}
string ReadStringDate(string message)
{
	string DataString;
	cout << message;
	getline(cin >> ws, DataString);

	return DataString;
}

int main()
{
	string DateString = ReadStringDate("Please Enter Date dd/mm/yyyy? ");

	stDate Date = StringToDate(DateString);

	
	cout << "\n" << FormatDate(Date) << "\n";
	cout << "\n" << FormatDate(Date, "yyyy/mm/dd") << "\n";
	cout << "\n" << FormatDate(Date, "mm/dd/yyyy") << "\n";
	cout << "\n" << FormatDate(Date, "mm-dd-yyyy") << "\n";
	cout << "\n" << FormatDate(Date, "Day:dd ,Month:mm, Year:yyyy") << "\n";
	
	
	system("pause>0");
	return 0;

}