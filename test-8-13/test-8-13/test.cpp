#include<iostream>
using namespace std;

//class Date
//{//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;//		_month = month;//		_day = day;
//	}
//	// Date(const Date& d) // ��ȷд��
//	Date(const Date& d) // ����д�������뱨������������ݹ�
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
//	// ��������(��������)
//	int _year = 1970;
//	int _month = 1;
//	int _day = 1;
//	// �Զ�������
//	Time _t;
//};
//int main()
//{
//	Date d1;
//	// ���Ѿ����ڵ�d1��������d2���˴������Date��Ŀ������캯��
//	// ��Date�ಢû����ʽ���忽�����캯��������������Date������һ��Ĭ�ϵĿ������캯��
//		Date d2(d1);
//	return 0;
//}

//// ����ᷢ������ĳ������������������Ҫ�����Ժ󽲵����ȥ�����
//typedef int DataType;
//class Stack
//{//public:
//	Stack(size_t capacity = 10)
//	{
//		_array = (DataType*)malloc(capacity * sizeof(DataType));
//		if (nullptr == _array)
//		{
//			perror("malloc����ռ�ʧ��");//			return;
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