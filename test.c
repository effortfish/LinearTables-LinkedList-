#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>

//��������
typedef struct Node
{
	int data;
	struct Node* next;
}Node;

typedef struct Node* LinkList;      //��һ������

//��ʼ������
bool InitList(LinkList l)
{
	l = (Node*)malloc(sizeof(Node));
	l->next = NULL;
	return true;
}

//��������
bool DestroyList(LinkList l)
{
	Node* a, * b;
	a = l->next;       //��ͷ�ڵ�ָ���һ���ڵ�
	while (a)
	{
		b = a->next;
		free(a);
		a = b;
	}
	free(l);
	return true;
}

//�������������
int ListLength(LinkList l)
{
	Node* p;
	p = l->next;
	int i = 1;
	while (p)
	{
		p = p->next;
		i++;
	}
	return i;
}

//������ŷ������е�ֵ
int* getElem(LinkList l,int n)
{
	Node* p;
	p = l->next;
	int j = 1;
	while (p && j < n)
	{
		p = p->next;
		j++;
	}
	return p->data;
}

//ͨ��ֵ�Ҷ�Ӧ�Ľڵ�
Node* LocateElem(LinkList l, int x)
{
	Node* p;
	p = l->next;
	while (p)
	{
		if (p->data == x)
			break;
		p = p->next;
	}
	return p;
}

//�ж��Ƿ��к��
int* NextElem(LinkList l, int data, int* nextData)
{
	Node* p;
	p = l->next;
	while (p)
	{
		if (p->data == data && p->next != NULL)
		{
			nextData = p->next;
			return nextData;
		}
		p = p->next;
	}
}

//�ж��Ƿ���ǰ��
bool priorElem(LinkList l, int data)
{
	Node* p,* r;
	p = l->next;
	r = l;      //rΪp��ǰ��
	if (p->data == data)
	{
		return false;
	}
	return true;
}

//�ڵ�i��ǰ�����µ�Ԫ��       û�п��ǳ��ִ�������
bool Insert(LinkList l, int i, int data)
{
	Node* p, * n;
	p = l->next;
	n = (Node*)malloc(sizeof(Node));
	if (i == 1)
	{
		n->data = data;
		n->next = p;
		l->next = n;
		return true;
	}
	if(i != 1)
	{
		int j = 1;
		for (j = 1; j < i; j++)
		{
			p = p->next;
		}
		n->data = data;
		n->next = p->next;
		p->next = n;
		return true;
	}
}

//ɾ����i������Ԫ��
bool deleteList(LinkList l, int i)
{
	Node* p, * n;
	p = l->next;
	if (i == 1)
	{
		l->next = p->next;
		free(p);
		return true;
	}
	if (i != 1)
	{
		int j = 1;
		for (j = 1; j < i; j++)
		{
			p = p->next;
		}
		n = p->next;
		p->next = n->next;
		free(n);
		return true;
	}
}

//��������
bool traverseList(LinkList l)
{
	Node* p;
	p = l->next;
	while (p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	return true;
}

//��������ͷ������ͷ�巨��
void CreateListHead(LinkList l, int n)
{
	Node* p;
	int a = 0;
	InitList(l);
	for (int i = 0; i < n; i++)
	{
		p = (Node*)malloc(sizeof(Node));
		scanf("%d", &a);
		p->data = a;
		p->next = l->next;
		l->next = p;
	}
}

//��������ͷ������β�巨��
void CreateListTail(LinkList l, int x)
{
	Node* p, * n;
	InitList(l);
	n = l;       //ָ��β����ָ��
	for (int i = 0; i < x; i++)
	{
		p = (Node*)malloc(sizeof(Node));
		scanf("%d", &(p->data));
		n->next = p;
		n = p;
	}
	n->next = NULL;
}

int main()
{
	return 0;
}