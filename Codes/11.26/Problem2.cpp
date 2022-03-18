#include<iostream>
using namespace std;
struct Node
{
	int val;
	Node* leftchild;
	Node* rightchild;
	Node(int v) :val(v), leftchild(NULL), rightchild(NULL) {};
};
bool Tree_Equal(Node* root1, Node* root2);
int main()
{
	int n1 = 0, n2 = 0, num = 0;

	cin >> n1 >> num;
	Node** Queue = new Node * [n1];
	int front = 0, rear = 0;            //模拟一个队列

	Node* root1 = new Node(num), * cur = NULL;
	Queue[rear++] = root1;              //根节点放入
	int left = 1;

	for (int i = 1; i < n1; i++)
	{
		cin >> num;
		if(left)
		{
			cur = Queue[front++];
			if (num == -1)cur->leftchild = NULL;
			else
			{
				cur->leftchild = new Node(num);
				Queue[rear++] = cur->leftchild;
			}
			left = 0;
		}
		else
		{
			if (num == -1)cur->rightchild = NULL;
			else
			{
				cur->rightchild = new Node(num);
				Queue[rear++] = cur->rightchild;
			}
			left = 1;
		}
	}

	cin >> n2 >> num;
	front = 0, rear = 0, left = 1;            //模拟一个队列

	Node* root2 = new Node(num);
	Queue[rear++] = root2;               //根节点放入

	for (int i = 1; i < n2; i++)
	{
		cin >> num;
		if (left)
		{
			cur = Queue[front++];
			if (num == -1)cur->leftchild = NULL;
			else
			{
				cur->leftchild = new Node(num);
				Queue[rear++] = cur->leftchild;
			}
			left = 0;
		}
		else
		{
			if (num == -1)cur->rightchild = NULL;
			else
			{
				cur->rightchild = new Node(num);
				Queue[rear++] = cur->rightchild;
			}
			left = 1;
		}
	}

	if (Tree_Equal(root1, root2))cout << "True" << endl;
	else cout << "False" << endl;
}

bool Tree_Equal(Node* root1, Node* root2)
{
	if (root1 == NULL && root2 == NULL)return true;
	else if ((root1 == NULL && root2 != NULL) || (root2 == NULL && root1 != NULL))return false;
	else return  root1->val == root2->val &&
		( (Tree_Equal(root1->leftchild, root2->leftchild) && Tree_Equal(root1->rightchild, root2->rightchild)) ||
		  (Tree_Equal(root1->leftchild, root2->rightchild) && Tree_Equal(root1->rightchild, root2->leftchild))  );
}