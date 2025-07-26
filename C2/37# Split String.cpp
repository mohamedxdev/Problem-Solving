#include <iostream>
#include <string>
#include <vector>
using namespace std;

string ReadString() {

	string S1;
	cout << "PLease enter your string\n";
	getline(cin, S1);

	return S1;
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
int main()
{
	vector<string> Vstring;

	Vstring = SplitString(ReadString(), " ");

	cout << "\nTokens = " << Vstring.size() << endl;

	for (string& s : Vstring)
	{
		cout << s << endl; 
	}
	system("pause>0");
		
}