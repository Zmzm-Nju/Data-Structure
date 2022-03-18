#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
using namespace std;
int main()
{
	int num = 0;
	scanf("%d", &num);
	int* Basin = new int[num];            //建立数组当作“盆”
	for (int i = 0; i < num; i++)
		scanf("%d", &Basin[i]);           //接收输入
	long long Water = 0;
	int  Left = 0, Right = 0;
	for (int i = 1; i < num - 1; i++)     //从第2行开始遍历到倒数第2行，累加（因为第一行和最后一行不可能可以放水）
	{
		Left = Right = Basin[i];
		for (int k = i - 1; k >= 0; k--)
		{
			if (Basin[k] > Left)
				Left = Basin[k];
		}
		for (int k = i + 1; k < num; k++)
		{
			if (Basin[k] > Right)
				Right = Basin[k];
		}
		Water += (Left > Right ? Right : Left) - Basin[i];
	}
	printf("%lld\n", Water);
}