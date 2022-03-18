#include<iostream>
using namespace std;
struct Node
{
	int Value;
	Node* lchild;
	Node* rchild;
	Node(int val) :Value(val), lchild(NULL), rchild(NULL) {};
};
void Creat_Tree(Node* & head);
bool Find_Pace(Node* head, int value,int pace);
int main()
{
	int pace = 0, value = 0;
	Node* head = NULL;
	while (cin >> pace)
	{
		Creat_Tree(head);
		bool find = Find_Pace(head,0,pace);
		if (find) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}
void Creat_Tree(Node*& head)
{
	int value = 0;
	cin >> value;
	if (value == -1) head = NULL;
	else 
	{
		Node* p = new Node(value);
		head = p;
		Creat_Tree(head->lchild);
		Creat_Tree(head->rchild);
	}
}
bool Find_Pace(Node* head, int value, int pace)
{
	if (head == NULL) return false;                
	if (head->Value + value == pace && !head->lchild && !head->rchild)return true;
	else return Find_Pace(head->lchild, head->Value + value, pace) || Find_Pace(head->rchild, head->Value + value, pace);
}
