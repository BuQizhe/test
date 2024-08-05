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
	pA->show();//B show 如果show方法前没用virtual声明为虚函数，这里会输出A show

	system("pause");
	return 0;
}
