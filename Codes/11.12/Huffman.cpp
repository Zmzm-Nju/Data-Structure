#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
struct Node
{
	int num;
	char ch;
	char code[10];
	Node* leftchild;
	Node* rightchild;
	Node* parent;
	Node(int n, char c) :num(n), ch(c), code("\0"), leftchild(NULL), rightchild(NULL), parent(NULL) {};
};
struct Letter
{
	int num;         //��ĸ���ִ���
	char ch;         //��ĸ
	char code[10];   //��ĸ��Ӧ����	
};
int Find_Letter(char ch, Letter* List, int n);
void Sort(Node** Array, int n);
void Code(Node* root, Letter* List, int n);//�ӹ�����������ĸ����
int main()
{
	char str[10000];
	cin >> str;
	Letter List[26];
	int n = 0, res = 0;                   //n��¼һ���ж��ٸ���ĸ
	for (int i = 0; str[i]; i++)
	{
		int find = Find_Letter(str[i], List, n);
		if (find == -1)
		{
			List[n].ch = str[i];
			List[n].num = 1;
			n++;
		}
		else List[find].num++;
	}                                    //�����ַ���
	Node** Huffman = new Node * [n];
	for (int i = 0; i < n; i++)
		Huffman[i] = new Node(List[i].num, List[i].ch);
	Sort(Huffman, n);
	for (int i = 0; i < n - 1; i++)      //����Huffman������n-1��
	{
		Node* p = new Node(Huffman[0]->num + Huffman[1]->num, '\0');//��ѡ��С�������ڵ㣬�ϲ���һ��
		p->leftchild = Huffman[0];
		p->rightchild = Huffman[1];
		Huffman[0]->parent = p;
		Huffman[1]->parent = p;         //�ı丸��ָ��
		Huffman[0] = p;
		Huffman[1] = Huffman[n - 1 - i];//���½ڵ����������ǰ�棬ͬʱ�����һ���ڵ�ǰ��
		Sort(Huffman, n - i - 1);       //����
	}
	Node* root = Huffman[0];            //���ĸ��ڵ�
	Code(root, List, n);                //����
	for (int i = 0; str[i]; i++)
	{
		int find = Find_Letter(str[i], List, n);
		res += strlen(List[find].code);
	}
	cout << res << endl;
	return 0;
}
int Find_Letter(char ch, Letter* List, int n)
{
	for (int i = 0; i < n; i++)
		if (ch == List[i].ch) return i;
	return -1;
}
void Sort(Node** Array, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (Array[i]->num > Array[j]->num)
			{
				Node* tmp = Array[i];
				Array[i] = Array[j];
				Array[j] = tmp;
			}
		}
	}
}
void Code(Node* root, Letter* List, int n)
{
	if (root == NULL)return;
	else if (root->parent == NULL) root->code[0] = '\0';  //���ڵ�Ϊ�մ�
	else if (root == root->parent->leftchild)             //�����0
	{
		strcpy(root->code, root->parent->code);
		strcat(root->code, "0");
	}
	else if (root == root->parent->rightchild)            //���ұ�1
	{
		strcpy(root->code, root->parent->code);
		strcat(root->code, "1");
	}
	if (root->ch != '\0')                                 //�������ĸ�����봢�浽List��
	{
		int find = Find_Letter(root->ch, List, n);
		strcpy(List[find].code, root->code);
	}
	Code(root->leftchild, List, n);
	Code(root->rightchild, List, n);                     //�ݹ����
}