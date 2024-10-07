#include<iostream>
using namespace std;

class Date
{
	Date(int year, int month, int day)
		: _year(year)
	{}
private:
};

class Date
{
	Date(int year, int month, int day)
	{
		_year = year;
	}
private:
};

class Date
{
	Date(int year, int month, int day)

		: _year(year)
	{}
private:
};

class A
{
	A(int a)
	{}
private:
};
class B
{
	B(int a, int ref)
	{}
	A _aobj; // û��Ĭ�Ϲ��캯��
	int& _ref; // ����
	const int _n; // const

};

class Time
{
	Time(int hour = 0)
	{
		cout << "Time()" << endl;
	}
		int _hour;
};
class Date
{
	Date(int day)
	{}
private:
};
int main()
{
	Date d(1);
}

class A
{
	A(int a)
	{}
	void Print() {
		cout << _a1 << " " << _a2 << endl;
private:
};
int main() {
	A aa(1);
} 
//A.���1 1
//B.�������
//C.���벻ͨ��
//D.���1 ���ֵ

class Date
{
	
		// 1. ���ι��캯����û��ʹ��explicit���Σ���������ת������
		// explicit���ι��캯������ֹ����ת��---explicitȥ��֮�󣬴������ͨ������
		explicit Date(int year)
		:_year(year)
	/*
	// 2. ��Ȼ�ж�����������Ǵ�������ʱ�������������Բ����ݣ�û��ʹ��explicit���Σ���
	������ת������
	// explicit���ι��캯������ֹ����ת��
	explicit Date(int year, int month = 1, int day = 1)
	: _year(year)
	{}
	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
		}
		return *this;
	}
private:
};
void Test()
{
	Date d1(2022);
	// ��һ�����α������������Ͷ���ֵ
	// ʵ�ʱ������������2023����һ������������������������d1������и�ֵ
	d1 = 2023;
	// ��1���ε���2�ſ�ʱ�����ʧ�ܣ���Ϊexplicit���ι��캯������ֹ�˵��ι��캯������ת��������
}

class A
{
A() { ++_scount; }
A(const A & t) { ++_scount; }
static int GetACount() { return _scount; }
private:
static int _scount;
};
int A::_scount = 0;
void TestA()
{
	cout << A::GetACount() << endl;
	A a1, a2;
	A a3(a1);
	cout << A::GetACount() << endl;
}

class Date
{
	Date(int year, int month, int day)
		: _year(year)
	{}

	// d1 << cout; -> d1.operator<<(&d1, cout); �����ϳ������
	// ��Ϊ��Ա������һ������һ�������ص�this������d1�������<<�����
	ostream& operator<<(ostream& _cout)
	{
		_cout << _year << "-" << _month << "-" << _day << endl;
		return _cout;
	}
private:
};

class Date
{
	friend ostream& operator<<(ostream& _cout, const Date& d);
	friend istream& operator>>(istream& _cin, Date& d);
public:
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
	{}
private:
};
ostream& operator<<(ostream& _cout, const Date& d)
{
	_cout << d._year << "-" << d._month << "-" << d._day;
	return _cout;
}
istream& operator>>(istream& _cin, Date& d)
{
	_cin >> d._year;
	_cin >> d._month;
	_cin >> d._day;
	return _cin;
}
int main()
{
	Date d;
	cin >> d;
	cout << d << endl;
	return 0;
}

class Time
{
	friend class Date; // ����������Ϊʱ�������Ԫ�࣬�����������о�ֱ�ӷ���Time���е�˽�г�Ա����
public:
	Time(int hour = 0, int minute = 0, int second = 0)
		: _hour(hour)
	{}
private:
};
class Date
{
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
	{}
	void SetTimeOfDate(int hour, int minute, int second)
	{
		// ֱ�ӷ���ʱ����˽�еĳ�Ա����
		_t._hour = hour;
		_t._minute = minute;
		_t._second = second;
	}
private:

	Time _t;
};

class A
{
	static int k;
	int h;
public:
	class B // B��������A����Ԫ
	{
		void foo(const A& a)
		{
			cout << k << endl;//OK
			cout << a.h << endl;//OK
		}
};
int A::k = 1;
int main()
{
	A::B b;
	b.foo(A());
	return 0;
}

class A
{
	A(int a = 0)
	{
		cout << "A(int a)" << endl;
		
	}
	~A()
		cout << "~A()" << endl;
	}
	int _a;
class Solution {
public:
	int Sum_Solution(int n) {
		//...
		return n;
	}
int main()
{
	A aa1;
	// ������ô���������Ϊ�������޷�ʶ��������һ���������������Ƕ�����
	// �������ǿ�����ô����������������������ص㲻��ȡ���֣�
	// ����������������ֻ����һ�У����ǿ��Կ�����һ�����ͻ��Զ�������������
	A();
	A aa2(2);
	// �������������������¾ͺܺ��ã���Ȼ����һЩ����ʹ�ó�������������Ժ���������˵
	Solution().Sum_Solution(10);
	return 0;
}


class A
{
	A(int a = 0)
	{
		cout << "A(int a)" << endl;
	}
	A(const A& aa)
	{
		cout << "A(const A& aa)" << endl;
	}
	A& operator=(const A& aa)
	{
		cout << "A& operator=(const A& aa)" << endl;
		if (this != &aa)
		{
			_a = aa._a;
		}
		return *this;
	}
	~A()
		cout << "~A()" << endl;
	}
	int _a;
void f1(A aa)
{}
A f2()
	A aa;
}
int main()
{
	// ��ֵ����
	A aa1;
	// ��ֵ����
	f2();
	cout << endl;
	// ��ʽ���ͣ���������+��������->�Ż�Ϊֱ�ӹ���
	f1(1);
	// һ������ʽ�У���������+��������->�Ż�Ϊһ������
	f1(A(2));
	// һ������ʽ�У�������������+��������->�Ż�һ����������
	A aa2 = f2();
	cout << endl;
	// һ������ʽ�У�������������+��ֵ����->�޷��Ż�
	aa1 = f2();
	cout << endl;
	return 0;
}