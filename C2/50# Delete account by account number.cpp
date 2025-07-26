#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>f

using namespace std;

const string ClientsFileName = "Me.txt";

struct sClient {

	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
	bool MarkeForDelete = false;
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

sClient ConverLineToRecord(string Line, string Seperator = "#//#")
{
	vector<string> Vclient;
	sClient Client;

	Vclient = SplitString(Line, Seperator);

	Client.AccountNumber = Vclient[0];
	Client.PinCode = Vclient[1];
	Client.Name = Vclient[2];
	Client.Phone = Vclient[3];
	Client.AccountBalance = stod(Vclient[4]);

	return Client;

}

string ConvertRecordToLine(sClient Client, string Seprator = "#//#")
{
	string StClientRecord = "";

	StClientRecord += Client.AccountNumber + Seprator;
	StClientRecord += Client.PinCode + Seprator;
	StClientRecord += Client.Name + Seprator;
	StClientRecord += Client.Phone+ Seprator;
	StClientRecord += to_string(Client.AccountBalance);

	return StClientRecord;

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

bool FindClientByAccountNumber(string AccountNumber,vector<sClient> VClients, sClient& Client)
{
	for (sClient C : VClients)
	{
		if (C.AccountNumber == AccountNumber)
		{
			Client = C;
			return true;
		}
	}
	return false;
}

bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector<sClient>& VClients)
{
	for (sClient& C : VClients)
	{
		if (C.AccountNumber == AccountNumber)
		{
			C.MarkeForDelete = true;
			return true;
		}
	}
	return false;
}

vector<sClient> SaveClientDataToFile(string FileName, vector<sClient> VClients)
{
	fstream MyFile;
	string DataLine;
	MyFile.open(FileName, ios::out);
	if (MyFile.is_open())
	{
		for (sClient C : VClients)
		{
			if (C.MarkeForDelete == false)
			{
				DataLine = ConvertRecordToLine(C);
				MyFile << DataLine << endl;

			}
		}
		MyFile.close();
	}
	return VClients;
	
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

bool DeleteClientByAccountNumber(string AccountNumber, vector<sClient> VClients)
{
	sClient Client;
	char Answer = 'n';

	if (FindClientByAccountNumber(AccountNumber, VClients, Client))
	{
		PrintClientCard(Client);
		cout << "\n\nAre you sure you want delete this client? y/n ?";
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			MarkClientForDeleteByAccountNumber(AccountNumber, VClients);
			SaveClientDataToFile(ClientsFileName, VClients);

			VClients = LoadClientDataFromFile(ClientsFileName);
			cout << "\n\nClient Deleted Successfully.";
			return true;

		}

	}
	else {
		cout << "\nClient with Account Numeber (" << AccountNumber << ") Not Found!";
		return false;
	}
}

int main()
{
	vector<sClient> VClients = LoadClientDataFromFile(ClientsFileName);
	string AccountNumber = ReadClientAcccountNumber();

	DeleteClientByAccountNumber(AccountNumber, VClients);

	
	system("pause>0");
}