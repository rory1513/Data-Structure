#include<iostream>
#include<string>
using namespace std;

constexpr auto MAXSIZE = 10;
#include "线性表.h"

//初始化线性表
bool InitList(SqList& L) {
	L.elem = new int[MAXSIZE];
	if (!L.elem)
	{
		cerr << "error" << endl;//在堆区开辟内存
	}
	L.length = 0;//设定线性表的长度为0
	cout<<"初始化成功！" << endl;
	return 0;
}//InitList

//线性表的摧毁
void DestroList(SqList& L) {
	if (L.elem)
	{
		delete L.elem;
		L.length = 0;
		cout<<"线性表销毁成功" << endl;
		cout << sizeof(L.elem) << endl;
		L.elem = NULL;//防止野指针
	}//end if

}//DestroList
//清空线性表
void ClearList(SqList& L) 
{

	L.length = 0;

}//ClearList

//判空操作
bool IsEmpty(const SqList& L)
{
	if (L.length == 0)
	{
		cout<<"空" << endl;
		return true;
	}
	else
	{
		return false;
	}

}//IsEmpty

//线性表的取值
bool GetELem(const SqList& L, const size_t i, int& e) 
{
	if (i<1 || i>MAXSIZE)
	{
		cerr << "out of range" << endl;
		return false;
	}
	e = L.elem[i - 1];
	return true;
}//GetElem

//按值查找
int LocateList(const SqList& L, const int& e) {
	for (int i = 0; i < L.length; ++i)
	{
		if (L.elem[i] == e)
		{
			return i + 1; //查找成功，返回其查找元素的第一个下标值
		}
	}
	return 0; //未能找到对应元素，返回0
	//算法时间复杂度：O(n)
}//LocateList
//线性表的插入

bool InsertList(SqList& L, const int& e, const int& i) {
	//判断线性表长度是否小于最大长度MAXSIZE
	if (L.length == MAXSIZE)
	{
		cerr << "can not insert!" << endl;
		return false;
	}
	if (i<0 || i>L.length)
	{
		cerr << "wrong insert position!" << endl;
		return false;
	}
	if (L.length >0)
	{
		//将位于插入位置之后的元素依次向后挪动一位
		for (int p =L.length-1;p>= i;--p)
		{
			L.elem[p+1] = L.elem[p];
		}
	}
	//插入元素
	L.elem[i] = e;
	//线性表长度+1
	L.length += 1;
	return true;
	//算法时间复杂度：O(n)
}//InsertList;

//线性表的删除
bool DeleteList(SqList& L, const int& i) 
{
	//判断线性表长度是否小于最大长度MAXSIZE
	if (L.length == MAXSIZE)
	{
		cerr << "can not insert!" << endl;
		return false;
	}
	if (i<0 || i>L.length)
	{
		cerr << "wrong insert position!" << endl;
		return false;
	}
	//将位于删除位置之后的元素依次向前挪动一位
	for (int p = i + 1; p < L.length; ++p)
	{
		L.elem[p - 1] = L.elem[p];
	}
	//线性表长度-1
	L.length -= 1;
	return true;
	//算法时间复杂度：O(n)
}
void testSqlist()
{
	SqList List;
	InitList(List);//初始化线性表
	for (int i = 1; i <= 8; i++)
	{
		List.elem[i] = i;
	}
	List.length = 8;

	
	int e;
	//GetELem(List, a, e);//按位查找
	cin >> e;
	//cout << LocateList(List, e) << endl;

	InsertList(List, e, 3);
	DestroList(List);//摧毁线性表

	//ClearList(List);//清空线性表
	//IsEmpty(List); //判空操作

}
//int main()
//{
//	testSqlist();
//	system("pause");
//	return 0;
//}
