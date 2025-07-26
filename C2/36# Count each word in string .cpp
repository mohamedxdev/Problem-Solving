#include <string>
#include <iostream>
using namespace std;
string ReadString()
{
	string S1;
	cout << "Please Enter Your String?\n";
	getline(cin, S1);
	return S1;
}
short CountWords(string S1)
{
	string delim = " ";
	
	short pos = 0;
	string sWord; 
	short counter = 0;

	while ((pos = S1.find(delim)) != std::string::npos)
	{
		sWord = S1.substr(0, pos); 
		if (sWord != "")
		{
			counter++;
		}
		S1.erase(0, pos + delim.length()); 
	}
	
	if (S1 != "")
	{
		counter++;
	}
	return counter;
}
int main()
{
	string S1 = ReadString();
	cout << "\nThe number of word in your string is: "<< CountWords(S1);
	system("pause>0");
}