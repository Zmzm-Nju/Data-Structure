#include<iostream>
using namespace std;
struct Node
{
	int value;
	Node* next;
	Node(int x, Node* n = NULL) :value(x), next(n) {};
};
Node* ReverseLink(Node* head);
void PrintLink(Node* head);
void FreeLink(Node* head);

int main()
{
	int n = 0, num;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		Node* first = new Node(num), * last = first;
		for (int j = num - 1; j > 0; j--)
		{
			Node* p = new Node(j);
			last->next = p;
			last = last->next;
			p = first;
			first = first->next;
			p->next = NULL;
			last->next = p;
			last = last->next;
		}
		first = ReverseLink(first);
		PrintLink(first);
		FreeLink(first);
	}

}
Node* ReverseLink(Node* head)
{
	Node* p = NULL, * q = head, * r = head->next;
	q->next = p;
	q->next = NULL;
	while (r)
	{
		p = q;
		q = r;
		r = r->next;
		q->next = p;
	}
	return q;
}

void PrintLink(Node* head)
{
	while (head)
	{
		cout << head->value << ' ';
		head = head->next;
	}
	cout << endl;
}
void FreeLink(Node* head)
{
	while (head)
	{
		Node* cur = head;
		head = head->next;
		delete cur;
	}
}
