#include <string>
#include <iostream>
using namespace std;

char ReadChar()
{
	char Ch1;
	cout << "Please enter a character\n";
	cin >> Ch1;

	return Ch1;
}
bool IsVowel(char Ch1)
{
	Ch1 = tolower(Ch1);

	return ((Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'i') || (Ch1 == 'o') || (Ch1 == 'u'));
}

int main() {

	char Ch1 = ReadChar();

	if (IsVowel(Ch1))
		cout << "\nYes Letter '" << Ch1 << "' is Vowel" << endl;
	else
		cout << "\nNo Letter '" << Ch1 << "' is no Vowel " << endl; 
}