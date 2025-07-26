#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int RandomNumber(int from, int to)
{
	int randum = rand() % to + 1;
	return randum;
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
int main()
{
	srand((unsigned)time(NULL));
	cout << getrandomCharacter(enchartype::smallletter) << endl;
	cout << getrandomCharacter(enchartype::capitalletter) << endl;
	cout << getrandomCharacter(enchartype::specialcharacter) << endl;
	cout << getrandomCharacter(enchartype::digit) << endl;
}