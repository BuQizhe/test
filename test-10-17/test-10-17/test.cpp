#include<iostream>
using namespace std;

class MyQueue
{
public:
	//��ʼ���б�������д��д��ÿ����Ա����������һ��
	//�Զ������͵ĳ�Ա�����Ĭ�Ϲ���(û��Ĭ�Ϲ���ͻ���뱨��)
	//����������ȱʡֵ��ȱʡֵ��û�еĻ�����ȷ����Ҫ�����������еĻᴦ���еĲ��ᴦ��
	//���߳�ʼ���б�+���ߺ�����
	//ʵ���У�������ʹ���б��ʼ������������ʹ�ú������ʼ��
	MyQueue()
		:_size(1)
		, _ptr((int*)malloc(40))
	{
		memset(_ptr, 0, 40);
	}
private:
	Stack _pushst;
	Stack _poost;
};

class A
{
public:
	//���������캯��
	//explicit A(int a)
	A(int a)
		:_a(a)
	{
		cout << "A(int a)" << endl;
	}

	//��������캯��
	A(int a1, int a2)
		:_a(0)
		, _a1(a1);
		, _a2(a2);
	{}

	A(const A& aa)
		:_a(aa._a)
	{
		cout << "A(const A&&aa)" << endl;
	}


	~A()
	{
		//--_scount;

	}

	//û��thisָ�룬ֻ�ܷ��ʾ�̬��Ա
	static int GetCount()
	{
		//_a1=1;
		return _scount;
	}

private:

	//����
	//��̬���������ڶ�����
	//���ܸ�ȱʡ����Ϊȱʡֵ�Ǹ���ʼ���б�
	//���ھ�̬�����ڶ����У����߳�ʼ���б�
	//�������������࣬�������ж���

	int _a1 = 1;
	int _a2 = 1;

	static int _scount;
};

//����
int A::_scount = 0;


int main()
{
	A aa1(1);
	//��������
	A aa2 = aa1;

	//��ʽ����ת��
	//��������ת��Ϊ�Զ�������
	//3 ����һ��A����ʱ�������������ʱ���󿽱�
	//������������������+��������->�Ż�Ϊֱ�ӹ���
	A aa3 = 3;

	//raa ���õ�������ת������3�������ʱ����
	const A & raa = 3;

	A aaa1(1, 2);
	A aaa2{ 1,2 };
	const A& aaa3{ 1,2 };

	return 0;
}



class Sum
{
public:
	Sum()
	{
		_ret += _i;
		++_i;
	}

	static int GetRet()
	{
		return _ret;
	}



private:
	static int _i;
	static int _ret;
};

int Sum::_i = 1;
int Sum::_ret = 0;

class Solution
{
public:
	int Sum_Solution(int n)
	{
		//�䳤����
		Sum arr[n];
		return Sum::GetRet();
	}


};


class Time
{
	//����Date��Time����Ԫ
	//Date�п��Է���Time��˽��
	//����Time�в��ܷ���Date��˽��
	friend class Date;
public:
	Time(int hour = 0, int minute = 0; int second = 0)
		:_hour(hour)
		,_minute(minute)
		,_second(second)
	{}
	private:
		int _hour;
		int _minute;
	};

	Date;::Date;()
	{
	}

	Date;::~Date;()
	{
	}
public:
	Time();
	~Time();

private:

};

Time::Time()
{
}

Time::~Time()
{
}