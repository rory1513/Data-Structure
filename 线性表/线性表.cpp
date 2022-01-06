#include<iostream>
#include<string>
using namespace std;

constexpr auto MAXSIZE = 10;
#include "���Ա�.h"

//��ʼ�����Ա�
bool InitList(SqList& L) {
	L.elem = new int[MAXSIZE];
	if (!L.elem)
	{
		cerr << "error" << endl;//�ڶ��������ڴ�
	}
	L.length = 0;//�趨���Ա�ĳ���Ϊ0
	cout<<"��ʼ���ɹ���" << endl;
	return 0;
}//InitList

//���Ա�Ĵݻ�
void DestroList(SqList& L) {
	if (L.elem)
	{
		delete L.elem;
		L.length = 0;
		cout<<"���Ա����ٳɹ�" << endl;
		cout << sizeof(L.elem) << endl;
		L.elem = NULL;//��ֹҰָ��
	}//end if

}//DestroList
//������Ա�
void ClearList(SqList& L) 
{

	L.length = 0;

}//ClearList

//�пղ���
bool IsEmpty(const SqList& L)
{
	if (L.length == 0)
	{
		cout<<"��" << endl;
		return true;
	}
	else
	{
		return false;
	}

}//IsEmpty

//���Ա��ȡֵ
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

//��ֵ����
int LocateList(const SqList& L, const int& e) {
	for (int i = 0; i < L.length; ++i)
	{
		if (L.elem[i] == e)
		{
			return i + 1; //���ҳɹ������������Ԫ�صĵ�һ���±�ֵ
		}
	}
	return 0; //δ���ҵ���ӦԪ�أ�����0
	//�㷨ʱ�临�Ӷȣ�O(n)
}//LocateList
//���Ա�Ĳ���

bool InsertList(SqList& L, const int& e, const int& i) {
	//�ж����Ա����Ƿ�С����󳤶�MAXSIZE
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
		//��λ�ڲ���λ��֮���Ԫ���������Ų��һλ
		for (int p =L.length-1;p>= i;--p)
		{
			L.elem[p+1] = L.elem[p];
		}
	}
	//����Ԫ��
	L.elem[i] = e;
	//���Ա���+1
	L.length += 1;
	return true;
	//�㷨ʱ�临�Ӷȣ�O(n)
}//InsertList;

//���Ա��ɾ��
bool DeleteList(SqList& L, const int& i) 
{
	//�ж����Ա����Ƿ�С����󳤶�MAXSIZE
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
	//��λ��ɾ��λ��֮���Ԫ��������ǰŲ��һλ
	for (int p = i + 1; p < L.length; ++p)
	{
		L.elem[p - 1] = L.elem[p];
	}
	//���Ա���-1
	L.length -= 1;
	return true;
	//�㷨ʱ�临�Ӷȣ�O(n)
}
void testSqlist()
{
	SqList List;
	InitList(List);//��ʼ�����Ա�
	for (int i = 1; i <= 8; i++)
	{
		List.elem[i] = i;
	}
	List.length = 8;

	
	int e;
	//GetELem(List, a, e);//��λ����
	cin >> e;
	//cout << LocateList(List, e) << endl;

	InsertList(List, e, 3);
	DestroList(List);//�ݻ����Ա�

	//ClearList(List);//������Ա�
	//IsEmpty(List); //�пղ���

}
//int main()
//{
//	testSqlist();
//	system("pause");
//	return 0;
//}
