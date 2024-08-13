#include<iostream>
using namespace std;

//class Date
//{//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;//		_month = month;//		_day = day;
//	}
//	// Date(const Date& d) // 正确写法
//	Date(const Date& d) // 错误写法：编译报错，会引发无穷递归
//	{
//		_year = d._year;//		_month = d._month;//		_day = d._day;
//	}
//private://	int _year;//	int _month;//	int _day;
//};
//
//int main()
//{
//	Date d1;
//	Date d2(d1);
//	return 0;
//}

//class Time
//{
//public://	Time()//	{
//		_hour = 1;
//		_minute = 1;
//		_second = 1;
//		
//	}
//	Time(const Time& t)
//	{
//		_hour = t._hour;
//		_minute = t._minute;
//		_second = t._second;
//		cout << "Time::Time(const Time&)" << endl;
//	}
//private://	int _hour;//	int _minute;//	int _second;
//};
//class Date
//{//private:
//	// 基本类型(内置类型)
//	int _year = 1970;
//	int _month = 1;
//	int _day = 1;
//	// 自定义类型
//	Time _t;
//};
//int main()
//{
//	Date d1;
//	// 用已经存在的d1拷贝构造d2，此处会调用Date类的拷贝构造函数
//	// 但Date类并没有显式定义拷贝构造函数，则编译器会给Date类生成一个默认的拷贝构造函数
//		Date d2(d1);
//	return 0;
//}

//// 这里会发现下面的程序会崩溃掉？这里就需要我们以后讲的深拷贝去解决。
//typedef int DataType;
//class Stack
//{//public:
//	Stack(size_t capacity = 10)
//	{
//		_array = (DataType*)malloc(capacity * sizeof(DataType));
//		if (nullptr == _array)
//		{
//			perror("malloc申请空间失败");//			return;
//		}
//		_size = 0;
//		_capacity = capacity;
//	}
//	void Push(const DataType& data)
//	{
//		// CheckCapacity();
//		_array[_size] = data;
//		_size++;//	}
//	~Stack()//	{
//		if (_array)//		{
//			free(_array);//			_array = nullptr;//			_capacity = 0;//			_size = 0;
//		}//	}
//private:
//	DataType* _array;//	size_t _size;//	size_t _capacity;
//};//int main()
//{
//	Stack s1;//	s1.Push(1);//	s1.Push(2);//	s1.Push(3);//	s1.Push(4);
//	Stack s2(s1);
//	return 0;
//}

//class Date
//{//public:
//	Date(int year, int minute, int day)
//	{
//		cout << "Date(int,int,int):" << this << endl;
//	}
//	Date(const Date& d)
//	{
//		cout << "Date(const Date& d):" << this << endl;
//	}
//	~Date()//	{
//		cout << "~Date():" << this << endl;
//	}
//private://	int _year;//	int _month;//	int _day;;
//};
//Date Test(Date d)
//{
//	Date temp(d);
//	return temp;//}
//int main()
//{
//	Date d1(2022, 1, 13);//	Test(d1);
//	return 0;
//}