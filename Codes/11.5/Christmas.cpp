#include<iostream>
using namespace std;
struct Node
{
	int Value;
	Node* lchild;
	Node* rchild;
	Node(int val) :Value(val), lchild(NULL), rchild(NULL) {};
};
//�ݹ齨������head���ڸı�ָ��ֵ��numΪ�������ܹ������ĸ���
void Creat_Tree(Node*& head, int* Post, int* In, int num);
int main()
{
	int num = 0;
	cin >> num;
	int* Post = new int[num];
	int* In = new int[num];
	for (int i = 0; i < num; i++)
		cin >> In[i];
	for (int i = 0; i < num; i++)
		cin >> Post[i];                 //��������

	Node* head = NULL;
	Creat_Tree(head, Post, In, num);    //������

	Node** Queue = new Node * [num + 1];
	int front = 0, rear = 0, floor = 0, n = 0;    //ģ��һ�����У�n��¼���������ڵ�0�㣬������˳�������ż���㵹�������n��¼����˶�������
	printf("%d", head->Value);
	if (head->lchild != NULL)
		Queue[rear++] = head->lchild;
	if (head->rchild != NULL)
		Queue[rear++] = head->rchild;            //��Ϊ���������治���пո������ȵ�������ͷ�ڵ㣬֮�󽫿ո����������֮ǰ
	n++, floor++;
	while (n < num)
	{
		if (floor % 2 == 0)
			for (int i = rear - 1; i >= front; i--)
			{
				printf(" %d", Queue[i]->Value);
				n++;
			}
		if (floor % 2 == 1)
			for (int i = front; i < rear; i++)
			{
				printf(" %d", Queue[i]->Value);
				n++;
			}
		int m = rear - front;
		for (int i = 0; i < m; i++)
		{
			Node* p = Queue[front++];
			if (p->lchild != NULL)Queue[rear++] = p->lchild;
			if (p->rchild != NULL)Queue[rear++] = p->rchild;
		}                  //����ò�ڵ㣬������Ů�ڵ����
		floor++;           //��������
	}
	delete []Post;
	delete []In;
	return 0;
}

void Creat_Tree(Node*& head, int* Post, int* In, int num)
{
	if (num == 0)
	{
		head = NULL;
		return;
	}
	int i = 0;
	while (In[i] != Post[num - 1])i++;                          //�ҵ������������е�λ��
	Node* p = new Node(In[i]);
	head = p;
	Creat_Tree(head->lchild, Post, In, i);                       //�ݹ齨��������
	Creat_Tree(head->rchild, Post + i, In + i + 1, num - i - 1); //�ݹ齨��������
}
