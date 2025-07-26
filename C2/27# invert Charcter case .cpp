#include <iostream>
#include <string>

using namespace std; 

char ReadChar()
{
	char char1;
	cout << "Please enter a character\n";
	cin >> char1;

	return char1;
}
char InvertLetterCase(char char1) {
	return isupper(char1) ? tolower(char1) : toupper(char1);
}

int main() {
	
	char char1 = ReadChar();
	
	cout << "char after inverting case:\n";
	char1 = InvertLetterCase(char1);

	cout << char1 << endl; 

	system("pause>0");
}