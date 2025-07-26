#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int RandomNumber(int from, int to)
{
    int random = rand()%(to - from +1) - from;
    return random;
}
int main()
{    srand((unsigned)time(NULL));
    cout << RandomNumber(1,10) << endl;
    cout << RandomNumber(1,10) << endl;
    cout << RandomNumber(1,10) << endl;
}
