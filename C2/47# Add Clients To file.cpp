#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
const string ClientFileName = "Clients.txt";

struct sClient {

	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
};

sClient ReadNewClient()
{
	sClient Client;

	cout << "\nEnter Account Number?";
	getline(cin >> ws, Client.AccountNumber);

	cout << "\nEnter Pin Code?";
	getline(cin, Client.PinCode);

	cout << "\nEnter Name?";
	getline(cin, Client.Name);

	cout << "\nPhone Number?";
	getline(cin, Client.Phone);

	cout << "\nEnter Account Balance?";
	cin >> Client.AccountBalance;

	return Client;
}

string ConvertRecordToLine(sClient Client, string Sperator = "#//#")
{
	string stClientToRecord = "";

	stClientToRecord += Client.AccountNumber + Sperator;
	stClientToRecord += Client.PinCode + Sperator;
	stClientToRecord += Client.Name + Sperator;
	stClientToRecord += Client.Phone + Sperator;
	stClientToRecord += to_string(Client.AccountBalance);

	return stClientToRecord;


}

void AddDataLineToFile(string FileName, string stDataLine)
{
	fstream Myfile;

	Myfile.open(FileName, ios::out | ios::app);
	if (Myfile.is_open())
	{
		Myfile << stDataLine << endl;
		Myfile.close();
	}

}
void AddNewClient()
{
	sClient Client;
	Client = ReadNewClient();
	AddDataLineToFile(ClientFileName, ConvertRecordToLine(Client));
}
void AddClients()
{
	char AddMore = 'Y';

	do {
		system("cls");
		cout << "Adding New Clients:\n\n";
		AddNewClient();
		cout << "\nClient Added successfully, do you want to add more clients? ";
		cin >> AddMore;
	} while (toupper(AddMore) == 'Y');
}

int main()
{
	AddClients();

	system("pause>0");

	

	

	
}