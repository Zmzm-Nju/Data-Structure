#define _CRT_SECURE_NO_WARNINGS
struct Node 
{
	int value;
	int next;
};
#define Addr_Size 100000
#include<cstdio>
using namespace std;
int main()
{
	int first, num;                        //首地址和节点数
	int current;
	scanf("%d%d", &first, &num);           //接收首地址和节点数
	Node addr[Addr_Size];
	for (int i = 0; i < num; i++)          //在虚拟内存中建立链表
	{
		scanf("%d", &current);
		scanf("%d", &addr[current].value);
		scanf("%d", &addr[current].next);
	}
	current = first;
	int p = -1, q = first, r = addr[first].next;
	addr[q].next = p;//摘下头节点
	while (r != -1)
	{
		p = q;
		q = r;
		r = addr[r].next;
		addr[q].next = p;
	}
	first = q;
	while (addr[first].next != -1)
	{
		printf("%05d %d %05d\n", first, addr[first].value, addr[first].next);
		first = addr[first].next;
	}
	printf("%05d %d -1\n", first, addr[first].value);
	return 0;
}

//动态链表翻转：
//Node* p = NULL, * q = head, * r = head->link;
//q->link = p;//摘下头节点
//q->next = -1;
//while (r)
//{
//	p = q;
//	q = r;
//	r = r->link;
//	q->link = p;
//	q->next = p->current;
//}
//head = q;
//Node* cur = NULL;
//while (head->link != NULL)
//{
//	printf("%05d %d %05d\n", head->current, head->value, head->next);
//	cur = head; 
//	head = head->link;
//	delete cur;
//}//输出并且删除链表
//printf("%05d %d -1\n", head->current, head->value);
//delete head;

//静态链表翻转：
//Node* item = new Node[num];            //用于保存数据
//for (int i = 0; i < num; i++)
//	scanf("%d%d%d", &(item[i].current), &(item[i].value), &(item[i].next)); //接收输入
//for (int i = 0; i < num; i++)
//{
//	if (item[i].current == first)
//	{
//		if (i != 0)
//		{
//			Node temp = item[i];
//			item[i] = item[0];
//			item[0] = temp; break;
//		}
//	}
//}//寻找头节点
//for (int i = 0; i < num - 1; i++)     //做num - 1次扫描，建立链表
//	for (int j = i + 1; j < num; j++)
//	{
//		if (item[j].current == item[i].next)
//		{
//			if (j != i + 1)
//			{
//				Node temp = item[i + 1];
//				item[i + 1] = item[j];
//				item[j] = temp;
//				break;
//			}//交换次序
//		}
//	}
//for (int i = num - 1; i > 0; i--)
//	item[i].next = item[i - 1].current;//翻转
//item[0].next = -1;                   //收尾
//for (int i = num - 1; i > 0; i--)
//	printf("%05d %d %05d\n", item[i].current, item[i].value, item[i].next);
//printf("%05d %d -1\n", item[0].current, item[0].value);
//delete[]item;

