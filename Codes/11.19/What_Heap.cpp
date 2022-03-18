#include<iostream>
using namespace std;
int  Height(int sz);
int  Pow(int m, int n);
void What_Heap(int* heap, int sz);
int main()
{
	int size = 0, height = 0, leaf = 0, top_leaf = 0;
	cin >> size;
	int* heap = new int[size];
	for (int i = 0; i < size; i++)
		cin >> heap[i];
	height = Height(size);
	top_leaf = size - Pow(2, height - 1) + 1;                  //最底层的叶子数
	leaf = top_leaf + Pow(2, height - 2) - (top_leaf + 1) / 2; //总共的叶子数
	int* Stack = new int[height]; int top = -1;                //模拟一个栈
	for (int i = size - top_leaf - 1; i >= size - leaf; i--)
	{
		for (int j = i; j > 0; j = (j - 1) / 2)
			Stack[++top] = heap[j];
		cout << heap[0] << ' ';
		while (top > 0)
			cout << Stack[top--] << ' ';
		cout << Stack[top--] << endl;
	}
	for (int i = size - 1; i >= size - top_leaf; i--)
	{
		for (int j = i; j > 0; j = (j - 1) / 2)
			Stack[++top] = heap[j];
		cout << heap[0] << ' ';
		while (top > 0)
			cout << Stack[top--] << ' ';
		cout << Stack[top--] << endl;
	}
	What_Heap(heap, size);
	return 0;
}
int Height(int sz)
{
	int i;
	for (i = 0; Pow(2, i) - 1 < sz; i++);
	return i;
}
int  Pow(int m, int n)
{
	int res = 1;
	for (int i = 0; i < n; i++)
		res *= m;
	return res;
}
void What_Heap(int* heap, int sz)
{
	bool max = true, min = true;
	for (int i = 0; i < sz; i++)
	{
		int left = 2 * i + 1, right = 2 * i + 2;
		if (left < sz - 1 && heap[i] < heap[left])max = false; 
		if (left < sz - 1 && heap[i] > heap[left])min = false;
		if (right < sz - 1 && heap[i] < heap[right])max = false;
		if (right < sz - 1 && heap[i] > heap[right])min = false;
		if (!max && !min)break;
	}
	if (max) cout << "Max Heap" << endl;
	else if (min) cout << "Min Heap" << endl;
	else cout << "Not Heap" << endl;
}