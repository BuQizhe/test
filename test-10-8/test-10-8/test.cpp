//#include<iostream>
//using namespace std;
//
////����Box��
//class Box
//{
//public:
//	friend void printWidth(Box box);  //friend �����ⲿ����
//	void setWidth(double wid);        //��Ա��������
//
//private:
//	double width;   //˽�б���
//};
//
////��Ա��������
//void Box::setWidth(double wid)
//{
//	width = wid;
//}
//
////��ע�⣺printWidth()�����κ���ĳ�Ա����
//void printWidth(Box box)
//{
//	//��ΪprintWidth()��Box����Ԫ,������ֱ�ӷ��ʸ�����κγ�Ա
//	cout << "Width of box:" << box.width << endl;
//}
//
//int main()
//{
//	Box box;
//	box.setWidth(10.0);//ʹ�ó�Ա�������ÿ��
//	printWidth(box);//ʹ����Ԫ����������
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
	static int count;  //��̬��Ա����

public:
	Internet(const char* name,const  char* address)  //���캯��
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

int Internet::count = 0;  //��̬��Ա��ʼ��

void main()
{
	cout << Internet::count << endl;  //��̬��Ա�����
	Internet a1("�Ѻ���վ", "www.sohu.com");
	Internet a2("������վ", "www.sina.com");
	Internet::Sc();  //��̬��Ա�����ĵ���
	Internet a3("","www.cndev-lab.com");
	Internet::Sc();  //��̬��Ա�����ĵ���

}
