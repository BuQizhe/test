#include<iostream>
#include<sstream>
#include<thread>
#include<mutex>
#include<vector>
using namespace std;

//int main()
//{
//	// ��io����Ƚϸߵĵط����粿�ִ�������ľ������У���������3�д���
//	// �������C++IOЧ��
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//
//	int i = 0;
//	cout << cin.good() << endl;
//	cout << cin.eof() << endl;
//	cout << cin.fail() << endl;
//	cout << cin.bad() << endl << endl;
//
//	cin >> i;
//
//	cout << cin.good() << endl;
//	cout << cin.eof() << endl;
//	cout << cin.fail() << endl;
//	cout << cin.bad() << endl << endl;
//	cin.clear();
//	char ch = cin.get();
//
//	cout << cin.good() << endl;
//	cout << cin.eof() << endl;
//	cout << cin.fail() << endl;
//	cout << cin.bad() << endl << endl;
//
//	
//	cin >> i;
//
//	cout << cin.good() << endl;
//	cout << cin.eof() << endl;
//	cout << cin.fail() << endl;
//	cout << cin.bad() << endl << endl;
//
//
//	cout << i << endl << endl;
//
//	return 0;
//}

//class Date
//{
//	friend ostream& operator<< (ostream& out, const Date& d);
//	friend istream& operator>> (istream& in, Date& d);
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{}
//	operator bool()
//	{
//		// ����������д�ģ���������_yearΪ0�������
//		if (_year == 0)
//			return false;
//		else
//			return true;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//istream& operator >> (istream& in, Date& d)
//{
//	in >> d._year >> d._month >> d._day;
//	return in;
//}
//
//ostream& operator << (ostream& out, const Date& d)
//{
//	out << d._year << " " << d._month << " " << d._day;
//	return out;
//}
//
//struct ChatInfo
//{
//	string _name; // ����
//	int _id;	 // id
//	Date _date;  // ʱ��
//	string _msg; // ������Ϣ
//};
//
//int main()
//{
//	// ���л�
//	ostringstream oss;
//	ChatInfo winfo = { "����", 135246, { 2024, 7, 12 }, "��������һ�𿴵�Ӱ��" };
//
//	oss << winfo._name << " " << winfo._id << " " << winfo._date << " " << winfo._msg;
//	string str = oss.str();
//
//	cout << str << endl;
//	
//	//....
//	// �����л�
//	istringstream iss(str);
//	ChatInfo rInfo;
//	iss >> rInfo._id >> rInfo._name >> rInfo._date >> rInfo._msg;
//	cout << iss.good() << endl;
//	cout << iss.eof() << endl;
//	cout << iss.fail() << endl;
//	cout << iss.bad() << endl << endl;
//	iss.clear();
//	cout << iss.good() << endl;
//	cout << iss.eof() << endl;
//	cout << iss.fail() << endl;
//	cout << iss.bad() << endl << endl;
//	iss >> rInfo._name>>rInfo._id >> rInfo._date >> rInfo._msg;
//
//	cout << "-------------------------------------------------------" << endl;
//	cout << "������" << rInfo._name << "(" << rInfo._id << ") ";
//	cout << rInfo._date << endl;
//	cout << rInfo._name << ":>" << rInfo._msg << endl;
//	cout << "-------------------------------------------------------" << endl;
//
//	return 0;
//}

//void Print(int n, int j)
//{
//	for (int i = j; i < n; i++)
//	{
//		cout << i << endl;
//	}
//}
//
//int main()
//{
//	thread t1(Print, 100, 5);
//	thread t2(Print, 100, 20);
//
//	t1.join();
//	t2.join();
//
//	return 0;
//}

// 16:10����
//void Print(int n, int& rx, mutex& rmtx)
//{
//	rmtx.lock();
//
//	for (int i = 0; i < n; i++)
//	{
//		// t1 t2
//		++rx;
//	}
//
//	rmtx.unlock();
//}
//
//int main()
//{
//	int x = 0;
//	mutex mtx;
//
//	thread t1(Print, 10000, ref(x), ref(mtx));
//	thread t2(Print, 20000, ref(x), ref(mtx));
//
//	t1.join();
//	t2.join();
//
//	cout << x << endl;
//
//	return 0;
//}

