#include<iostream>
using namespace std;

//class Date
//{
//public:
//	
//
//private:
//
//};
//
//int main()
//{
//
//	return 0;
//}

//class human {//������һ�����࣬���ֽ�human
//public:
//	string name = "С��";//�������涨����һ��string���͵ĺ�һ��int����
//	int age = 18;
//};
//class student :public human {//������һ����public��ʽ�̳и��������student
//public:
//	int schoolnum = 666;//�ڸ����name��age�Ļ�����������һ��schoolnum
//	void print()
//	{
//		cout << name << endl << age << endl << schoolnum << endl;//���
//	}
//};
//int main()
//{
//	student st;
//	st.print();
//	return 0;
//}

//class human {
//public:
//	string name = "С��";
//	void print()
//	{
//		cout << name << endl;
//	}
//};
//class student :public human {
//public:
//	string name = "С��";
//	void print()
//	{
//		cout << name << endl;
//	}
//};
//int main()
//{
//	student st;
//	st.print();
//	return 0;
//}

class A {
public:
	string name;
};
class B :public A {
public:
	int age;
};
class C :public A {
public:
	string sex;
};
class D :public B, public C {
public:
	int id;
};
int main()
{
	D student;
	student.B::name = "С��";
	student.age = 18;
	student.sex = "��";
	student.id = 666;
	return 0;
}