#include <iostream>
#include <string>
#include <vector>
using namespace std;

string JoinString(vector <string> vString, string Delim)
{
	string S1 = "";
	for (string& s : vString)
	{
		S1 = S1 + s + Delim;
	}
	return S1.substr(0, S1.length() - Delim.length());
}
string JoinString(string arrstring[], short arrlength, string Delim)
{
	string S1 = "";
	for (short i = 0; i < arrlength; i++)
	{
		S1 = S1 + arrstring[i] + Delim;
	}
	return S1.substr(0, S1.length() - Delim.length());
	
}

int main()
{
	vector<string> vString = { "Mohamed","oussama","issam","abdou" };
	string arrstring[] = {"Mohamed", "oussama", "issam", "abdou"};
	
	cout << "\nVector After join: \n";
	cout << JoinString(vString, " ");

	cout << "\nArray After join \n";
	cout << JoinString(arrstring, 4, " ");
	
	
	system("pause>0");

}