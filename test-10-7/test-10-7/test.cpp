//#include<iostream>
//using namespace std;

//typedef int DateaType;
//
//class Stack
//{
//public:
//	Stack(size_t capacity=3) 
//	{
//		_array = (DateaType*)malloc(sizeof(DateaType) * capacity);
//		if (NULL==_array)
//		{
//			perror("mallloc����ռ�ʧ�ܣ�����");
//			return;
//		}
//		_capacity = capacity;
//		_size = 0;
//	}
//
//	void Push(DateaType data)
//	{
//		_array[_size] = data;
//		_size++;
//	}
//
//	~Stack()
//	{
//		if (_array)
//		{
//			free(_array);
//			_array = NULL;
//			_capacity = 0;
//			_size = 0;
//		}
//	}
//private:
//	DateaType* _array;
//	int _capacity;
//	int _size;
//};
//
//class MyQueue
//{
//public:
//	//��ʼ���б�������д��д��ÿ����Ա������������һ��
//	//�Զ������͵ĳ�Ա�����Ĭ�Ϲ���(û��Ĭ�Ϲ���ͱ��뱨��)
//	//����������ȱʡֵ��ȱʡֵ��û�еĻ�����ȷ��,Ҫ�����������еı������ᴦ���еĲ��ᴦ��
//	//���߳�ʼ���б����ߺ�����
//	//ʵ���У�������ʹ�ó�ʼ���б��ʼ������������ʹ�ú������ʼ��
//	/*MyQueue()
//	{}*/
//
//	/*Stack���߱�Ĭ�Ϲ��졣MyQueueҲ�޷�����Ĭ�Ϲ���
//	��ʼ���б�
//	��ʼ���б��ʿ������Ϊÿ�������г�Ա����ĵط�
//	���еĳ�Ա��������ڳ�ʼ���б��ʼ����Ҳ�����ں������ڲ���ʼ��
//	1.���� 2.const 3.û��Ĭ�Ϲ����Զ������ͳ�Ա��������ʽ���ε����죩*/
//
//	MyQueue(int n, int& rr)
//		:_Pushst(n)
//		,_Popst(n)
//		,_x(1)
//		,_ret(rr)
//		,_ptr((int*)malloc(8))
//	{
//		//ȱʡֵ�Ǹ���ʼ���б��õ�
//		_size = 0;
//		//_x=1;
//	}
//private:
//	//����
//	Stack _Pushst;
//	Stack _Popst;
//	int _size;
//
//	int* _ptr;
//
//	//�����ڶ���ʱ��ʼ��
//	const int _x;
//
//	//�����ڶ���ʱ��ʼ��
//	int& _ret;
//};
//
//int main()
//{
//	int xx = 0;
//	MyQueue q(10,xx);
//
//	//const int y = 2;
//
//	//int& ry;  //Ҫ��ʼ�� 
//	return 0;
//}
//
//
//class A
//{
//public:
//	A(int a)
//		:_a1(a)
//		, _a2(_a1)
//	{}
//
//	void Print() {
//		cout << _a1 << " " << _a2 << endl;
//	}
//
//private:
//	int _a2;
//	int _a1;
//};
//
//int main() {
//	A aa(1);
//	aa.Print();
//}
//
////���1�����ֵ
////��Ա����������������������ڳ�ʼ���б��г�ʼ��˳�������ڳ�ʼ���б��е��Ⱥ�����޹�


