#include<iostream>
using namespace std;

//class Time
//{
//	Time()
//		cout << "Time()" << endl;
//		_hour = 0;
//		_minute = 0;
//		_second = 0;
//	}
//private:
//};
//class Date
//{
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
//public:
//		cout << "Time()" << endl;
//		_hour = 0;
//		_minute = 0;
//		_second = 0;
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
//	Date d;
//	return 0;
//{
//	Date()
//		_year = 1900;
//	}
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//	}
//private:
//};
//// ���²��Ժ�����ͨ��������
//void Test()
//{
//	Date d1;
//}



//typedef int DataType;
//class Stack
//{
//	Stack(size_t capacity = 3)
//	{
//		_array = (DataType*)malloc(sizeof(DataType) * capacity);
//		if (NULL == _array)
//		{
//			perror("malloc����ռ�ʧ��!!!");
//		}
//		_capacity = capacity;
//		_size = 0;
//	}
//	void Push(DataType data)
//	{
//		// CheckCapacity();
//		_array[_size] = data;
//		_size++;
//	// ��������...
//	~Stack()
//		if (_array)
//			free(_array);
//			
//		}
//	DataType* _array;
//};
//void TestStack()
//{
//	Stack s;
//}
//int main()
//{
//	TestStack();
//	return 0;
//}

class Time
{
	~Time()
		cout << "~Time()" << endl;
	}
private:
};
class Date
{
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
	return 0;
// �������н����������~Time()
// ��main�����и���û��ֱ�Ӵ���Time��Ķ���Ϊʲô�������Time�������������
// �������ͳ�Ա������ʱ����Ҫ��Դ���������ϵͳֱ�ӽ����ڴ���ռ��ɣ���_t��Time�����������
// d����ʱ��Ҫ�����ڲ�������Time���_t�������٣�����Ҫ����Time����������������ǣ�main����
// �в���ֱ�ӵ���Time�������������ʵ��Ҫ�ͷŵ���Date��������Ա����������Date���������
// ������Dateû����ʽ�ṩ������������Date������һ��Ĭ�ϵ�����������Ŀ���������ڲ�����Time
// �����������������Date��������ʱ��Ҫ��֤���ڲ�ÿ���Զ�����󶼿�����ȷ����
// main�����в�û��ֱ�ӵ���Time������������������ʽ���ñ�����ΪDate�����ɵ�Ĭ����������
// ע�⣺�����ĸ���Ķ�������ø�������������������Ǹ���Ķ�������ø������������