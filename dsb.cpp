#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<Windows.h>

int main()
{
	int user = 0;
	{
		int users = 0;
		printf("����Ҫ���bcrepi��mem�����1/0��%d\n", users);
		scanf("%d", &users);
		if (users == 1)
			printf("�õ�����Ϊ���ȡmem���\n"); }
	Sleep(3000);
	while (user < 50000)
	{
		
		printf("���ڻ�ȡ��%c\n", user);
		user++;
	}
	if (user == 50000) {
		printf("�ޣ�û�뵽�㾹Ȼ�����Ŀ����⣬��ϲ����ɵ�Ƴƺ�\n");
	}
	return 0;
}