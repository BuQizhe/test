#include<iostream>
using namespace std;

class MyClass
{
public:
	typedef int LengthType;
	LengthType getLength() const
	{
		return this->length;
	}
	void setLength(LengthType length)
	{
		this->length = length;
	}

private:
	LengthType length;
};
template<class T>
void MyMethod(T myclass)
{
	//告诉 c++ 编译器，typename 后面的字符串为一个类型名称，而不是成员函数或者成员变量
	typedef typename T::LengthType LengthType; //
	LengthType length = myclass.getLength();
	cout << "length = " << length << endl;

}
int main()
{
	MyClass my;
	my.setLength(666);
	MyMethod(my);//length = 666
	return 0;
}
