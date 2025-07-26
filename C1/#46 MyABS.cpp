#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int readnumber()
{
	float number;
	cout << "Please enter a number\n";
	cin >> number;
	return number;
}
float MyABS(float number)
{
	if (number > 0)
		return number;
	else
		return number * -1;
}
int main()
{
	float number = readnumber();
	cout << "My ABS Result: " << MyABS(number) << endl;
	cout << "C++ Result: " << abs(number) << endl;
	
}