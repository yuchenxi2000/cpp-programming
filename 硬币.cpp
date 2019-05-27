/*
 C:硬币
 查看 提交 统计 提问
 总时间限制: 1000ms 内存限制: 262144kB
 描述
 宇航员Bob有一天来到火星上，他有收集硬币的习惯。于是他将火星上所有面值的硬币都收集起来了，一共有n种，每种只有一个：面值分别为a1,a2… an。 Bob在机场看到了一个特别喜欢的礼物，想买来送给朋友Alice，这个礼物的价格是X元。Bob很想知道为了买这个礼物他的哪些硬币是必须被使用的，即Bob必须放弃收集好的哪些硬币种类。飞机场不提供找零，只接受恰好X元。
 
 输入
 第一行包含两个正整数n和x。（1 <= n <= 200, 1 <= x <= 10000)
 第二行从小到大为n个正整数a1, a2, a3 … an （1 <= ai <= x)
 输出
 第一行是一个整数，即有多少种硬币是必须被使用的。
 第二行是这些必须使用的硬币的面值（从小到大排列）。
 样例输入
 5 18
 1 2 3 5 10
 样例输出
 2
 5 10
 提示
 输入数据将保证给定面值的硬币中至少有一种组合能恰好能够支付X元。
 如果不存在必须被使用的硬币，则第一行输出0，第二行输出空行。
 */

#include <iostream>
#include <vector>
using namespace std;
int f[10005];
int p[205];
int N, X;

int exclusive(int total, int coin) {
    int ans = 0;
    while (total >= 0) {
        ans += f[total];
        total -= coin;
        if (total < 0) break;
        ans -= f[total];
        total -= coin;
    }
    return ans;
}

int main() {
    cin >> N >> X;
    
    f[0] = 1;
    for (int i = 0; i < N; ++i) {
        cin >> p[i];
        for (int x = X; x >= 0; --x) {
            if (x >= p[i]) f[x] += f[x - p[i]];
        }
    }
    
    vector<int> ans;
    for (int i = 0; i < N; ++i)
        if (exclusive(X, p[i]) == 0) ans.push_back(p[i]);
    
    cout << ans.size() << endl;
    auto p = ans.begin();
    if (p != ans.end()) {
        cout << *p;
        for (++p; p != ans.end(); ++p)
            cout << ' ' << *p;
    }
    cout << endl;

    return 0;
}
