
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
void printalldigit(int number)
{
    cout << endl;
    for (int i = 0; i < 10; i++)
    {
        short digitfrequency = 0;
        digitfrequency = frequencynumber(i, number);
        if (digitfrequency > 0)
        {
            cout << "Digit " << i << " Frequency " << digitfrequency << " Times " << endl;
        }
    }
}
int main()
{
    int number = readPositiveNumber("PLease enter the main number");
    printalldigit(number);
    
   
}