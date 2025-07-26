#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
void PrintFibonacciUsingLoop(short Number)
{
	short FebNumber = 0;
	short Prev1 = 0, Prev2 = 1;
	cout << "1   ";
	for(short i=2; i<Number; i++)
	{
		FebNumber = Prev1 + Prev2;
		cout << FebNumber << "    ";
		Prev1 = Prev2;
		Prev2 = FebNumber;
}
}

int main()
{
	PrintFibonacciUsingLoop(20);
	

	system("pause>0");
}