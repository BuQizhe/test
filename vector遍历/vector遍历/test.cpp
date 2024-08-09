#include <vector>
#include <iostream>

using namespace std;

struct Point
{
	double x;
	double y;
	Point()
	{
		x = 0;
		y = 0;
	}
};


int main()
{
	vector<Point> m_testPoint;
	m_testPoint.clear();
	m_testPoint.shrink_to_fit();

	for (int i = 0; i < 10; ++i)
	{
		Point temp;
		temp.x = i * i;
		temp.y = i * i;
		m_testPoint.push_back(temp);
	}

	//第一种遍历方式，下标
	cout << "第一种遍历方式，下标访问" << endl;
	for (int i = 0; i < m_testPoint.size(); ++i)
	{

		cout << m_testPoint[i].x << "	" << m_testPoint[i].y << endl;
	}

	//第二种遍历方式，迭代器
	cout << "第二种遍历方式，迭代器访问" << endl;
	for (vector<Point>::iterator iter = m_testPoint.begin(); iter != m_testPoint.end(); iter++)
	{
		cout << (*iter).x << "	" << (*iter).y << endl;
	}

	//第三种遍历方式，auto关键字
	cout << "C++11,第三种遍历方式，auto关键字" << endl;
	for (auto iter = m_testPoint.begin(); iter != m_testPoint.end(); iter++)
	{
		cout << (*iter).x << "	" << (*iter).y << endl;
	}

	//第四种遍历方式，auto关键字的另一种方式
	cout << "C++11,第四种遍历方式，auto关键字" << endl;
	for (auto i : m_testPoint)
	{
		cout << i.x << "	" << i.y << endl;
	}

	return 0;
}