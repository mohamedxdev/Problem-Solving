#include <iostream>	
#include <string>
#include <vector>

using namespace std;


struct stDate {

	short Day, Month, Year;
};

string ReadStringDate(string message)
{
	string DataString;
	cout << message;
	getline(cin >> ws, DataString);

	return DataString;
}

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


string DateToString(stDate Date)
{
	
	return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
}


int main()
{
	string ReadString = ReadStringDate("Please Enter Date dd/mm/yyyy? ");

	stDate Date = StringToDate(ReadString);

	cout << "\nDay: " << Date.Day;
	cout << "\nMonth: " << Date.Month;
	cout << "\nYear: " << Date.Year;

	cout << "\n\nYou Entered: " << DateToString(Date);
	
	system("pause>0");
	return 0;

}