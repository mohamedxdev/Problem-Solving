
#include <iostream>
#include <cmath>
#include <string>
using namespace std;
enum enPrimeNotPrime {prime =1, notPrime =2};
int readnumber(string message)
{
    int num = 0;
    do{
        cout << message << endl;
        cin >> num;
    } while(num<=0);
    return num;
}
enPrimeNotPrime checkPrimeNumber(int num)
{
    int M = round(num /2);
    for (int i=2; i<=M; i++)
    {
        if (num% i==0)
            return enPrimeNotPrime::notPrime;
        else
            return enPrimeNotPrime::prime;
    }

}
void PrimeNotPrime(int num)
{
    cout << "\n";
    cout << "Prime number from " << 1 << " to " << num << " are: " << endl;
    for (int i=1; i<=num; i++)
    {
        if(checkPrimeNumber(i) == enPrimeNotPrime::prime)
           {

           cout << i << endl;}
    }

}
int main()
{
    PrimeNotPrime(readnumber("Please enter a number!!"));
    return 0;
}

