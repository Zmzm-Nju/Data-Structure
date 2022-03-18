#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstring>
using namespace std;
struct Location
{
	long long x;
	long long y;
	Location() :x(0), y(0) {}
};
int Search(Location* Vertex, int& m, long long x, long long y);
long long Distance(Location Vertex1, Location Vertex2);
int main()
{
	int Num = 0;
	Location Vertex[1000];
	long long Edge[1000][1000];
	memset(Edge, 0, sizeof(Edge));
	scanf("%d", &Num);
	scanf("%lld%lld%lld%lld", &Vertex[0].x, &Vertex[0].y, &Vertex[1].x, &Vertex[1].y); //0，1为起点和终点

	int x = 0, y = 0, m = 2;
	long long x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	for (int i = 0; i < Num; i++)
	{
		scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
		x = Search(Vertex, m, x1, y1);
		y = Search(Vertex, m, x2, y2);
		Edge[x][y] = Edge[y][x] = 10;
	}

	for (int i = 0; i < m; i++)
		for (int j = i + 1; j < m; j++)
			if(Edge[i][j] == 0)
				Edge[i][j] = Edge[j][i] = Distance(Vertex[i], Vertex[j]);

	for (int k = 0; k < m; k++)
		for (int i = 0; i < m; i++)
			for (int j = 0; j < m; j++)
				if (Edge[i][k] + Edge[k][j] < Edge[i][j])
					Edge[i][j] = Edge[i][k] + Edge[k][j];

	printf("%lld\n", Edge[0][1]);
	return 0;
}

int Search(Location* Vertex, int& m, long long x, long long y)
{
	for (int i = 0; i < m; i++)
		if (Vertex[i].x == x && Vertex[i].y == y)
			return i;
	Vertex[m].x = x, Vertex[m].y = y, m++;
	return m - 1;
}

long long Distance(Location Vertex1, Location Vertex2)
{
	return (Vertex1.x > Vertex2.x ? (Vertex1.x - Vertex2.x) : (Vertex2.x - Vertex1.x))
		 + (Vertex1.y > Vertex2.y ? (Vertex1.y - Vertex2.y) : (Vertex2.y - Vertex1.y));
}

