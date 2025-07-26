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
int Mysqrt(int num)
{
	return pow(num, 0.5);
	
}
int main()
{
	float num = readnumber();
	cout << "My sqrt result: " << Mysqrt(num) << endl;
	cout << "C++ sqrt result: " << sqrt(num) << endl;

}