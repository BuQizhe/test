#include<iostream>
using namespace std;

class MyQueue
{
public:
	//初始化列表，不管你写不写，每个成员变量都会走一遍
	//自定义类型的成员会调用默认构造(没有默认构造就会编译报错)
	//内置类型有缺省值用缺省值，没有的话，不确定，要看编译器，有的会处理，有的不会处理
	//先走初始化列表+再走函数体
	//实践中：尽可能使用列表初始化，不方便再使用函数体初始化
	MyQueue()
		:_size(1)
		, _ptr((int*)malloc(40))
	{
		memset(_ptr, 0, 40);
	}
private:
	Stack _pushst;
	Stack _poost;
};

class A
{
public:
	//单参数构造函数
	//explicit A(int a)
	A(int a)
		:_a(a)
	{
		cout << "A(int a)" << endl;
	}

	//多参数构造函数
	A(int a1, int a2)
		:_a(0)
		, _a1(a1);
		, _a2(a2);
	{}

	A(const A& aa)
		:_a(aa._a)
	{
		cout << "A(const A&&aa)" << endl;
	}


	~A()
	{
		//--_scount;

	}

	//没有this指针，只能访问静态成员
	static int GetCount()
	{
		//_a1=1;
		return _scount;
	}

private:

	//声明
	//静态区，不存在对象中
	//不能给缺省，因为缺省值是给初始化列表
	//他在静态区不在对象中，不走初始化列表
	//属于所有整个类，属于所有对象

	int _a1 = 1;
	int _a2 = 1;

	static int _scount;
};

//定义
int A::_scount = 0;


int main()
{
	A aa1(1);
	//拷贝构造
	A aa2 = aa1;

	//隐式类型转换
	//内置类型转换为自定义类型
	//3 构造一个A的临时对象，在用这个临时对象拷贝
	//编译器遇到连续构造+拷贝构造->优化为直接构造
	A aa3 = 3;

	//raa 引用的是类型转换中用3构造的临时对象
	const A & raa = 3;

	A aaa1(1, 2);
	A aaa2{ 1,2 };
	const A& aaa3{ 1,2 };

	return 0;
}



class Sum
{
public:
	Sum()
	{
		_ret += _i;
		++_i;
	}

	static int GetRet()
	{
		return _ret;
	}



private:
	static int _i;
	static int _ret;
};

int Sum::_i = 1;
int Sum::_ret = 0;

class Solution
{
public:
	int Sum_Solution(int n)
	{
		//变长数组
		Sum arr[n];
		return Sum::GetRet();
	}


};


class Time
{
	//声明Date是Time的友元
	//Date中可以访问Time的私有
	//但是Time中不能访问Date的私有
	friend class Date;
public:
	Time(int hour = 0, int minute = 0; int second = 0)
		:_hour(hour)
		,_minute(minute)
		,_second(second)
	{}
	private:
		int _hour;
		int _minute;
	};

	Date;::Date;()
	{
	}

	Date;::~Date;()
	{
	}
public:
	Time();
	~Time();

private:

};

Time::Time()
{
}

Time::~Time()
{
}