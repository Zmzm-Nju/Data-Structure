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
	int first, num;                        //�׵�ַ�ͽڵ���
	int current;
	scanf("%d%d", &first, &num);           //�����׵�ַ�ͽڵ���
	Node addr[Addr_Size];
	for (int i = 0; i < num; i++)          //�������ڴ��н�������
	{
		scanf("%d", &current);
		scanf("%d", &addr[current].value);
		scanf("%d", &addr[current].next);
	}
	current = first;
	int p = -1, q = first, r = addr[first].next;
	addr[q].next = p;//ժ��ͷ�ڵ�
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

//��̬����ת��
//Node* p = NULL, * q = head, * r = head->link;
//q->link = p;//ժ��ͷ�ڵ�
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
//}//�������ɾ������
//printf("%05d %d -1\n", head->current, head->value);
//delete head;

//��̬����ת��
//Node* item = new Node[num];            //���ڱ�������
//for (int i = 0; i < num; i++)
//	scanf("%d%d%d", &(item[i].current), &(item[i].value), &(item[i].next)); //��������
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
//}//Ѱ��ͷ�ڵ�
//for (int i = 0; i < num - 1; i++)     //��num - 1��ɨ�裬��������
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
//			}//��������
//		}
//	}
//for (int i = num - 1; i > 0; i--)
//	item[i].next = item[i - 1].current;//��ת
//item[0].next = -1;                   //��β
//for (int i = num - 1; i > 0; i--)
//	printf("%05d %d %05d\n", item[i].current, item[i].value, item[i].next);
//printf("%05d %d -1\n", item[0].current, item[0].value);
//delete[]item;

