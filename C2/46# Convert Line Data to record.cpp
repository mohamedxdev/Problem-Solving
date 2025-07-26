#include <iostream>
#include <string>
#include <vector>
using namespace std;


struct sClient {
	
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
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

sClient ConverLineToRecord(string S1, string Seperator = "#//#")
{
	vector<string> Vclient;
	sClient Client;

	Vclient = SplitString(S1, Seperator);
	
	Client.AccountNumber = Vclient[0];
	Client.PinCode = Vclient[1];
	Client.Name = Vclient[2];
	Client.Phone = Vclient[3];
	Client.AccountBalance = stod(Vclient[4]);

	return Client;

}

void PrintRecord(sClient Client)
{
	cout << "The Following is the extracted client record:\n";

	cout << "\nAccount Number    :" << Client.AccountNumber;
	cout << "\nPin Code          :" << Client.PinCode;
	cout << "\nName              :" << Client.Name;
	cout << "\nPhone             :" << Client.Phone;
	cout << "\nAccount Balance   :" << Client.AccountBalance;
}
int main()
{
	
	string S1 = "A150#//#1234#//#mohamed Mazighi#//#07999#//#5270.000";

	sClient Client;
	Client = ConverLineToRecord(S1);

	PrintRecord(Client);

	
	system("pause>0");

}