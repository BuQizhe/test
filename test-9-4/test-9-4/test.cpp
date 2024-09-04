#include<iostream>
using namespace std;

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
//    //d3.operator==(d4)
//    /*bool operator==(const Date& d2)
//    {
//        return this->_year == d2._year 
//            && this->_month == d2._month 
//            && this->_day == d2._day;
//    }*/
//
////private:
//    int _year;
//    int _month;
//    int _day;
//};
//
//bool operator==(const Date &d1,const Date& d2)
//{
//    return d1._year == d2._year && d1._month == d2._month && d1._day == d2._day;
//}
//
//int main()
//{
//    Date d3(2024, 8, 28);
//    Date d4(2024, 8, 29);
//
//    // 显示调用
//    operator==(d3,d4);//重载成类的成员函数，显示调用要做修改
//
//    // 直接写，转换调用
//    d3 == d4;
//
//    return 0;
//}

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
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

	//显式赋值
	//d1=d4
	/*void operator=(const Date& d)
	{
			_year = d._year;
			_month = d._month;
			_day = d._day;
	}*/


	//d1=d4
	//d1=d2=d4,d是d4的别名，d4赋值给d2，返回d2的this指针，d2再把值给d1。一般this指针可隐藏不写，但在有用的需求，可以拿来用
	//void变Date，为了连续赋值
	/*Date operator=(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;

		return *this;
	}*/


	//传引用返回和传值返回
	// 传值返回会产生一份临时变量返回并拷贝，产生时间
	// 引用用别名，减少空间的开辟，一般情况下引用和引用变量共用一块空间，速度效率更快
	//为了防止自己给自己赋值，例如：d1=d1，用if语句优化
	Date &operator=(const Date& d)
	{
		if (this!=&d)//防止自己给自己赋值
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

//int main()
//{
//	Date d1(2024, 9, 1);
//	
//	//拷贝构造
//	//一个已经存在的对象，拷贝给另一个要创建初始化的对象
//	Date d2(d1);
//	Date d3 = d1;
//
//	Date d4(2024, 9, 4);
//
//	//赋值拷贝/赋值重载
//	//一个已经存在的对象，拷贝赋值给另一个已经存在的对象
//	d1 = d4;
//
//	d1 = d2 = d4;//连续赋值
//
//	return 0;
//}

//Date func()
//{
//	Date d(2024, 9, 3);
//	return d;
//	//返回的d，是d的一份临时拷贝，临时变量具有常性
//}
//int main()
//{
//	//返回的func是一份临时变量，临时对象具有常性，直接使用时对其权限的放大，要加const在前面
//	const Date& ref = func();
//
//	return 0;
//}


Date& func()
{
	 static Date d(2024, 9, 3);//static ：出了作用域还没析构，那就可以用引用返回，减少拷贝
	return d;
	//如果是传值返回，没有&，没有static返回的d是d的一份临时拷贝，临时变量具有常性
	//如果加&，没有static，引用返回，返回是d的别名
}
//总结：
//1.返回对象生命周期到了，会析构，传值返回
//2.返回对象生命周期没到，不会析构，传引用返回


int fx()
{
	int a = 1;
	int b = 2;
	int c = 3;

	return a + b + c;
}
int main() 
{ 
	//如果是传值返回，没有&，返回的func是一份临时变量，临时对象具有常性，直接使用时对其权限的放大，要加const在前面，权限的缩小，
	// 如果是引用返回加不加const都无所谓
	//拷贝的是临时对象，析构的是d

	Date& ref = func();
	//如果上面这一语句不加&,就是传值，又要拷贝一份临时变量
	//如果加&是引用返回，引用d的引用 ，ref相当于是d的别名，那片空间
	//但是会产生随机值，因为d出了func作用域，自动调用析构函数，销毁资源空间，ref又指向销毁的那片空间，所以有点类似野指针，野引用
	fx();//更可怕的是如果再有函数使用，会覆盖原本销毁的空间，又是随机值

	return 0;
}

