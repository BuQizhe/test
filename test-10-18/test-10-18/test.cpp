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
int A::_scount = 0;//��̬��Ա��ʼ��


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
	const A& raa = 3;

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
		, _minute(minute)
		, _second(second)
	{}
private:
	int _hour;
	int _minute;
};

int main()
{
	//��������
	//�����÷����㣬c mallocûʲô����
	int *p1=new int;
	int* p2 = new int[10];
	//Ĭ�ϲ���ʼ�������ǿ��Գ�ʼ��
	int* p1 = new int(10);
	int* p2 = new int[10] {1, 2, 3, 4};

	delete p1;
	delete[]p2;

	//�Զ�������,new���ܵ��ù����ʼ����malloc��������
	A* p1 = (A*)malloc(sizeof(A));
	//p1->_a = 0;
	free(p1);

	//���ռ�/�ͷſռ䣬������ù������������
	A* p2 = new A;
	A* p3 = new A(2);

	delete p2;
	delete p3;

	cout << endl;

	//A*p4=new A[10];
	A aa1(1);
	A aa2(2);
	A aa3(3);

	A* p4 = new A[10]{aa1,aa2,aa3};
	A* p4 = new A[10]{1,2,3,4,5};
	delete[]p4;


	return 0;
}


#include<stack>

int main()
{
	//operator new->(malloc)+���캯��
	A* p2 = new A;
	
	//����+operator delete
	delete p2;

	stack<int>* p3 = new stack<int>;
	delete p3;

	return 0;
}


struct ListNode
{
	ListNode* _next;
	int _val;

	ListNode(int val)
		:_next(nullptr)
		,_val(val)
	{}
};

void func()
{
	//newʧ���ˣ��׳��쳣
	ListNode* n1 = new ListNode(1);
	ListNode* n2 = new ListNode(2);
	ListNode* n3 = new ListNode(3);

	int* p1 = new int[100 * 1024 * 1024];
	int* p2 = new int[100 * 1024 * 1024];
	int* p3 = new int[100 * 1024 * 1024];
	int* p4 = new int[100 * 1024 * 1024];
	int* p5 = new int[100 * 1024 * 1024];
	int* p6 = new int[100 * 1024 * 1024];

	n1->_next = n2;
	n2->_next = n3;


	delete n1;
	delete n2;
	delete n3;
}


int main()
{
	try
	{
		func();
	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
	}
}


int main()
{
	//A* p1 = new A;
	A* p1 = (A*)operator new(sizeof(A));
	//p1->A();//��֧��������ʾ���ù���
	//new(p1)A; //�����пռ䣬��ʾ���ù���
	new(p1)A(10);//�����пռ䣬��ʾ���ù���

	//delete p1
	p1->~A();
	operator delete(p1);

	//new[]
	A* p2 = (A*)operator new[](sizeof(A) * 10);
	//new(p2)A[10]{1,2,3,4};//�����пռ䣬��ʾ���ù���
	for (int i = 0; i < 10; i++)
	{
		new(p2 + i)A(i);
	}

	//delete[]
	for (int i = 0; i < 10; i++)
	{
		(p2 + i)->~A();
	}
	operator delete[](p2);

	return 0;
}