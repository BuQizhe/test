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
//	void Print()const//const修饰的是*this ,本质是改变this类型,const Date *this(详细是const Date* const this)，权限的平移
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
//	int _year; // 年
//	int _month; // 月
//	int _day; // 日
//};
//
//int main()
//{
//	const Date d1(2024, 9, 23);//权限的平移
//	d1.Print();
//
//	Date d2(2024, 9, 22);
//	d2.Print();//非const也可以调用，权限的缩小
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
//		return nullptr;//不想被取地址
//	}
//	const A* operator&()const
//	{
//		cout << "A* operator&()const" << endl;
//		return (const A*)0xffffffff;//或故意给个假地址
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
	//我们不实现，编译器会自己实现，我们实现了编译器就不会自己实现
	/*A* operator&()
	{

		cout << "A* operator&()" << endl;
		return this;
	}
	const A* operator&()const
	{
		cout << "A* operator&()const" << endl;
		return this;
	}*///不写，也会取地址

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