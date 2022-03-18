#include<iostream>
using namespace std;
int main()
{
	int n = 0, i = 0;
	cin >> n;
	if (n <= 2)
	{
		cout << "False";
		return 0;
	}
	int* num = new int[n];
	for (i = 0; i < n; i++)
		cin >> num[i];
	int left = num[0], right = 0;
	for (i = 1; i < n; i++)
	{
		if (num[i] < left)
			left = num[i];
		else if (num[i] > left)
		{
			right = left;
			break;
		}
	}
	if (i == n)
	{
		cout << "False";
		return 0;
	}
	int min = left;
	for (; i < n; i++)
	{
		if(num[i]>left && num[i]<right)
		{
			cout << "True";
			return 0;
		}
		else if (num[i] < left)
		{
			min = num[i];
		}
		else if (num[i] > right)
		{
			left = min;
			right = num[i];
		}
	}
	cout << "False";
	return 0;
}