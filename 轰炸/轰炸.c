
#include<stdio.h>
#include<Windows.h>
int main(void)
{
	
	int Message = 100;
	
		while (Message > 0)
	{
		FindWindowA(NULL, "平面海报设计");
		SendMessageA(FindWindowA(NULL, "平面海报设计"),WM_PASTE, NULL, NULL);
		SendMessageA(FindWindowA(NULL, "平面海报设计"),WM_KEYDOWN,VK_RETURN,NULL);
		Message--;
	}

	return 0;
}