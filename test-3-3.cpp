#include<iostream>
using namespace std;

int main()
{
	short num = 123456;
	cout << "shortռ�õ��ڴ�Ϊ��" << sizeof num << endl;//sizeof�������������ռ�õĴ���ռ�
	int Genshit = 114514;
	cout << "int��ռ�õ��ڴ�ռ䣺" << sizeof Genshit << endl;//���genshitռ���ڴ�ռ�
	//short=2  int=4  long=4  long long=8
	//short<int<=long<=long long

	return 0;
}