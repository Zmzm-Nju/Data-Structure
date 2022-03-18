#include<iostream>
using namespace std;
int my_strlen(char* str1);
bool my_strncmp(char* str1, char* str2, int n);
int main()
{
	char str[100000];
	char ch[1000];
	bool find = false;
	cin >> str >> ch;
	int len = my_strlen(ch);
	for (int i = 0; str[i]; i++)
	{
		if (my_strncmp(str + i, ch, len))
		{
			printf("%d ", i);
			find = true;
		}
	}
	if (!find) printf("%d", -1);
	return 0;
}
int my_strlen(char* str1)
{
	int i = 0;
	while (str1[i]) i++;
	return i;
}
bool my_strncmp(char* str1, char* str2, int n)
{
	int i = 0;
	for (; i < n && str1[i] && str2[i]; i++)
		if (str1[i] != str2[i])return false;
	if (i == n) return true;
	return false;
}