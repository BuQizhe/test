#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>

using namespace std;

vector<string> visit;

int numofchurch, numofwild, boatload;     //�ֱ��ʾ����ʿ��������Ұ�������������ؿ���
int totalanswer = 0;                      //�ⷨ��Ŀ

bool check(int M, int C, int flag)
{
	if ((flag != 0) && (flag != 1))
		return false;
	if (M < 0 || C < 0 || numofchurch - M < 0 || numofwild - C < 0)           //��������С��0
		return false;
	if ((M && M < C) || ((numofchurch - M) && (numofchurch - M) < (numofwild - C)))               //�κ�һ���д���ʿ�Ҵ���ʿ����С��Ұ������
		return false;
	char s[30];
	sprintf_s(s, "M=%d, C=%d, flag=%d", M, C, flag);
	for (int i = 0; i < visit.size(); i++)          //�����֮ǰ���ֹ�
		if (s == visit[i])
			return false;
	visit.push_back(s);
	return true;
}

void path(int M, int C, int flag)
{
	if ((M == 0) && (C == 0) && (flag == 0))
	{
		totalanswer++;
		cout << "��" << totalanswer << "�ַ�����" << endl << endl;
		for (int i = 0; i < visit.size(); i++)
			cout << visit[i] << endl << endl;
		return;
	}

	int i, j, k;
	for (i = boatload; i > 0; i--)          //����������i����
	{
		for (j = i; j >= 0; j--)        //jΪ���͵Ĵ���ʿ����
		{
			k = i - j;                 //kΪ���͵�Ұ����
			if (check(M - j, C - k, flag - 1))
			{
				path(M - j, C - k, flag - 1);
				visit.pop_back();
			}
			else if (check(M + j, C + k, flag + 1))
			{
				path(M + j, C + k, flag + 1);
				visit.pop_back();


			}
		}
	}
}


int main()
{
	int flag = 1;                         //flag=1��ʾ������
	char s[30];
	cout << "���봫��ʿ����Ұ�����ʹ��ؿ��������������Կո�������" << endl;
	cin >> numofchurch >> numofwild >> boatload;
	sprintf_s(s, "M=%d, C=%d, flag=%d", numofchurch, numofwild, flag);
	visit.push_back(s);
	path(numofchurch, numofwild, flag);
	if (totalanswer != 0)
		cout << "Total answer: " << totalanswer << endl;
	else
		cout << "FAIL!" << endl;
	system("pause");
}

