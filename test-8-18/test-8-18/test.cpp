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
		cout << _age << " " << _name << " " << _id << " ";//���ȷ���student�����Ա
		cout << person::_age << " " << _name << " " << _id << " ";//����ָ������
	}
private:
	int _age;
	int _id;
};
