
#include <iostream>
#include <cmath>
#include <string>
using namespace std;
string readPostiveNumber (string message)
{
    int number;
    do{
        cout << message << endl;
        cin >> number;
    } while (number<=0);
    return to_string(number);
}
void PrintResult()
{
    string word = readPostiveNumber("please enter a positive number ");
    for (int i=word.length();i>=0; i--)
        cout << word[i] << endl;

}
int main()
{
    PrintResult();
}
