#include<stdio.h>

int main()
{
	int user = 0;
	while (user < 500)
	{
		printf("等待bcrepi壮大中%d\n", user);
		user++;
	}
	if (user == 500)
		printf("欢迎来到bcrepi的世界\n");

	return 0;
}