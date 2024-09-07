#include"Date.h"

Date::Date(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
}

void Date::Print()
{
	cout << _year << "-" << _month << "-" << _day << endl;
}

//d1<d2
bool Date::operator<(const Date& d)
{
	if (_year < d._day)
	{
		return true;
	}
	else if (_year == d._year)
	{
		if (_month < d._month)
		{
			return true;
		}
		else if (_month == d._month)
		{
			return _day < d._day;
		}
	}
	return false;
}

//d1<=d2
bool Date::operator<=(const Date& d)
{
	return *this < d || *this == d;
}

bool Date::operator>(const Date& d)
{
	return !(*this < d);
}
bool Date::operator>=(const Date& d)
{
	return !(*this < d);
}
bool Date::operator==(const Date& d)
{
	return _year == d._year
		&& _month == d._month
		&& _day == d._day;
}
bool Date::operator!=(const Date& d)
{
	return !(*this == d);
}

//d1+=50
Date& Date::operator+=(int day)
{
	if (day<0)
	{
		return *this -= -day;
	}
	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		++_month;
		if (_month == 13)
		{
			++_year;
			_month = 1;
		}
	}
	return *this;
}

Date Date::operator+(int day)
{
	Date tmp = *this;
	tmp += day;

	return tmp;
}


//d1-=100
Date& Date::operator-=(int day)
{
	if (day < 0)
	{
		return *this += -day;
	}
	_day -= day;
	while (_day<=0)
	{
		--_month;
		if (_month==0)
		{
			_month = 12;
			_year--;
		}

		//借上一个月的天数
		_day -= GetMonthDay(_year, _month);
	}


	return *this;
}


Date Date::operator-(int day)
{
	Date tmp = *this;
	tmp -= day;

	return tmp;
}





