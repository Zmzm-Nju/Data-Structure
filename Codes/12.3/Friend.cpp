#define _CRT_SECURE_NO_WARNINGS
//#include<cmath>
//#include<cstdio>
//using namespace std;
//int Is_Prime(int n);
//class Set
//{
//public:
//	Set(int n)
//	{
//		set_elements = new int[n];
//		for (int i = 0; i < n; i++)
//			set_elements[i] = -1;
//		set_size = n;
//	}
//	void Union(int i, int j)
//	{
//		int m = Find_Parent(i), n = Find_Parent(j);
//		if (m == n)return;
//		else {
//			set_elements[m] = set_elements[m] + set_elements[n];
//			set_elements[n] = m;
//		}
//	}
//	int Find_Parent(int i)
//	{
//		while (set_elements[i] >= 0)
//			i = set_elements[i];
//		return i;
//	}
//	int  Biggest()
//	{
//		int res = 0;
//		for (int i = 0; i < set_size; i++)
//			if (set_elements[i] < 0 && (-set_elements[i])>res)res = -set_elements[i];
//		return res + 1;
//	}
//	~Set() { delete[]set_elements; }
//	int set_size;
//	int* set_elements;
//};
//int main()
//{
//	int num = 0, max = 0, res = 0;
//	scanf("%d", &num);
//	Set Friend(num);
//	int* People = new int[num];
//	for (int i = 0; i < num; i++)
//	{
//		scanf("%d", &People[i]);
//		max = max > People[i] ? max : People[i];
//	}
//	int* seat = new int[max];
//	for (int i = 0; i < max; i++)
//		seat[i] = -1;
//	for (int i = 0; i < num; i++)
//		seat[People[i]] = i;
//
//	for (int i = 2; i < max; i++)
//	{
//		if (!Is_Prime(i))continue;
//		int temp = -1;
//		if (seat[i] >= 0)temp = seat[i];
//		for (int j = 2 * i; j < max; j += i)
//			if (seat[j] >= 0)
//			{
//				if (temp < 0)temp = seat[j];
//				else Friend.Union(temp, seat[j]);
//			}
//	}
//	printf("%d\n", Friend.Biggest());
//	return 0;
//}
//int Is_Prime(int n)
//{
//	if (n == 1) return 0;
//	for (int i = 2; i * i <= n; i++)
//		if (n % i == 0) return 0;
//	return 1;
//}

#include<stdio.h>
#define Size 100
int* count(char* ch_p);
int Is_Vowel(char ch);
int main()
{
	int i = 0, a = 0;
	char str[Size] = { '\0' };
	scanf("%s", str);
	while (str[i] != '\0')
		a = *(count(&str[i++]));
	printf("%s\n%d\n", str, a);
	return 0;
}
int* count(char* ch_p)
{
	static int num = 0;
	if ((*ch_p) >= 'A' && (*ch_p) <= 'Z')
		*ch_p = *ch_p + 32;
	if (Is_Vowel(*ch_p))
		num++;
	return &num;
}
int Is_Vowel(char ch)
{
	switch (ch)
	{
		case 'a':
		case 'e' :
		case 'i' :
		case 'o' :
		case 'u': return 1;
		default: return 0;
	}
}