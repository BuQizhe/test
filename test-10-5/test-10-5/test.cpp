template<class T>
T Add(const T& left, const T& right){
	return left + right;}
int main(){
	int a1 = 10, a2 = 20;	double d1 = 10.0, d2 = 20.0;	Add(a1, a2);
	Add(d1, d2);
		/*
该语句不能通过编译，因为在编译期间，当编译器看到该实例化时，需要推演其实参类型
通过实参a1将T推演为int，通过实参d1将T推演为double类型，但模板参数列表中只有一个T，编译器无法确定此处到底该将T确定为int 或者 double类型而报错
注意：在模板中，编译器一般不会进行类型转换操作，因为一旦转化出问题，编译器就需要背黑锅Add(a1, d1);
*/
// 此时有两种处理方式：1. 用户自己来强制转化 2. 使用显式实例化
		return 0;}template<class T1, class T2, ..., class Tn>
class 类模板名
{
	// 类内成员定义
};
// 动态顺序表
// 注意：Vector不是具体的类，是编译器根据被实例化的类型生成具体类的模具
template<class T>class Vector
{public:
	Vector(size_t capacity = 10)		: _pData(new T[capacity])		, _size(0)		, _capacity(capacity)
	{}
	// 使用析构函数演示：在类中声明，在类外定义。
	~Vector();
	void PushBack(const T& data)；		void PopBack()；
		// ...
		size_t Size() { return _size; }
	T& operator[](size_t pos)
	{
		assert(pos < _size);
		return _pData[pos];	}
private:
	T* _pData;	size_t _size;
	size_t _capacity;};
// 注意：类模板中函数放在类外进行定义时，需要加模板参数列表
template <class T>Vector<T>::~Vector(){
	if (_pData)
		delete[] _pData;	_size = _capacity = 0;}