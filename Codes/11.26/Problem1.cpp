#include<cstdio>
#include<iostream>
using namespace std;
bool Is_HuiWen(int n);
bool Is_Binary_HuiWen(int n);
int main()
{
	int num = 0;
	scanf("%d", &num);
	for (int i = num+1; i < 10e6; i++)
	{
		if (Is_HuiWen(i))
		{
			if (Is_Binary_HuiWen(i))
			{
				printf("%d\n", i);
				break;
			}
		}
	}
	return 0;
}
bool Is_HuiWen(int n)
{
	int a = 0, b = n;
	do{
		a = a * 10 + n % 10;
	} while (n /= 10);
	return a == b;
}
bool Is_Binary_HuiWen(int n)
{
	char str[50];
	int i = 0;
	do {
		str[i++] = n % 2 + '0';
	} while (n /= 2);
	str[i] = '\0';
	for (int j = 0, k = i - 1; j <= k; j++, k--)
	{
		if (str[j] != str[k])return false;
	}
	return true;
}