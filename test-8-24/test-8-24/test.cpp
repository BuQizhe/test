
#include<iostream>
using namespace std;
class A
{
public:
	//explicit A(int a = 0)
	A(int a = 0)
	{
		_a1 = a;
	}

	A(const A& aa)
	{
		_a1 = aa._a1;
	}

	A(int a1, int a2)
		:_a1(a1)
		, _a2(a2)
	{}

	void Print() {
		cout << _a1 << " " << _a2 << endl;
	}
private:
	int _a1;
	int _a2;
};

class Stack
{
public:
	void Push(const A& aa)
	{
		//...
	}
private:
	A _arr[10];
	int _top;
};

int main()
{
	A aa1(1);
	aa1.Print();

	// 隐式类型转换
	// 2构造一个A的临时对象，再用这个临时对象拷贝构造aa2
	// 编译器遇到连续构造+拷贝构造->优化为直接构造
	A aa2 = 2;
	aa2.Print();

	A& raa1 = aa2;
	const A& raa2 = 2;

	int i = 1;
	double d = i;
	const double& rd = i;

	Stack st;

	A aa3(3);
	st.Push(aa3);

	st.Push(3);

	// C++11
	A aa5 = { 1, 1 };
	const A& raa6 = { 2,2 };
	st.Push(aa5);
	st.Push({ 2,2 });

	return 0;
}