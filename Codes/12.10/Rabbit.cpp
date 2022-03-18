#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
using namespace std;
struct Edge
{
	int dest;
	Edge* next;
	Edge() :dest(0), next(NULL) {};
	Edge(int d) :dest(d), next(NULL) {};
};
void Sort(int* a, int size);
void DFS(Edge* List, int* visited, int u, int* count, int round);
int main()
{
	int u = 0, v = 0;
	int vertex_num = 0, left_vertex_num = 0, edge_num = 0;
	Edge* cur = NULL, * p = NULL;
	scanf("%d%d%d", &vertex_num, &left_vertex_num, &edge_num);
	Edge* List = new Edge[vertex_num];
	for (int i = 0; i < edge_num; i++)
	{
		scanf("%d%d", &u, &v);
		p = new Edge(v);
		cur = &List[u];
		while (cur->next != NULL)cur = cur->next;
		cur->next = p;
		p = new Edge(u);
		cur = &List[v];
		while (cur->next != NULL)cur = cur->next;
		cur->next = p;
	}

	int* left_vertex = new int[left_vertex_num]; //记录未被堵的洞的下标
	for (int i = 0; i < left_vertex_num; i++)
		scanf("%d", &left_vertex[i]);
	Sort(left_vertex, left_vertex_num);

	int* count = new int[vertex_num];            //记录点所在连通分量的点数
	int* visited = new int[vertex_num];          //记录点在第几轮被访问
	for (int i = 0; i < vertex_num; i++)
	{
		count[i] = 0;
		visited[i] = 0;
	}

	int top = -1;
	int* store = new int[left_vertex_num];             //存储只有一个点没堵上的洞        

	int round = 1, num = 0, block = 0;
	for (int i = 0; i < left_vertex_num; i++)
	{
		u = left_vertex[i];                            //取节点
		if (visited[u] != 0) continue;                 //已经访问过

		num = 0;                                       //记录该连通分量点数       
		DFS(List, visited, u, &num, round);            //深度优先搜索

		block = 0;
		for (int j = 0; j < vertex_num; j++)
		{
			if (visited[j] == round)
			{
				count[j] = num;
				int k = 0;
				for (; k < left_vertex_num; k++)
					if (left_vertex[k] == j) break;
				if (k == left_vertex_num) block++;
			}
		}

		if (num == block + 1)
			store[++top] = u;

		round++;
	}

	if (top == -1)
	{
		printf("%d\n", left_vertex[0]);
		return 0;
	}

	int res = store[0], max = count[store[0]];
	for (int i = 1; i <= top; i++)
		if (max < count[store[i]] || (max == count[store[i]] && res > store[i]))
			res = store[i], max = count[store[i]];
	printf("%d\n", res);

	return 0;
}

void DFS(Edge* List, int* visited, int u, int* count, int round)
{
	Edge* cur = &List[u];
	visited[u] = round, (*count)++;
	cur = cur->next;//取表头
	while (cur != NULL)
	{
		if (!visited[cur->dest])DFS(List, visited, cur->dest, count, round);
		cur = cur->next;
	}
}

void Sort(int* a, int size)
{
	for (int i = 0; i < size - 1; i++)
		for (int j = i + 1; j < size; j++)
		{
			if (a[j] < a[i])
			{
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
}