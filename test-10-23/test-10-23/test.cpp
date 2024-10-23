#include<iostream>
#include<set>
#include<climits>
using namespace std;

#define ll long long

const int N = 1e3 + 10;
int a[N], s[N];//前缀和和数组
multiset<int> ms;


int main()
{
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		//前缀和
		s[i] = s[i - 1] + a[i];
	}

	//用set去维护所有的区间和
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			//维护区间和
			ms.insert(s[j] - s[i - 1]);
		}
	}

	int ans = LONG_MAX;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			//枚举以i结尾的区间，因为这里i-1只会有一个人，所以应该是j-1
			int sum = s[i] - s[j - 1];
			//找到与该区间和sum相似的区间和
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
		//删除以i开头且以j结尾的区间，防止后续查询区间的时候出现区间重叠/交叉问题
		for (int j = i; j <= n; j++) ms.erase(ms.find(s[j] - s[i - 1]));
	}
	cout << ans << endl;
	return 0;
}
