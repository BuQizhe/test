#include "iostream"
using namespace std;

class Student
{
public:
	// ���ι��캯��
	Student(int age, int height)
	{
		m_age = age;
		m_height = height;
		cout << "ִ�� Student �Ĺ��캯��" << endl;
	}

	~Student()
	{
		cout << "ִ�� Student ����������" << endl;
	}

	static void fun()
	{
		// ��̬��Ա���� �� ���ʷǾ�̬��Ա�ᱨ��
		// error C2597: �ԷǾ�̬��Ա��Student::m_age���ķǷ�����
		//m_age = 10;
		cout << "��̬��Ա���������� : number = " << number << endl;
	}

public:
	int m_age;		// ����
	int m_height;	// ���

	// �����ڲ����徲̬��Ա
	static int number;
};

// �����ⲿ��ʼ����̬��Ա����  
int Student::number = 1;

int main() {


	// I. ��̬��Ա����


	// ʹ�� ������� ���� �ྲ̬��Ա����
	// ����::��̬��Ա������
	cout << "Student::number = " << Student::number << endl;

	// �ں�����Ϊ �� ��̬��Ա���� ��ֵ
	Student::number = 2;

	// ���� Student ���Ͷ���
	Student s(10, 150);

	// ʹ�� ���� ���� �ྲ̬��Ա����
	// ��������.��̬��Ա������
	cout << "s.number = " << s.number << endl;


	// II. ��̬��Ա����


	// ͨ�� ����:: ���� ��̬��Ա����
	Student::fun();

	// ͨ�� ����. ���� ��̬��Ա����
	s.fun();

	// ����̨��ͣ , ��������������ִ��
	system("pause");

	return 0;
}
