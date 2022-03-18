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
	int num;         //字母出现次数
	char ch;         //字母
	char code[10];   //字母对应编码	
};
int Find_Letter(char ch, Letter* List, int n);
void Sort(Node** Array, int n);
void Code(Node* root, Letter* List, int n);//从哈夫曼树给字母编码
int main()
{
	char str[10000];
	cin >> str;
	Letter List[26];
	int n = 0, res = 0;                   //n记录一共有多少个字母
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
	}                                    //处理字符串
	Node** Huffman = new Node * [n];
	for (int i = 0; i < n; i++)
		Huffman[i] = new Node(List[i].num, List[i].ch);
	Sort(Huffman, n);
	for (int i = 0; i < n - 1; i++)      //建立Huffman树，做n-1次
	{
		Node* p = new Node(Huffman[0]->num + Huffman[1]->num, '\0');//挑选最小的两个节点，合并成一个
		p->leftchild = Huffman[0];
		p->rightchild = Huffman[1];
		Huffman[0]->parent = p;
		Huffman[1]->parent = p;         //改变父子指针
		Huffman[0] = p;
		Huffman[1] = Huffman[n - 1 - i];//将新节点放在数组最前面，同时把最后一个节点前移
		Sort(Huffman, n - i - 1);       //排序
	}
	Node* root = Huffman[0];            //树的根节点
	Code(root, List, n);                //编码
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
	else if (root->parent == NULL) root->code[0] = '\0';  //根节点为空串
	else if (root == root->parent->leftchild)             //往左编0
	{
		strcpy(root->code, root->parent->code);
		strcat(root->code, "0");
	}
	else if (root == root->parent->rightchild)            //往右编1
	{
		strcpy(root->code, root->parent->code);
		strcat(root->code, "1");
	}
	if (root->ch != '\0')                                 //如果是字母，编码储存到List中
	{
		int find = Find_Letter(root->ch, List, n);
		strcpy(List[find].code, root->code);
	}
	Code(root->leftchild, List, n);
	Code(root->rightchild, List, n);                     //递归编码
}