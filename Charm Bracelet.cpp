/*
 A:Charm Bracelet
 查看 提交 统计 提问
 总时间限制: 1000ms 内存限制: 65536kB
 描述
 Bessie has gone to the mall's jewelry store and spies a charm bracelet. Of course, she'd like to fill it with the best charms possible from the N(1 ≤ N≤ 3,402) available charms. Each charm iin the supplied list has a weight Wi(1 ≤ Wi≤ 400), a 'desirability' factor Di(1 ≤ Di≤ 100), and can be used at most once. Bessie can only support a charm bracelet whose weight is no more than M(1 ≤ M≤ 12,880).
 
 Given that weight limit as a constraint and a list of the charms with their weights and desirability rating, deduce the maximum possible sum of ratings.
 
 
 
 输入
 Line 1: Two space-separated integers: N and M
 Lines 2..N+1: Line i+1 describes charm i with two space-separated integers: Wi and Di
 输出
 Line 1: A single integer that is the greatest sum of charm desirabilities that can be achieved given the weight constraints
 样例输入
 4 6
 1 4
 2 6
 3 12
 2 7
 样例输出
 23
 来源
 USACO 2007 December Silver
 */

#include <iostream>
using namespace std;
int N, M;
#define CAPCITY (13000)
#define MAX(a, b) ((a > b) ? a : b)
int f[CAPCITY];
int main() {
    cin >> N >> M;
    
    for (int i = 0; i < N; ++i) {
        int w, d; cin >> w >> d;
        for (int x = M; x >= w; --x)
            f[x] = MAX(f[x], f[x - w] + d);
    }
    
    cout << f[M] << endl;
    return 0;
}
