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
		Node* p = (Node*)malloc(sizeof(Node));//创建新节点
		scanf("%d", &(p->data)); 
		p->next = head;						  //head的值赋给新节点的指针成员
		head = p;							  //将p这个指针变量的值赋给指针变量head
	}
	return head;
}

Node* AppCreate(int N)
{
	Node* head = NULL, * tail = NULL;
	for (int i = 0; i < N; i++)
	{
		Node* p = (Node*)malloc(sizeof(Node)); //创建新节点
		scanf("%d", &(p->data));
		p->next = NULL;                        //给新节点的指针成员赋值
		if (head == NULL)                      //已有链表为空链表的情况
			head = p;
		else                                   //已有链表不空的情况
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
	Node* current = head;                  // current指向第一个节点
	int j = 1;
	while (j < i && current->next != NULL) //查找第i个节点
	{
		current = current->next;
		j++;
	}                                        //循环结束时，current指向第i个节点或最后一个节点（节点数不够i时）
	if (j == i)                           // current指向第i个节点
	{
		Node* p = (Node*)malloc(sizeof(Node)); //创建新节点
		scanf("%d", &p->data);
		p->next = current->next;              //让第i+1个节点链接在新节点之后
		current->next = p;                    //让新节点链接在第i个节点之后
	}
	else                                      //链表中没有第i个节点
		printf("没有节点: %d \n", i);
}

Node* DeleteNode(Node* head, int i)
{
	if (i == 1) //删除头节点
	{
		Node* current = head;  //current指向头节点
		head = head->next;     //head指向新的头节点
		free(current);         //释放删除节点的空间
	}
	else
	{
		Node* previous = head; //previous指向头节点
		int j = 1;
		while (j < i - 1 && previous->next != NULL)
		{
			previous = previous->next;
			j++;
		} //查找第i-1个节点
		if (previous->next != NULL) //链表中存在第i个节点
		{
			Node* current = previous->next;// current指向第i个节点
			previous->next = current->next;//让待删除节点的前后两个节点相链接
			free(current);                 //释放第i个节点的空间
		}
		else //链表中没有第i个节点
			printf("没有节点: %d \n", i);
	}
	return head;
}

void PrintList(Node* head)
{
	if (!head) //如果是空链表
		printf("List is empty. \n");
	else
	{
		while (head) //遍历链表，等价于while(head != NULL)
		{
			printf("%d, ", head->data);
			head = head->next;
		}
		printf("\n");
	}
}

void DeleteList(Node* head)
{
	while (head)//遍历链表
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
