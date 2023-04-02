#include<iostream>
using namespace std;

int main()
{
	short num = 123456;
	cout << "short占用的内存为：" << sizeof num << endl;//sizeof求出数据类型所占用的储存空间
	int Genshit = 114514;
	cout << "int所占用的内存空间：" << sizeof Genshit << endl;//求出genshit占的内存空间
	//short=2  int=4  long=4  long long=8
	//short<int<=long<=long long

	return 0;
}