#include<iostream>
using namespace std;
//class Date
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	//  error C2652: ��Date��: �Ƿ��ĸ��ƹ��캯��: ��һ��������Ӧ�ǡ�Date��
//	// Date d2(d1)
//	//Date(const Date& d)
//	//{
//	//	_year = d._year;
//	//	_month = d._month;
//	//	_day = d._day;
//	//}
//
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
////void Func1(const Date& d)
//void Func1(Date d)
//{
//	cout << &d << endl;
//	d.Print();
//}

//int main()
//{
//	Date d1(2024, 7, 12);
//	d1.Print();
//
//	// C++�Ĺ涨����ֵ����Ҫ���ÿ�������
//	Func1(d1);
//
//	Date d2(d1);
//	d2.Print();
//
//	return 0;
//}
//
//typedef int STDataType;
//class Stack
//{
//public:
//	Stack(int n = 4)
//	{
//		_a = (STDataType*)malloc(sizeof(STDataType) * n);
//		if (nullptr == _a)
//		{
//			perror("malloc����ռ�ʧ��");
//			return;
//		}
//		_capacity = n;
//		_top = 0;
//	}
//
//	// st2(st1)
//	Stack(const Stack& st)
//	{
//		cout << "Stack(const Stack& st)" << endl;
//
//		// ��Ҫ��_aָ����Դ����ͬ�������Դ�ٿ���ֵ
//		_a = (STDataType*)malloc(sizeof(STDataType) * st._capacity);
//		if (nullptr == _a)
//		{
//			perror("malloc����ռ�ʧ��!!!");
//			return;
//		}
//		memcpy(_a, st._a, sizeof(STDataType) * st._top);
//		_top = st._top;
//		_capacity = st._capacity;
//	}
//
//	void Push(STDataType x)
//	{
//		if (_top == _capacity)
//		{
//			int newcapacity = _capacity * 2;
//			STDataType* tmp = (STDataType*)realloc(_a, newcapacity *
//				sizeof(STDataType));
//			if (tmp == NULL)
//			{
//				perror("realloc fail");
//				return;
//			}
//			_a = tmp;
//			_capacity = newcapacity;
//		}
//		_a[_top++] = x;
//
//	}
//	~Stack()
//	{
//		cout << "~Stack()" << endl;
//		free(_a);
//		_a = nullptr;
//		_top = _capacity = 0;
//	}
//private:
//	STDataType* _a;
//	size_t _capacity;
//	size_t _top;
//};

//int main()
//{
//	Stack st1;
//	st1.Push(1);
//	st1.Push(2);
//
//	// Stack����ʾʵ�ֿ������죬���Զ����ɵĿ����������ǳ����
//	// �ᵼ��st1��st2�����_aָ��ָ��ͬһ����Դ������ʱ���������Σ��������
//	Stack st2(st1);
//
//	return 0;
//}

//void func1(const Stack& st)
//{
//
//}
//
//// ����Stackʵ�ֶ���
//class MyQueue
//{
//public:
//private:
//	Stack pushst;
//	Stack popst;
//};

//int main()
//{
//	Stack st1;
//	st1.Push(1);
//	st1.Push(2);
//
//	func1(st1);
//
//	// Stack����ʾʵ�ֿ������죬���Զ����ɵĿ����������ǳ����
//	// �ᵼ��st1��st2�����_aָ��ָ��ͬһ����Դ������ʱ���������Σ��������
//	Stack st2(st1);
//	Stack st3 = st1;
//
//	MyQueue mq1;
//	// MyQueue�Զ����ɵĿ������죬���Զ�����Stack�����������pushst/popst
//	// �Ŀ�����ֻҪStack���������Լ�ʵ�������������û����
//	MyQueue mq2(mq1);
//
//	return 0;
//}

//Stack& func2(Stack& st)
//{
//	st.Push(1);
//	st.Push(1);
//	st.Push(1);
//
//	return st;
//}
//
//int main()
//{
//	//Stack ret = func2();
//	Stack st1;
//	func2(st1);
//
//	return 0;
//}

/////////////////////////////////////////////////////////////////////////////
//class A
//{
//public:
//	void func()
//	{
//		cout << "A::func()" << endl;
//	}
//};
//
//typedef void(A::*PF)(); //��Ա����ָ������
//
//int main()
//{
//	// void(A::*pf)() = nullptr;
//	PF pf = nullptr;
//	// C++�涨��Ա����Ҫ��&����ȡ������ָ��
//
//	pf = &A::func;
//	A aa;
//	(aa.*pf)();
//}


