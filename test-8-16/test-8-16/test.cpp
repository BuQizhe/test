#include<iostream>
using namespace std;
int cnt = 1;//方案计数器
int chess[8][8];//棋盘情况
bool judge(int row, int col);//判断某个位置是否可放
void print();//输出函数
void dfs(int row) {
    if (row >= 8) {//深搜结束条件
        print();
        cnt++;
        return;
    }
    for (int j = 0; j <= 7; j++) {
        if (judge(row, j)) {
            chess[row][j] = 1;
            dfs(row + 1);//深搜
            chess[row][j] = 0;//回溯，表示换个位置试试，之前的位置就当作没走咯
        }
    }
}
int main() {
    dfs(0);
    return 0;
}
bool judge(int row, int col) {
    for (int i = 0; i <= 7; i++)//判断列
        if (chess[i][col] == 1) return false;
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {//判断左上对角线
        if (chess[i][j] == 1) return false;
    }
    for (int i = row, j = col; i >= 0 && j <= 7; i--, j++) {//判断右上对角线
        if (chess[i][j] == 1) return false;
    }
    return true;
}
void print() {
    cout << "No. " << cnt << endl;
    for (int j = 0; j <= 7; j++) {//!!!按列输出!!!
        for (int i = 0; i <= 7; i++) {
            if (chess[i][j] == 1) cout << "1" << " ";
            else cout << "0" << " ";
        }
        cout << endl;
    }
}
