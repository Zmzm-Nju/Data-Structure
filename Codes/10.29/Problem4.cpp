#include<cstdio>
#include<iostream>
using namespace std;
int Find_Ch(char* str, char ch, int top);//�����ַ�ch�����������λ�õ��±꣬�Ҳ����򷵻�-1
int main()
{
	char str[5000000], res[27];
	cin >> str;
	int top = 0;
	for (int i = 0; str[i]; i++)
	{
		while (str[i + 1] && str[i] == str[i + 1]) i++; //����һ���ĵ�һ������
		int k = Find_Ch(res, str[i], top);
		if (k == -1) res[top++] = str[i];             //û���ֹ���ֱ�ӽ���res
		else if (res[k + 1] && res[k + 1] < res[k])   //���ֹ�������Ѵ��ڵ��Ǹ���ĸ����һ������С����ǰ�ƣ����ҰѸ���ĸ�ŵ����
		{
			for (int j = k; j < top - 1; j++)
				res[j] = res[j + 1];
			res[top - 1] = str[i];
		}
	}
	res[top] = '\0';
	cout << res;
	return 0;

}
int Find_Ch(char* str, char ch, int top)
{
	int n = 0;
	while (n < top)
	{
		if (str[n] == ch)
			return n;
		else
			n++;
	}
	return -1;
}