#include <iostream>
#include <string>
#include <vector>
using namespace std;
string ReplaceWordInStringUsingBuiltInFunction(string S1,string StringToReplace,string sRepalceTo)
{
	short pos = S1.find(StringToReplace);
	while (pos != std::string::npos)
	{
		S1.replace(pos, StringToReplace.length(), sRepalceTo);
		pos = S1.find(StringToReplace);
	}
	return S1;
}

int main()
{
	string S1= "\nWelcome to Algeria , Algeria is a nice country";
	cout << S1 << endl;
	string StringToReplace = "Algeria";
	string sRepalceTo = "medea";

	cout << "\nString After Replace: \n";
	cout << ReplaceWordInStringUsingBuiltInFunction(S1, StringToReplace, sRepalceTo);

	system("pause>0");
}
