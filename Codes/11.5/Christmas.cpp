#include<iostream>
using namespace std;
struct Node
{
	int Value;
	Node* lchild;
	Node* rchild;
	Node(int val) :Value(val), lchild(NULL), rchild(NULL) {};
};
//递归建立树，head用于改变指针值，num为该子树总共的数的个数
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
		cin >> Post[i];                 //数据输入

	Node* head = NULL;
	Creat_Tree(head, Post, In, num);    //建立树

	Node** Queue = new Node * [num + 1];
	int front = 0, rear = 0, floor = 0, n = 0;    //模拟一个队列，n记录层数，根在第0层，奇数层顺序输出，偶数层倒序输出，n记录输出了多少数字
	printf("%d", head->Value);
	if (head->lchild != NULL)
		Queue[rear++] = head->lchild;
	if (head->rchild != NULL)
		Queue[rear++] = head->rchild;            //因为最后输出后面不能有空格，所以先单独处理头节点，之后将空格输出在数字之前
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
		}                  //处理该层节点，令其子女节点入队
		floor++;           //层数递增
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
	while (In[i] != Post[num - 1])i++;                          //找到根在中序表达中的位置
	Node* p = new Node(In[i]);
	head = p;
	Creat_Tree(head->lchild, Post, In, i);                       //递归建立左子树
	Creat_Tree(head->rchild, Post + i, In + i + 1, num - i - 1); //递归建立右子树
}
