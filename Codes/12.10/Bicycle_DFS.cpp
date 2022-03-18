#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstring>
#define Size 20
#define Max_Int 0x7FFFFFFF
using namespace std;
int Edge[Size][Size];  //记录各边权值
int Vertex[Size];      //记录顶点单车数
int In_Out[Size];      //记录顶点需带进/带出单车数
int Dist[Size];
int Path[Size], Temp_Path[Size];
int Tail = -1, Temp_Tail = -1;
bool Visited[Size];
int cmax, n, sp, m;
int Mintake, Minback;
int Vector[Size][Size];
int Vector_Tail[Size];
void Dfs(int v);
void Dijkstra(int v);
int main()
{
	Mintake = Max_Int; Minback = Max_Int;
	scanf("%d%d%d%d", &cmax, &n, &sp, &m);

	memset(Vertex, 0, sizeof(Vertex));
	for (int i = 0; i < Size; i++)
		for (int j = 0; j < Size; j++)
			if (i == j)Edge[i][j] = 0;
			else Edge[i][j] = Max_Int;
	In_Out[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &Vertex[i]);
		In_Out[i] = Vertex[i] - cmax / 2;
	}
	int u = 0, v = 0, cost = 0;
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d", &u, &v, &cost);
		Edge[u][v] = Edge[v][u] = cost;
	}

	memset(Vector, 0, sizeof(Vector));
	for (int i = 0; i < Size; i++)
		Vector_Tail[i] = -1;
	Dijkstra(sp);
	Dfs(sp);

	printf("%d 0", Mintake);
	for (int i = Tail - 1; i >= 0; i--)
		printf("->%d", Path[i]);
	printf("%d\n", Minback);
	return 0;
}
void Dijkstra(int v)
{
	memset(Visited, 0, sizeof(Visited));
	Dist[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		Dist[i] = Edge[0][i];
		if (Edge[0][i] != Max_Int)
			Vector[i][++Vector_Tail[i]] = 0;
	}
	for (int i = 0; i < n; i++)              //求解各顶点最短路径
	{
		int Min = Max_Int, Tmp = -1;
		for (int j = 1; j <= n; j++)
		{
			if (!Visited[j] && Dist[j] < Min)
			{
				Min = Dist[j];
				Tmp = j;
			}
		}
		if (Tmp == -1)
			break;
		Visited[Tmp] = true;
		for (int j = 1; j <= n; j++)
		{
			if (!Visited[j] && Edge[Tmp][j] != Max_Int)
			{
				if (Dist[j] > Dist[Tmp] + Edge[Tmp][j])
				{
					Vector_Tail[j] = -1;
					Vector[j][++Vector_Tail[j]] = Tmp;
					Dist[j] = Dist[Tmp] + Edge[Tmp][j];
				}
				else if (Dist[j] == Dist[Tmp] + Edge[Tmp][j])
				{
					Vector[j][++Vector_Tail[j]] = Tmp;
				}
			}
		}
	}
}
void Dfs(int v)
{
	Temp_Path[++Temp_Tail] = v;
	if (v == 0)
	{
		int back = 0, take = 0;
		for (int i = Temp_Tail; i >= 0; i--)
		{
			int id = Temp_Path[i];
			if (In_Out[id] > 0)
				back += In_Out[id]; //需要带走的
			else
			{
				if (back > - In_Out[id])//如果之前带走的大于当前需要的
					back += In_Out[id];
				else
				{
					take += -(back + In_Out[id]);
					back = 0;
				}
			}
		}
		if (take < Mintake)
		{
			Mintake = take;
			Minback = back;
			Tail = Temp_Tail;
			for (int i = 0; i <= Tail; i++)
				Path[i] = Temp_Path[i];
		}
		else if (take == Mintake && back < Minback)
		{
			Mintake = take;
			Minback = back;
			Tail = Temp_Tail;
			for (int i = 0; i <= Tail; i++)
				Path[i] = Temp_Path[i];
		}
		Temp_Tail--;
		return;
	}
	for (int i = 0; i <= Vector_Tail[v]; i++)
		Dfs(Vector[v][i]);
	Temp_Tail--;
}