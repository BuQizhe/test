


//1534. ͳ�ƺ���Ԫ��
class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int n = arr.size(), cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    if (abs(arr[i] - arr[j]) <= a && abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c) {
                        ++cnt;
                    }
                }
            }
        }
        return cnt;
    }
};


//584. Ѱ���û��Ƽ���
// Write your MySQL query statement below
SELECT name FROM customer WHERE referee_id != 2 OR referee_id IS NULL;


//1757. �ɻ����ҵ�֬�Ĳ�Ʒ
SELECT
product_id
FROM
Products
WHERE
low_fats = 'Y' AND recyclable = 'Y'

//709. ת����Сд��ĸ
class Solution {
public:
    string toLowerCase(string s) {
        for (char& ch : s) {
            if (ch >= 65 && ch <= 90) {
                ch |= 32;
            }
        }
        return s;
    }
};

class Solution {
public:
    string toLowerCase(string s) {
        for (char& ch : s) {
            ch = tolower(ch);
        }
        return s;
    }
};


//258. ��λ���

class Solution {
public:
    int addDigits(int num) {
        while (num >= 10) {
            int sum = 0;
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
            num = sum;
        }
        return num;
    }
};

class Solution {
public:
    int addDigits(int num) {
        return (num - 1) % 9 + 1;
    }
};