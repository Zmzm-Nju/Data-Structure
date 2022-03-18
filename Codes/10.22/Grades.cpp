#include<iostream>
using namespace std;
int main()
{
	int row = 0, col = 0;
	cin >> row >> col;

	int** Matrix = new int* [row];
	for (int i = 0; i < row; i++)
		Matrix[i] = new int[col];
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			cin >> Matrix[i][j];

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (Matrix[i][j] == 0)
			{
				for (int k = 0; k < row; k++)
					Matrix[k][j] = (Matrix[k][j] == 0) ? 0 : (-1);
				for (int k = 0; k < col; k++)
					Matrix[i][k] = (Matrix[i][k] == 0) ? 0 : (-1);
			}
		}
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			cout << ((Matrix[i][j] == -1) ? 0 : Matrix[i][j]) << " ";
		cout << endl;
	}
	return 0;
}