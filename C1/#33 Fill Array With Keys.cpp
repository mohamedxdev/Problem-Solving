#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int RandomNumber(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}
enum enchartype
{
	smallletter, capitalletter, specialcharacter, digit
};
char getrandomCharacter(enchartype chartype)
{
	switch (chartype)
	{
	case enchartype::smallletter:
		return char(RandomNumber(97, 122));
		break;
	case enchartype::capitalletter:
		return char(RandomNumber(65, 90));
		break;
	case enchartype::specialcharacter:
		return char(RandomNumber(33, 47));
		break;
	case enchartype::digit:
		return char(RandomNumber(48, 57));
		break;
	}
}
int readpositivenumber(string message)
{
	int number;
	do {
		cout << message << endl;
		cin >> number;
	} while (number <= 0);
	return number;

}
string generateWord(enchartype chartype, short length)
{
	string word;
	for (int i = 1; i <= length; i++)
	{
		word = word + getrandomCharacter(chartype);
	}
	return word;
}
string generateKey()
{
	string key = "";
	key = generateWord(enchartype::capitalletter, 4) + "-";
	key = key + generateWord(enchartype::capitalletter, 4) + "-";
	key = key + generateWord(enchartype::capitalletter, 4) + "-";
	key = key + generateWord(enchartype::capitalletter, 4);

	return key;

}
void fillarraywithrandomkeys(string arr[100], short arrlength)
{
	for (int i = 0; i <= arrlength - 1; i++)
	{
		arr[i] = generateKey();
	}

}
void printarray(string arr[100], short arrlength)
{
	for (int i = 0; i <= arrlength - 1; i++)
	{
		cout << "Array[" << i << "]: ";
		cout << arr[i] << endl;
	}
}
int main()
{
	srand((unsigned)time(NULL));
	string arr[100];
	int arrlength = readpositivenumber("Please enter how many keys to generate ");
	
	fillarraywithrandomkeys(arr, arrlength);

	cout << "\nArray elements:\n" << endl;
	printarray(arr, arrlength);
	return 0;

}

