//#include<iostream>
//using namespace std;

//typedef int DateaType;
//
//class Stack
//{
//public:
//	Stack(size_t capacity=3) 
//	{
//		_array = (DateaType*)malloc(sizeof(DateaType) * capacity);
//		if (NULL==_array)
//		{
//			perror("mallloc申请空间失败！！！");
//			return;
//		}
//		_capacity = capacity;
//		_size = 0;
//	}
//
//	void Push(DateaType data)
//	{
//		_array[_size] = data;
//		_size++;
//	}
//
//	~Stack()
//	{
//		if (_array)
//		{
//			free(_array);
//			_array = NULL;
//			_capacity = 0;
//			_size = 0;
//		}
//	}
//private:
//	DateaType* _array;
//	int _capacity;
//	int _size;
//};
//
//class MyQueue
//{
//public:
//	//初始化列表，不管你写不写，每个成员变量都会先走一遍
//	//自定义类型的成员会调用默认构造(没有默认构造就编译报错)
//	//内置类型有缺省值用缺省值，没有的话，不确定,要看编译器，有的编译器会处理，有的不会处理
//	//先走初始化列表，再走函数体
//	//实践中，尽可能使用初始化列表初始化，不方便再使用函数体初始化
//	/*MyQueue()
//	{}*/
//
//	/*Stack不具备默认构造。MyQueue也无法生成默认构造
//	初始化列表
//	初始化列表本质可以理解为每个对象中成员定义的地方
//	所有的成员，你可以在初始化列表初始化，也可以在函数体内部初始化
//	1.引用 2.const 3.没有默认构造自定义类型成员（必须显式传参调构造）*/
//
//	MyQueue(int n, int& rr)
//		:_Pushst(n)
//		,_Popst(n)
//		,_x(1)
//		,_ret(rr)
//		,_ptr((int*)malloc(8))
//	{
//		//缺省值是给初始化列表用的
//		_size = 0;
//		//_x=1;
//	}
//private:
//	//声明
//	Stack _Pushst;
//	Stack _Popst;
//	int _size;
//
//	int* _ptr;
//
//	//必须在定义时初始化
//	const int _x;
//
//	//必须在定义时初始化
//	int& _ret;
//};
//
//int main()
//{
//	int xx = 0;
//	MyQueue q(10,xx);
//
//	//const int y = 2;
//
//	//int& ry;  //要初始化 
//	return 0;
//}
//
//
//class A
//{
//public:
//	A(int a)
//		:_a1(a)
//		, _a2(_a1)
//	{}
//
//	void Print() {
//		cout << _a1 << " " << _a2 << endl;
//	}
//
//private:
//	int _a2;
//	int _a1;
//};
//
//int main() {
//	A aa(1);
//	aa.Print();
//}
//
////输出1，随机值
////成员变量在类中声明次序就是在初始化列表中初始化顺序，与其在初始化列表中的先后次序无关


//class A
//{
//public:
//	//单参数构造函数
//	A(int a)
//		:_a(a)
//	{
//		cout << "A(int a)" << endl;
//	}
//
//	A(const A& aa)
//		:_a(aa._a)
//	{
//		cout << "A(const A& aa)" << endl;
//	}
//
//private:
//	int _a;
//};
//
//int main()
//{
//	A aa1(1);
//
//	//拷贝构造
//	A aa2 = aa1;
//
//	//隐式类型转换
//	//内置类型转化为自定义类型
//	//3构造一个A的临时对象，在用这个临时对象拷贝构造aa3
//	//编译器遇到连续构造+拷贝构造->优化为直接构造
//	A aa3 = 3;
//	A aa4 = 3.3;
//
//	//不能直接给raa，临时变量具有常性要加const在前面,权限要缩小
//	//raa 引用的是类型转换中用3构造的临时对象
//	const A& raa = 3;
//
//
//	//不支持字符串
//	//A aa4="fsafds";
//	return 0;
//}

//class A {
//public:
//    explicit A(int x) : data(x) {}
//private:
//    int data;
//};
//A obj(5); // 显式方式进行类型转换
//A obj = 5; // 隐式方式进行类型转换，编译错误


