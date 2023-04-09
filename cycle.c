//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include<stdio.h>
//
//
//
//
//int main()
//{
//	int input = 0;
//	printf("你想要加入bcrepi的discord吗？(1/0)\n");
//	scanf("%d\n", &input);
//	
//	if (input == 1) {
//        printf("	https://discord.gg/MujhH2BtqG\n");
//	}
//	else {
//		printf("好吧，你继续你的注入吧\n");
//	}
//	return 0;
//}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//********选择语句**********
int main() {
	int input = 0;
	printf("你要好好学习吗？(1/0)\n");
	//输入
	scanf("%d", &input);
	//判断
	if (input == 1) {
		printf("好offer\n");
	}
	else {
		printf("回家卖红薯\n");
	}

	return 0;
}
