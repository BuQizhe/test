# P5738 �����7.��4���質����

## ��Ŀ����

n(n<=100) ��ͬѧ�μӸ質������������ m(m<+20)����ί�����֣����ַ�Χ�� 0 �� 10 �֡�����ͬѧ�ĵ÷־�����Щ��ί������ȥ��һ����߷֣�ȥ��һ����ͷ֣�ʣ�� m - 2 �����ֵ�ƽ���������ʵ÷���ߵ�ͬѧ�����Ƕ��٣����ֱ��� $2$ λС����

## �����ʽ

��һ���������� $n, m$��
������ $n$ �У�ÿ�и� $m$ ����������ʾ�÷֡�

## �����ʽ

���������ߵ�ͬѧ�ķ�����������λС����

## ����������� #1

### ���� #1

```
7 6
4 7 2 6 10 7
0 5 0 10 3 10
2 6 8 4 3 6
6 3 6 7 5 8
5 9 3 3 8 1
5 9 9 3 2 0
5 8 0 4 1 10
```

### ��� #1

```
6.00
```

#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;
int main()
{

    int n, m;
    cin >> n >> m;
    vector<int>scores;
    double max_score = 0.0;
    for (int i = 0; i < n; ++i)
    {
        vector<int>scores(m);
        for (int j = 0; j < m; ++j)
        {
            cin >> scores[j];
        }
        sort(scores.begin(), scores.end());


        int sum = 0;
        for (int j = 1; j < m - 1; ++j)
        {
            sum += scores[j];
        }
        double avg = sum / (m - 2);
        if (avg > max_score)
        {
            max_score = avg;
        }
    }
    printf("%.2lf", max_score);
    return 0;
}




// #include <iostream>
// #include <iomanip>
// using namespace std;

// int main() {
//     int n, m;
//     cin >> n >> m;
//     double max_score = 0.0;
//     for (int i = 0; i < n; ++i) {
//         int x;
//         cin >> x;
//         int sum = x;
//         int max_val = x;
//         int min_val = x;
//         for (int j = 1; j < m; ++j) {
//             cin >> x;
//             sum += x;
//             if (x > max_val) max_val = x;
//             if (x < min_val) min_val = x;
//         }
//         int sum_total = sum - max_val - min_val;
//         double average = static_cast<double>(sum_total) / (m - 2);
//         if (average > max_score) {
//             max_score = average;
//         }
//     }
//     cout << fixed << setprecision(2) << max_score << endl;
//     return 0;
// }



// #include <iostream>
// #include <vector>
// #include <algorithm> // ��������
// #include <iomanip>   // ���ڿ����������
// using namespace std;

// int main() {
//     int n, m;
//     cin >> n >> m;

//     // ������Ч�Լ�飨������ĿԼ��������
//     if (n < 1 || n > 100 || m < 1 || m > 20) {
//         cerr << "�������ݲ�������ĿԼ����" << endl;
//         return 1;
//     }

//     double max_score = 0.0; // ��¼��߷�

//     for (int student = 0; student < n; ++student)
//         { 
//         vector<int> scores(m);
//         for (int judge = 0; judge < m; ++judge)
//             {
//             cin >> scores[judge];
//             if (scores[judge] < 0 || scores[judge] > 10) 
//                {
//                 cerr << "���� " << scores[judge] << "��Ч��" << endl;
//                 return 1;
//             }
//         }
//         sort(scores.begin(), scores.end());
//         int valid_sum = 0;
//         for (int i = 1; i < m-1; ++i)
//         { 
//             valid_sum += scores[i];
//         }
//         double avg=static_cast<double>(valid_sum)/(m -2);
//         if (avg > max_score) 
//         {
//             max_score = avg;
//         }
//     }
//     cout << fixed << setprecision(2) << max_score <<endl;

//     return 0;
// }