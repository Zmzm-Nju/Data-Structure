#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	Node* next;
};

Node* InsCreate(int N)
{
	Node* head = NULL;
	for (int i = 0; i < N; i++)
	{
		Node* p = (Node*)malloc(sizeof(Node));//�����½ڵ�
		scanf("%d", &(p->data)); 
		p->next = head;						  //head��ֵ�����½ڵ��ָ���Ա
		head = p;							  //��p���ָ�������ֵ����ָ�����head
	}
	return head;
}

Node* AppCreate(int N)
{
	Node* head = NULL, * tail = NULL;
	for (int i = 0; i < N; i++)
	{
		Node* p = (Node*)malloc(sizeof(Node)); //�����½ڵ�
		scanf("%d", &(p->data));
		p->next = NULL;                        //���½ڵ��ָ���Ա��ֵ
		if (head == NULL)                      //��������Ϊ����������
			head = p;
		else                                   //���������յ����
			tail->next = p;
		tail = p;
	}
	return head;
}

Node* SearchNode(Node* head, int val)
{
	while (head)
		if (head->data == val)return head;
		else head = head->next;
	return NULL;
}

void InsertNode(Node* head, int i)
{
	Node* current = head;                  // currentָ���һ���ڵ�
	int j = 1;
	while (j < i && current->next != NULL) //���ҵ�i���ڵ�
	{
		current = current->next;
		j++;
	}                                        //ѭ������ʱ��currentָ���i���ڵ�����һ���ڵ㣨�ڵ�������iʱ��
	if (j == i)                           // currentָ���i���ڵ�
	{
		Node* p = (Node*)malloc(sizeof(Node)); //�����½ڵ�
		scanf("%d", &p->data);
		p->next = current->next;              //�õ�i+1���ڵ��������½ڵ�֮��
		current->next = p;                    //���½ڵ������ڵ�i���ڵ�֮��
	}
	else                                      //������û�е�i���ڵ�
		printf("û�нڵ�: %d \n", i);
}

Node* DeleteNode(Node* head, int i)
{
	if (i == 1) //ɾ��ͷ�ڵ�
	{
		Node* current = head;  //currentָ��ͷ�ڵ�
		head = head->next;     //headָ���µ�ͷ�ڵ�
		free(current);         //�ͷ�ɾ���ڵ�Ŀռ�
	}
	else
	{
		Node* previous = head; //previousָ��ͷ�ڵ�
		int j = 1;
		while (j < i - 1 && previous->next != NULL)
		{
			previous = previous->next;
			j++;
		} //���ҵ�i-1���ڵ�
		if (previous->next != NULL) //�����д��ڵ�i���ڵ�
		{
			Node* current = previous->next;// currentָ���i���ڵ�
			previous->next = current->next;//�ô�ɾ���ڵ��ǰ�������ڵ�������
			free(current);                 //�ͷŵ�i���ڵ�Ŀռ�
		}
		else //������û�е�i���ڵ�
			printf("û�нڵ�: %d \n", i);
	}
	return head;
}

void PrintList(Node* head)
{
	if (!head) //����ǿ�����
		printf("List is empty. \n");
	else
	{
		while (head) //���������ȼ���while(head != NULL)
		{
			printf("%d, ", head->data);
			head = head->next;
		}
		printf("\n");
	}
}

void DeleteList(Node* head)
{
	while (head)//��������
	{
		Node* current = head;
		head = head->next;
		free(current);
	}
}

Node* ReverseList(Node* head)
{
	if (!head || !head->next)return head;
	Node* p = NULL, * q = head, * r = head->next;
	while (r)
	{
		q->next = p;
		p = q, q = r, r = r->next;
	}
	q->next = p;
	return q;
}
