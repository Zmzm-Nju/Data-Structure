#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	int num = 0, n = 0, res = 0;
	scanf("%d", &num);
	int** a = new int*[num / 2];   //a[i][0]��a[i][1]�ֱ�Ϊ2i��2i+1��Ӧ�±�
	int* b = new int[num];         //b[i]�洢��Ϊ����ĵ�i����
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
			int tmp = a[i][1];      //��ԭ��a[i][1]�±�
			a[i][1] = a[i][0] ^ 1;  //����Ҫ��λ�����ݵ��±��a[i][1]
			n = b[a[i][1]];         //�õ���Ҫ��λ������
			a[n / 2][n % 2] = tmp;  //��a�н����±�

			//a[i][1] = a[i][0] ^ 1��˼��֮��ľ���ʵ�֣�ԭ���Ĵ���ɼ�ȫ������֮���ע��

			int tmp_2 = b[a[i][1]];
			b[a[i][1]] = b[tmp];    //tmpΪ֮ǰa[i][1]�±꣬��ʱ��a[i][1]�Ѿ�Ϊ�������ݵ��±�
			b[tmp] = tmp_2;         //��b�н����±�
			res++;
		}
	}
	printf("%d\n", res);
}
/*if (a[i][0] % 2 == 1)
{
	int tmp = a[i][1];     //��ԭ��a[i][1]�±�
	a[i][1] = a[i][0] - 1; //��Ҫ��λ�����ݵ��±��a[i][1]
	n = b[a[i][1]];        //�õ���Ҫ��λ������
	a[n / 2][n % 2] = tmp; //��a�н����±�

	int tmp_2 = b[a[i][1]];
	b[a[i][1]] = b[tmp];
	b[tmp] = tmp_2;        //��b�н����±�
}
if (a[i][0] % 2 == 0)
{
	int tmp = a[i][1];     //��ԭ��a[i][1]�±�
	a[i][1] = a[i][0] + 1; //��Ҫ��λ�����ݵ��±��a[i][1]
	n = b[a[i][1]];        //�õ���Ҫ��λ������
	a[n / 2][n % 2] = tmp; //��a�н����±�

	int tmp_2 = b[a[i][1]];
	b[a[i][1]] = b[tmp];
	b[tmp] = tmp_2;        //��b�н����±�
}*/