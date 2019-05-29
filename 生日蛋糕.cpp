/*
 B:生日蛋糕
 查看 提交 统计 提问
 总时间限制: 5000ms 内存限制: 65536kB
 描述
 7月17日是Mr.W的生日，ACM-THU为此要制作一个体积为Nπ的M层生日蛋糕，每层都是一个圆柱体。
 设从下往上数第i(1 <= i <= M)层蛋糕是半径为Ri, 高度为Hi的圆柱。当i < M时，要求Ri > Ri+1且Hi > Hi+1。
 由于要在蛋糕上抹奶油，为尽可能节约经费，我们希望蛋糕外表面（最下一层的下底面除外）的面积Q最小。
 令Q = Sπ
 请编程对给出的N和M，找出蛋糕的制作方案（适当的Ri和Hi的值），使S最小。
 （除Q外，以上所有数据皆为正整数）
 输入
 有两行，第一行为N（N <= 10000），表示待制作的蛋糕的体积为Nπ；第二行为M(M <= 20)，表示蛋糕的层数为M。
 输出
 仅一行，是一个正整数S（若无解则S = 0）。
 样例输入
 100
 2
 样例输出
 68
 提示
 圆柱公式
 体积V = πR2H
 侧面积A' = 2πRH
 底面积A = πR2
 */

// 我竟然从最上面一层开始递归
// 我蔡炸了.jpg

#include <iostream>
#include <cstring>
#include <climits>
#include <cmath>
using namespace std;
int N, M;
int S_min;

int min_s[25];
int min_v[25];

void dfs(int v, int r, int h, int s, int level) {
    if (level == 0) {
        if (v == 0 && s < S_min) {
            S_min = s;
        }
        return;
    }
    if (v <= 0) return;
    
    for (int j = r - 1; j >= level; --j) {
        for (int i = level; i <= h - 1; ++i) {
            int vv = v - j * j * i;
            int ss = s + 2 * j * i;
            if (level == M) ss += j * j;
            
            if (level >= 1 && vv < min_v[level - 1]) break;
            if (level >= 1 && ss + min_s[level - 1] >= S_min) break;
            
            dfs(vv, j, i, ss, level - 1);
        }
    }
}

int main() {
    cin >> N >> M;
    
    for (int i = 1; i <= M; ++i) {
        min_s[i] = min_s[i - 1] + 2 * i * i;
        min_v[i] = min_v[i - 1] + i * i * i;
    }
    
    S_min = INT_MAX;
    
    dfs(N, sqrt(N / M) + 1, N + 1, 0, M);
    
    if (S_min == INT_MAX) cout << '0' << endl;
    else cout << S_min << endl;
    
    return 0;
}