//class A
//{
//public:
//	//���������캯��
//	A(int a)
//		:_a(a)
//	{
//		cout << "A(int a)" << endl;
//	}
//
//	A(const A& aa)
//		:_a(aa._a)
//	{
//		cout << "A(const A& aa)" << endl;
//	}
//
//private:
//	int _a;
//};
//
//int main()
//{
//	A aa1(1);
//
//	//��������
//	A aa2 = aa1;
//
//	//��ʽ����ת��
//	//��������ת��Ϊ�Զ�������
//	//3����һ��A����ʱ�������������ʱ���󿽱�����aa3
//	//������������������+��������->�Ż�Ϊֱ�ӹ���
//	A aa3 = 3;
//	A aa4 = 3.3;
//
//	//����ֱ�Ӹ�raa����ʱ�������г���Ҫ��const��ǰ��,Ȩ��Ҫ��С
//	//raa ���õ�������ת������3�������ʱ����
//	const A& raa = 3;
//
//
//	//��֧���ַ���
//	//A aa4="fsafds";
//	return 0;
//}

//class A {
//public:
//    explicit A(int x) : data(x) {}
//private:
//    int data;
//};
//A obj(5); // ��ʽ��ʽ��������ת��
//A obj = 5; // ��ʽ��ʽ��������ת�����������


//#include<iostream>
//using namespace std;
//
//typedef int DateaType;
//
//class Stack
//{
//public:
//	Stack(size_t capacity = 3)
//	{
//		_array = (DateaType*)malloc(sizeof(DateaType) * capacity);
//		if (NULL == _array)
//		{
//			perror("mallloc����ռ�ʧ�ܣ�����");
//			return;
//		}
//		_capacity = capacity;
//		_size = 0;
//	}
//
//	void Push(DateaType data)
//	{
//		_array[_size] = data;
//		_size++;
//	}
//
//	~Stack()
//	{
//		if (_array)
//		{
//			free(_array);
//			_array = NULL;
//			_capacity = 0;
//			_size = 0;
//		}
//	}
//private:
//	DateaType* _array;
//	int _capacity;
//	int _size;
//};
//
//class MyQueue
//{
//public:
//	//��ʼ���б�������д��д��ÿ����Ա������������һ��
//	//�Զ������͵ĳ�Ա�����Ĭ�Ϲ���(û��Ĭ�Ϲ���ͱ��뱨��)
//	//����������ȱʡֵ��ȱʡֵ��û�еĻ�����ȷ��,Ҫ�����������еı������ᴦ���еĲ��ᴦ��
//	//���߳�ʼ���б����ߺ�����
//	//ʵ���У�������ʹ�ó�ʼ���б��ʼ������������ʹ�ú������ʼ��
//	/*MyQueue()
//	{}*/
//
//	/*Stack���߱�Ĭ�Ϲ��졣MyQueueҲ�޷�����Ĭ�Ϲ���
//	��ʼ���б�
//	��ʼ���б��ʿ������Ϊÿ�������г�Ա����ĵط�
//	���еĳ�Ա��������ڳ�ʼ���б��ʼ����Ҳ�����ں������ڲ���ʼ��
//	1.���� 2.const 3.û��Ĭ�Ϲ����Զ������ͳ�Ա��������ʽ���ε����죩*/
//
//	MyQueue(int n, int& rr)
//		:_Pushst(n)
//		, _Popst(n)
//		, _x(1)
//		, _ret(rr)
//		, _ptr((int*)malloc(8))
//	{
//		//ȱʡֵ�Ǹ���ʼ���б��õ�
//		_size = 0;
//		//_x=1;
//	}
//private:
//	//����
//	Stack _Pushst;
//	Stack _Popst;
//	int _size;
//
//	int* _ptr;
//
//	//�����ڶ���ʱ��ʼ��
//	const int _x;
//
//	//�����ڶ���ʱ��ʼ��
//	int& _ret;
//};
//
//int main()
//{
//	int xx = 0;
//	MyQueue q(10, xx);
//
//	//const int y = 2;
//
//	//int& ry;  //Ҫ��ʼ�� 
//	return 0;
//}

//class Time
//{
//public:
//	Time(int hour = 0)
//		:_hour(hour)
//	{
//		cout << "Time()" << endl;
//	}
//private:
//	int _hour;
//};
//class Date
//{
//public:
//	Date(int day)
//	{}
//private:
//	int _day;
//	Time _t;
//};
//int main()
//{
//	Date d(1);
//}

