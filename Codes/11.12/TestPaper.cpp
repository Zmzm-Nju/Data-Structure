#include<iostream>
using namespace std;
struct Node
{
	int val;
	Node* leftchild;
	Node* rightchild;
	Node(int v) :val(v), leftchild(NULL), rightchild(NULL) {};
};
int Size(Node* root);
int Value(Node* root);
void Visit(Node* root, double* max);
void PreOrder(Node* root, double* max);
int main()
{
	int num = 0;
	cin  >> num;
	double max = 0;

	Node* Queue[5000] = { NULL };
	int front = 0, rear = 0;            //模拟一个队列

	Node* root = new Node(num);
	Queue[rear++] = root;               //根节点放入
	
	while (cin >> num)
	{
		Node* cur = Queue[front++];
		if (num == -1)cur->leftchild = NULL;
		else
		{
			cur->leftchild = new Node(num);
			Queue[rear++] = cur->leftchild;
		}

		cin >> num;
		if (num == -1)cur->rightchild = NULL;
		else
		{
			cur->rightchild = new Node(num);
			Queue[rear++] = cur->rightchild;
		}
	}                                 //建立树
	PreOrder(root, &max);
	printf("%.5lf", max);
	return 0;
}
int Size(Node* root)
{
	if (root == NULL)return 0;
	else return 1 + Size(root->leftchild) + Size(root->rightchild);
}
int Value(Node* root)
{
	if (root == NULL)return 0;
	else return Value(root->leftchild) + Value(root->rightchild) + root->val;
}
void Visit(Node* root, double* max)
{
	double res = Value(root) * 1.0 / Size(root);
	if (res > * max)*max = res;
}
void PreOrder(Node* root, double* max)
{
	if (root == NULL)return;
	Visit(root, max);
	PreOrder(root->leftchild, max);
	PreOrder(root->rightchild, max);
}