#pragma once
#include<iostream>
#include<string>
using namespace std;
struct SqList
{
    int * elem;//顺序线性表的表头
    int length;//顺序线性表的长度
};

//线性表的初始化
bool InitList(SqList& L);

//线性表的摧毁
void DestroList(SqList& L);

//清空线性表
void ClearList(SqList& L);

//判断线性表是否为空
bool IsEmpty(const SqList& L);
//线性表的取值
bool GetELem(const SqList& L, const size_t i, int& e);
//线性表的查找
int LocateList(const SqList& L, const int& e);
//线性表的插入
bool InsertList(SqList& L, const int& e, const int& i);

//线性表的删除
bool DeleteList(SqList& L, const int& i);
