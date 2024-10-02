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
	//���� c++ ��������typename ������ַ���Ϊһ���������ƣ������ǳ�Ա�������߳�Ա����
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
