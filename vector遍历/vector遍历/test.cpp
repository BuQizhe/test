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

	//��һ�ֱ�����ʽ���±�
	cout << "��һ�ֱ�����ʽ���±����" << endl;
	for (int i = 0; i < m_testPoint.size(); ++i)
	{

		cout << m_testPoint[i].x << "	" << m_testPoint[i].y << endl;
	}

	//�ڶ��ֱ�����ʽ��������
	cout << "�ڶ��ֱ�����ʽ������������" << endl;
	for (vector<Point>::iterator iter = m_testPoint.begin(); iter != m_testPoint.end(); iter++)
	{
		cout << (*iter).x << "	" << (*iter).y << endl;
	}

	//�����ֱ�����ʽ��auto�ؼ���
	cout << "C++11,�����ֱ�����ʽ��auto�ؼ���" << endl;
	for (auto iter = m_testPoint.begin(); iter != m_testPoint.end(); iter++)
	{
		cout << (*iter).x << "	" << (*iter).y << endl;
	}

	//�����ֱ�����ʽ��auto�ؼ��ֵ���һ�ַ�ʽ
	cout << "C++11,�����ֱ�����ʽ��auto�ؼ���" << endl;
	for (auto i : m_testPoint)
	{
		cout << i.x << "	" << i.y << endl;
	}

	return 0;
}