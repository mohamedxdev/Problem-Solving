
#include <iostream>
#include <cmath>
#include <string>
using namespace std;
string readpassword()
{
	string password;
	cout << "Please enter a password of 3 letters (all capital)\n";
	cin >> password;

	return password;
}
bool GuessPassword(string originalpassword)
{
	string word = "";
	int counter = 0;
	for (int i = 65; i <= 90; i++)
	{
		for (int j = 65; j <= 90; j++)
		{
			for (int k = 65; k <= 90; k++)
			{
				word = word + char(i);
				word = word + char(j);
				word = word + char(k);
				counter++;
				cout << "Trial[" << counter << "]: " << word << endl;
				
				if (word == originalpassword)
				{
					cout << "\nPassword is: " << word << endl;
					cout << "\nFound after " << counter << " Trial(s)\n\n";
					
					return true;
					
				}
				word = "";
			}
		}
	}
	return false;
}
int main()
{
	GuessPassword(readpassword());
	return 0;
}
