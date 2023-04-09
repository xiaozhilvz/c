#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<Windows.h>

int main()
{
	int user = 0;
	{
		int users = 0;
		printf("你想要获得bcrepi的mem身份吗（1/0）%d\n", users);
		scanf("%d", &users);
		if (users == 1)
			printf("好的正在为你获取mem身份\n"); }
	Sleep(3000);
	while (user < 50000)
	{
		
		printf("正在获取中%c\n", user);
		user++;
	}
	if (user == 50000) {
		printf("噢，没想到你竟然会耐心看到这，恭喜你获得傻逼称号\n");
	}
	return 0;
}