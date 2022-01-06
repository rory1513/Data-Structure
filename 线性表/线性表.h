#pragma once
#include<iostream>
#include<string>
using namespace std;
struct SqList
{
    int * elem;//˳�����Ա�ı�ͷ
    int length;//˳�����Ա�ĳ���
};

//���Ա�ĳ�ʼ��
bool InitList(SqList& L);

//���Ա�Ĵݻ�
void DestroList(SqList& L);

//������Ա�
void ClearList(SqList& L);

//�ж����Ա��Ƿ�Ϊ��
bool IsEmpty(const SqList& L);
//���Ա��ȡֵ
bool GetELem(const SqList& L, const size_t i, int& e);
//���Ա�Ĳ���
int LocateList(const SqList& L, const int& e);
//���Ա�Ĳ���
bool InsertList(SqList& L, const int& e, const int& i);

//���Ա��ɾ��
bool DeleteList(SqList& L, const int& i);
