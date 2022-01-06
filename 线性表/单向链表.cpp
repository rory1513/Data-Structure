#include<iostream>
#pragma once
#include "��������.h"
using namespace std;
typedef int ElemType;

//��ʼ������
bool InitList(LinkList& L)
{
	L = new Lnode;//��������һ��ͷ���,������������ΪLonda
	L->next = nullptr;// �ձ�Ҳ����˵ͷ����ָ��ָ��Ϊ��
	return true;
}//InitList
//ͷ�巨����������
void CreatListHead(LinkList& L, const size_t n)
{
	for (unsigned int i = 0; i<n;i++)
	{
		Lnode* p = new Lnode;
		cout<<"����������" << endl;
		cin >> p->data;
		p->next = L->next;
		L->next = p;
	}
}
//β�巨������������
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

//�ж������Ƿ�Ϊ��
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
//�ݻ�����
bool DestroyList(LinkList& L)
{
	if (IsEmpty(L))
	{
		cerr << "empty List!" << endl;
		return false;
	}
	while (L)//����δ��β��
	{
		auto temp = L->next;//��ͷָ��ָ����һ�����
		delete L;
		L = temp;
	}
	return true;
}//DestroyList
//ͳ��������
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

//ȥ�����еĵ�i��Ԫ�ص�ֵ
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
			return false;//�����ʱpΪ�գ���ζ���Ѿ���������β�ˣ�ֹͣѭ��
		}
	}
	e = p->data;
	return true; 
}//GetElem
//��ֵ��������
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
}//��ֵ��������
//�������в���Ԫ��
bool InserList(LinkList &L, const int &i, const ElemType &e) 
{

	Lnode *p = L;
	int j = 0;
	while (p&&j<i-1)
	{
		p = p->next;
		++j;
	}
	//�쳣�ж�
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
}//����Ԫ��

void testLonda()
{
	LinkList L;
	InitList(L);
	//CreatListHead(L,1);//ͷ�巨
	CreatListTail(L, 3);//β�巨
	//bool b = IsEmpty(L);//�пղ���
	//bool a= DestroyList(L);//�ݻ�����
	//size_t a = GetLength(L);//��������
	/* {int e, i;
	i = 1;
	GetElem(L, i, e);
	cout << e << endl;
	}*///ȡ�����е�i��Ԫ�ص�ֵ
	/* {
		int e= 5;
		size_t a = LocateElem(L, e);
		cout<<a << endl;
	}*///��ֵ��������
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


