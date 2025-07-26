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

int CountCapitalLetters(string S1)
{
	int count = 0;
	for (int i = 0; i < S1.length(); i++)
	{
		if (isupper(S1[i]))
			count++;
	}
	return count;
}
int CountSmalLetters(string S1)
{
	int count = 0;
	for (int i = 0; i < S1.length(); i++)
	{
		if (islower(S1[i]))
			count++;
	}
	return count;
}
int main()
{
	string S1 = readstring();
	cout << "\nString length = " << S1.length() << endl; 
	cout << "\nCapital letters Count = " << CountCapitalLetters(S1) << endl; 
	cout << "\nSmall letters Count = " << CountSmalLetters(S1);

	system("pause>0");
}