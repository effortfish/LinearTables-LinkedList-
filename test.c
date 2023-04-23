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
int main()
{
	return 0;
}