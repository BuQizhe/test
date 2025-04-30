#include<iostream>
using namespace std;

//1422. 分割字符串的最大得分
//给你一个由若干 0 和 1 组成的字符串 s ，请你计算并返回将该字符串分割成两个 非空 子字符串（即 左 子字符串和 右 子字符串）所能获得的最大得分。
//「分割字符串的得分」为 左 子字符串中 0 的数量加上 右 子字符串中 1 的数量。
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


//1281. 整数的各位积和之差
//给你一个整数 n，请你帮忙计算并返回该整数「各位数字之积」与「各位数字之和」的差。
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

//326. 3 的幂
//给定一个整数，写一个函数来判断它是否是 3 的幂次方。如果是，返回 true ；否则，返回 false 。
//整数 n 是 3 的幂次方需满足：存在整数 x 使得 n == 3x
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