//int main()
//{
//	int x = 0;
//	mutex mtx;
//
//	auto Func = [&](int n)
//	{
//		mtx.lock();
//		for (int i = 0; i < n; i++)
//		{
//			++x;
//		}
//		mtx.unlock();
//	};
//
//	thread t1(Func, 10000);
//	thread t2(Func, 20000);
//
//	cout << t1.get_id() << endl;
//	cout << t2.get_id() << endl;
//
//	t1.join();
//	t2.join();
//
//	cout << this_thread::get_id() << endl;
//
//	cout << x << endl;
//
//	return 0;
//}

//int main()
//{
//	int x = 0;
//	mutex mtx;
//
//	auto Func = [&](int n)
//	{
//		mtx.lock();
//		for (int i = 0; i < n; i++)
//		{
//			//++x;
//			cout << this_thread::get_id() << "->" << i << endl;
//			//this_thread::sleep_for(chrono::seconds(1));
//			this_thread::sleep_for(chrono::milliseconds(10));
//		}
//		mtx.unlock();
//	};
//  17:20����
//	int n;
//	cin >> n;
//	vector<thread> vthds(n);
//	//vthds.resize(n, thread());
//	for (auto& thd : vthds)
//	{
//		thd = thread(Func, 10000);
//	}
//
//	for (auto& thd : vthds)
//	{
//		thd.join();
//	}
//
//	cout << x << endl;
//
//	return 0;
//}

//int main()
//{
//	using std::chrono::system_clock;
//	std::time_t tt = system_clock::to_time_t(system_clock::now());
//
//	struct std::tm* ptm = std::localtime(&tt);
//	std::cout << "Current time: " << std::put_time(ptm, "%X") << '\n';
//
//	std::cout << "Waiting for the next minute to begin...\n";
//	++ptm->tm_min; ptm->tm_sec = 0;
//	std::this_thread::sleep_until(system_clock::from_time_t(mktime(ptm)));
//
//	std::cout << std::put_time(ptm, "%X") << " reached!\n";
//	return 0;
//}

//template<class Lock>
//class LockGuard
//{
//public:
//	LockGuard(Lock& lk)
//		:_lk(lk)
//	{
//		_lk.lock();
//	}
//
//	~LockGuard()
//	{
//		_lk.unlock();
//	}
//
//private:
//	Lock& _lk;
//};
//
//int main()
//{
//	int x = 0;
//	mutex mtx;
//
//	auto Func = [&](int n)
//	{
//		//mtx.lock();
//		{
//			unique_lock<mutex> lk(mtx);
//			for (int i = 0; i < n; i++)
//			{
//				//++x;
//				cout << this_thread::get_id() << "->" << i << endl;
//
//				lk.unlock();
//				//...����Ҫ����
//				lk.lock();
//				
//				//this_thread::sleep_for(chrono::seconds(1));
//				this_thread::sleep_for(chrono::milliseconds(10));
//			}
//		}
//		//mtx.unlock();
//
//		// ...
//
//	};
//
//	int n;
//	cin >> n;
//	vector<thread> vthds(n);
//	//vthds.resize(n, thread());
//	for (auto& thd : vthds)
//	{
//		thd = thread(Func, 10000);
//	}
//
//	for (auto& thd : vthds)
//	{
//		thd.join();
//	}
//
//	cout << x << endl;
//
//	return 0;
//}

template<class Lock>
class LockGuard
{
public:
	LockGuard(Lock& lk)
		:_lk(lk)
	{
		_lk.lock();
	}

	~LockGuard()
	{
		_lk.unlock();
	}

private:
	Lock& _lk;
};

int main()
{
	//atomic<int> x = 0;
	atomic<int> x{ 0 };

	//int x = 0;

	auto Func = [&](int n)
		{
			for (int i = 0; i < n; i++)
			{
				++x;
			}
		};

	int n;
	cin >> n;
	vector<thread> vthds(n);
	for (auto& thd : vthds)
	{
		thd = thread(Func, 10000000);
	}

	for (auto& thd : vthds)
	{
		thd.join();
	}

	cout << x << endl;
	printf("%d\n", x.load());

	return 0;
}