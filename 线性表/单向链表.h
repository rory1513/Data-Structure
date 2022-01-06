#pragma once
using namespace std;
typedef int ElemType;



typedef struct Lnode
{
	ElemType data; //����е�������
	Lnode* next;

}Lnode,*LinkList;

//����ĳ�ʼ��
bool InitList(LinkList& L);//�������⻰��LinkList &L�ȼ��� Lnode *&L��Lnode *&L��һ��ָ��ָ�������
//ͷ�巨������������
void CreatListHead(LinkList& L, const size_t n);
//β�巨������������
void CreatListTail(LinkList& L, const size_t n);
//�ж������Ƿ�Ϊ��
bool IsEmpty(const LinkList& L);
//��������
bool DestroyList(LinkList& L);
//ͳ��������
size_t GetLength(const LinkList &L);
//ȡ�����е�i��Ԫ�ص�ֵ
bool GetElem(const LinkList& L, const int& i, ElemType& e);
//��ֵ��������
size_t LocateElem(LinkList& L, ElemType& e);
//�������в���Ԫ��
bool InserList(LinkList& L, const int& i, const ElemType &e);
//ɾ�������ĳ�����
bool EraseList(LinkList& L, const int& i);

