/*
 G:Avoid The Lakes
 查看 提交 统计 提问
 总时间限制: 20000ms 单个测试点时间限制: 1000ms 内存限制: 65536kB
 描述
 Farmer John's farm was flooded in the most recent storm, a fact only aggravated by the information that his cows are deathly afraid of water. His insurance agency will only repay him, however, an amount depending on the size of the largest "lake" on his farm.
 
 The farm is represented as a rectangular grid with N (1 <= N <= 100) rows and M (1 <= M <= 100) columns. Each cell in the grid is either dry or submerged, and exactly K (1 <= K <= N*M) of the cells are submerged. As one would expect, a lake has a central cell to which other cells connect by sharing a long edge (not a corner). Any cell that shares a long edge with the central cell or shares a long edge with any connected cell becomes a connected cell and is part of the lake.
 输入
 * Line 1: Three space-separated integers: N, M, and K
 
 * Lines 2..K+1: Line i+1 describes one submerged location with two space separated integers that are its row and column: R and C
 输出
 * Line 1: The number of cells that the largest lake contains.
 样例输入
 3 4 5
 3 2
 2 2
 3 1
 2 3
 1 1
 样例输出
 4
 提示
 INPUT DETAILS:
 
 The farm is a grid with three rows and four columns; five of the cells are submerged. They are located in the positions (row 3, column 2); (row 2, column 2); (row 3, column 1); (row 2, column 3); (row 1, column 1):
 # . . .
 . # # .
 # # . .
 
 OUTPUT DETAILS:
 
 The largest lake consists of the input's first four cells.
 */

#include <iostream>
using namespace std;
int N, M, K;
int b[105][105];
int vis[105][105];
int cnt = 0;int size = 0;
inline bool inBoard(int i, int j) {
    return i >= 1 && i <= N && j >= 1 && j <= M;
}
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
void dfs(int i, int j) {
    vis[i][j] = 1;
    ++cnt;
    ++size;
    for (int k = 0; k < 4; ++k) {
        int x = i + dx[k];
        int y = j + dy[k];
        if (b[x][y] == 1 && inBoard(x, y) && !vis[x][y]) {
            dfs(x, y);
        }
    }
}

int max_size = 0;
void Output() {
    cout << max_size << endl;
}

int main() {
    cin >> N >> M >> K;
    for (int i = 1; i <= K; ++i) {
        int R, C; cin >> R >> C;
        b[R][C] = 1;
    }
    
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (b[i][j] == 1 && !vis[i][j]) {
                dfs(i, j);
                if (size > max_size) max_size = size;
                size = 0;
                if (K - cnt <= max_size) {
                    Output();
                    return 0;
                }
            }
        }
    }
    Output();
    return 0;
}
