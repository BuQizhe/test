#include "iostream"
using namespace std;

class Student
{
public:
	// 带参构造函数
	Student(int age, int height)
	{
		m_age = age;
		m_height = height;
		cout << "执行 Student 的构造函数" << endl;
	}

	~Student()
	{
		cout << "执行 Student 的析构函数" << endl;
	}

	static void fun()
	{
		// 静态成员函数 中 访问非静态成员会报错
		// error C2597: 对非静态成员“Student::m_age”的非法引用
		//m_age = 10;
		cout << "静态成员函数被调用 : number = " << number << endl;
	}

public:
	int m_age;		// 年龄
	int m_height;	// 身高

	// 在类内部定义静态成员
	static int number;
};

// 在类外部初始化静态成员变量  
int Student::number = 1;

int main() {


	// I. 静态成员变量


	// 使用 域操作符 访问 类静态成员变量
	// 类名::静态成员变量名
	cout << "Student::number = " << Student::number << endl;

	// 在函数中为 类 静态成员变量 赋值
	Student::number = 2;

	// 创建 Student 类型对象
	Student s(10, 150);

	// 使用 对象 访问 类静态成员变量
	// 对象名称.静态成员变量名
	cout << "s.number = " << s.number << endl;


	// II. 静态成员函数


	// 通过 类名:: 调用 静态成员函数
	Student::fun();

	// 通过 对象. 调用 静态成员函数
	s.fun();

	// 控制台暂停 , 按任意键继续向后执行
	system("pause");

	return 0;
}
