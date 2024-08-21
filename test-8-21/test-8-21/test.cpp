//// 全局的operator==
//class Date
//{//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;//		_month = month;//		_day = day;
//	}
//	//private:
//	int _year;
//	int _month;
//	int _day;
//};
//// 这里会发现运算符重载成全局的就需要成员变量是公有的，那么问题来了，封装性如何保证？//// 这里其实可以用我们后面学习的友元解决，或者干脆重载成成员函数。
//bool operator==(const Date& d1, const Date& d2)
//{
//	return d1._year == d2._year
//		&& d1._month == d2._month
//		&& d1._day == d2._day;
//}
//void Test()
//{
//	Date d1(2018, 9, 26);
//	Date d2(2018, 9, 27);
//	cout << (d1 == d2) << endl;//}
//class Date
//{//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;//		_month = month;//		_day = day;
//	}
//	// bool operator==(Date* this, const Date& d2)//	// 这里需要注意的是，左操作数是this，指向调用函数的对象
//	bool operator==(const Date& d2)
//	{
//		return _year == d2._year;
//		&& _month == d2._month
//			&& _day == d2._day;
//	}
//private://	int _year;//	int _month;//	int _day;
//};

//class Date
//{//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;//		_month = month;//		_day = day;
//	}
//	Date(const Date& d)
//	{
//		_year = d._year;//		_month = d._month;//		_day = d._day;
//	}
//	Date& operator=(const Date& d)
//	{
//		if (this != &d)
//		{
//			_year = d._year;//			_month = d._month;//			_day = d._day;
//		}
//		return *this;
//	}//private://	int _year;
//	int _month;
//	int _day;
//}

//class Time
//{
//public://	Time()//	{
//		_hour = 1;
//		_minute = 1;
//		_second = 1;
//	}
//	Time& operator=(const Time& t)
//	{
//		if (this != &t)
//		{
//			_hour = t._hour;
//			_minute = t._minute;
//			_second = t._second;
//		}
//		return *this;
//	}
//private://	int _hour;//	int _minute;//	int _second;
//};
//class Date
//{//private:
//	// 基本类型(内置类型)
//	int _year = 1970;
//	int _month = 1;
//	int _day = 1;
//	// 自定义类型
//	Time _t;
//};
//int main()
//{
//	Date d1;
//	Date d2;
//	d1 = d2;
//	return 0;
//};

//// 这里会发现下面的程序会崩溃掉？这里就需要我们以后讲的深拷贝去解决。
//typedef int DataType;
//class Stack
//{//public:
//	Stack(size_t capacity = 10)
//	{
//		_array = (DataType*)malloc(capacity * sizeof(DataType));
//		if (nullptr == _array)
//		{
//			perror("malloc申请空间失败");//			return;
//		}
//			_size = 0;
//		_capacity = capacity;
//	}
//	void Push(const DataType& data)
//	{
//		// CheckCapacity();
//		_array[_size] = data;
//		_size++;//	}
//	~Stack()//	{
//		if (_array)//		{
//			free(_array);//			_array = nullptr;//			_capacity = 0;//			_size = 0;
//		}//	}
//private:
//	DataType* _array;//	size_t _size;//	size_t _capacity;
//};//int main()
//{
//	Stack s1;//	s1.Push(1);//	s1.Push(2);//	s1.Push(3);//	s1.Push(4);
//	Stack s2;//	s2 = s1;//	return 0;
//}

//class Date
//{//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;//		_month = month;//		_day = day;
//	}
//	// 前置++：返回+1之后的结果
//	// 注意：this指向的对象函数结束后不会销毁，故以引用方式返回提高效率
//	Date& operator++()
//	{
//		_day += 1;
//		return *this;//	}
//	// 后置++：
//	// 前置++和后置++都是一元运算符，为了让前置++与后置++形成能正确重载
//	// C++规定：后置++重载时多增加一个int类型的参数，但调用函数时该参数不用传递，编译器自动传递
//		// 注意：后置++是先使用后+1，因此需要返回+1之前的旧值，故需在实现时需要先将this保存	一份，然后给this + 1
//		// 而temp是临时对象，因此只能以值的方式返回，不能返回引用
//	Date operator++(int)
//	{
//		Date temp(*this);
//		_day += 1;
//		return temp;//	}
//private://	int _year;//	int _month;//	int _day;
//};
//
//int main()
//{
//	Date d;
//	Date d1(2022, 1, 13);
//	d = d1++; // d: 2022,1,13 d1:2022,1,14
//	d = ++d1; // d: 2022,1,15 d1:2022,1,15
//	return 0;
//}

//class Date
//{//public:
//	// 获取某年某月的天数
//	int GetMonthDay(int year, int month)
//	{
//		static int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30,
//		31 };
//		int day = days[month];
//		if (month == 2
//			&& ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
//		{
//			day += 1;
//		}
//		return day;
//	}
//	// 全缺省的构造函数
//	Date(int year = 1900, int month = 1, int day = 1);
//	// 拷贝构造函数//	// d2(d1)
//	Date(const Date& d);
//	// 赋值运算符重载
//	// d2 = d3 -> d2.operator=(&d2, d3)
//	Date& operator=(const Date& d);
//	// 析构函数
//	~Date();
//	// 日期+=天数
//	Date& operator+=(int day);
//	// 日期+天数
//	Date operator+(int day);
//	// 日期-天数
//	Date operator-(int day);
//	// 日期-=天数
//	Date& operator-=(int day);
//	// 前置++
//	Date& operator++();
//	// 后置++
//	Date operator++(int);
//	// 后置--
//	Date operator--(int);
//	// 前置--
//	Date& operator--();
//	// >运算符重载
//	bool operator>(const Date& d);
//	// ==运算符重载
//	bool operator==(const Date& d);
//	// >=运算符重载
//	bool operator >= (const Date& d);
//	// <运算符重载
//	bool operator < (const Date& d);
//	// <=运算符重载
//	bool operator <= (const Date& d);
//	// !=运算符重载
//	bool operator != (const Date& d);
//	// 日期-日期 返回天数
//	int operator-(const Date& d);
//private://	int _year;//	int _month;//	int _day;
//};

//class Date
//{//public:
//	Date(int year, int month, int day)
//	{
//		_year = year;//		_month = month;//		_day = day;
//	}
//	void Print()
//	{
//		cout << "Print()" << endl;
//		cout << "year:" << _year << endl;
//		cout << "month:" << _month << endl;
//		cout << "day:" << _day << endl << endl;
//	}
//	void Print() const
//	{
//		cout << "Print()const" << endl;
//		cout << "year:" << _year << endl;
//		cout << "month:" << _month << endl;
//		cout << "day:" << _day << endl << endl;
//	}//private:
//	int _year; // 年
//	int _month; // 月
//	int _day; // 日
//};
//void Test()
//{
//	Date d1(2022, 1, 13);
//	d1.Print();
//	const Date d2(2022, 1, 13);
//	d2.Print();//}

class Date
{public:
	Date* operator&()
	{
		return this;
	}
	const Date* operator&()const
	{
		return this;
	}private:
	int _year; // 年
	int _month; // 月
	int _day; // 日
}