#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<iostream>
#include<Windows.h>
#include<ctime>
using namespace std;

int main()
{
	int szj = 0;
	cout << "szj几岁了" << endl;
	cin >> szj;
		cout << "你输入的szj岁数为：" << szj << endl;
		switch (szj)
		{
		case 14:
			cout << "恭喜你答对了，奖励你一个szj大礼包" << endl;
			Sleep(1000);

			while (szj < 233) {
				cout << "szj szj szj szj szj szj szj szj szj szj szj szj szj szj szj szj szj szj szj szj szj szj szj szj szj szj szj szj szj szj szj" << endl;
				szj++;
			}
			if (szj == 233)
				cout << "既然你都看到这里了，要不要玩个游戏，猜对了有奖励的噢" << endl;
			int youxi = 0;
			cout << "你是否想要玩游戏（1/0）" << endl;
			cout << "1为同意进行游戏" << endl;
			scanf("%d", &youxi);
			cin >> youxi;
			srand((unsigned int)time(NULL));
			if (youxi == 1)
			{
				cout << "好的，正在为你创建游戏项目" << endl;
				int num = rand() % 100 + 1;
				int sb = 0;
				Sleep(1000);
				cout << "这是一个简单的猜数字游戏，祝你玩得开心" << endl;
				while (1)
				{
					cout << "请输入你猜测的数字：" << endl;
					cin >> sb;
					if (sb > num) {
						cout << "猜测过大" << endl;

					}
					else if (sb < num) {
						cout << "猜测过小" << endl;

					}
					else {
						cout << "恭喜你猜对了" << endl;
						cout << "给你奖励一个坤坤视频" << endl;
						Sleep(1000);
						system("start https://www.bilibili.com/video/BV178411Y7QB/?spm_id_from=333.337.search-card.all.click");
						break;

					}
				}
			}
			else {


				cout << "好吧，你不玩一下真的是太可惜了" << endl;

			}
		default:
			cout << "你真是个大烧杯，这都能输错" << endl;
			Sleep(1000);
		}
		
	return 0;
}