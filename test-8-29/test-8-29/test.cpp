#include <iostream>
#include <vector>
using namespace std;
class Solutions {
public:
    vector<vector<int>> Snake(const int& n) {
        vector<vector<int>> snake(n, vector<int>(n));
        int num = 1;
        int x = 0, y = 0;
        int flag;
        for (int k = 0; k < 2 * n; ++k) {
            flag = k >= n - 1 ? 1 : 0;
            if (!flag) {//������
                if (!(k & 1)) {//б����
                    while (x >= 0)
                        snake[x--][y++] = num++;
                    ++x;
                }
                else {//б����
                    while (y >= 0)
                        snake[x++][y--] = num++;
                    ++y;
                }
            }
            else {//������
                if (!(k & 1)) {//б����
                    while (y < n)
                        snake[x--][y++] = num++;
                    x += 2, --y;
                }
                else {//б����
                    while (x < n)
                        snake[x++][y--] = num++;
                    y += 2, --x;
                }
            }
        }
        return snake;
    }
    void ShowMatrix(const vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j)
                printf("%4d ", matrix[i][j]);
            cout << endl;
        }
    }
};
int main() {
    int n;
    cin >> n;
    Solutions s;
    vector<vector<int>> m(n, vector<int>(n));
    m = s.Snake(n);
    s.ShowMatrix(m);
    return 0;
}

