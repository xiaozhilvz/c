#include<stdio.h>
#define ZX 114514//Ӧ��ȫ�ֱ���

int main(void)
{
	const int abc = 1919;//const�����������ɸ���(���г����ԣ�
	printf("%d\n", ZX);
	const int a=10;
	{
		int num1 = 10;
		int num2 = 104;//��num2��ֵ
		int num = num1 + num2;//��ֵ���
		printf("%d\n", num);
		{
			printf("%d\n", abc);
			printf("%d\n", num+abc);
			printf("%d\n", num+ZX);
			printf("%d\n", a);
		}
		extern int KXR;
		printf("%d\n", KXR);
		//printf("%d\n", KXR);x��Ҫ��extern��������Դ�ļ���ֵ
	}
	return 0;
}