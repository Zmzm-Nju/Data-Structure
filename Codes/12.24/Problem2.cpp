#define _CRT_SECURE_NO_WARNINGS
#define Size 200
#define Max_Int 0x3f3f3f3f
#include<cstdio>
#include<cstring>
using namespace std;
int N, A, B;
int Edge[Size][Size];
int Dist[Size];
int Visited[Size];
void Dijkstra(int v);
int main()
{
	memset(Edge, Max_Int, sizeof(Edge));
	int num = 0, v = 0;
	scanf("%d%d%d", &N, &A, &B);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &num);
		for (int j = 0; j < num; j++)
		{
			scanf("%d", &v);
			if (j == 0)
				Edge[i][v - 1] = 0;
			else Edge[i][v -1] = 1;
		}
	}
	Dijkstra(A - 1);
	if (Dist[B - 1] == Max_Int)printf("-1\n");
	else printf("%d\n", Dist[B - 1]);
	return 0;
}
void Dijkstra(int v)
{
	for (int i = 0; i < N; i++)
		Dist[i] = Edge[v][i];
	Dist[v] = 0;
	Visited[v] = true;
	for (int i = 0; i < N; i++)              //求解各顶点最短路径
	{
		int Min = Max_Int, Tmp = -1;
		for (int j = 0; j < N; j++)
		{
			if (!Visited[j] && Dist[j] < Min)
			{
				Min = Dist[j];
				Tmp = j;
			}
		}
		if (Tmp == -1||Tmp == B - 1)
			break;
		Visited[Tmp] = true;
		for (int j = 0; j < N; j++)
			if (!Visited[j] && Edge[Tmp][j] != Max_Int)
				if (Dist[j] > Dist[Tmp] + Edge[Tmp][j])
					Dist[j] = Dist[Tmp] + Edge[Tmp][j];
				
	}
}