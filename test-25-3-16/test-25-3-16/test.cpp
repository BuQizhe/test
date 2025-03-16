# P5738 【深基7.例4】歌唱比赛

## 题目描述

n(n<=100) 名同学参加歌唱比赛，并接受 m(m<+20)名评委的评分，评分范围是 0 到 10 分。这名同学的得分就是这些评委给分中去掉一个最高分，去掉一个最低分，剩下 m - 2 个评分的平均数。请问得分最高的同学分数是多少？评分保留 $2$ 位小数。

## 输入格式

第一行两个整数 $n, m$。
接下来 $n$ 行，每行各 $m$ 个整数，表示得分。

## 输出格式

输出分数最高的同学的分数，保留两位小数。

## 输入输出样例 #1

### 输入 #1

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

### 输出 #1

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
// #include <algorithm> // 用于排序
// #include <iomanip>   // 用于控制输出精度
// using namespace std;

// int main() {
//     int n, m;
//     cin >> n >> m;

//     // 输入有效性检查（根据题目约束条件）
//     if (n < 1 || n > 100 || m < 1 || m > 20) {
//         cerr << "输入数据不符合题目约束！" << endl;
//         return 1;
//     }

//     double max_score = 0.0; // 记录最高分

//     for (int student = 0; student < n; ++student)
//         { 
//         vector<int> scores(m);
//         for (int judge = 0; judge < m; ++judge)
//             {
//             cin >> scores[judge];
//             if (scores[judge] < 0 || scores[judge] > 10) 
//                {
//                 cerr << "评分 " << scores[judge] << "无效！" << endl;
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