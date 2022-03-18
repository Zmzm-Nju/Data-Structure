#define _CRT_SECURE_NO_WARNINGS
#define Size 100
#define Max_Cost 0x3f3f3f3f
#include<cstdio>
#include<cstring>
using namespace std;
struct Point
{
	int Value;
	int Status;
};
int M, N;
int Ans, Dest_Status;
int Dist[Size];
int Visited[Size];
int Edge[Size][Size];
Point Vertex[Size];
void Dijkstra(int v);
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
	Ans = Vertex[1].Value;
	Dest_Status = Vertex[1].Status;
	Dijkstra(1);
	printf("%d\n", Ans);
	return 0;
}

void Dijkstra(int v)
{
	int Min_Status = 0, Max_Status = 0;
	for (int k = 0; k <= M; k++)
	{
		Min_Status = Dest_Status - M + k;
		Max_Status = Dest_Status + k;
		for (int i = 1; i <= N; i++)
			Dist[i] = Edge[v][i];
		memset(Visited, 0, sizeof(Visited));
		Dist[v] = 0;
		Visited[v] = 1;
		
		for (int i = 1; i <= N; i++)              //求解各顶点最短路径
		{
			int Min = Max_Cost, Tmp = -1;
			for (int j = 1; j <= N; j++)
			{
				if (!Visited[j] && Dist[j] < Min && Vertex[j].Status >= Min_Status && Vertex[j].Status <= Max_Status)
				{
					Min = Dist[j];
					Tmp = j;
				}
			}

			if (Tmp == -1) break;

			Visited[Tmp] = true;
			if (Vertex[Tmp].Status >= Min_Status && Vertex[Tmp].Status <= Max_Status && Dist[Tmp] + Vertex[Tmp].Value < Ans)
				Ans = Dist[Tmp] + Vertex[Tmp].Value;

			for (int j = 1; j <= N; j++)
				if (!Visited[j] && Edge[Tmp][j] != Max_Cost)
					if (Dist[j] > Dist[Tmp] + Edge[Tmp][j] && Vertex[j].Status >= Min_Status && Vertex[j].Status <= Max_Status)
							Dist[j] = Dist[Tmp] + Edge[Tmp][j];
		}
	}
}