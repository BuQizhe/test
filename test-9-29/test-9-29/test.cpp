#include<iostream>
using namespace std;

//class Date
//{
//public:
//		// 1. 单参构造函数，没有使用explicit修饰，具有类型转换作用
//		// explicit修饰构造函数，禁止类型转换---explicit去掉之后，代码可以通过编译
//		explicit Date(int year)
//		:_year(year)
//	{}
//	/*
//	// 2. 虽然有多个参数，但是创建对象时后两个参数可以不传递，没有使用explicit修饰，具
//	有类型转换作用
//	// explicit修饰构造函数，禁止类型转换
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
//	// 用一个整形变量给日期类型对象赋值
//	// 实际编译器背后会用2023构造一个无名对象，最后用无名对象给d1对象进行赋值
//	d2 = 2023;
//	// 将1屏蔽掉，2放开时则编译失败，因为explicit修饰构造函数，禁止了单参构造函数类型转换的作用
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
	// 不能这么定义对象，因为编译器无法识别下面是一个函数声明，还是对象定义
	//A aa1();
	// 但是我们可以这么定义匿名对象，匿名对象的特点不用取名字，
	// 但是他的生命周期只有这一行，我们可以看到下一行他就会自动调用析构函数
	A();
	A aa2(2);
	// 匿名对象在这样场景下就很好用，当然还有一些其他使用场景，这个我们以后遇到了再说
	Solution().Sum_Solution(10);
	return 0;
}