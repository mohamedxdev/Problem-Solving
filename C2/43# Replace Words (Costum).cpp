#include <iostream>
#include <string>
#include <vector>
using namespace std;

string LowerAllString(string S1)
{
	for (short i = 0; i < S1.length(); i++)
	{ 
		S1[i] = tolower(S1[i]);
	} 
	return S1;
}
string JoinString(vector<string> vString, string Delim)
{
	string S1 = "";
	for (string& s : vString)
	{
		S1 = S1 + s + Delim;
	}
	return S1.substr(0, S1.length() - Delim.length());


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

string ReplaceWordInStringUsingSplit(string S1, string StringToReplace, string sRepalceTo, bool MatchCase = true)
{
	vector<string> vString = SplitString(S1, " ");

	for (string& s : vString)
	{
		if (MatchCase)
		{
			if (s == StringToReplace)
			{
				s = sRepalceTo;
			}
		}
		else
		{
			if (LowerAllString(s) == LowerAllString(StringToReplace)) {

				s = sRepalceTo;
			}
		}
	}
	return JoinString(vString, " ");
}



int main() {

	string S1 = "Welcome to Jordan , Jordan is a nice country";
	string StringToReplace = "jordan";
	string ReplaceTo = "USA";
	cout << "\nOriginal String:\n" << S1;

	cout << "\n\nReplace with match case: ";
	cout << "\n" << ReplaceWordInStringUsingSplit(S1, StringToReplace, ReplaceTo);

	cout << "\n\nReplace with dont match case: ";
	cout << "\n" << ReplaceWordInStringUsingSplit(S1, StringToReplace, ReplaceTo, false);
	system("pause>0");
}
