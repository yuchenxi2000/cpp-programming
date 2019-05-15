#include <iostream>
#include <climits>
#include <memory>
using namespace std;
bool init_board[16][16];
bool board[16][16];
int N;
/*
 描述
 有一个正方形的墙，由N*N个正方形的砖组成，其中一些砖是白色的，另外一些砖是黄色的。Bob是个画家，想把全部的砖都涂成黄色。但他的画笔不好使。当他用画笔涂画第(i, j)个位置的砖时， 位置(i-1, j)、 (i+1, j)、 (i, j-1)、 (i, j+1)上的砖都会改变颜色。请你帮助Bob计算出最少需要涂画多少块砖，才能使所有砖的颜色都变成黄色。
 输入
 第一行是一个整数n (1≤n ≤15)，表示墙的大小。接下来的n行表示墙的初始状态。每一行包含n个字符。第i行的第j个字符表示位于位置(i,j)上的砖的颜色。“w”表示白砖，“y”表示黄砖。
 输出
 一行，如果Bob能够将所有的砖都涂成黄色，则输出最少需要涂画的砖数，否则输出“inf”。
 样例输入
 5
 wwwww
 wwwww
 wwwww
 wwwww
 wwwww
 样例输出
 15
 */
void Reverse(int i, int j) {
    board[i][j] = !board[i][j];
    if (i > 0) board[i - 1][j] = !board[i - 1][j];
    if (i < N - 1) board[i + 1][j] = !board[i + 1][j];
    if (j > 0) board[i][j - 1] = !board[i][j - 1];
    if (j < N - 1) board[i][j + 1] = !board[i][j + 1];
}

void Reset() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            board[i][j] = init_board[i][j];
        }
    }
}

int main(){
    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            char c; cin >> c; // 'w' : 0; 'y' : 1
            if (c == 'w') init_board[i][j] = 0;
            else init_board[i][j] = 1;
        }
    }
    
    Reset();
    
    unsigned int m = (1 << N);
    int min = INT_MAX;
    for (unsigned int i = 0; i < m; ++i) {
        int cnt = 0;
        for (int k = 0; k < N; ++k) {
            if (i & (1 << k)) {
                Reverse(0, k);
                ++cnt;
            }
        }
        
        for (int j = 1; j <= N - 1; ++j) {
            for (int t = 0; t < N; ++t) {
                if (board[j - 1][t] == 0) {
                    Reverse(j, t);
                    ++cnt;
                }
            }
        }
        
        bool done = true;
        for (int t = 0; t < N; ++t) {
            if (board[N - 1][t] == 0) {
                done = false;
                break;
            }
        }
        if (done) {
            if (cnt < min) {
                min = cnt;
            }
        }
        
        Reset();
    }
    
    if (min == INT_MAX) {
        cout << "inf" << endl;
    }else {
        cout << min << endl;
    }
}
