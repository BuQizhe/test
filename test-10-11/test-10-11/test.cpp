#include<iostream>
using namespace std;

//输入格式
//第一行是一个整数 N，表示一共进行了 N 次游戏。1≤N≤100。
//接下来 N 行的每一行包括两个字符串，表示游戏参与者 Player1，Player2 的选择（石头、剪子或者是布）： S1, S2
//字符串之间以空格隔开 S1 S2 只可能取值在 Rock, Scissors, Paper(大小写敏感）中。
char a[100], b[100];
int n;
int count1=0;
int count2=0;
int main()
{
	cout << "几局：" << endl;
	cin >>n;
	for (int i = 1; i <= n; i++)
	{
		cout << "剪刀:S  石头:R  布:p  (字母全部大写)" << endl;
		cin >> a >> b;
		if (a[0] == 'R' && b[0] == 'S')
		{
			cout << "胜：Player1" << endl;
			count1++;
		}
		if (a[0] == 'S' && b[0] == 'R')
		{
			cout << "胜：Player2" << endl;
			count2++;
		}
		if (a[0] == 'R' && b[0] == 'P')
		{
			cout << "胜：Player2" << endl;
			count2++;
		}
		if (a[0] == 'P' && b[0] == 'R')
		{
			cout << "胜：Player1" << endl;
			count1++;
		}
		if (a[0] == 'P' && b[0] == 'S')
		{
			cout << "胜：Player2" << endl;
			count2++;
		}
		if (a[0] == 'S' && b[0] == 'P')
		{
			cout << "胜：Player1" << endl;
			count1++;
		}
		if (a[0] == b[0])
		{
			cout << "平：Tie" << endl;
		}
	}
	if (count1>count2)
	{
		cout << endl<<"最胜：Player1" << endl;
	}
	else if (count1 < count2)
	{
		cout <<endl<< "最终胜：Player2" << endl;
	}
	else
	{
		cout <<endl<< "平局" << endl;
	}
	return 0;
}