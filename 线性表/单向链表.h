#pragma once
using namespace std;
typedef int ElemType;



typedef struct Lnode
{
	ElemType data; //结点中的数据域
	Lnode* next;

}Lnode,*LinkList;

//链表的初始化
bool InitList(LinkList& L);//插入题外话：LinkList &L等价于 Lnode *&L，Lnode *&L是一个指向指针的引用
//头插法创建单向链表
void CreatListHead(LinkList& L, const size_t n);
//尾插法创建单向链表
void CreatListTail(LinkList& L, const size_t n);
//判断链表是否为空
bool IsEmpty(const LinkList& L);
//销毁链表
bool DestroyList(LinkList& L);
//统计链表长度
size_t GetLength(const LinkList &L);
//取链表中第i个元素的值
bool GetElem(const LinkList& L, const int& i, ElemType& e);
//按值查找链表
size_t LocateElem(LinkList& L, ElemType& e);
//在链表中插入元素
bool InserList(LinkList& L, const int& i, const ElemType &e);
//删除链表的某个结点
bool EraseList(LinkList& L, const int& i);

