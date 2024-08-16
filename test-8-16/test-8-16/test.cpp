#include<iostream>
using namespace std;
int cnt = 1;//����������
int chess[8][8];//�������
bool judge(int row, int col);//�ж�ĳ��λ���Ƿ�ɷ�
void print();//�������
void dfs(int row) {
    if (row >= 8) {//���ѽ�������
        print();
        cnt++;
        return;
    }
    for (int j = 0; j <= 7; j++) {
        if (judge(row, j)) {
            chess[row][j] = 1;
            dfs(row + 1);//����
            chess[row][j] = 0;//���ݣ���ʾ����λ�����ԣ�֮ǰ��λ�þ͵���û�߿�
        }
    }
}
int main() {
    dfs(0);
    return 0;
}
bool judge(int row, int col) {
    for (int i = 0; i <= 7; i++)//�ж���
        if (chess[i][col] == 1) return false;
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {//�ж����϶Խ���
        if (chess[i][j] == 1) return false;
    }
    for (int i = row, j = col; i >= 0 && j <= 7; i--, j++) {//�ж����϶Խ���
        if (chess[i][j] == 1) return false;
    }
    return true;
}
void print() {
    cout << "No. " << cnt << endl;
    for (int j = 0; j <= 7; j++) {//!!!�������!!!
        for (int i = 0; i <= 7; i++) {
            if (chess[i][j] == 1) cout << "1" << " ";
            else cout << "0" << " ";
        }
        cout << endl;
    }
}
