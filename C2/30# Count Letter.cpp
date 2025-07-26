#include <iostream>
#include <string>

using namespace std;

string readstring()
{
	string S1;
	cout << "Please enter Your string\n";
	getline(cin, S1);
	return S1;
}
short CountChar(string S1, char Letter)
{
	short count = 0;
	for (short i = 0; i < S1.length(); i++)
	{
		if (S1[i] == Letter)
			count++;
	}
	return count;
}
int main()
{
	string S1 = readstring();
	char Letter;
	cout << "\nPlease enter a character?\n";
	cin >> Letter;
	cout << "\nLetter '" << Letter << "' count = " << CountChar(S1, Letter);
	system("pause>0");
}