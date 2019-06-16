/*
 B:迷宫问题
 查看 提交 统计 提问
 总时间限制: 1000ms 内存限制: 65536kB
 描述
 定义一个二维数组：
 
 int maze[5][5] = {
 
 0, 1, 0, 0, 0,
 
 0, 1, 0, 1, 0,
 
 0, 0, 0, 0, 0,
 
 0, 1, 1, 1, 0,
 
 0, 0, 0, 1, 0,
 
 };
 
 它表示一个迷宫，其中的1表示墙壁，0表示可以走的路，只能横着走或竖着走，不能斜着走，要求编程序找出从左上角到右下角的最短路线。
 
 
 
 输入
 一个5 × 5的二维数组，表示一个迷宫。数据保证有唯一解。
 输出
 左上角到右下角的最短路径，格式如样例所示。
 样例输入
 0 1 0 0 0
 0 1 0 1 0
 0 0 0 0 0
 0 1 1 1 0
 0 0 0 1 0
 样例输出
 (0, 0)
 (1, 0)
 (2, 0)
 (2, 1)
 (2, 2)
 (2, 3)
 (2, 4)
 (3, 4)
 (4, 4)
 */

#include <iostream>
#include <vector>
using namespace std;
#define CAPCITY 100
int maze[5][5];
struct Coord {
    int x, y;
    int parent;
};
ostream & operator << (ostream & os, const Coord & coord) {
    os << '(' << coord.x << ", " << coord.y << ")\n";
    return os;
}
Coord queue[CAPCITY];
int vis[5][5];
int head = 0, tail = 0;
void step(int x, int y) {
    if (!vis[x][y] && maze[x][y] == 0) {
        ++tail;
        queue[tail].x = x;
        queue[tail].y = y;
        queue[tail].parent = head;
        vis[x][y] = true;
    }
}

void bfs() {

    while (head <= tail) {
        Coord & coord = queue[head];
        if (coord.x == 4 && coord.y == 4) {
            vector<Coord> ans;
            int p = head;
            while (p != 0) {
                ans.push_back(queue[p]);
                p = queue[p].parent;
            }
            ans.push_back(queue[0]);
            while (!ans.empty()) {
                cout << ans.back();
                ans.pop_back();
            }
            return;
        }
        if (coord.x + 1 < 5) step(coord.x + 1, coord.y);
        if (coord.y + 1 < 5) step(coord.x, coord.y + 1);
        if (coord.x - 1 >= 0) step(coord.x - 1, coord.y);
        if (coord.y - 1 >= 0) step(coord.x, coord.y - 1);
        ++head;
    }
    
}

int main() {
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j) {
            int c; cin >> c;
            maze[i][j] = c;
        }
    
    bfs();
    
    return 0;
}
