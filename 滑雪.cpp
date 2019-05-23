/*
 B:滑雪
 查看 提交 统计 提问
 总时间限制: 1000ms 内存限制: 65536kB
 描述
 Michael喜欢滑雪百这并不奇怪， 因为滑雪的确很刺激。可是为了获得速度，滑的区域必须向下倾斜，而且当你滑到坡底，你不得不再次走上坡或者等待升降机来载你。Michael想知道载一个区域中最长的滑坡。区域由一个二维数组给出。数组的每个数字代表点的高度。下面是一个例子
 1  2  3  4 5
 16 17 18 19 6
 15 24 25 20 7
 14 23 22 21 8
 13 12 11 10 9
 
 一个人可以从某个点滑向上下左右相邻四个点之一，当且仅当高度减小。在上面的例子中，一条可滑行的滑坡为24-17-16-1。当然25-24-23-...-3-2-1更长。事实上，这是最长的一条。
 输入
 输入的第一行表示区域的行数R和列数C(1 <= R,C <= 100)。下面是R行，每行有C个整数，代表高度h，0<=h<=10000。
 输出
 输出最长区域的长度。
 样例输入
 5 5
 1 2 3 4 5
 16 17 18 19 6
 15 24 25 20 7
 14 23 22 21 8
 13 12 11 10 9
 样例输出
 25
 */

#include <iostream>
#include <vector>
using namespace std;
int a[110][110];
int vis[110][110];
int R, C;

inline bool inArea(int i, int j) {
    return i >= 0 && j >= 0 && i < R && j < C;
}

#define MAX(a, b) ((a > b) ? a : b)

int Path(int i, int j) {
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};
    
    int ans = 1;
    for (int k = 0; k < 4; ++k)
        if (inArea(i + dx[k], j + dy[k]) && a[i + dx[k]][j + dy[k]] < a[i][j]) {
            int path = vis[i + dx[k]][j + dy[k]];
            if (path == 0) {
                path = Path(i + dx[k], j + dy[k]);
            }
            ans = MAX(ans, path + 1);
        }
    
    vis[i][j] = ans;
    return ans;
}

int main() {
    
    cin >> R >> C;
    
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            cin >> a[i][j];
    
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            if (vis[i][j] == 0) vis[i][j] = Path(i, j);
    
    int max_path = 1;
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            if (vis[i][j] > max_path) max_path = vis[i][j];
    
    cout << max_path << endl;
    return 0;
}
