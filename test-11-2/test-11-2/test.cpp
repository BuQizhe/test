//#include<iostream>
//using namespace std;
//
//
//
//#define _CRT_SECURE_NO_WARNINGS
//
//#include <iostream>
//using namespace std;
//
//#include <string>
//
//////////////////////////////////////////////////////////////////////////
//// 测试string容量相关的接口
//// size/clear/resize
//void Teststring1()
//{
//	// 注意：string类对象支持直接用cin和cout进行输入和输出
//	string s("hello, bit!!!");
//	cout << s.size() << endl;
//	cout << s.length() << endl;
//	cout << s.capacity() << endl;
//	cout << s << endl;
//
//	//std::cout << "Initial capacity: " << s.capacity() << std::endl;
//	// 
//// 将s中的字符串清空，注意清空时只是将size清0，不改变底层空间的大小
//	s.clear();
//	cout << s.size() << endl;
//	cout << s.capacity() << endl;
//
//	// 将s中有效字符个数增加到10个，多出位置用'a'进行填充
//	// “aaaaaaaaaa”
//	s.resize(10, 'a');
//	cout << s.size() << endl;
//	cout << s.capacity() << endl;
//
//	// 将s中有效字符个数增加到15个，多出位置用缺省值'\0'进行填充
//	// "aaaaaaaaaa\0\0\0\0\0"
//	// 注意此时s中有效字符个数已经增加到15个
//	s.resize(15);
//	cout << s.size() << endl;
//	cout << s.capacity() << endl;
//	cout << s << endl;
//
//	// 将s中有效字符个数缩小到5个
//	s.resize(5);
//	cout << s.size() << endl;
//	cout << s.capacity() << endl;
//	cout << s << endl;
//}
//
////====================================================================================
//void Teststring2()
//{
//	string s;
//	// 测试reserve是否会改变string中有效元素个数
//	s.reserve(100);
//	cout << s.size() << endl;
//	cout << s.capacity() << endl;
//
//	// 测试reserve参数小于string的底层空间大小时，是否会将空间缩小
//	s.reserve(50);
//	cout << s.size() << endl;
//	cout << s.capacity() << endl;
//}
//
//// 利用reserve提高插入数据的效率，避免增容带来的开销
////====================================================================================
//void TestPushBack()
//{
//	string s;
//	size_t sz = s.capacity();
//	cout << "making s grow:\n";
//	for (int i = 0; i < 100; ++i)
//	{
//		s.push_back('c');
//		if (sz != s.capacity())
//		{
//			sz = s.capacity();
//			cout << "capacity changed: " << sz << '\n';
//		}
//	}
//}
//
//// 构建vector时，如果提前已经知道string中大概要放多少个元素，可以提前将string中空间设置好
//void TestPushBackReserve()
//{
//	string s;
//	s.reserve(100);
//	size_t sz = s.capacity();
//
//	cout << "making s grow:\n";
//	for (int i = 0; i < 100; ++i)
//	{
//		s.push_back('c');
//		if (sz != s.capacity())
//		{
//			sz = s.capacity();
//			cout << "capacity changed: " << sz << '\n';
//		}
//	}
//}
//
//
//////////////////////////////////////////////////////////////////
//// string的遍历
//// begin()+end()   for+[]  范围for
//// 注意：string遍历时使用最多的还是for+下标 或者 范围for(C++11后才支持)
//// begin()+end()大多数使用在需要使用STL提供的算法操作string时，比如：采用reverse逆置string
//void Teststring3()
//{
//	string s1("hello Bit");
//	const string s2("Hello Bit");
//	cout << s1 << " " << s2 << endl;
//	cout << s1[0] << " " << s2[0] << endl;
//
//	s1[0] = 'H';
//	cout << s1 << endl;
//
//	// s2[0] = 'h';   代码编译失败，因为const类型对象不能修改
//}
//
//void Teststring4()
//{
//	string s("hello Bit");
//	// 3种遍历方式：
//	// 需要注意的以下三种方式除了遍历string对象，还可以遍历是修改string中的字符，
//	// 另外以下三种方式对于string而言，第一种使用最多
//	// 1. for+operator[]
//	for (size_t i = 0; i < s.size(); ++i)
//		cout << s[i] << endl;
//
//	// 2.迭代器
//	string::iterator it = s.begin();
//	while (it != s.end())
//	{
//		cout << *it << endl;
//		++it;
//	}
//
//	// string::reverse_iterator rit = s.rbegin();
//	// C++11之后，直接使用auto定义迭代器，让编译器推到迭代器的类型
//	auto rit = s.rbegin();
//	while (rit != s.rend())
//		cout << *rit << endl;
//
//	// 3.范围for
//	for (auto ch : s)
//		cout << ch << endl;
//}
//
//
////////////////////////////////////////////////////////////////
//// 测试string：
//// 1. 插入(拼接)方式：push_back  append  operator+= 
//// 2. 正向和反向查找：find() + rfind()
//// 3. 截取子串：substr()
//// 4. 删除：erase
//void Teststring5()
//{
//	string str;
//	str.push_back(' ');   // 在str后插入空格
//	str.append("hello");  // 在str后追加一个字符"hello"
//	str += 'b';           // 在str后追加一个字符'b'   
//	str += "it";          // 在str后追加一个字符串"it"
//	cout << str << endl;
//	cout << str.c_str() << endl;   // 以C语言的方式打印字符串
//
//	// 获取file的后缀
//	string file("string.cpp");
//	size_t pos = file.rfind('.');
//	string suffix(file.substr(pos, file.size() - pos));
//	cout << suffix << endl;
//
//	// npos是string里面的一个静态成员变量
//	 //static const size_t npos = -1;
//
//	// 取出url中的域名
//	string url("http://www.cplusplus.com/reference/string/string/find/");
//	cout << url << endl;
//	size_t start = url.find("://");
//	if (start == string::npos)
//	{
//		cout << "invalid url" << endl;
//		return;
//	}
//	start += 3;
//	size_t finish = url.find('/', start);
//	string address = url.substr(start, finish - start);
//	cout << address << endl;
//
//	// 删除url的协议前缀
//	pos = url.find("://");
//	url.erase(0, pos + 3);
//	cout << url << endl;
//}
//
//int main()
//{
//	//Teststring1();
//	//Teststring2();
//	//TestPushBack();
//	//Teststring3();
//	//Teststring4();
//	//Teststring5();
//	return 0;
//}