//class A
//{
//public:
//	A(int a)
//		:_a1(a)
//		, _a2(_a1)
//	{}
//
//	void Print() {
//		cout << _a1 << " " << _a2 << endl;
//	}
//
//private:
//	int _a2;
//	int _a1;
//};
//
//int main() {
//	A aa(1);
//	aa.Print();
//}

//class A
//{
//public:
//	//���������캯��
//	A(int a)
//		:_a(a)
//	{
//		cout << "A(int a)" << endl;
//	}
//
//	A(const A& aa)
//		:_a(aa._a)
//	{
//		cout << "A(const A& aa)" << endl;
//	}
//
//private:
//	int _a;
//};
//
//int main()
//{
//	A aa1(1);
//
//	//��������
//	A aa2 = aa1;
//
//	//��ʽ����ת��
//	//��������ת��Ϊ�Զ�������
//	//3����һ��A����ʱ�������������ʱ���󿽱�����aa3
//	//������������������+��������->�Ż�Ϊֱ�ӹ���
//	A aa3 = 3;
//	A aa4 = 3.3;
//
//	//����ֱ�Ӹ�raa����ʱ�������г���Ҫ��const��ǰ��,Ȩ��Ҫ��С
//	//raa ���õ�������ת������3�������ʱ����
//	const A& raa = 3;
//
//
//	//��֧���ַ���
//	//A aa4="fsafds";
//	return 0;
//}

//class A
//{
//public:
//	A(int a = 0)
//		:_a(a)
//	{
//		cout << "A(int a)" << endl;
//	}
//	A(const A& aa)
//		:_a(aa._a)
//	{
//		cout << "A(const A& aa)" << endl;
//	}
//	A& operator=(const A& aa)
//	{
//		cout << "A& operator=(const A& aa)" << endl;
//		if (this != &aa)
//		{
//			_a = aa._a;
//		}
//		return *this;
//	}
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//private:
//	int _a;
//};
//void f1(A aa)
//{}
//A f2()
//{
//	A aa;
//	return aa;
//}
//int main()
//{
//	// ��ֵ����
//	A aa1;
//	f1(aa1);
//	cout << endl;
//	// ��ֵ����
//	f2();
//	cout << endl;
//	// ��ʽ���ͣ���������+��������->�Ż�Ϊֱ�ӹ���
//	f1(1);
//	// һ�����ʽ�У���������+��������->�Ż�Ϊһ������
//	f1(A(2));
//	cout << endl;
//	// һ�����ʽ�У�������������+��������->�Ż�һ����������
//	A aa2 = f2();
//	cout << endl;
//	// һ�����ʽ�У�������������+��ֵ����->�޷��Ż�
//	aa1 = f2();
//	cout << endl;
//	return 0;
//}


#include<iostream>
using namespace std;

class Date
{
public:

	// 1. ���ι��캯����û��ʹ��explicit���Σ���������ת������
	// explicit���ι��캯������ֹ����ת��---explicitȥ��֮�󣬴������ͨ������
	Date(int year)
		:_year(year)
	{}
	
	// 2. ��Ȼ�ж�����������Ǵ�������ʱ�������������Բ����ݣ�û��ʹ��explicit���Σ���������ת������
	// explicit���ι��캯������ֹ����ת��
	 Date(int year, int month = 1, int day = 1)
	: _year(year)
	, _month(month)
	, _day(day)
	{}
	
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
void Test()
{
	Date d1(2022);
	// ��һ�����α������������Ͷ���ֵ
	// ʵ�ʱ������������2023����һ������������������������d1������и�ֵ
	d1 = 2023;
	// ��1���ε���2�ſ�ʱ�����ʧ�ܣ���Ϊexplicit���ι��캯������ֹ�˵��ι��캯������ת��������
}

int main()
{
	Test();
	return 0;
}