
#include <iostream>
#include <cmath>
#include <string>
using namespace std;
int readPositiveNumber (string message)
{
    int number;
    do{
        cout << message << endl;
        cin >> number;
    } while(number<=0);
    return number;
}
bool isPerfectNumber(int number)
{
    int sum = 0;
    for(int i=1; i<=number; i++)
    {
        if(number%i==0)
            sum +=i;

    }
    return number == sum;
}
void PrintResult (int number)
{
    if(isPerfectNumber(number))
        cout << number << " is Perfect number " << endl;
    else
        cout << number << " is Not Perfect number " << endl;
}
int main()
{
    PrintResult(readPositiveNumber("Please enter a positive number "));
}
