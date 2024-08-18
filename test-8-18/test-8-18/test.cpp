class person
{
protected:
	int _age;
	string _name;
};

class student :public person
{
public:
	void print()
	{
		cout << _age << " " << _name << " " << _id << " ";//优先访问student子类成员
		cout << person::_age << " " << _name << " " << _id << " ";//可以指定类域
	}
private:
	int _age;
	int _id;
};
