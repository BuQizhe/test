// g++ 18_friend_fun.cpp 
#include <iostream>
using namespace std;

class CDate
{
	friend CDate operator+(int day, const CDate& date);	// 友元函数声明
public:
	CDate(int year, int mon, int day);	// 构造函数声明
	CDate(const CDate& date);			// 拷贝构造函数声明
	CDate operator+(int day);			// 加号运算符声明

private:
	int m_year;
	int m_mon;
	int m_day;
};

// 构造函数定义
CDate::CDate(int year, int mon, int day)
{
	m_year = year;
	m_mon = mon;
	m_day = day;
	cout << "Calling Constructor" << ", this=" << this << endl;
}

// 拷贝构造函数定义
CDate::CDate(const CDate& date)
{
	m_year = date.m_year;
	m_mon = date.m_mon;
	m_day = date.m_day;
	cout << "Calling Copy Constructor" << ", this=" << this << ", Copy Data" << endl;
}

// 加号运算符定义
CDate CDate::operator+(int day)
{
	CDate temp = *this;
	temp.m_day += day;
	cout << "Calling operator+(int)" << ", this=" << &temp << endl;
	return temp;
}

// 友元函数定义
CDate operator+(int day, const CDate& date)
{
	CDate temp = date;
	temp.m_day += day;
	cout << "Calling operator+(int, CDate)" << ", temp=" << &temp << endl;
	return temp;
}

int main()
{
	CDate date(2024, 6, 17);
	CDate CB = CA + 1;
	CB = 1 + CA;	// 如果没有实现友元函数，则这句报错
	return 0;
}
