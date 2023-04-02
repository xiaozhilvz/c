#include<stdio.h>
#define ZX 114514//应用全局变量

int main(void)
{
	const int abc = 1919;//const常变量，不可更改(具有常属性）
	printf("%d\n", ZX);
	const int a=10;
	{
		int num1 = 10;
		int num2 = 104;//给num2赋值
		int num = num1 + num2;//两值相加
		printf("%d\n", num);
		{
			printf("%d\n", abc);
			printf("%d\n", num+abc);
			printf("%d\n", num+ZX);
			printf("%d\n", a);
		}
		extern int KXR;
		printf("%d\n", KXR);
		//printf("%d\n", KXR);x需要用extern调用其他源文件赋值
	}
	return 0;
}