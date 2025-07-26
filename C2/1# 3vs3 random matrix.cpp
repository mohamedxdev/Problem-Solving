#include <iostream>
#include <iomanip>

using namespace std;
int RandomNumber(int From, int To)
{
	int Randnum;
	Randnum = rand() & (To - From +1) + From;

	return Randnum;
}
void FillArrayWithRandomNumbers(int arr[3][3],short rows, short cols)
{
	for(int i=0; i<rows;i++)
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = RandomNumber(1, 100);
		}
}
void PrintArray(int arr[3][3], short rows, short cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << setw(3) << arr[i][j] << "     ";
		}
		cout << endl;
	}
}
int main()
{
	srand((unsigned)time(NULL));
	int arr[3][3];
	FillArrayWithRandomNumbers(arr,3,3);
	cout <<"The following is 3*3 random matrix:\n";
	PrintArray(arr,3,3);


}

