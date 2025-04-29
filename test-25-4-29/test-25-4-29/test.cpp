#include<iostream>
using namespace std;

//867. ת�þ���
//����һ����ά�������� matrix�� ���� matrix �� ת�þ��� ��
//����� ת�� ��ָ����������Խ��߷�ת���������������������������
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> transposed(n, vector<int>(m));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                transposed[j][i] = matrix[i][j];
            }
        }
        return transposed;
    }
};


//231. 2 ����
//����һ������ n�������жϸ������Ƿ��� 2 ���ݴη�������ǣ����� true �����򣬷��� false ��
//�������һ������ x ʹ�� n == 2x ������Ϊ n �� 2 ���ݴη���

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }
};

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & -n) == n;
    }
};

class Solution {
private:
    static constexpr int BIG = 1 << 30;

public:
    bool isPowerOfTwo(int n) {
        return n > 0 && BIG % n == 0;
    }
};

//2586. ͳ�Ʒ�Χ�ڵ�Ԫ���ַ�����
//����һ���±�� 0 ��ʼ���ַ������� words ������������left �� right ��
//����ַ�����Ԫ����ĸ��ͷ����Ԫ����ĸ��β����ô���ַ�������һ�� Ԫ���ַ��� ������Ԫ����ĸ�� 'a'��'e'��'i'��'o'��'u' ��
//���� words[i] ��Ԫ���ַ�������Ŀ������ i �ڱ�����[left, right] �ڡ�
class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        unordered_set<char> vowels = { 'a', 'e', 'i', 'o', 'u' };
        int ans = 0;
        for (int i = left; i <= right; ++i) {
            const string& word = words[i];
            if (vowels.count(word[0]) && vowels.count(word.back())) {
                ++ans;
            }
        }
        return ans;
    }
};