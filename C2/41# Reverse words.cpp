#include <iostream>
#include <string>
#include <vector>
using namespace std;

string Readstring()
{
	string S1;
	cout << "Please enter your string\n";
	getline(cin, S1);
	return S1;
}
vector<string> SplitString(string S1, string Delim)
{
	vector<string> vString;
	short pos = 0;
	string sWord; 
	
	while ((pos = S1.find(Delim)) != std::string::npos)
	{
		sWord = S1.substr(0, pos); 
		if (sWord != "")
		{
			vString.push_back(sWord);
		}
		S1.erase(0, pos + Delim.length()); 
		
	}
	if (S1 != "")
	{
		vString.push_back(S1); 
	}
	return vString;
}
string ReverseWordsInString(string S1) {

	vector<string> Vstring;
	string S2 = "";

	Vstring = SplitString(S1, " ");
	vector<string>::iterator iter = Vstring.end();

	while (iter != Vstring.begin())
	{
		--iter;
		S2 += *iter + " ";
	}
	S2 = S2.substr(0, S2.length() -1 );

	return S2;
}
int main()
{
	string S1 = Readstring();
	cout << "String After reversing words: \n";
	cout << "\n" << ReverseWordsInString(S1);

	system("pause>0");
}
