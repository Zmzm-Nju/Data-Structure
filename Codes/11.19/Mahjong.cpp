#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	int num = 0, n = 0, res = 0;
	scanf("%d", &num);
	int** a = new int*[num / 2];   //a[i][0]与a[i][1]分别为2i与2i+1对应下标
	int* b = new int[num];         //b[i]存储的为输入的第i个数
	for (int i = 0; i < num / 2; i++)
		a[i] = new int[2];
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &n);
		a[n / 2][n % 2] = i;
		b[i] = n;
	}
	for (int i = 0; i < num / 2; i++)
	{
		if (a[i][0] / 2 == a[i][1] / 2)continue;
		else 
		{
			int tmp = a[i][1];      //存原来a[i][1]下标
			a[i][1] = a[i][0] ^ 1;  //将需要换位的数据的下标给a[i][1]
			n = b[a[i][1]];         //得到需要换位的数据
			a[n / 2][n % 2] = tmp;  //在a中交换下标

			//a[i][1] = a[i][0] ^ 1是思考之后的精简实现，原来的代码可见全部代码之后的注释

			int tmp_2 = b[a[i][1]];
			b[a[i][1]] = b[tmp];    //tmp为之前a[i][1]下标，此时的a[i][1]已经为交换数据的下标
			b[tmp] = tmp_2;         //在b中交换下标
			res++;
		}
	}
	printf("%d\n", res);
}
/*if (a[i][0] % 2 == 1)
{
	int tmp = a[i][1];     //存原来a[i][1]下标
	a[i][1] = a[i][0] - 1; //需要换位的数据的下标给a[i][1]
	n = b[a[i][1]];        //得到需要换位的数据
	a[n / 2][n % 2] = tmp; //在a中交换下标

	int tmp_2 = b[a[i][1]];
	b[a[i][1]] = b[tmp];
	b[tmp] = tmp_2;        //在b中交换下标
}
if (a[i][0] % 2 == 0)
{
	int tmp = a[i][1];     //存原来a[i][1]下标
	a[i][1] = a[i][0] + 1; //需要换位的数据的下标给a[i][1]
	n = b[a[i][1]];        //得到需要换位的数据
	a[n / 2][n % 2] = tmp; //在a中交换下标

	int tmp_2 = b[a[i][1]];
	b[a[i][1]] = b[tmp];
	b[tmp] = tmp_2;        //在b中交换下标
}*/