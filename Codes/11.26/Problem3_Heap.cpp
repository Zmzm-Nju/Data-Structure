#define _CRT_SECURE_NO_WARNINGS
#include<cmath>
#include<cstdio>
using namespace std;
void Shift_Up(double* Heap, int start);
void Shift_Down(double* Heap, int start, int m);
int main()
{
	int num = 0, del = 0, heap_size = 0;
	double  x = 0, y = 0, z = 0;
	scanf("%d", &num);
	double* Heap = new double[num];
	char ch = '\0';
	for (int i = 0; i < num; i++)
	{
		scanf(" %c", &ch);
		if (ch == 'A')
		{
			scanf("%lf%lf%lf", &x, &y, &z);
			Heap[heap_size++] = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
			Shift_Up(Heap, heap_size - 1);
		}
		else if (ch == 'Q')
		{
			scanf("%d", &del);
			double sum = 0;
			for (int i = 0; i < del; i++)
			{
				sum += Heap[0];
				Heap[0] = Heap[--heap_size];
				Shift_Down(Heap, 0, heap_size - 1);
			}
			printf("%.5lf\n", sum / del);
		}
	}
	return 0;
}
void Shift_Up(double* Heap, int start)
{
	int j = start, i = (j - 1) / 2;
	double Temp = Heap[j];
	while (i >= 0)
	{
		if (Heap[i] <= Temp)break;
		else {
			Heap[j] = Heap[i];
			j = i;
			i = (i - 1) / 2;
		}
	}
	Heap[j] = Temp;
}
void Shift_Down(double* Heap, int start, int m)
{
	int i = start, j = 2 * i + 1;
	double Temp = Heap[i];
	while (j <= m)
	{
		if (j + 1 <= m && Heap[j + 1] < Heap[j]) j++;
		if (Heap[j] >= Temp)break;
		else {
			Heap[i] = Heap[j];
			i = j; j = 2 * j + 1;
		}
	}
	Heap[i] = Temp;
}