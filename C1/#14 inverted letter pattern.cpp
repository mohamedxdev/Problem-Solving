


#include <iostream>
#include <cmath>
#include <string>
using namespace std;
int readPositiveNumber(string message)
{
    int number;
    do{
        cout << message << endl;
        cin >> number;
        cout << "\n";

    }while(number<=0);
    return number;
}
void PrintInvertedPattern(int number)
{
    for(int i=65+number-1; i>=65 ; i--)
    {
        for(int j=65; j<=i; j++)
    {
        cout << char(i);}
        cout << "\n";}
}
int main()
{
    PrintInvertedPattern(readPositiveNumber("Please enter a positive number"));
}

