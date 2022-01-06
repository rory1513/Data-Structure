#include<iostream>
#pragma once
#include "单向链表.h"
using namespace std;
typedef int ElemType;

//初始化链表
bool InitList(LinkList& L)
{
	L = new Lnode;//堆区开辟一个头结点,结点的数据类型为Londa
	L->next = nullptr;// 空表，也就是说头结点的指针指向为空
	return true;
}//InitList
//头插法创建单链表
void CreatListHead(LinkList& L, const size_t n)
{
	for (unsigned int i = 0; i<n;i++)
	{
		Lnode* p = new Lnode;
		cout<<"请输入内容" << endl;
		cin >> p->data;
		p->next = L->next;
		L->next = p;
	}
}
//尾插法创建单向链表
void CreatListTail(LinkList& L, const size_t n)
{
	Lnode* r = L;
	for (unsigned int i = 0; i < n; i++)
	{
		Lnode* p = new Lnode;
		cin >> p->data;
		p->next = r->next;
		r->next = p;
		r = r->next;
	}
}//CreateListTail

//判断链表是否为空
bool IsEmpty(const LinkList& L) 
{
	if (L->next)
	{
		return false;
	}
	else
	{
		return true;
	}

}//IsEmpty
//摧毁链表
bool DestroyList(LinkList& L)
{
	if (IsEmpty(L))
	{
		cerr << "empty List!" << endl;
		return false;
	}
	while (L)//链表还未到尾端
	{
		auto temp = L->next;//将头指针指向下一个结点
		delete L;
		L = temp;
	}
	return true;
}//DestroyList
//统计链表长度
size_t GetLength(const LinkList &L)
{
	Lnode* p;
	p = L->next;
	size_t cnt = 0;
	while (p)
	{
		++cnt;
		p = p->next;
	}
	return cnt;
}//GetLength

//去链表中的第i个元素的值
bool GetElem(const LinkList& L, const int& i, ElemType& e)
{
	if (i < 0)
	{
		cerr << "out of range" << endl;
		return false;
	}
	Lnode* p = L->next;
	for (int j = 1; j < i+1; j++)
	{
		p = p->next;
		if (!p)
		{
			cerr << "out of range" << endl;
			return false;//如果此时p为空，意味着已经到达链表尾端，停止循环
		}
	}
	e = p->data;
	return true; 
}//GetElem
//按值查找链表
size_t LocateElem(LinkList& L, ElemType& e)
{
	Lnode* p = L->next;
	size_t cnt = 1;
	while (p)
	{
		if (p->data == e)
		{
			return cnt;
		}
		++cnt;
		p = p->next;
	}
	cerr << "not found" << endl;
	return 0;
}//按值查找链表
//在链表中插入元素
bool InserList(LinkList &L, const int &i, const ElemType &e) 
{

	Lnode *p = L;
	int j = 0;
	while (p&&j<i-1)
	{
		p = p->next;
		++j;
	}
	//异常判断
	if (!p || i < 0)
	{
		cerr << "out of range" << endl;
		return false;
	}
	LinkList insert = new Lnode;
	insert->data = e;
	insert->next = p->next;
	p->next = insert;
	return 0;
}//插入元素

void testLonda()
{
	LinkList L;
	InitList(L);
	//CreatListHead(L,1);//头插法
	CreatListTail(L, 3);//尾插法
	//bool b = IsEmpty(L);//判空操作
	//bool a= DestroyList(L);//摧毁链表
	//size_t a = GetLength(L);//求链表长度
	/* {int e, i;
	i = 1;
	GetElem(L, i, e);
	cout << e << endl;
	}*///取链表中第i个元素的值
	/* {
		int e= 5;
		size_t a = LocateElem(L, e);
		cout<<a << endl;
	}*///按值查找链表
	{
		int i = 2;
		int e = 9;
		InserList(L,2, e);
		Lnode* p = L;
		while (p != NULL)
		{
			cout << p->data << endl;
			p = p->next;
		}
	}

}

int main()
{
	testLonda();
	system("pause");
	return 0;
}


