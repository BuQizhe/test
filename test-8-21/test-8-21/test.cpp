//// ȫ�ֵ�operator==
//class Date
//{
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//	}
//	//private:
//	int _year;
//	int _month;
//	int _day;
//};
//// ����ᷢ����������س�ȫ�ֵľ���Ҫ��Ա�����ǹ��еģ���ô�������ˣ���װ����α�֤��
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
//	cout << (d1 == d2) << endl;
//class Date
//{
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//	}
//	// bool operator==(Date* this, const Date& d2)
//	bool operator==(const Date& d2)
//	{
//		return _year == d2._year;
//		&& _month == d2._month
//			&& _day == d2._day;
//	}
//private:
//};

//class Date
//{
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//	}
//	Date(const Date& d)
//	{
//		_year = d._year;
//	}
//	Date& operator=(const Date& d)
//	{
//		if (this != &d)
//		{
//			_year = d._year;
//		}
//		return *this;
//	}
//	int _month;
//	int _day;
//}

//class Time
//{
//public:
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
//private:
//};
//class Date
//{
//	// ��������(��������)
//	int _year = 1970;
//	int _month = 1;
//	int _day = 1;
//	// �Զ�������
//	Time _t;
//};
//int main()
//{
//	Date d1;
//	Date d2;
//	d1 = d2;
//	return 0;
//};

//// ����ᷢ������ĳ������������������Ҫ�����Ժ󽲵����ȥ�����
//typedef int DataType;
//class Stack
//{
//	Stack(size_t capacity = 10)
//	{
//		_array = (DataType*)malloc(capacity * sizeof(DataType));
//		if (nullptr == _array)
//		{
//			perror("malloc����ռ�ʧ��");
//		}
//			_size = 0;
//		_capacity = capacity;
//	}
//	void Push(const DataType& data)
//	{
//		// CheckCapacity();
//		_array[_size] = data;
//		_size++;
//	~Stack()
//		if (_array)
//			free(_array);
//		}
//private:
//	DataType* _array;
//};
//{
//	Stack s1;
//	Stack s2;
//}

//class Date
//{
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//	}
//	// ǰ��++������+1֮��Ľ��
//	// ע�⣺thisָ��Ķ����������󲻻����٣��������÷�ʽ�������Ч��
//	Date& operator++()
//	{
//		_day += 1;
//		return *this;
//	// ����++��
//	// ǰ��++�ͺ���++����һԪ�������Ϊ����ǰ��++�����++�γ�����ȷ����
//	// C++�涨������++����ʱ������һ��int���͵Ĳ����������ú���ʱ�ò������ô��ݣ��������Զ�����
//		// ע�⣺����++����ʹ�ú�+1�������Ҫ����+1֮ǰ�ľ�ֵ��������ʵ��ʱ��Ҫ�Ƚ�this����	һ�ݣ�Ȼ���this + 1
//		// ��temp����ʱ�������ֻ����ֵ�ķ�ʽ���أ����ܷ�������
//	Date operator++(int)
//	{
//		Date temp(*this);
//		_day += 1;
//		return temp;
//private:
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
//{
//	// ��ȡĳ��ĳ�µ�����
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
//	// ȫȱʡ�Ĺ��캯��
//	Date(int year = 1900, int month = 1, int day = 1);
//	// �������캯��
//	Date(const Date& d);
//	// ��ֵ���������
//	// d2 = d3 -> d2.operator=(&d2, d3)
//	Date& operator=(const Date& d);
//	// ��������
//	~Date();
//	// ����+=����
//	Date& operator+=(int day);
//	// ����+����
//	Date operator+(int day);
//	// ����-����
//	Date operator-(int day);
//	// ����-=����
//	Date& operator-=(int day);
//	// ǰ��++
//	Date& operator++();
//	// ����++
//	Date operator++(int);
//	// ����--
//	Date operator--(int);
//	// ǰ��--
//	Date& operator--();
//	// >���������
//	bool operator>(const Date& d);
//	// ==���������
//	bool operator==(const Date& d);
//	// >=���������
//	bool operator >= (const Date& d);
//	// <���������
//	bool operator < (const Date& d);
//	// <=���������
//	bool operator <= (const Date& d);
//	// !=���������
//	bool operator != (const Date& d);
//	// ����-���� ��������
//	int operator-(const Date& d);
//private:
//};

//class Date
//{
//	Date(int year, int month, int day)
//	{
//		_year = year;
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
//	}
//	int _year; // ��
//	int _month; // ��
//	int _day; // ��
//};
//void Test()
//{
//	Date d1(2022, 1, 13);
//	d1.Print();
//	const Date d2(2022, 1, 13);
//	d2.Print();

class Date
{
	Date* operator&()
	{
		return this;
	}
	const Date* operator&()const
	{
		return this;
	}
	int _year; // ��
	int _month; // ��
	int _day; // ��
}