#include<iostream>
using namespace std;

//�����ʽ
//��һ����һ������ N����ʾһ�������� N ����Ϸ��1��N��100��
//������ N �е�ÿһ�а��������ַ�������ʾ��Ϸ������ Player1��Player2 ��ѡ��ʯͷ�����ӻ����ǲ����� S1, S2
//�ַ���֮���Կո���� S1 S2 ֻ����ȡֵ�� Rock, Scissors, Paper(��Сд���У��С�
char a[100], b[100];
int n;
int count1=0;
int count2=0;
int main()
{
	cout << "���֣�" << endl;
	cin >>n;
	for (int i = 1; i <= n; i++)
	{
		cout << "����:S  ʯͷ:R  ��:p  (��ĸȫ����д)" << endl;
		cin >> a >> b;
		if (a[0] == 'R' && b[0] == 'S')
		{
			cout << "ʤ��Player1" << endl;
			count1++;
		}
		if (a[0] == 'S' && b[0] == 'R')
		{
			cout << "ʤ��Player2" << endl;
			count2++;
		}
		if (a[0] == 'R' && b[0] == 'P')
		{
			cout << "ʤ��Player2" << endl;
			count2++;
		}
		if (a[0] == 'P' && b[0] == 'R')
		{
			cout << "ʤ��Player1" << endl;
			count1++;
		}
		if (a[0] == 'P' && b[0] == 'S')
		{
			cout << "ʤ��Player2" << endl;
			count2++;
		}
		if (a[0] == 'S' && b[0] == 'P')
		{
			cout << "ʤ��Player1" << endl;
			count1++;
		}
		if (a[0] == b[0])
		{
			cout << "ƽ��Tie" << endl;
		}
	}
	if (count1>count2)
	{
		cout << endl<<"��ʤ��Player1" << endl;
	}
	else if (count1 < count2)
	{
		cout <<endl<< "����ʤ��Player2" << endl;
	}
	else
	{
		cout <<endl<< "ƽ��" << endl;
	}
	return 0;
}