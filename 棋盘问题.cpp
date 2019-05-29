/*
 A:棋盘问题
 查看 提交 统计 提问
 总时间限制: 1000ms 内存限制: 65536kB
 描述
 在一个给定形状的棋盘（形状可能是不规则的）上面摆放棋子，棋子没有区别。要求摆放时任意的两个棋子不能放在棋盘中的同一行或者同一列，请编程求解对于给定形状和大小的棋盘，摆放k个棋子的所有可行的摆放方案C。
 输入
 输入含有多组测试数据。
 每组数据的第一行是两个正整数，n k，用一个空格隔开，表示了将在一个n*n的矩阵内描述棋盘，以及摆放棋子的数目。 n <= 8 , k <= n
 当为-1 -1时表示输入结束。
 随后的n行描述了棋盘的形状：每行有n个字符，其中 # 表示棋盘区域， . 表示空白区域（数据保证不出现多余的空白行或者空白列）。
 输出
 对于每一组数据，给出一行输出，输出摆放的方案数目C （数据保证C<2^31）。
 样例输入
 2 1
 #.
 .#
 4 4
 ...#
 ..#.
 .#..
 #...
 -1 -1
 样例输出
 2
 1
 */

#include <iostream>
#include <cstring>
using namespace std;
char board[8][8];
int column[8];
int dfs(char board[8][8], int row, int remain, int n, int k) {
    if (remain == 0) return 1;
    if (row >= n) return 0;
    
    int ret = 0;
    for (int i = 0; i < n; ++i)
        if (board[row][i] == '#' && column[i] == 0) {
            column[i] = 1;
            ret += dfs(board, row + 1, remain - 1, n, k);
            column[i] = 0;
        }
    ret += dfs(board, row + 1, remain, n, k);
    
    return ret;
}

int main() {
    while (1) {
        int n, k; cin >> n >> k;
        if (n == -1) break;
        
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cin >> board[i][j];
        
        cout << dfs(board, 0, k, n, k) << endl;
        
        memset(board, 0, sizeof(board));
        memset(column, 0, sizeof(column));
    }
    return 0;
}
