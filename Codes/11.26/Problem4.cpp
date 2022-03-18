#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;
struct Node
{
	int val;
	Node* leftchild;
	Node* rightchild;
	Node(int v) :val(v), leftchild(NULL), rightchild(NULL) {};
};
bool Check(Node* root);
int Adjust(Node* root);
int Size(Node* root);
int Weight(Node* root);
int main()
{
	int n, num = 0;

	cin >> n >> num;
	Node** Queue = new Node * [n];
	int front = 0, rear = 0;            //模拟一个队列

	Node* root = new Node(num), * cur = NULL;
	Queue[rear++] = root;              //根节点放入
	int left = 1;

	for (int i = 1; i < n; i++)
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
	printf("%d", Adjust(root));
	return 0;
}
bool Check(Node* root)
{
	if (root == NULL)return true;
	if (root->val != 1)return false;
	else return Check(root->leftchild) && Check(root->rightchild);
}
int Adjust(Node* root)
{
	if (root == NULL || (root->leftchild == NULL && root->rightchild == NULL))return 0;
	else if (root->leftchild == NULL)
	{
		int right = Weight(root->rightchild) - Size(root->rightchild);
		root->rightchild->val -= right;
		return (root->val <= 0 ? 1 - root->val : root->val - 1) + Adjust(root->rightchild);
	}
	else if (root->rightchild == NULL)
	{
		int left = Weight(root->leftchild) - Size(root->leftchild);
		root->leftchild->val -= left;
		return (root->val <= 0 ? 1 - root->val : root->val - 1) + Adjust(root->leftchild);
	}
	else 
	{
		int left = Weight(root->leftchild) - Size(root->leftchild);
		int right = Weight(root->rightchild) - Size(root->rightchild);
		if (left >= 0 && right >= 0)
		{
			root->leftchild->val -= left;
			root->rightchild->val -= right;
			return 1 - root->val + Adjust(root->leftchild) + Adjust(root->rightchild);
		}
		if (left <= 0 && right <= 0)
		{
			root->leftchild->val -= left;
			root->rightchild->val -= right;
			return root->val - 1 + Adjust(root->leftchild) + Adjust(root->rightchild);
		}
		else if (left <= 0 && right >= 0)
		{
			root->leftchild->val -= left;
			root->rightchild->val -= right;
			if (root->val <= 0)
				return (1 - root->val) + 2 * (right + root->val - 1) + Adjust(root->leftchild) + Adjust(root->rightchild);
			else
				return root->val - 1 + 2 * right + Adjust(root->leftchild) + Adjust(root->rightchild);
		}
		else if (left >= 0 && right <= 0)
		{
			root->leftchild->val -= left;
			root->rightchild->val -= right;
			if (root->val <= 0)
				return  (1 - root->val) + 2 * (left + root->val - 1) + Adjust(root->leftchild) + Adjust(root->rightchild);
			else
				return root->val - 1 + 2 * left + Adjust(root->leftchild) + Adjust(root->rightchild);
		}
	}
}
int Size(Node* root)
{
	if (root == NULL)return 0;
	else return 1 + Size(root->leftchild) + Size(root->rightchild);
}
int Weight(Node* root)
{
	if (root == NULL)return 0;
	else return root->val + Weight(root->leftchild) + Weight(root->rightchild);
}