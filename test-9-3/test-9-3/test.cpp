#include<iostream>
using namespace std;

class Date
{
public:
	Date(int year = 2024, int month = 9, int day = 3)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	int _year;
	int _month;
	int _day;
};

// ��ֵ��������س�ȫ�ֺ�����ע�����س�ȫ�ֺ���ʱû��thisָ���ˣ���Ҫ����������
Date& operator=(Date& left, const Date& right)
{
	if (&left != &right)
	{
		left._year = right._year;
		left._month = right._month;
		left._day = right._day;
	}
	return left;
}

int main()
{
	Date d1;

	return 0;
}

// ����ʧ�ܣ�
// error C2801: ��operator =�������ǷǾ�̬��Ա