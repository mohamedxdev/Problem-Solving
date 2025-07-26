
#include <iostream>
#include <cmath>
#include <string>
using namespace std;
int readPositiveNumber(string message)
{
    int number;
    do {
        cout << message << endl;
        cin >> number;
    } while (number <= 0);
    return number;
}
int frequencynumber(int digitocheck, int number)
{
    int freecount = 0, remainder = 0;
    while (number > 0)
    {
        remainder = number % 10;
        number = number / 10;
        if (digitocheck == remainder)
        {
            freecount++;
        }

        
        
    }
    return freecount;
}
int main()
{
    int number = readPositiveNumber("PLease enter the main number");
    int digittocheck = readPositiveNumber("Pleas enter one digit to check");
    cout << "Digit " << digittocheck << " frequency is: " << frequencynumber(digittocheck, number) << " times";
}