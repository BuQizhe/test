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
int A::_scount = 0;//静态成员初始化


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
	const A& raa = 3;

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
		, _minute(minute)
		, _second(second)
	{}
private:
	int _hour;
	int _minute;
};

int main()
{
	//内置类型
	//除了用法方便，c malloc没什么区别
	int *p1=new int;
	int* p2 = new int[10];
	//默认不初始化，但是可以初始化
	int* p1 = new int(10);
	int* p2 = new int[10] {1, 2, 3, 4};

	delete p1;
	delete[]p2;

	//自定义类型,new才能调用构造初始化，malloc不再适用
	A* p1 = (A*)malloc(sizeof(A));
	//p1->_a = 0;
	free(p1);

	//开空间/释放空间，还会调用构造和析构函数
	A* p2 = new A;
	A* p3 = new A(2);

	delete p2;
	delete p3;

	cout << endl;

	//A*p4=new A[10];
	A aa1(1);
	A aa2(2);
	A aa3(3);

	A* p4 = new A[10]{aa1,aa2,aa3};
	A* p4 = new A[10]{1,2,3,4,5};
	delete[]p4;


	return 0;
}


#include<stack>

int main()
{
	//operator new->(malloc)+构造函数
	A* p2 = new A;
	
	//析构+operator delete
	delete p2;

	stack<int>* p3 = new stack<int>;
	delete p3;

	return 0;
}


struct ListNode
{
	ListNode* _next;
	int _val;

	ListNode(int val)
		:_next(nullptr)
		,_val(val)
	{}
};

void func()
{
	//new失败了，抛出异常
	ListNode* n1 = new ListNode(1);
	ListNode* n2 = new ListNode(2);
	ListNode* n3 = new ListNode(3);

	int* p1 = new int[100 * 1024 * 1024];
	int* p2 = new int[100 * 1024 * 1024];
	int* p3 = new int[100 * 1024 * 1024];
	int* p4 = new int[100 * 1024 * 1024];
	int* p5 = new int[100 * 1024 * 1024];
	int* p6 = new int[100 * 1024 * 1024];

	n1->_next = n2;
	n2->_next = n3;


	delete n1;
	delete n2;
	delete n3;
}


int main()
{
	try
	{
		func();
	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
	}
}


int main()
{
	//A* p1 = new A;
	A* p1 = (A*)operator new(sizeof(A));
	//p1->A();//不支持这样显示调用构造
	//new(p1)A; //对已有空间，显示调用构造
	new(p1)A(10);//对已有空间，显示调用构造

	//delete p1
	p1->~A();
	operator delete(p1);

	//new[]
	A* p2 = (A*)operator new[](sizeof(A) * 10);
	//new(p2)A[10]{1,2,3,4};//对已有空间，显示调用构造
	for (int i = 0; i < 10; i++)
	{
		new(p2 + i)A(i);
	}

	//delete[]
	for (int i = 0; i < 10; i++)
	{
		(p2 + i)->~A();
	}
	operator delete[](p2);

	return 0;
}