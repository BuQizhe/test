#include<iostream>
using namespace std;

//class Date
//{
//public:
//		// 1. ���ι��캯����û��ʹ��explicit���Σ���������ת������
//		// explicit���ι��캯������ֹ����ת��---explicitȥ��֮�󣬴������ͨ������
//		explicit Date(int year)
//		:_year(year)
//	{}
//	/*
//	// 2. ��Ȼ�ж�����������Ǵ�������ʱ�������������Բ����ݣ�û��ʹ��explicit���Σ���
//	������ת������
//	// explicit���ι��캯������ֹ����ת��
//	explicit Date(int year, int month = 1, int day = 1)
//	: _year(year)
//	, _month(month)
//	, _day(day)
//	{}
//	*/
//	Date& operator=(const Date& d)
//	{
//		if (this != &d)
//		{
//			_year = d._year;
//			_month = d._month;
//			_day = d._day;
//		}
//		return *this;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//void Test()
//{
//	Date d1(2022);
//	// ��һ�����α������������Ͷ���ֵ
//	// ʵ�ʱ������������2023����һ������������������������d1������и�ֵ
//	d2 = 2023;
//	// ��1���ε���2�ſ�ʱ�����ʧ�ܣ���Ϊexplicit���ι��캯������ֹ�˵��ι��캯������ת��������
//}

class A
{
public:
	A(int a = 0)
		:_a(a)
	{
		cout << "A(int a)" << endl;
	}
	~A()
	{
		cout << "~A()" << endl;
	}
private:
	int _a;
};
class Solution {
public:
	int Sum_Solution(int n) {
		//...
		return n;
	}
};
int main()
{
	A aa1;
	// ������ô���������Ϊ�������޷�ʶ��������һ���������������Ƕ�����
	//A aa1();
	// �������ǿ�����ô����������������������ص㲻��ȡ���֣�
	// ����������������ֻ����һ�У����ǿ��Կ�����һ�����ͻ��Զ�������������
	A();
	A aa2(2);
	// �������������������¾ͺܺ��ã���Ȼ����һЩ����ʹ�ó�������������Ժ���������˵
	Solution().Sum_Solution(10);
	return 0;
}