//#include<iostream>
//using namespace std;
//
//typedef int DateaType;
//
//class Stack
//{
//public:
//	Stack(size_t capacity = 3)
//	{
//		_array = (DateaType*)malloc(sizeof(DateaType) * capacity);
//		if (NULL == _array)
//		{
//			perror("mallloc申请空间失败！！！");
//			return;
//		}
//		_capacity = capacity;
//		_size = 0;
//	}
//
//	void Push(DateaType data)
//	{
//		_array[_size] = data;
//		_size++;
//	}
//
//	~Stack()
//	{
//		if (_array)
//		{
//			free(_array);
//			_array = NULL;
//			_capacity = 0;
//			_size = 0;
//		}
//	}
//private:
//	DateaType* _array;
//	int _capacity;
//	int _size;
//};
//
//class MyQueue
//{
//public:
//	//初始化列表，不管你写不写，每个成员变量都会先走一遍
//	//自定义类型的成员会调用默认构造(没有默认构造就编译报错)
//	//内置类型有缺省值用缺省值，没有的话，不确定,要看编译器，有的编译器会处理，有的不会处理
//	//先走初始化列表，再走函数体
//	//实践中，尽可能使用初始化列表初始化，不方便再使用函数体初始化
//	/*MyQueue()
//	{}*/
//
//	/*Stack不具备默认构造。MyQueue也无法生成默认构造
//	初始化列表
//	初始化列表本质可以理解为每个对象中成员定义的地方
//	所有的成员，你可以在初始化列表初始化，也可以在函数体内部初始化
//	1.引用 2.const 3.没有默认构造自定义类型成员（必须显式传参调构造）*/
//
//	MyQueue(int n, int& rr)
//		:_Pushst(n)
//		, _Popst(n)
//		, _x(1)
//		, _ret(rr)
//		, _ptr((int*)malloc(8))
//	{
//		//缺省值是给初始化列表用的
//		_size = 0;
//		//_x=1;
//	}
//private:
//	//声明
//	Stack _Pushst;
//	Stack _Popst;
//	int _size;
//
//	int* _ptr;
//
//	//必须在定义时初始化
//	const int _x;
//
//	//必须在定义时初始化
//	int& _ret;
//};
//
//int main()
//{
//	int xx = 0;
//	MyQueue q(10, xx);
//
//	//const int y = 2;
//
//	//int& ry;  //要初始化 
//	return 0;
//}

//class Time
//{
//public:
//	Time(int hour = 0)
//		:_hour(hour)
//	{
//		cout << "Time()" << endl;
//	}
//private:
//	int _hour;
//};
//class Date
//{
//public:
//	Date(int day)
//	{}
//private:
//	int _day;
//	Time _t;
//};
//int main()
//{
//	Date d(1);
//}

//class A
//{
//public:
//	A(int a)
//		:_a1(a)
//		, _a2(_a1)
//	{}
//
//	void Print() {
//		cout << _a1 << " " << _a2 << endl;
//	}
//
//private:
//	int _a2;
//	int _a1;
//};
//
//int main() {
//	A aa(1);
//	aa.Print();
//}

//class A
//{
//public:
//	//单参数构造函数
//	A(int a)
//		:_a(a)
//	{
//		cout << "A(int a)" << endl;
//	}
//
//	A(const A& aa)
//		:_a(aa._a)
//	{
//		cout << "A(const A& aa)" << endl;
//	}
//
//private:
//	int _a;
//};
//
//int main()
//{
//	A aa1(1);
//
//	//拷贝构造
//	A aa2 = aa1;
//
//	//隐式类型转换
//	//内置类型转化为自定义类型
//	//3构造一个A的临时对象，在用这个临时对象拷贝构造aa3
//	//编译器遇到连续构造+拷贝构造->优化为直接构造
//	A aa3 = 3;
//	A aa4 = 3.3;
//
//	//不能直接给raa，临时变量具有常性要加const在前面,权限要缩小
//	//raa 引用的是类型转换中用3构造的临时对象
//	const A& raa = 3;
//
//
//	//不支持字符串
//	//A aa4="fsafds";
//	return 0;
//}

//class A
//{
//public:
//	A(int a = 0)
//		:_a(a)
//	{
//		cout << "A(int a)" << endl;
//	}
//	A(const A& aa)
//		:_a(aa._a)
//	{
//		cout << "A(const A& aa)" << endl;
//	}
//	A& operator=(const A& aa)
//	{
//		cout << "A& operator=(const A& aa)" << endl;
//		if (this != &aa)
//		{
//			_a = aa._a;
//		}
//		return *this;
//	}
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//private:
//	int _a;
//};
//void f1(A aa)
//{}
//A f2()
//{
//	A aa;
//	return aa;
//}
//int main()
//{
//	// 传值传参
//	A aa1;
//	f1(aa1);
//	cout << endl;
//	// 传值返回
//	f2();
//	cout << endl;
//	// 隐式类型，连续构造+拷贝构造->优化为直接构造
//	f1(1);
//	// 一个表达式中，连续构造+拷贝构造->优化为一个构造
//	f1(A(2));
//	cout << endl;
//	// 一个表达式中，连续拷贝构造+拷贝构造->优化一个拷贝构造
//	A aa2 = f2();
//	cout << endl;
//	// 一个表达式中，连续拷贝构造+赋值重载->无法优化
//	aa1 = f2();
//	cout << endl;
//	return 0;
//}


#include<iostream>
using namespace std;

class Date
{
public:

	// 1. 单参构造函数，没有使用explicit修饰，具有类型转换作用
	// explicit修饰构造函数，禁止类型转换---explicit去掉之后，代码可以通过编译
	Date(int year)
		:_year(year)
	{}
	
	// 2. 虽然有多个参数，但是创建对象时后两个参数可以不传递，没有使用explicit修饰，具有类型转换作用
	// explicit修饰构造函数，禁止类型转换
	 Date(int year, int month = 1, int day = 1)
	: _year(year)
	, _month(month)
	, _day(day)
	{}
	
	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}
private:
	int _year;
	int _month;
	int _day;
};
void Test()
{
	Date d1(2022);
	// 用一个整形变量给日期类型对象赋值
	// 实际编译器背后会用2023构造一个无名对象，最后用无名对象给d1对象进行赋值
	d1 = 2023;
	// 将1屏蔽掉，2放开时则编译失败，因为explicit修饰构造函数，禁止了单参构造函数类型转换的作用
}

int main()
{
	Test();
	return 0;
}