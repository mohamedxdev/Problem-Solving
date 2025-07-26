
#include <iostream>
#include <cmath>
#include <string>
using namespace std;
int readPostiveNumber (string message)
{
    int number;
    do{
        cout << message << endl;
        cin >> number;
    } while (number<=0);
    return number;
}
int sumofdigits(int number)
{
    int sum =0,remainder = 0;
    while(number>0)
    {
        remainder = number %10;
        number = number /10;
        sum = sum +remainder;
    }
    return sum;

}
int main()
{
    cout << "\n sum of Digits = "
    << sumofdigits(readPostiveNumber("Please enter a positive number "));
    cout << "\n";
    return 0;
}