//#include<iostream>
//using namespace std;
//
//class Date
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	// d3 = d1
//	/*Date& operator=(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//
//		return *this;
//	}*/
//
//	// ��������
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//
//	// ����
//	Date(const Date* d)
//	{
//		_year = d->_year;
//		_month = d->_month;
//		_day = d->_day;
//	}
//
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//	bool operator==(const Date& d)
//	{
//		return _year == d._year
//			&& _month == d._month
//			&& _day == d._day;
//	}
//
//	//d1 + 100;
//	Date operator+(int day);
//
//	//d1 - 100;
//	Date operator-(int day);
//
//	// d1 - d2;
//	int operator-(const Date& d);
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};

//bool operator==(const Date& d1, const Date& d2)
//{
//	return d1._year == d2._year
//		&& d1._month == d2._month
//		&& d1._day == d2._day;
//}

//int main()
//{
//	Date d1(2024, 7, 5);
//	Date d2(2024, 7, 6);
//
//	// ��������غ���������ʾ����
//	//operator==(d1, d2);
//	// ��������ת���� operator==(d1, d2);
//	//d1 == d2;
//
//	// ��������غ���������ʾ����
//	d1.operator==(d2);
//
//	// ��������ת���� d1.operator==(d2);
//	d1 == d2;
//
//	d1 + 100;
//	d1 - 100;
//	d1 - d2;
//
//	return 0;
//}

//int main()
//{
//	// 11��45����
//	Date d1(2024, 7, 5);
//	Date d2(2024, 7, 6);
//
//	// ��ֵ���ؿ���
//	d1 = d2;
//
//	// ��������
//	Date d3(d2);
//	Date d4 = d2;
//
//	d4 = d3 = d1;
//
//	int i, j, k;
//	i = j = k = 1;
//
//	return 0;
//}

#include"Date.h"

void TestDate1()
{
	Date d1(2024, 7, 12);
	Date d2 = d1 + 100;
	//Date d3(d1 + 100);
	d1.Print();
	d2.Print();

	//d1 += 100;
	//d1.Print();

	d1 += 30000;
	d1.Print();
}

void TestDate2()
{
	/*Date d1(2024, 7, 13);
	d1 -= 30000;
	d1.Print();*/

	Date d1(2024, 7, 13);
	Date ret1 = d1++;
	ret1.Print();
	d1.Print();

	Date d2(2024, 7, 13);
	Date ret2 = ++d2;
	ret2.Print();
	d2.Print();
}

void TestDate3()
{
	Date d1(2024, 7, 12);
	d1 += -100;
	d1.Print();

	d1 -= -100;
	d1.Print();
}

void TestDate4()
{
	Date d1(2034, 10, 1);
	Date d2(2024, 6, 31);

	cout << d1 - d2 << endl;
}

void TestDate5()
{
	Date d1, d2;
	cin >> d1 >> d2;
	cout << d1 << d2;

	cout << d1 - d2 << endl;

	//cout << d1;
	//operator<<(cout, d1);

	//cout << d1 << d2;

	// �������
	//d1 << cout;
	//d1.operator<<(cout);
}

void TestDate6()
{
	const Date d1(2024, 7, 13);
	d1.Print();

	Date d2(2024, 7, 13);
	d2.Print();

	cout << &d1 << endl;
	cout << &d2 << endl;
}

//int main()
//{
//	TestDate6();
//
//	return 0;
//}

#include<iostream>
using namespace std;
class A
{
public:
	//explicit A(int a = 0)
	A(int a = 0)
	{
		_a1 = a;
	}

	A(const A& aa)
	{
		_a1 = aa._a1;
	}

	A(int a1, int a2)
		:_a1(a1)
		, _a2(a2)
	{}

	void Print() {
		cout << _a1 << " " << _a2 << endl;
	}
private:
	int _a1;
	int _a2;
};

class Stack
{
public:
	void Push(const A& aa)
	{
		//...
	}
private:
	A _arr[10];
	int _top;
};

int main()
{
	A aa1(1);
	aa1.Print();

	// ��ʽ����ת��
	// 2����һ��A����ʱ�������������ʱ���󿽱�����aa2
	// ������������������+��������->�Ż�Ϊֱ�ӹ���
	A aa2 = 2;
	aa2.Print();

	A& raa1 = aa2;
	const A& raa2 = 2;

	int i = 1;
	double d = i;
	const double& rd = i;

	Stack st;

	A aa3(3);
	st.Push(aa3);

	st.Push(3);

	// C++11
	A aa5 = { 1, 1 };
	const A& raa6 = { 2,2 };
	st.Push(aa5);
	st.Push({ 2,2 });

	return 0;
}
