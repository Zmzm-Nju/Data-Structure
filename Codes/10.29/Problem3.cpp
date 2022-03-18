#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	int n = 0;
	scanf("%d", &n);
	int up[1000000] = { 0 };
	int down[1000000] = { 0 };
	int res[1000000] = { 0 };
	int left = 0, right = 0, stop = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d",&left,&right);
		up[left - 1]++;
		down[right - 1]++;
		stop = right > stop ? right : stop;
	}
	int max = res[0] = up[0] - down[0];
	for (int i = 1; i < stop; i++)
	{
		res[i] = res[i-1] + up[i] - down[i];
		max = res[i] > max ? res[i] : max;
	}
	printf("%d\n",max);
	return 0;

}