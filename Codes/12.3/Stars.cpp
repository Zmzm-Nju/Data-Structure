#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
using namespace std;
struct Position
{
	int i;
	int j;
	Position() {};
	Position(int i_n, int j_n) :i(i_n), j(j_n) {}
	Position operator = (Position p)
	{
		i = p.i;
		j = p.j;
		return *this;
	}
};
void Visit(int** Sea, bool** Visited, int i, int j, int row, int col);
int main()
{
	int row = 0, col = 0, res = 0;
	scanf("%d%d", &row, &col);
	int** Sea = new int* [row];
	bool** Visited = new bool* [row];
	for (int i = 0; i < row; i++)
	{
		Sea[i] = new int[col];
		Visited[i] = new bool[col];
	}
	
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			scanf("%d", &Sea[i][j]);
			Visited[i][j] = false;
		}
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (Sea[i][j] == 0)
			{
				Visited[i][j] = true;
				continue;
			}
			else if (!Visited[i][j])
			{
				Visit(Sea, Visited, i, j, row, col);
				res++;
			}
		}
	}
	printf("%d\n", res);
	return 0;
}
void Visit(int** Sea, bool** Visited, int i, int j, int row, int col)
{
	Position p(i, j);
	Position* Queue = new Position[row * col];
	int front = 0, rear = 0;
	Queue[rear++] = p;
	Visited[i][j] = true;
	while (front < rear)
	{
		p = Queue[front++];
		if (p.j - 1 >= 0 && Visited[p.i][p.j - 1] == false)
		{
			Visited[p.i][p.j - 1] = true;
			if (Sea[p.i][p.j - 1] == 1)
			{
				Position q(p.i, p.j - 1);
				Queue[rear++] = q;
			}
		}
		if (p.i + 1 < row && Visited[p.i + 1][p.j] == false)
		{
			Visited[p.i + 1][p.j] = true;
			if (Sea[p.i + 1][p.j] == 1)
			{			
				Position q(p.i + 1, p.j);
				Queue[rear++] = q;
			}
		}
		if (p.j + 1 < col && Visited[p.i][p.j + 1] == false)
		{
			Visited[p.i][p.j + 1] = true;
			if (Sea[p.i][p.j + 1] == 1)
			{
				Position q(p.i, p.j + 1);
				Queue[rear++] = q;
			}
		}
		if (p.i - 1 >= 0 && Visited[p.i - 1][p.j] == false)
		{
			Visited[p.i - 1][p.j] = true;
			if (Sea[p.i - 1][p.j] == 1)
			{
				Position q(p.i - 1, p.j);
				Queue[rear++] = q;
			}
		}
	}
	delete[]Queue;
}