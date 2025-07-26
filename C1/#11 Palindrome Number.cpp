
#include <iostream>
#include <cmath>
#include <string>
using namespace std;
int readPositvienumber(string message)
{
    int number;
    do{
        cout << message << endl;
        cin >> number;
    } while (number<=0);
    return number;
}
int Reversenumber(int number)
{
    int Remainder = 0, number2 = 0;
    while(number>0)
    {
        Remainder = number%10;
        number = number/10;
        number2 = number2*10+Remainder;
    }
    return number2;
}
bool isPalindromeNumber(int number)
{
    return (number == Reversenumber(number));
}
int main()
{
    if(isPalindromeNumber(readPositvienumber("Please enter a positive number")))
        cout << "\n Yes, it's a Palindrome number. \n";
    else
        cout << "\n no, it's not a Palindrome number. \n";
}
