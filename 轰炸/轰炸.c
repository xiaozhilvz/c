
#include<stdio.h>
#include<Windows.h>
int main(void)
{
	
	int Message = 100;
	
		while (Message > 0)
	{
		FindWindowA(NULL, "ƽ�溣�����");
		SendMessageA(FindWindowA(NULL, "ƽ�溣�����"),WM_PASTE, NULL, NULL);
		SendMessageA(FindWindowA(NULL, "ƽ�溣�����"),WM_KEYDOWN,VK_RETURN,NULL);
		Message--;
	}

	return 0;
}