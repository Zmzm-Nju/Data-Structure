#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int N = 0, M = 0;
	scanf("%d%d", &N, &M);

	int** Edge = new int* [N];
	for (int i = 0; i < N; i++)
		Edge[i] = new int[N];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			Edge[i][j] = 0;
	int* Color = new int[N];
	memset(Color, 0, sizeof(Color));

	int u = 0, v = 0;
	for (int i = 0; i < M; i++)
	{
		scanf("%d%d", &u, &v);
		Edge[u][v] = Edge[v][u] = 1;
	}

	Color[0] = 1;
	int* Queue = new int[N];
	int front = 0, rear = 0;
	Queue[rear++] = 0;
	while(rear!=front)
	{
		u = Queue[front++];
		for (int i = 0; i < N; i++)
			if (Edge[u][i] && !Color[i])
			{
				Color[i] = -Color[u];
				Queue[rear++] = i;
			}
			else if (Edge[u][i] && Color[i])
				if (Color[u] != -Color[i])
				{
					printf("No\n");
					return 0;
				}
	}
	printf("Yes\n");
	return 0;
}
