#include<cstdio>
#include<iostream>
using namespace std;
int Find_Ch(char* str, char ch, int top);//查找字符ch，返回其出现位置的下标，找不到则返回-1
int main()
{
	char str[5000000], res[27];
	cin >> str;
	int top = 0;
	for (int i = 0; str[i]; i++)
	{
		while (str[i + 1] && str[i] == str[i + 1]) i++; //连续一样的当一个处理
		int k = Find_Ch(res, str[i], top);
		if (k == -1) res[top++] = str[i];             //没出现过，直接进入res
		else if (res[k + 1] && res[k + 1] < res[k])   //出现过，如果已存在的那个字母后面一个比它小，则前移，并且把该字母放到最后
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