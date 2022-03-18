#include<iostream>
#include<cstring>
using namespace std;
#define Max(a,b) ((a>b)?a:b)
int main()
{
	char Mooncake[100000];
	cin >> Mooncake;
	int Status[32];
	for (int i = 0; i < 32; i++)
		Status[i] = -2;              //��Ϊ-2����ȫ1״̬�ֿ���
	Status[31] = -1;                 //��Ϊ-1��������״̬���ȼ���ͳһ
	int max = 0, statu = 31;
	for (int i = 0; Mooncake[i] != '\0'; i++)
	{
		switch (Mooncake[i])
		{
		case 'n':statu ^= 1; break;
		case 'j':statu ^= 1 << 1; break;
		case 'u':statu ^= 1 << 2; break;
		case 'c':statu ^= 1 << 3; break;
		case 's':statu ^= 1 << 4; break;
		}
		if (Status[statu] == -2)
			Status[statu] = i;
		else 
			max = Max(max, i - Status[statu]);
	}
	cout << max << endl;
	return 0;
}
