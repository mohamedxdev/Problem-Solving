#include <iostream>
#include <string>
#include <vector>	
#include <iomanip>
#include <fstream>

using namespace std;

const string ClientsFileName = "NotMyFile.txt";
struct sClient {

	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
};

vector<string> SplitString(string S1, string Delim) {

	short pos = 0;
	string sWord = "";
	vector<string> Vstring;

	while ((pos = S1.find(Delim)) != std::string::npos)
	{
		sWord = S1.substr(0, pos);
		if (sWord != "")
		{
			Vstring.push_back(sWord);
		}
		S1.erase(0, pos + Delim.length());
	}
	if (S1 != "")
	{
		Vstring.push_back(S1);
	}
	return Vstring;
}

sClient ConvertLineToRecord(string S1, string Seprator = "#//#")
{
	sClient Client;
	vector<string> VClientData;
	VClientData = SplitString(S1, Seprator);

	Client.AccountNumber = VClientData[0];
	Client.PinCode = VClientData[1];
	Client.Name = VClientData[2];
	Client.Phone = VClientData[3];
	Client.AccountBalance = stod(VClientData[4]);
	
	return Client;
}

vector<sClient> LoadClientDataFromFile(string FileName)
{
	vector<sClient> VClients;
	fstream MyFile;
	MyFile.open(FileName, ios::in);

	if (MyFile.is_open())
	{
		string Line;
		sClient Client;
		while (getline(MyFile, Line))
		{
			Client = ConvertLineToRecord(Line);

		    VClients.push_back(Client); 
		}
		MyFile.close();
	}
	return VClients;


}

void PrintClientRecord(sClient Client) {

	cout << "| " << setw(15) << left <<  Client.AccountNumber;
	cout << "| " << setw(10) << left << Client.PinCode;
	cout << "| " << setw(40) << left << Client.Name;
	cout << "| " << setw(12) << left << Client.Phone;
	cout << "| " << setw(12) << left << Client.AccountBalance;
}
void PrintAllClientData(vector<sClient> VClients) {

	cout << "\n\t\t\t\t\tClient List (" << VClients.size() << ") Client(s)";
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;


	cout << "| " << left << setw(15) << "Accout Number";
	cout << "| " << left << setw(10) << "Pin Code";
	cout << "| " << left << setw(40) << "Client Name";
	cout << "| " << left << setw(12) << "Phone";
	cout << "| " << left << setw(12) << "Balance";
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;

	for (sClient Client : VClients)
	{
		PrintClientRecord(Client);
		cout << endl;
	}
	cout << "_______________________________________________________";
	cout << "_________________________________________\n" << endl;
}
int main() {
	vector<sClient> VClients = LoadClientDataFromFile(ClientsFileName);

	PrintAllClientData(VClients);

	system("pause>0");

}