#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
struct sClient
{
	string AccountNumber;
	string PinCode;
	string NameAccount;
	string PhoneNumber;
	double AccountBalance;
};
sClient ReadInfoAccount()
{
	sClient Client;
	
	

	cout << "Enter Account Number? ";
	cin >> Client.AccountNumber;

	cout << "Enter PinCode? ";
	cin >> Client.PinCode;

	cout << "Enter Name? ";
	getline(cin, Client.NameAccount);

	cout << "Enter Phone ";
	cin >> Client.PhoneNumber;

	cout << "Enter Account Balance? ";
	cin >> Client.AccountBalance;

	return Client;	

}
string ConvertRecordToLine(sClient Client, string Seprator = "#//#")
{
	string StClientRecord = "";
	StClientRecord += Client.AccountNumber + Seprator;
	StClientRecord += Client.PinCode + Seprator;
	StClientRecord += Client.NameAccount + Seprator;
	StClientRecord += Client.PhoneNumber + Seprator;
	StClientRecord += to_string(Client.AccountBalance);

	return StClientRecord;

}
int main()
{
	sClient Client;
	cout << "\nPlease enter Client Data\n\n";
	Client = ReadInfoAccount();

	cout << "\nClient Record for saving is: \n";
	cout << ConvertRecordToLine(Client);
	
}