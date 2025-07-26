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
float Myceil(float num)
{
	if (num >= 0)
		return int(num)+1;
	else
		return int(num);
}
int main()
{
	float num = readnumber();
	cout << "My ceil result: " << Myceil(num) << endl;
	cout << "C++ ceil result: " << ceil(num) << endl;

}