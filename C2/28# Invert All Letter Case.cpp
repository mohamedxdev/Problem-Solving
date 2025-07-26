#include <iostream>
#include <string>

using namespace std; 

string Readstring()
{
	string S1;
	cout << "Please enter your string\n";
	getline(cin, S1);

	return S1;
}
char InvertLetterCase(char char1) {
	return isupper(char1) ? tolower(char1) : toupper(char1);
}
string InverAllettersCase(string S1)
{
	for (short i = 0; i < S1.length(); i++)
	{
		S1[i] = InvertLetterCase(S1[i]);
	}
	return S1;
}

int main() {
	
	string S1 = Readstring();
	
	cout << "string after inverting all letters case:\n";
	S1 = InverAllettersCase(S1);
	cout << S1 << endl; 

	system("pause>0");
}