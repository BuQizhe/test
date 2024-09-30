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

//class human {//定义了一个父类，名字叫human
//public:
//	string name = "小明";//父类里面定义了一个string类型的和一个int类型
//	int age = 18;
//};
//class student :public human {//定义了一个以public方式继承父类的子类student
//public:
//	int schoolnum = 666;//在父类的name和age的基础上增加了一个schoolnum
//	void print()
//	{
//		cout << name << endl << age << endl << schoolnum << endl;//输出
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
//	string name = "小明";
//	void print()
//	{
//		cout << name << endl;
//	}
//};
//class student :public human {
//public:
//	string name = "小红";
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
	student.B::name = "小明";
	student.age = 18;
	student.sex = "男";
	student.id = 666;
	return 0;
}