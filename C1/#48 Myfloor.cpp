#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;
float readnumber()
{
	float num;
	cout << "Please enter a number\n";
	cin >> num;
	return num;
}
float Myfloor(float num)
{
	if (num >= 0)
		return int(num);
	else
		return int(num) - 1;
}
int main()
{
	float num = readnumber();
	cout << "My floor result: " << Myfloor(num) << endl;
	cout << "C++ floor result: " << floor(num) << endl;

}#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;
float readnumber()
{
	float num;
	cout << "Please enter a number\n";
	cin >> num;
	return num;
}
float Myfloor(float num)
{
	if (num >= 0)
		return int(num);
	else
		return int(num) - 1;
}
int main()
{
	float num = readnumber();
	cout << "My floor result: " << Myfloor(num) << endl;
	cout << "C++ floor result: " << floor(num) << endl;

}