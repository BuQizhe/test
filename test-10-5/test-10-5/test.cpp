template<class T>
T Add(const T& left, const T& right)
	return left + right;
int main()
	int a1 = 10, a2 = 20;
	Add(d1, d2);
		/*
����䲻��ͨ�����룬��Ϊ�ڱ����ڼ䣬��������������ʵ����ʱ����Ҫ������ʵ������
ͨ��ʵ��a1��T����Ϊint��ͨ��ʵ��d1��T����Ϊdouble���ͣ���ģ������б���ֻ��һ��T��
ע�⣺��ģ���У�������һ�㲻���������ת����������Ϊһ��ת�������⣬����������Ҫ���ڹ�
*/
// ��ʱ�����ִ�����ʽ��1. �û��Լ���ǿ��ת�� 2. ʹ����ʽʵ����
		return 0;
class ��ģ����
{
	// ���ڳ�Ա����
};
// ��̬˳���
// ע�⣺Vector���Ǿ�����࣬�Ǳ��������ݱ�ʵ�������������ɾ������ģ��
template<class T>
{
	Vector(size_t capacity = 10)
	{}
	// ʹ������������ʾ�������������������ⶨ�塣
	~Vector();
	void PushBack(const T& data)��
		// ...
		size_t Size() { return _size; }
	T& operator[](size_t pos)
	{
		assert(pos < _size);
		return _pData[pos];
private:
	T* _pData;
	size_t _capacity;
// ע�⣺��ģ���к�������������ж���ʱ����Ҫ��ģ������б�
template <class T>
	if (_pData)
		delete[] _pData;