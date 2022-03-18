#include<cstring>
#include<iostream>
using namespace std;
#define Max_Size 12
int N = 0, M = 0, Res = 0;
int Block[Max_Size][Max_Size];
int Stack[Max_Size], top = -1;
bool Is_Ok();         //�жϷ����Ƿ�Ϸ�
void Queen(int n);    //�ݹ鴦��
int main()
{
	memset(Block, 0, sizeof(Block));
	cin >> N >> M;
	int u = 0, v = 0;
	for (int i = 0; i < M; i++)
	{
		cin >> u >> v;
		Block[u - 1][v - 1] = 1;     //��ˮ������վ��
	}
	Queen(0);
	cout << Res << endl;
}
void Queen(int n)
{
	for (int i = 0; i < N; i++)
	{
		if (!Block[n][i])
		{
			Stack[++top] = i;     //�½ڵ���ջ
			if (Is_Ok())          //���úϷ�           
				if(n == N - 1)Res++;
				else Queen(n + 1);
			top--;
		}
	}
}
bool Is_Ok()
{
	for (int i = 0; i <= top; i++)
		for (int j = i + 1; j <= top; j++)
		{
			if (Stack[i] == Stack[j])return false;//ͬһ��
			if (abs(j - i) == abs(Stack[j] - Stack[i]))return false;
		}
	return true;
}