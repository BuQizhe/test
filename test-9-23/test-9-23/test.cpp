#include<iostream>
using namespace std;

 
//class Date
//{
//public:
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//	int GetMonthDay(int year, int month)
//	{
//		static int monthDayArray[13] = { -1, 31, 28, 31, 30, 31, 30,31, 31, 30, 31, 30, 31 };
//
//		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
//		{
//			return 29;
//		}
//
//		return monthDayArray[month];
//	}
//
//	Date& operator++()
//	{
//		*this += 1;
//		return *this;
//	}
//
//	Date operator++(int)
//	{
//		Date tmp(*this);
//		*this += 1;
//		return tmp;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	
//}

//class Date
//{
//public:
//	void Print()const//const���ε���*this ,�����Ǹı�this����,const Date *this(��ϸ��const Date* const this)��Ȩ�޵�ƽ��
//			{
//				cout << _year << "-" << _month << "-" << _day << endl;
//			}
//	Date(int year,int month,int day)
//	{
//		int _year = year;
//		int _month = month;
//		int _day = day;
//	}
//private:
//	int _year; // ��
//	int _month; // ��
//	int _day; // ��
//};
//
//int main()
//{
//	const Date d1(2024, 9, 23);//Ȩ�޵�ƽ��
//	d1.Print();
//
//	Date d2(2024, 9, 22);
//	d2.Print();//��constҲ���Ե��ã�Ȩ�޵���С
//
//	
//	return 0;
//}

//class A
//{
//public:
//	A* operator&()
//	{
//
//		cout << "A* operator&()" << endl;
//		return nullptr;//���뱻ȡ��ַ
//	}
//	const A* operator&()const
//	{
//		cout << "A* operator&()const" << endl;
//		return (const A*)0xffffffff;//���������ٵ�ַ
//	}
//
//private:
//	int _a1 = 1;
//	int _a2 = 2;
//	int _a3 = 3;
//};
//
//int main()
//{
//	A aa1;
//	const A aa2;
//	
//	cout << &aa1 << endl;
//	cout << &aa2 << endl;
//	return 0;
//}

class A
{
public:
	//���ǲ�ʵ�֣����������Լ�ʵ�֣�����ʵ���˱������Ͳ����Լ�ʵ��
	/*A* operator&()
	{

		cout << "A* operator&()" << endl;
		return this;
	}
	const A* operator&()const
	{
		cout << "A* operator&()const" << endl;
		return this;
	}*///��д��Ҳ��ȡ��ַ

private:
	int _a1 = 1;
	int _a2 = 2;
	int _a3 = 3;
};

int main()
{
	A aa1;
	const A aa2;

	cout << &aa1 << endl;
	cout << &aa2 << endl;
	return 0;
}