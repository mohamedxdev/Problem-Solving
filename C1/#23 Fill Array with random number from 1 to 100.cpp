#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

int randomnumber(int from , int to)
{
	int randnum = rand() % (to - from + 1) + from;

	return randnum;
}
void FillarraywithrandomNumbers(int arr[100], int &arrlength)
{
	cout << "Please enter a number\n";
	cin >> arrlength;
	for (int i = 0; i <= arrlength - 1; i++)
	{
		arr[i] = randomnumber(1, 100);
	}
}
void Printarray(int arr[100], int arrlength)
{
	for (int i = 0; i <= arrlength - 1; i++)
	{
		cout << arr[i] << " ";
		
	}
}
int main()
{
	srand((unsigned)time(NULL));
	int arr[100], arrlength;
	FillarraywithrandomNumbers(arr, arrlength);

	cout << "\n Array Elements: ";
	Printarray(arr, arrlength);
	return 0;

}