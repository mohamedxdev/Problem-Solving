#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
using namespace std;

const string ClientsFileName = "Me.txt";

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

vector<sClient> LoadClientDataFromFile(string FileName)
{
	vector<sClient> VClient;

	fstream Myfile;
	Myfile.open(FileName, ios::in);
	if (Myfile.is_open())
	{
		string Line;
		sClient Client;

		while (getline(Myfile, Line))
		{
			Client = ConverLineToRecord(Line);
			VClient.push_back(Client);
		}
		Myfile.close();
	}
	return VClient;
}

string ReadClientAcccountNumber()
{
	string AccountNumber;
	cout << "PLease Enter Account Number ";
	getline(cin, AccountNumber);

	return AccountNumber;
}

bool FindClientByAccountNumber(string AccountNumber, sClient& Client)
{
	vector<sClient> VClient = LoadClientDataFromFile(ClientsFileName);
	for (sClient C : VClient)
	{
		if (C.AccountNumber == AccountNumber)
		{
			Client = C;
			return true;
		}
	}
	return false;
}
void PrintClientCard(sClient Client)
{
	cout << "\nThe following are the client details:\n\n";
	cout << "\nAccount Number    :" << Client.AccountNumber;
	cout << "\nPin Code          :" << Client.PinCode;
	cout << "\nName              :" << Client.Name;
	cout << "\nPhone             :" << Client.Phone;
	cout << "\nAccount Balance   :" << Client.AccountBalance;

}

int main()
{
	sClient Client;
	string AccountNumber = ReadClientAcccountNumber();

	if (FindClientByAccountNumber(AccountNumber, Client))
	{
		PrintClientCard(Client);
	}
	else {
		cout << "\nClient with account number (" << AccountNumber << ") Not found!";
	}
	system("pause>0");
}