class  A
{
public:
	virtual void show()
	{
		cout << "A show" << endl;
	}
};
class B : public A
{
public:
	void show()
	{
		cout << "B show" << endl;
	}
};
int main()
{

	B b;
	b.show();//B show
	A* pA = &b;
	pA->show();//B show ���show����ǰû��virtual����Ϊ�麯������������A show

	system("pause");
	return 0;
}
