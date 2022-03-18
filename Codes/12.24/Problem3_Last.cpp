#define _CRT_SECURE_NO_WARNINGS
#define Size 100
#define Max_Cost 0x3f3f3f3f
#define Max(x,y) (x)>(y)?(x):(y)
#define Min(x,y) (x)<(y)?(x):(y)
#include<cstdio>
#include<cstring>
using namespace std;

struct Point
{
	int Value;
	int Status;
};
struct Path
{
	int Value;
	int Min_Status;
	int Max_Status;
};
int M, N;
int Edge[Size][Size];
Point Vertex[Size];
int Visited[Size];
Path Dist[Size];    //储存了到当前点的权值和最小最大权限
int Dijkstra(int v);
int main()
{
	memset(Edge, Max_Cost, sizeof(Edge));
	int Num = 0, V = 0, Cost = 0;
	scanf("%d%d", &M, &N);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d%d", &Vertex[i].Value, &Vertex[i].Status);
		scanf("%d", &Num);
		for (int j = 0; j < Num; j++)
		{
			scanf("%d%d", &V, &Cost);
			Edge[i][V] = Cost;
		}
	}
	int Ans = Dijkstra(1);
	printf("%d\n", Ans);
	return 0;
}

int Dijkstra(int v)
{
	int Ans = 0;
	for (int i = 1; i <= N; i++)
	{
		Dist[i].Value = Edge[v][i];
		if (Edge[v][i] != Max_Cost)
		{
			Dist[i].Max_Status = Max(Vertex[i].Status, Vertex[v].Status);
			Dist[i].Min_Status = Min(Vertex[i].Status, Vertex[v].Status);
		}
		else
		{
			Dist[i].Max_Status = Vertex[i].Status;
			Dist[i].Min_Status = Vertex[i].Status;
		}
	}
	Dist[v].Value = 0;
	Dist[v].Min_Status = Vertex[v].Status;
	Dist[v].Max_Status = Vertex[v].Status;
	Visited[v] = 1;
	Ans = Dist[v].Value + Vertex[v].Value;
	for (int i = 1; i <= N; i++)              //求解各顶点最短路径
	{
		int Min = Max_Cost, Tmp = -1;
		for (int j = 1; j <= N; j++)
		{
			if (!Visited[j] && Dist[j].Value < Min)
			{
				Min = Dist[j].Value;
				Tmp = j;
			}
		}
		if (Tmp == -1) break;
		Visited[Tmp] = true;
		if ((Dist[Tmp].Max_Status - Dist[Tmp].Min_Status) <= M && Dist[Tmp].Value + Vertex[Tmp].Value < Ans)
			Ans = Dist[Tmp].Value + Vertex[Tmp].Value;

		for (int j = 1; j <= N; j++)
			if (!Visited[j] && Edge[Tmp][j] != Max_Cost)
				if (Dist[j].Value > Dist[Tmp].Value + Edge[Tmp][j])
				{
					int a = Max(Dist[j].Max_Status, Vertex[Tmp].Status);
					int b = Min(Dist[j].Min_Status, Vertex[Tmp].Status);
					if (a - b <= M)
					{
						Dist[j].Value = Dist[Tmp].Value + Edge[Tmp][j];
						Dist[j].Max_Status = a;
						Dist[j].Min_Status = b;
					}
				}


	}
	return Ans;
}