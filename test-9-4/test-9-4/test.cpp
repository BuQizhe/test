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
//    // ��ʾ����
//    operator==(d3,d4);//���س���ĳ�Ա��������ʾ����Ҫ���޸�
//
//    // ֱ��д��ת������
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

	//��ʽ��ֵ
	//d1=d4
	/*void operator=(const Date& d)
	{
			_year = d._year;
			_month = d._month;
			_day = d._day;
	}*/


	//d1=d4
	//d1=d2=d4,d��d4�ı�����d4��ֵ��d2������d2��thisָ�룬d2�ٰ�ֵ��d1��һ��thisָ������ز�д���������õ����󣬿���������
	//void��Date��Ϊ��������ֵ
	/*Date operator=(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;

		return *this;
	}*/


	//�����÷��غʹ�ֵ����
	// ��ֵ���ػ����һ����ʱ�������ز�����������ʱ��
	// �����ñ��������ٿռ�Ŀ��٣�һ����������ú����ñ�������һ��ռ䣬�ٶ�Ч�ʸ���
	//Ϊ�˷�ֹ�Լ����Լ���ֵ�����磺d1=d1����if����Ż�
	Date &operator=(const Date& d)
	{
		if (this!=&d)//��ֹ�Լ����Լ���ֵ
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
//	//��������
//	//һ���Ѿ����ڵĶ��󣬿�������һ��Ҫ������ʼ���Ķ���
//	Date d2(d1);
//	Date d3 = d1;
//
//	Date d4(2024, 9, 4);
//
//	//��ֵ����/��ֵ����
//	//һ���Ѿ����ڵĶ��󣬿�����ֵ����һ���Ѿ����ڵĶ���
//	d1 = d4;
//
//	d1 = d2 = d4;//������ֵ
//
//	return 0;
//}

//Date func()
//{
//	Date d(2024, 9, 3);
//	return d;
//	//���ص�d����d��һ����ʱ��������ʱ�������г���
//}
//int main()
//{
//	//���ص�func��һ����ʱ��������ʱ������г��ԣ�ֱ��ʹ��ʱ����Ȩ�޵ķŴ�Ҫ��const��ǰ��
//	const Date& ref = func();
//
//	return 0;
//}


Date& func()
{
	 static Date d(2024, 9, 3);//static ������������û�������ǾͿ��������÷��أ����ٿ���
	return d;
	//����Ǵ�ֵ���أ�û��&��û��static���ص�d��d��һ����ʱ��������ʱ�������г���
	//�����&��û��static�����÷��أ�������d�ı���
}
//�ܽ᣺
//1.���ض����������ڵ��ˣ�����������ֵ����
//2.���ض�����������û�������������������÷���


int fx()
{
	int a = 1;
	int b = 2;
	int c = 3;

	return a + b + c;
}
int main() 
{ 
	//����Ǵ�ֵ���أ�û��&�����ص�func��һ����ʱ��������ʱ������г��ԣ�ֱ��ʹ��ʱ����Ȩ�޵ķŴ�Ҫ��const��ǰ�棬Ȩ�޵���С��
	// ��������÷��ؼӲ���const������ν
	//����������ʱ������������d

	Date& ref = func();
	//���������һ��䲻��&,���Ǵ�ֵ����Ҫ����һ����ʱ����
	//�����&�����÷��أ�����d������ ��ref�൱����d�ı�������Ƭ�ռ�
	//���ǻ�������ֵ����Ϊd����func�������Զ���������������������Դ�ռ䣬ref��ָ�����ٵ���Ƭ�ռ䣬�����е�����Ұָ�룬Ұ����
	fx();//�����µ���������к���ʹ�ã��Ḳ��ԭ�����ٵĿռ䣬�������ֵ

	return 0;
}

