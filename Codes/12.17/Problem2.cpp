#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
using namespace std;
int Row = 0, Col = 0, max = 0; 
int Dest[4][2] = { {1,0},{0,-1},{-1,0},{0,1} };
int Max(int x, int y);
int DFS(int** Matrix, int** Path, int x, int y);
int main()
{
	
	scanf("%d%d", &Row, &Col);

	int** Matrix = new int* [Row];
	for (int i = 0; i < Row; i++)
	{
		Matrix[i] = new int[Col];
		for (int j = 0; j < Col; j++)
			scanf("%d", &Matrix[i][j]);
	}
	int** Path = new int* [Row];
	for (int i = 0; i < Row; i++)
	{
		Path[i] = new int[Col];
		for (int j = 0; j < Col; j++)
			Path[i][j] = 0;
	}

	for (int i = 0; i < Row; i++)
		for (int j = 0; j < Col; j++)
		{
			DFS(Matrix, Path, i, j);
			if (Path[i][j] > max)max = Path[i][j];
		}

	printf("%d\n", max);
	return 0;
}

int DFS(int** Matrix, int** Path, int x, int y)
{
	if (Path[x][y] != 0) return Path[x][y];
	Path[x][y] = 1;
	for (int k = 0; k < 4; k++)
	{
		int nx = x + Dest[k][0];
		int ny = y + Dest[k][1];
		if (nx >= 0 && nx < Row && ny >= 0 && ny < Col && Matrix[nx][ny] > Matrix[x][y])
			Path[x][y] = Max(Path[x][y], 1 + DFS(Matrix, Path, nx, ny));
	}
	return Path[x][y];
}
int Max(int x, int y)
{
	return x > y ? x : y;
}
