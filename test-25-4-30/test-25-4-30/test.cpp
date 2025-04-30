#include<iostream>
using namespace std;

//1422. �ָ��ַ��������÷�
//����һ�������� 0 �� 1 ��ɵ��ַ��� s ��������㲢���ؽ����ַ����ָ������ �ǿ� ���ַ������� �� ���ַ����� �� ���ַ��������ܻ�õ����÷֡�
//���ָ��ַ����ĵ÷֡�Ϊ �� ���ַ����� 0 ���������� �� ���ַ����� 1 ��������
class Solution {
public:
    int maxScore(string s) {
        int ans = 0;
        int n = s.size();
        for (int i = 1; i < n; i++) {
            int score = 0;
            for (int j = 0; j < i; j++) {
                if (s[j] == '0') {
                    score++;
                }
            }
            for (int j = i; j < n; j++) {
                if (s[j] == '1') {
                    score++;
                }
            }
            ans = max(ans, score);
        }
        return ans;
    }
};

class Solution {
public:
    int maxScore(string s) {
        int score = 0;
        int n = s.size();
        if (s[0] == '0') {
            score++;
        }
        for (int i = 1; i < n; i++) {
            if (s[i] == '1') {
                score++;
            }
        }
        int ans = score;
        for (int i = 1; i < n - 1; i++) {
            if (s[i] == '0') {
                score++;
            }
            else {
                score--;
            }
            ans = max(ans, score);
        }
        return ans;
    }
};


//1281. �����ĸ�λ����֮��
//����һ������ n�������æ���㲢���ظ���������λ����֮�����롸��λ����֮�͡��Ĳ
//
class Solution {
public:
    int subtractProductAndSum(int n) {
        int m = 1, s = 0;
        while (n) {
            int x = n % 10;
            n /= 10;
            m *= x;
            s += x;
        }
        return m - s;
    }
};

//326. 3 ����
//����һ��������дһ���������ж����Ƿ��� 3 ���ݴη�������ǣ����� true �����򣬷��� false ��
//���� n �� 3 ���ݴη������㣺�������� x ʹ�� n == 3x
class Solution {
public:
    bool isPowerOfThree(int n) {
        while (n && n % 3 == 0) {
            n /= 3;
        }
        return n == 1;
    }
};

class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && 1162261467 % n == 0;
    }
};