//#include<iostream>
//using namespace std;
//
////定义Box类
//class Box
//{
//public:
//	friend void printWidth(Box box);  //friend 声明外部函数
//	void setWidth(double wid);        //成员函数声明
//
//private:
//	double width;   //私有变量
//};
//
////成员函数定义
//void Box::setWidth(double wid)
//{
//	width = wid;
//}
//
////请注意：printWidth()不是任何类的成员函数
//void printWidth(Box box)
//{
//	//因为printWidth()是Box的友元,它可以直接访问该类的任何成员
//	cout << "Width of box:" << box.width << endl;
//}
//
//int main()
//{
//	Box box;
//	box.setWidth(10.0);//使用成员函数设置宽度
//	printWidth(box);//使用友元函数输出宽度
//
//	return 0;
//}


#include<iostream>
#include<string.h>
using namespace std;

class Internet
{
public:
	char name[20];
	char address[20];
	static int count;  //静态成员变量

public:
	Internet(const char* name,const  char* address)  //构造函数
	{
		strcpy_s(Internet::name, name);
		strcpy_s(Internet::address, address);
		count++;
	}
	static void Sc()
	{
		cout << count << endl;
	}
};

int Internet::count = 0;  //静态成员初始化

void main()
{
	cout << Internet::count << endl;  //静态成员的输出
	Internet a1("搜狐网站", "www.sohu.com");
	Internet a2("新浪网站", "www.sina.com");
	Internet::Sc();  //静态成员函数的调用
	Internet a3("","www.cndev-lab.com");
	Internet::Sc();  //静态成员函数的调用

}
