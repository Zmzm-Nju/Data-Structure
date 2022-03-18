#include<iostream>
using namespace std;
int main()
{
	int row = 0;
	cin >> row;
	bool diagonal = true, upper = true, lower = true;
	int** Matrix = new int* [row];
	for (int i = 0; i < row; i++)
		Matrix[i] = new int[row];
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < row; j++)
		{
			cin >> Matrix[i][j];
			if (i < j && Matrix[i][j] != 0)
			{
				lower = false;
				diagonal = false;
			}
			if (i > j && Matrix[i][j] != 0)
			{
				upper = false;
				diagonal = false;
			}
		}
	}
	if (diagonal)
		cout << "diagonal" << endl;
	else if (upper)
		cout << "upper" << endl;
	else if (lower)
		cout << "lower" << endl;
	else
		cout << "none" << endl;
	return 0;
}