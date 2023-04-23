#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>

//定义链表
typedef struct Node
{
	int data;
	struct Node* next;
}Node;

typedef struct Node* LinkList;      //是一个类型

//初始化链表
bool InitList(LinkList l)
{
	l = (Node*)malloc(sizeof(Node));
	l->next = NULL;
	return true;
}

//销毁链表
bool DestroyList(LinkList l)
{
	Node* a, * b;
	a = l->next;       //让头节点指向第一个节点
	while (a)
	{
		b = a->next;
		free(a);
		a = b;
	}
	free(l);
	return true;
}

//返回链表结点个数
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

//根据序号返回其中的值
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

//通过值找对应的节点
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