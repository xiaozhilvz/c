#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<iostream>
#include<Windows.h>
#include<ctime>
using namespace std;

int main()
{
	int szj = 0;
	cout << "szj������" << endl;
	cin >> szj;
		cout << "�������szj����Ϊ��" << szj << endl;
		switch (szj)
		{
		case 14:
			cout << "��ϲ�����ˣ�������һ��szj�����" << endl;
			Sleep(1000);

			while (szj < 233) {
				cout << "szj szj szj szj szj szj szj szj szj szj szj szj szj szj szj szj szj szj szj szj szj szj szj szj szj szj szj szj szj szj szj" << endl;
				szj++;
			}
			if (szj == 233)
				cout << "��Ȼ�㶼���������ˣ�Ҫ��Ҫ�����Ϸ���¶����н�������" << endl;
			int youxi = 0;
			cout << "���Ƿ���Ҫ����Ϸ��1/0��" << endl;
			cout << "1Ϊͬ�������Ϸ" << endl;
			scanf("%d", &youxi);
			cin >> youxi;
			srand((unsigned int)time(NULL));
			if (youxi == 1)
			{
				cout << "�õģ�����Ϊ�㴴����Ϸ��Ŀ" << endl;
				int num = rand() % 100 + 1;
				int sb = 0;
				Sleep(1000);
				cout << "����һ���򵥵Ĳ�������Ϸ��ף����ÿ���" << endl;
				while (1)
				{
					cout << "��������²�����֣�" << endl;
					cin >> sb;
					if (sb > num) {
						cout << "�²����" << endl;

					}
					else if (sb < num) {
						cout << "�²��С" << endl;

					}
					else {
						cout << "��ϲ��¶���" << endl;
						cout << "���㽱��һ��������Ƶ" << endl;
						Sleep(1000);
						system("start https://www.bilibili.com/video/BV178411Y7QB/?spm_id_from=333.337.search-card.all.click");
						break;

					}
				}
			}
			else {


				cout << "�ðɣ��㲻��һ�������̫��ϧ��" << endl;

			}
		default:
			cout << "�����Ǹ����ձ����ⶼ�����" << endl;
			Sleep(1000);
		}
		
	return 0;
}