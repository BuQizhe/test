//̰���㷨��¥��

#include<stdio.h>
// ʹ��̰���㷨������¥�ݵ����ٲ���
void greedyStairs(int n) {
    int steps = 0; // �ܲ���
    int threeSteps = 0; // ��3���Ĵ���
    int twoSteps = 0; // ��2���Ĵ���
    int oneStep = 0; // ��1���Ĵ���
    // ���Ⱦ����ܶ����3��
    threeSteps = n / 3;
    n -= threeSteps * 3;
    // Ȼ�󾡿��ܶ����2��
    twoSteps = n / 2;
    n -= twoSteps * 2;
    // �����ʣ�µ�1��
    oneStep = n;
    // ������
    printf("��3���Ĵ���: %d\n", threeSteps);
    printf("��2���Ĵ���: %d\n", twoSteps);
    printf("��1���Ĵ���: %d\n", oneStep);
    printf("�ܲ���: %d\n", threeSteps + twoSteps + oneStep);
}
int main() {
    int n;
    printf("������¥�ݵ��ܲ���: ");
    scanf_s("%d", &n);
    greedyStairs(n);
    return 0;
}
