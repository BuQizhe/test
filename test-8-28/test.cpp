//#include<iostream>
//using namespace std;

//class Date
//{
//public:
//	Date(int year = 2024, int month = 8, int day = 28)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	
//	
//	int GetYear()
//	{
//		return _year;
//	}
//
//	int GetMonth()
//	{
//		return _month;
//	}
//	int GetDay()
//	{
//		return _day;
//	}
////private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//bool operator==(const Date& d1, const Date& d2)
//{
// return d1._year == d2._year&& d1._month == d2._month&& d1._day == d2._day;
//}
//
//int main()
//{
//	Date d3(2024, 8, 28);
//	Date d4(2024, 8, 29);
//
//	//��ʾ����
//	operator==(d3, d4);
//
//	//ֱ��д��ת�����ã������ת����operator==(d3,d4);
//	d3 == d4;
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//class Date
//{
//public:
//    Date(int year = 2024, int month = 8, int day = 28)
//    {
//        _year = year;
//        _month = month;
//        _day = day;
//    }
//
//    int GetYear()
//    {
//        return _year;
//    }
//
//    // ����������Ƶĺ�����ȡ�·ݺ�����
//    int GetMonth()
//    {
//        return _month;
//    }
//
//    int GetDay()
//    {
//        return _day;
//    }
//
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//
//bool operator==(Date& d1,Date& d2)
//{
//    return d1.GetYear() ==  d2.GetYear() && d1.GetMonth() == d2.GetMonth() && d1.GetDay() == d2.GetDay();
//}
//
//int main()
//{
//    Date d3(2024, 8, 28);
//    Date d4(2024, 8, 29);
//
//    // ��ʾ����
//   operator==(d3, d4);
//
//    // ֱ��д��ת������
//    d3 == d4;
//
//    return 0;
//}

//#include<iostream>
//using namespace std;
//
//class Date
//{
//public:
//	Date(int year = 2024, int month = 8, int day = 28)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	bool operator==(const Date& d2)
//	{
//		return _year = d2._year
//			&& _month == d2._month
//			&& _day == d2._day;
//	}
//
//private:
//	int _year;
//	int _month;
//	int  _day;
//};
//
//int main()
//{
//	Date d3(2024, 8, 28);
//	Date d4(2024, 8, 29);
//
//	operator==(d3, d4);
//
//	d3 == d4;
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//class Date
//{
//public:
//    Date(int year = 2024, int month = 8, int day = 28)
//    {
//        _year = year;
//        _month = month;
//        _day = day;
//    }
//    bool operator==(const Date& d2)
//    {
//        return _year == d2._year && _month == d2._month && _day == d2._day;
//    }
//    
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//
//int main()
//{
//    Date d3(2024, 8, 28);
//    Date d4(2024, 8, 29);
//
//    // ��ʾ����
//    d3.operator==(d4);//���س���ĳ�Ա��������ʾ����Ҫ���޸�
//
//    // ֱ��д��ת������
//    d3 == d4;
//
//    return 0;
//}

//
//#include <iostream>
//using namespace std;
//
//class Date
//{
//public:
//    Date(int year = 2024, int month = 8, int day = 28)
//    {
//        _year = year;
//        _month = month;
//        _day = day;
//    }
//
//    // ������Ԫ����
//    friend bool operator==(const Date& d1, const Date& d2);
//
//    /*int GetYear()
//    {
//        return _year;
//    }
//
//    int GetMonth()
//    {
//        return _month;
//    }
//
//    int GetDay()
//    {
//        return _day;
//    }*/
//
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//
//// ������Ԫ����
//bool operator==(const Date& d1, const Date& d2)
//{
//    return d1._year == d2._year && d1._month == d2._month && d1._day == d2._day;
//}
//
//int main()
//{
//    Date d3(2024, 8, 28);
//    Date d4(2024, 8, 29);
//
//    operator==(d3, d4);
//
//    d3 == d4;
//
//    return 0;
//}

#include<iostream>
using namespace std;

class Date
{
public:
	Date(int year = 2024, int month = 1,  int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1(2024, 8, 28);

	//��������
	//һ���Ѿ����ڵĶ��󣬿�������һ��Ҫ������ʼ���Ķ���
	Date d2(d1);
	Date d3 = d1;

	Date d4(2024, 8, 29);

	//��ֵ����/��ֵ����
	//һ���Ѿ����ڵĶ��󣬿�����ֵ����һ���Ѿ����ڵĶ���
	d1 = d4;

	//������ֵ
	d1 = d2 = d4;
	//d4����d2����ֵΪDate���ٸ�ֵ��d1

	return 0;
}