#include<assert.h>
#include<string>
#include<iostream>
#include<list>
using namespace std;

class String
{
public:

	/*string(char a[])
	{
		_size = a[];
	}*/

	//引用返回
	//1.减少拷贝
	//2.修改返回对象

	char& operator[](size_t i)
	{
		assert(i < _size);
		return _str[i];
	}


private:
	char* _str;
	size_t _size;
	size_t _capacity;
};

void test_string1()
{
	//常用
	string s1;
	string s2("hello world");
	string s3(s2);

	//不常用 （了解）
	string s4(s2, 3, 5);//从第三个字符后输出五个字符
	string s5(s2, 3);//从第三个字符后输出所有字符
	string s6(s2, 3, 30);//从第三个字符后输出30个字符，不够补齐
	string s7("hello world", 5);//输出目标字符里的五个字符
	string s8(10, 'x');//输出十个所需要的字符

	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
	cout << s5 << endl;
	cout << s6 << endl;
	cout << s7 << endl;
	cout << s8 << endl;
}

void push_back(const string& s)
{

}


void test_string2()
{
	//隐式类型转换
	string s2 = "hello world";
	const string& s3 = "hello world";

	//构造
	string s1("hello world");
	push_back(s1);
	push_back("hello world");
}

void test_string3()
{
	string s1("hello world");
	cout << s1.size() << endl;//11
	//cout << s1.length() << endl;//11与上相等

	for (size_t i = 0; i < s1.size(); i++)
	{
		s1[i]++;
	}
	cout<< endl;

	//const string s2("hello world");
	//不能修改
	//s1[0] = 'x';

	//可以修改
	/*string s1("hello world");
	s1[0] = 'x';*/

	//越界检查
	//s1[20];

	for (size_t i = 0; i < s1.size(); i++)
	{
		cout << s1.operator[](i) << " ";
		cout<<s1[i]<<" ";
	}
	cout << endl;
}

void test_string4()
{
	string s1("hello world");

	//遍历方式1：下标+[]
	for (size_t i = 0; i < s1.size(); i++)
	{
		cout << s1[i] << " ";
	}
	cout << endl;

	//遍历方式2：迭代器
	string::iterator it1 = s1.begin();
	while (it1 != s1.end())
	{
		//*it1 += 3;
		cout << *it1 << " ";
		++it1;
	}
	cout << endl;

	//遍历方式3：范围for
	//底层角度，他就是迭代器
	for (auto e:s1)
	{
		//e++;
		cout << e << " ";
	}
	cout << endl;
	cout << s1 << endl;

	//输出类型
	//cout << typeid(it1).name() << endl;

	list<int>lt1;
	lt1.push_back(1);
	lt1.push_back(2);
	lt1.push_back(3);

	list<int>::iterator it = lt1.begin();
	while (it != lt1.end())
	{
		cout << *it1 << " ";
		++it;
	}
	cout << endl;
}

void test_string5()
{
	const string s1("hello world");
	//string::const_iterator it1 = s1.begin();
	auto it1 = s1.begin();
	while (it1 != s1.end())
	{
		//不能修改
		//*it1+=3;

		cout << *it1 << " ";
		++it1;
	}
	cout << endl;

}

void test_string6()
{
	string s1("hello world");
	cout << s1 << endl;

	//s1按字典序排序
	//qsort(s1.begin(), s1.end());

	//第一个和最后一个参与排序
	//qsort(++s1.begin(), --s1.end());

	//前五个排序[0,5)
    //sort(s1.begin(),s1.begin()+5);

	cout << s1 << endl;

}

void test_string7()
{
	string s1("hello world");
	cout << s1 << endl;

	s1.push_back('x');
	cout << s1 << endl;

	s1.append("aaaaaaa!!!");
	cout << s1 << endl;

	string s2("45646546");

	s1 += 'y';
	s1 += "zzzzzz";
	s1 += s2;
	cout << s1 << endl;
}

//
void test_string8()
{
	string s2("hello world");
	string::reserve_iterator it2 = s2.rbegin();
	//auto it2=s2.rbegin();
	while (it2 != s2.rend())
	{
		cout << *it2 << endl;
	}
}
int main()
{
	//test_string1();
	//test_string2();
	//test_string3();
	//test_string4();
	//test_string5();
	//test_string6();
	test_string7();

	/*std::cout << typeid(std::string::iterator).name() << std::endl;
	string s2("hello world");*/

	return 0;
}