#include<iostream>
using namespace std;
int main()
{
	char str[1001];
	char ch = '\0';
	cin >> str;
	int i = 0, n = 0;
	for (i = 0; str[i] != '\0'; i++)
	{
		ch = str[i]; n = 1;
		while (str[i + 1] && str[i] == str[i + 1])
		{
			i++; n++;
		}
		if (n == 1)
			cout << ch;
		else
			cout << n << ch;
	}
	return 0;
}