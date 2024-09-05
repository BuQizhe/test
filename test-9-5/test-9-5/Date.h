#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

class Date
{
public:
	Date(int year = 2024, int month = 9, int day = 1);
	void Print();
	bool operator<(const Date& d);
	bool operator<=(const Date& d);
	bool operator>(const Date& d);
	bool operator>=(const Date& d);
	bool operator==(const Date& d);
	bool operator!=(const Date& d);
	
	//d1+100
	Date operator+=(int day);
	Date operator-=(int day);

	Date operator+(int day);
	Date operator-(int day);

	//直接定义类里面，他默认是inline
	//频繁调用
	int GetMonthDay(int year, int month)
	{
		assert(month > 0 && month < 13);
		static int monthDayArray[13] = { -1,31,28,31,30,31,30,31,31,30,31,30,31 };
		if (month==2 && (year%4==0&&year%100!=0||year%400==0))
		{
			return 29;
		}
		else
		{
			return monthDayArray[month];
		}
	}

	/*Date(const Date& d)
	{
		cout << "Date(const Date &d)" << endl;

		_year = d._year;
		_month = d._month;
		_day = d._day;
	}*/

	
	/*~Date()
	{
		cout << "~Date()" << endl;
		_year = -1;
		_month = -1;
		_day = -1;
	}*/
private:
	int _year;
	int _month;
	int _day;
};
