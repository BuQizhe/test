template<class T>
T Add(const T& left, const T& right){
	return left + right;}
int main(){
	int a1 = 10, a2 = 20;	double d1 = 10.0, d2 = 20.0;	Add(a1, a2);
	Add(d1, d2);
		/*
����䲻��ͨ�����룬��Ϊ�ڱ����ڼ䣬��������������ʵ����ʱ����Ҫ������ʵ������
ͨ��ʵ��a1��T����Ϊint��ͨ��ʵ��d1��T����Ϊdouble���ͣ���ģ������б���ֻ��һ��T���������޷�ȷ���˴����׸ý�Tȷ��Ϊint ���� double���Ͷ�����
ע�⣺��ģ���У�������һ�㲻���������ת����������Ϊһ��ת�������⣬����������Ҫ���ڹ�Add(a1, d1);
*/
// ��ʱ�����ִ���ʽ��1. �û��Լ���ǿ��ת�� 2. ʹ����ʽʵ����
		return 0;}template<class T1, class T2, ..., class Tn>
class ��ģ����
{
	// ���ڳ�Ա����
};
// ��̬˳���
// ע�⣺Vector���Ǿ�����࣬�Ǳ��������ݱ�ʵ�������������ɾ������ģ��
template<class T>class Vector
{public:
	Vector(size_t capacity = 10)		: _pData(new T[capacity])		, _size(0)		, _capacity(capacity)
	{}
	// ʹ������������ʾ�������������������ⶨ�塣
	~Vector();
	void PushBack(const T& data)��		void PopBack()��
		// ...
		size_t Size() { return _size; }
	T& operator[](size_t pos)
	{
		assert(pos < _size);
		return _pData[pos];	}
private:
	T* _pData;	size_t _size;
	size_t _capacity;};
// ע�⣺��ģ���к�������������ж���ʱ����Ҫ��ģ������б�
template <class T>Vector<T>::~Vector(){
	if (_pData)
		delete[] _pData;	_size = _capacity = 0;}