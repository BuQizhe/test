#include<iostream>
using namespace std;

//class Solution {
//    public boolean isSameTree(TreeNode p, TreeNode q) {
//        // 判断结构
//        if (p == null && q == null) {
//            return true;
//        }
//        // 判断结构       
//        if (p == null || q == null) {
//            return false;
//        }
//        // 判断值相等
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
		//保存资源
		auto_ptr(T* ptr)
			:_ptr(ptr)
		{}

		//释放资源
		~auto_ptr()
		{
			//delete[] _ptr;
			delete _ptr;
			cout << _ptr << endl;
		}

		//拷贝构造 -- 对象悬空
		//这里不能加const
		auto_ptr(auto_ptr<T>& ap)
			:_ptr(ap._ptr)
		{
			ap._ptr = nullptr;
		}

		//像指针一样
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
