#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
using namespace std;
struct Node
{
	int val;
	bool valid;
	Node* leftchild;
	Node* rightchild;
	Node() :val(0), valid(true), leftchild(NULL), rightchild(NULL) {}
};

int Visit(Node* head);             //前序遍历查找叶节点
int Leave_Num(Node* head);         //返回树当前的叶子数
int Count(Node* head, Node* node); //计算一共有多少种可能情况
void Insert(Node*& head, int val);
Node* tree_head;
int main()
{
	int y = -81;
	printf("%d", y / 2);
	/*int num = 0, val = 0;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &val);
		Insert(tree_head, val);
	}
	int Ans = Visit(tree_head);
	printf("%d\n", Ans);
	return 0;*/
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

int Visit(Node* head)
{
	if (head == NULL || head->valid == false)return 0;
	bool left = (head->leftchild == NULL) || (head->leftchild->valid == false);
	bool right = (head->rightchild == NULL) || (head->rightchild->valid == false);
	if (left && right) //碰到了叶节点
		return Count(tree_head, head);
	return Visit(head->leftchild) + Visit(head->rightchild);
}

int Count(Node* head, Node* node)
{
	int Ans = 0;
	node->valid = false;  //逻辑上删除该点
	if (Leave_Num(tree_head) <= 1) Ans = 1;
	else  Ans = Visit(tree_head);
	node->valid = true;   //将此点恢复
	return Ans;
}

int Leave_Num(Node* head)
{
	if (head == NULL || head->valid == false)return 0;
	bool left = (head->leftchild == NULL) || (head->leftchild->valid == false);
	bool right = (head->rightchild == NULL) || (head->rightchild->valid == false);
	if (left && right)return 1;
	return Leave_Num(head->leftchild) + Leave_Num(head->rightchild);
}
