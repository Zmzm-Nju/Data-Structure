#include<iostream>
using namespace std;
int main()
{
	int RowA = 0, ColA = 0, RowB = 0, ColB = 0, RowC = 0, ColC = 0;
	cin >> RowA >> ColA >> ColB;
	RowB = ColA, RowC = RowA, ColC = ColB;

	int** A = new int* [RowA];
	for (int i = 0; i < RowA; i++)
		A[i] = new int[ColA];
	for (int i = 0; i < RowA; i++)
		for (int j = 0; j < ColA; j++)
			cin >> A[i][j];

	int** B = new int* [RowB];
	for (int i = 0; i < RowB; i++)
		B[i] = new int[ColB];
	for (int i = 0; i < RowB; i++)
		for (int j = 0; j < ColB; j++)
			cin >> B[i][j];

	int** C = new int* [RowC];
	for (int i = 0; i < RowC; i++)
		C[i] = new int[ColC];
	for (int i = 0; i < RowC; i++)
		for (int j = 0; j < ColC; j++)
			C[i][j] = 0;

	for (int i = 0; i < RowA; i++)
	{
		for (int j = 0; j < ColB; j++)
		{
			for (int k = 0; k < ColA; k++)
				C[i][j] += A[i][k] * B[k][j];
		}
	}

	for (int i = 0; i < RowC; i++)
	{
		for (int j = 0; j < ColC; j++)
			cout << C[i][j] << " ";
		cout << endl;
	}
	return 0;
}