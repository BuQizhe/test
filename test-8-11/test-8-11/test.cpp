#include<iostream>
using namespace std;

//class Time
//{//public:
//	Time()//	{
//		cout << "Time()" << endl;
//		_hour = 0;
//		_minute = 0;
//		_second = 0;
//	}
//private://	int _hour;//	int _minute;//	int _second;
//};
//class Date
//{//private:
//	// ��������(��������)
//	int _year;
//	int _month;
//	int _day;
//	// �Զ�������
//	Time _t;
//};
//int main()
//{
//	Date d;
//	return 0;
//}


//class Time
//{
//public://	Time()//	{
//		cout << "Time()" << endl;
//		_hour = 0;
//		_minute = 0;
//		_second = 0;
//	}
//private://	int _hour;//	int _minute;//	int _second;
//};
//class Date
//{//private:
//	// ��������(��������)
//	int _year = 1970;
//	int _month = 1;
//	int _day = 1;
//	// �Զ�������
//	Time _t;
//};
//int main()
//{
//	Date d;
//	return 0;//}//class Date
//{//public:
//	Date()//	{
//		_year = 1900;//		_month = 1;//		_day = 1;
//	}
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;//		_month = month;//		_day = day;
//	}
//private://	int _year;//	int _month;//	int _day;
//};
//// ���²��Ժ�����ͨ��������
//void Test()
//{
//	Date d1;
//}



//typedef int DataType;
//class Stack
//{//public:
//	Stack(size_t capacity = 3)
//	{
//		_array = (DataType*)malloc(sizeof(DataType) * capacity);
//		if (NULL == _array)
//		{
//			perror("malloc����ռ�ʧ��!!!");//			return;
//		}
//		_capacity = capacity;
//		_size = 0;
//	}
//	void Push(DataType data)
//	{
//		// CheckCapacity();
//		_array[_size] = data;
//		_size++;//	}
//	// ��������...
//	~Stack()//	{
//		if (_array)//		{
//			free(_array);//			_array = NULL;//			_capacity = 0;//			_size = 0;
//			
//		}//	}//private:
//	DataType* _array;//	int _capacity;//	int _size;
//};
//void TestStack()
//{
//	Stack s;//	s.Push(1);//	s.Push(2);
//}
//int main()
//{
//	TestStack();
//	return 0;
//}

class Time
{public:
	~Time()	{
		cout << "~Time()" << endl;
	}
private:	int _hour;	int _minute;	int _second;
};
class Date
{private:
	// ��������(��������)
	int _year = 1970;
	int _month = 1;
	int _day = 1;
	// �Զ�������
	Time _t;
};
int main()
{
	Date d;
	return 0;}
// �������н����������~Time()
// ��main�����и���û��ֱ�Ӵ���Time��Ķ���Ϊʲô�������Time�������������// ��Ϊ��main�����д�����Date����d����d�а���4����Ա����������_year, _month,_day������
// �������ͳ�Ա������ʱ����Ҫ��Դ�������ϵͳֱ�ӽ����ڴ���ռ��ɣ���_t��Time�����������
// d����ʱ��Ҫ�����ڲ�������Time���_t�������٣�����Ҫ����Time����������������ǣ�main����
// �в���ֱ�ӵ���Time�������������ʵ��Ҫ�ͷŵ���Date��������Ա����������Date���������
// ������Dateû����ʽ�ṩ������������Date������һ��Ĭ�ϵ�����������Ŀ���������ڲ�����Time
// �����������������Date��������ʱ��Ҫ��֤���ڲ�ÿ���Զ�����󶼿�����ȷ����
// main�����в�û��ֱ�ӵ���Time������������������ʽ���ñ�����ΪDate�����ɵ�Ĭ����������
// ע�⣺�����ĸ���Ķ�������ø�������������������Ǹ���Ķ�������ø������������