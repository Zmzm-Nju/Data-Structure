#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
using namespace std;
struct Node
{
	int val;
	Node* leftchild;
	Node* rightchild;
	Node() :val(0), leftchild(NULL), rightchild(NULL) {}
};
int Ans;
int Abs(int n);
int Max(int a, int b);
int Height(Node* head);
void Visit(Node* head);
void Insert(Node* &head, int val);
int main()
{
	int num = 0, val = 0;
	scanf("%d", &num);
	Node* head = NULL;
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &val);
		Insert(head, val);
	}
	Visit(head);
	printf("%d\n", Ans);
	return 0;
}
void Insert(Node*& head, int val)
{
	if (head == NULL)
	{
		Node* p = new Node;
		p->val = val;
		head = p;
	}
	else if (head->val < val)
		Insert(head->rightchild, val);
	else Insert(head->leftchild, val);
}
void Visit(Node* head)
{
	if (head == NULL)return;
	int n = Abs(Height(head->rightchild) - Height(head->leftchild));
	if (n > Ans)Ans = n;
	Visit(head->leftchild);
	Visit(head->rightchild);
}
int Abs(int n)
{
	return n >= 0 ? n : -n;
}
int Max(int a, int b)
{
	return a > b ? a : b;
}
int Height(Node* head)
{
	if (head == NULL)return 0;
	else return 1 + Max(Height(head->leftchild), Height(head->rightchild));
}