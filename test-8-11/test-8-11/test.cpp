#include<iostream>
using namespace std;

//class Time
//{//public:
//	Time()//	{
//		cout << "Time()" << endl;
//		_hour = 0;
//		_minute = 0;
//		_second = 0;
//	}
//private://	int _hour;//	int _minute;//	int _second;
//};
//class Date
//{//private:
//	// 基本类型(内置类型)
//	int _year;
//	int _month;
//	int _day;
//	// 自定义类型
//	Time _t;
//};
//int main()
//{
//	Date d;
//	return 0;
//}


//class Time
//{
//public://	Time()//	{
//		cout << "Time()" << endl;
//		_hour = 0;
//		_minute = 0;
//		_second = 0;
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
//	Date d;
//	return 0;//}//class Date
//{//public:
//	Date()//	{
//		_year = 1900;//		_month = 1;//		_day = 1;
//	}
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;//		_month = month;//		_day = day;
//	}
//private://	int _year;//	int _month;//	int _day;
//};
//// 以下测试函数能通过编译吗？
//void Test()
//{
//	Date d1;
//}



//typedef int DataType;
//class Stack
//{//public:
//	Stack(size_t capacity = 3)
//	{
//		_array = (DataType*)malloc(sizeof(DataType) * capacity);
//		if (NULL == _array)
//		{
//			perror("malloc申请空间失败!!!");//			return;
//		}
//		_capacity = capacity;
//		_size = 0;
//	}
//	void Push(DataType data)
//	{
//		// CheckCapacity();
//		_array[_size] = data;
//		_size++;//	}
//	// 其他方法...
//	~Stack()//	{
//		if (_array)//		{
//			free(_array);//			_array = NULL;//			_capacity = 0;//			_size = 0;
//			
//		}//	}//private:
//	DataType* _array;//	int _capacity;//	int _size;
//};
//void TestStack()
//{
//	Stack s;//	s.Push(1);//	s.Push(2);
//}
//int main()
//{
//	TestStack();
//	return 0;
//}

class Time
{public:
	~Time()	{
		cout << "~Time()" << endl;
	}
private:	int _hour;	int _minute;	int _second;
};
class Date
{private:
	// 基本类型(内置类型)
	int _year = 1970;
	int _month = 1;
	int _day = 1;
	// 自定义类型
	Time _t;
};
int main()
{
	Date d;
	return 0;}
// 程序运行结束后输出：~Time()
// 在main方法中根本没有直接创建Time类的对象，为什么最后会调用Time类的析构函数？// 因为：main方法中创建了Date对象d，而d中包含4个成员变量，其中_year, _month,_day三个是
// 内置类型成员，销毁时不需要资源清理，最后系统直接将其内存回收即可；而_t是Time类对象，所以在
// d销毁时，要将其内部包含的Time类的_t对象销毁，所以要调用Time类的析构函数。但是：main函数
// 中不能直接调用Time类的析构函数，实际要释放的是Date类对象，所以编译器会调用Date类的析构函
// 数，而Date没有显式提供，则编译器会给Date类生成一个默认的析构函数，目的是在其内部调用Time
// 类的析构函数，即当Date对象销毁时，要保证其内部每个自定义对象都可以正确销毁
// main函数中并没有直接调用Time类析构函数，而是显式调用编译器为Date类生成的默认析构函数
// 注意：创建哪个类的对象则调用该类的析构函数，销毁那个类的对象则调用该类的析构函数