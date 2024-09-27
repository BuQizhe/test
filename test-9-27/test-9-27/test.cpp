// g++ 18_friend_fun.cpp 
#include <iostream>
using namespace std;

class CDate
{
	friend CDate operator+(int day, const CDate& date);	// ��Ԫ��������
public:
	CDate(int year, int mon, int day);	// ���캯������
	CDate(const CDate& date);			// �������캯������
	CDate operator+(int day);			// �Ӻ����������

private:
	int m_year;
	int m_mon;
	int m_day;
};

// ���캯������
CDate::CDate(int year, int mon, int day)
{
	m_year = year;
	m_mon = mon;
	m_day = day;
	cout << "Calling Constructor" << ", this=" << this << endl;
}

// �������캯������
CDate::CDate(const CDate& date)
{
	m_year = date.m_year;
	m_mon = date.m_mon;
	m_day = date.m_day;
	cout << "Calling Copy Constructor" << ", this=" << this << ", Copy Data" << endl;
}

// �Ӻ����������
CDate CDate::operator+(int day)
{
	CDate temp = *this;
	temp.m_day += day;
	cout << "Calling operator+(int)" << ", this=" << &temp << endl;
	return temp;
}

// ��Ԫ��������
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
	CB = 1 + CA;	// ���û��ʵ����Ԫ����������䱨��
	return 0;
}
