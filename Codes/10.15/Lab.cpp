#include<stdio.h>
int main()
{
	int num[15] = { 14,22 };
	for (int i = 2; i < 15; i++)
	{
		num[i] = num[i - 1] + num[i - 2]/2;
	}
	printf("%d", num[10]);
}