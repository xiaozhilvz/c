#include<stdio.h>

int arr = 1;//ȫ�ֱ���

extern int c ;//�˴����ñ�c�ļ���ֵ
int main(void)
{
	printf("%d\n", arr);
	{
		int b = 5;//�ֲ�����
		printf("%d\n",arr);//��ӡȫ�ֱ���
		printf("%d\n", b  );//��ӡ�ֲ�������ע�⣬����Ҫ����ֵ��ĸ���=Ҳ�����ֻ�轫�ø�ֵ��ĸ�������
		printf("%d\n",c);
	}
	return 0;
}
//externΪ�����ô