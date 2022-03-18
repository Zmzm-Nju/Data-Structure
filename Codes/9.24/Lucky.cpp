#include<iostream>
using namespace std;
#define max 35000
void Delete_Num(int* A, int n, int num);//删除数组中第n个元素
int main()
{
	int number = max;//用于记录数组中剩下的人数
	int People[max];
	int Lucky [3000] = { 0 };
	for (int i = 0; i < number; i++)
		People[i] = i + 2;       //初始化每个人的编号
	for (int i = 0; i < number; i++)
	{
		for (int j = i + People[i]; j < number; j = j + People[i])
		{
			Delete_Num(People, j + 1, number);
			j--; number--;
		}	
	}
	for (int i = 0, j = 0; i < 3000 && j < number; i++, j++)
		Lucky[i] = People[j];//查找幸运人
	int n = 0;
	while (cin >> n, n != 0)
		cout << Lucky[n - 1] << endl;
	return 0;
}

void Delete_Num(int* A, int n,int num)
{
	for (int i = n ; i < num ; i++)
		A[i-1] = A[i];
}