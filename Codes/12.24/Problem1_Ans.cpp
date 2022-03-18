#define _CRT_SECURE_NO_WARNINGS
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#define Size 100
#define Max_Int 0x3F3F3F3F
#define Max(x,y) ((x) > (y) ? (x) : (y))
using namespace std;
int Row, Col;
int Mount[Size][Size];
int Dist[Size * Size];
int Visited[Size * Size];
int Dest[4][2] = { {1,0},{0,-1},{-1,0},{0,1} };
void Dijkstra();
int main()
{
	scanf("%d%d", &Row, &Col);
	for (int i = 0; i < Row; i++)
		for (int j = 0; j < Col; j++)
			scanf("%d", &Mount[i][j]);
	Dijkstra();
	printf("%d\n", Dist[Row * Col - 1]);
	return 0;
}

void Dijkstra()
{
	memset(Dist, Max_Int, sizeof(Dist));
	memset(Visited, 0, sizeof(Visited));
	Dist[0] = 0;
	Dist[1] = abs(Mount[0][1] - Mount[0][0]);
	Dist[Col] = abs(Mount[1][0] - Mount[0][0]);
	Visited[0] = 1;
	for (int i = 0; i < Row * Col; i++)           //求解各顶点最短路径
	{
		int Min = Max_Int, Tmp = -1;
		for (int j = 1; j < Row * Col; j++)
		{
			if (!Visited[j] && Dist[j] < Min)
			{
				Min = Dist[j];
				Tmp = j;
			}
		}
		if (Tmp == -1 || Tmp == Row * Col - 1)
			break;
		Visited[Tmp] = true;
		int x = Tmp / Col;
		int y = Tmp % Col;
		for (int j = 0; j < 4; j++)
		{
			int nx = x + Dest[j][0];
			int ny = y + Dest[j][1];
			if (nx < 0 || nx >= Row || ny < 0 || ny >= Col)continue;
			int k = nx * Col + ny;
			int a = abs(Mount[nx][ny] - Mount[x][y]);
			if (!Visited[k] && (Dist[k] > Max(Dist[Tmp], a)))
				Dist[k] = Max(Dist[Tmp], a);
		}
	}
}