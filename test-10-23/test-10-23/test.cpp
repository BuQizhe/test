#include<iostream>
#include<set>
#include<climits>
using namespace std;

#define ll long long

const int N = 1e3 + 10;
int a[N], s[N];//ǰ׺�ͺ�����
multiset<int> ms;


int main()
{
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		//ǰ׺��
		s[i] = s[i - 1] + a[i];
	}

	//��setȥά�����е������
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			//ά�������
			ms.insert(s[j] - s[i - 1]);
		}
	}

	int ans = LONG_MAX;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			//ö����i��β�����䣬��Ϊ����i-1ֻ����һ���ˣ�����Ӧ����j-1
			int sum = s[i] - s[j - 1];
			//�ҵ���������sum���Ƶ������
			auto it = ms.lower_bound(sum);
			if (it != ms.end())
			{
				ans = min(ans, abs(*it - sum));
			}
			if (it != ms.begin())
			{
				it--;
				ans = min(ans, abs(*it - sum));
			}
		}
		//ɾ����i��ͷ����j��β�����䣬��ֹ������ѯ�����ʱ����������ص�/��������
		for (int j = i; j <= n; j++) ms.erase(ms.find(s[j] - s[i - 1]));
	}
	cout << ans << endl;
	return 0;
}
