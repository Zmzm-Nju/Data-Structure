#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
using namespace std;
class Set
{
public:
	Set(int n)
	{
		set_elements = new int[n];
		for (int i = 0; i < n; i++)
			set_elements[i] = -1;
		set_size = n;
	}
	bool Union(int i, int j)
	{
		int m = Find_Parent(i), n = Find_Parent(j);
		if (m == n)return false;
		else {
			set_elements[m] = set_elements[m] + set_elements[n];
			set_elements[n] = m;
		}
		return true;
	}
	int Find_Parent(int i)
	{
		while (set_elements[i] >= 0)
			i = set_elements[i];
		return i;
	}
	~Set() { delete[]set_elements; }
private:
	int set_size;
	int* set_elements;
};
struct Edge
{
	int u;
	int v;
	int cost;
	Edge operator=(Edge e)
	{
		u = e.u;
		v = e.v;
		cost = e.cost;
		return *this;
	}
	bool operator>(Edge e)
	{
		return cost > e.cost;
	}
	bool operator<(Edge e)
	{
		return cost < e.cost;
	}
};
void Shift_Up(Edge* Heap, int heap_size);
void Shift_Down(Edge* Heap, int i, int heap_size);
int main()
{
	int V_num = 0, E_num = 0;
	int u = 0, v = 0, cost = 0, heap_size = 0;
	scanf("%d%d", &V_num, &E_num);
	Edge* Heap = new Edge[E_num];
	for (int i = 0; i < E_num; i++)
	{
		Edge p;
		scanf("%d%d%d", &p.u, &p.v, &p.cost);
		Heap[heap_size++] = p;
		Shift_Up(Heap, heap_size);
	}
	Set Net(V_num);
	int edges = 0;
	long long result = 0;
	while (heap_size > 0 && edges < V_num - 1)
	{
		if (Net.Union(Heap[0].u - 1, Heap[0].v - 1))
		{
			edges++;
			result += Heap[0].cost;
		}
		Heap[0] = Heap[--heap_size];
		Shift_Down(Heap, 0, heap_size);
	}
	printf("%lld\n", result);
	return 0;
}
void Shift_Down(Edge* Heap, int i, int heap_size)
{
	Edge Temp = Heap[i];
	int j = 2 * i + 1;
	while (j < heap_size)
	{
		if (j + 1 < heap_size && Heap[j + 1] < Heap[j]) j++; //指向较小者
		if (Heap[j] > Temp)break;
		else {
			Heap[i] = Heap[j];
			i = j, j = 2 * j + 1;
		}
	}
	Heap[i] = Temp;
}
void Shift_Up(Edge* Heap, int heap_size)
{
	int j = heap_size - 1, i = (j - 1) / 2;
	Edge Temp = Heap[j];
	while (j > 0)
	{
		if (Heap[i].cost <= Temp.cost)break;
		else {
			Heap[j] = Heap[i];
			j = i, i = (i - 1) / 2;
		}
	}
	Heap[j] = Temp;
}