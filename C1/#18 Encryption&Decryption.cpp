
#include <iostream>
#include <cmath>
#include <string>
using namespace std;
string ReadText()
{
	string Text;
	cout << "Please enter Text\n";
	getline(cin, Text);

	return Text;
}
string EncryptText(string Text, short EncryptKey)
{
	for (int i = 0; i <= Text.length(); i++)
	{
		Text[i] = char((int)Text[i] + EncryptKey);

	}
	return Text;
}
string DecryptText(string Text, short EncryptKey)
{
	for (int i = 0; i <= Text.length(); i++)
	{
		Text[i] = char((int)Text[i] - EncryptKey);

	}
	return Text;
}
int main()
{
	string Text = ReadText();
	const short EncryptKey = 2;
	cout << "Text Before Encryption: " << Text << endl;
	cout << "Text After Encryption: " << EncryptText(Text, EncryptKey) << endl;
	cout << "Text After Decryption: " << DecryptText(EncryptText(Text, EncryptKey), EncryptKey) << endl;
	return 0;
}
