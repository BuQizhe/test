//贪心算法上楼梯

#include<stdio.h>
// 使用贪心算法计算上楼梯的最少步数
void greedyStairs(int n) {
    int steps = 0; // 总步数
    int threeSteps = 0; // 走3步的次数
    int twoSteps = 0; // 走2步的次数
    int oneStep = 0; // 走1步的次数
    // 首先尽可能多地走3步
    threeSteps = n / 3;
    n -= threeSteps * 3;
    // 然后尽可能多地走2步
    twoSteps = n / 2;
    n -= twoSteps * 2;
    // 最后走剩下的1步
    oneStep = n;
    // 输出结果
    printf("走3步的次数: %d\n", threeSteps);
    printf("走2步的次数: %d\n", twoSteps);
    printf("走1步的次数: %d\n", oneStep);
    printf("总步数: %d\n", threeSteps + twoSteps + oneStep);
}
int main() {
    int n;
    printf("请输入楼梯的总步数: ");
    scanf_s("%d", &n);
    greedyStairs(n);
    return 0;
}
