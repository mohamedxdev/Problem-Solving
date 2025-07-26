#include <iostream>
#include <string>

using namespace std; 

string Readstring()
{
	string S1;
	cout << "\nPlease enter your string\n";
	getline(cin, S1);

	return S1;
}
string LowerFirstWord(string S1)
{
	bool IsFirstLetter = true;

	for (short i = 0; i < S1.length(); i++) {
		if (S1[i] != ' ' && IsFirstLetter)
		{
			S1[i] = tolower(S1[i]);
		}
		IsFirstLetter = (S1[i] == ' ' ? true : false);
	}
	return S1;
}
int main()
{
	string S1 = Readstring();

	cout << "\nString After Conversion:\n";
	S1 = LowerFirstWord(S1);
	cout << S1 << endl; 

	system("pause>0");
}