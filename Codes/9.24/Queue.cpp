#include<iostream>
using namespace std;
struct Node
{
	int first; //排在前面的序号
	int last;  //排在后面的序号
};
int main()
{
	int n;
	cin >> n;
	Node* Queue = new Node[n];//动态数组储存输入值
	for (int i = 0; i < n; i++)
	{
		cin >> Queue[i].last;
		cin >> Queue[i].first;
	}//输入数据
	for (int i = 0; i < n; i++)
	{
		if (Queue[i].first == 0)
		{
			if (i != 0)
			{
				Node temp = Queue[i];
				Queue[i] = Queue[0];
				Queue[0] = temp;
			}
			break;
		}
	}//先找到第一个，放到最前面
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (Queue[j].first == Queue[i].last)
			{
				if (j != i + 1)
				{
					Node temp = Queue[i + 1];
					Queue[i + 1] = Queue[j];
					Queue[j] = temp;
					break;
				}//交换次序
			}
		}
	}//做n-1次链接，每次在还没链接好的节点中寻找
	for (int i = 0; i < n; i++)
		cout << Queue[i].last << " ";//输出结果
	delete[]Queue;
	return 0;
}