#include<iostream>
using namespace std;
struct Node
{
	int first; //����ǰ������
	int last;  //���ں�������
};
int main()
{
	int n;
	cin >> n;
	Node* Queue = new Node[n];//��̬���鴢������ֵ
	for (int i = 0; i < n; i++)
	{
		cin >> Queue[i].last;
		cin >> Queue[i].first;
	}//��������
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
	}//���ҵ���һ�����ŵ���ǰ��
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
				}//��������
			}
		}
	}//��n-1�����ӣ�ÿ���ڻ�û���ӺõĽڵ���Ѱ��
	for (int i = 0; i < n; i++)
		cout << Queue[i].last << " ";//������
	delete[]Queue;
	return 0;
}