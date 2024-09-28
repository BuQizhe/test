#include<iostream>
using namespace std;

//class Solution {
//    public boolean isSameTree(TreeNode p, TreeNode q) {
//        // �жϽṹ
//        if (p == null && q == null) {
//            return true;
//        }
//        // �жϽṹ       
//        if (p == null || q == null) {
//            return false;
//        }
//        // �ж�ֵ���
//        if (p.val != q.val)
//            return false;
//        return isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
//    }
//}

namespace bit
{
	template<class T>
	class auto_ptr
	{
	public:
		//������Դ
		auto_ptr(T* ptr)
			:_ptr(ptr)
		{}

		//�ͷ���Դ
		~auto_ptr()
		{
			//delete[] _ptr;
			delete _ptr;
			cout << _ptr << endl;
		}

		//�������� -- ��������
		//���ﲻ�ܼ�const
		auto_ptr(auto_ptr<T>& ap)
			:_ptr(ap._ptr)
		{
			ap._ptr = nullptr;
		}

		//��ָ��һ��
		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		T& operator[](size_t pos)
		{
			return _ptr[pos];
		}
	private:
		T* _ptr;
	};
}
int main()
{

	bit::auto_ptr<int> ap1(new int);
	bit::auto_ptr<int> ap2(ap1);

	(*ap2)++;
	(*ap1)++;

	return 0;
}
