#include<iostream>
using namespace std;
struct Node
{
	int val;
	Node* leftchild;
	Node* rightchild;
	Node(int v) :val(v), leftchild(NULL), rightchild(NULL) {};
};
Node* Find_Parent(Node* tar, Node* root);
bool Search_Node(Node* tar, Node** List, int n);
int main()
{
	int p = 0, q = 0, n = 0, num = 0;
	cin >> p >> q >> n >> num;

	Node** Queue = new Node * [n];
	int front = 0, rear = 0;            //模拟一个队列

	Node* root = new Node(num);
	Queue[rear++] = root;               //根节点放入
	Node* p_node = NULL, * q_node = NULL;

	for (int i = 1; i < n; i += 2)
	{
		Node* cur = Queue[front++];
		cin >> num; 
		if (num == -1)cur->leftchild = NULL;
		else 
		{
			cur->leftchild = new Node(num);
			Queue[rear++] = cur->leftchild;
			if (num == p)p_node = cur->leftchild;
			if (num == q)q_node = cur->leftchild;
		}

		cin >> num; 
		if (num == -1)cur->rightchild = NULL;
		else 
		{
			cur->rightchild = new Node(num);
			Queue[rear++] = cur->rightchild;
			if (num == p)p_node = cur->rightchild;
			if (num == q)q_node = cur->rightchild;
		}
	}                                //建立树并且找到p、q的节点

	Node** List_p = new Node * [n];
	Node** List_q = new Node * [n];
	List_p[0] = p_node; List_q[0] = q_node;
	int i = 0, j = 0;
	for (i = 0; List_p[i] != root; i++)
		List_p[i + 1] = Find_Parent(List_p[i], root);
	for (j = 0; List_q[j] != root; j++)
		List_q[j + 1] = Find_Parent(List_q[j], root);         //查找p和q的所有祖先节点

	for (int k = 0; k <= i; k++)
	{
		if (Search_Node(List_p[k], List_q, j))
		{
			cout << List_p[k]->val << endl;
			break;
		}
	}                                                      //找到p和q的所有祖先节点中，第一个相同的
	return 0;
}

Node* Find_Parent(Node* tar, Node* root)
{
	if (tar == root) return NULL;   //此分支只有外部调用时才会触发
	if (root == NULL) return NULL;
	if (root->leftchild == tar || root->rightchild == tar)
		return root;
	if (Find_Parent(tar, root->leftchild) != NULL)return Find_Parent(tar, root->leftchild);
	else return Find_Parent(tar, root->rightchild);
}
bool Search_Node(Node* tar, Node** List, int n)
{
	for (int i = 0; i <= n; i++)
	{
		if (tar == List[i])
			return true;
	}
	return false;
}