
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
int reversenumber(int number)
{
    int remainder = 0, number2 = 0;
    
    while (number > 0)
    {
        remainder = number % 10;
        number = number / 10;
        number2 = number2 * 10 + remainder;
        
    }
    return number2;
}
int main()
{
    cout << "\nreverse is:\n"
        << reversenumber(readPositiveNumber("PLease enter a number!!"));

    
}