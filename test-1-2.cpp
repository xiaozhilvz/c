#include<stdio.h>

int arr = 1;//全局变量

extern int c ;//此处引用别处c文件赋值
int main(void)
{
	printf("%d\n", arr);
	{
		int b = 5;//局部变量
		printf("%d\n",arr);//打印全局变量
		printf("%d\n", b  );//打印局部变量，注意，不需要将赋值字母后的=也打出，只需将该赋值字母打出即可
		printf("%d\n",c);
	}
	return 0;
}
//extern为声明用处