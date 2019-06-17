// 这份代码主要是为了看看垃圾代码能垃圾到什么程度

/*
 04:拖延症
 查看 提交 统计 提问
 总时间限制: 1000ms 内存限制: 65536kB
 描述
 Tony老师是一个自由职业者。他手中有一份接下来15天的每日工作安排，他要选择一些日子来工作。
 每天的工作会带来一定的收入w_i，但会消耗一定的精神值s_i。
 Tony老师最初一共有S点精神值；如果进行到某天，他的剩余精神值不足以完成当天的任务，那么他就不会开始这项任务。
 另外，Tony老师有严重的拖延症，他在最后5天的工作天数一定要比前10天的加起来多（或者相等）。
 请你帮Tony老师计算一下，他这三个礼拜最多可以赚到多少钱？
 
 
 输入
 第一行是一个正整数S，表示Tony老师一开始的精神值。（保证所有精神值加起来不超过int的范围）
 随后是15行，每行2个整数，分别表示当天工作的收入wi和要消耗的精神值si。
 输出
 一个整数，Tony老师最多可以赚到的钱数。
 样例输入
 120
 3 2
 3 2
 3 2
 8 2
 3 2
 5 4
 5 4
 5 4
 5 4
 5 4
 10 5
 10 5
 10 5
 10 5
 10 5
 样例输出
 78
 提示
 样例解释：
 最后5天每天都工作。
 前10天中，第四天（8 2）工作，然后再在6-10天中（5 4）选择4天工作即可。
 */

#include <iostream>
using namespace std;
int S;
int w[15];
int s[15];
int main() {
    cin >> S;
    for (int i = 0; i < 15; ++i) {
        cin >> w[i] >> s[i];
    }
    
    int wmax = 0;
    for (int i = 0; i < (1 << 5); ++i) {
        int s5 = 0, d5 = 0, w5 = 0;
        for (int k = 0; k < 5; ++k) {
            if (i & (1 << k)) {
                ++d5;
                s5 += s[k + 10];
                w5 += w[k + 10];
            }
        }
        
        int s10 = S - s5;
        if (s10 <= 0) continue;
        if (d5 < 1) continue;
        for (int j = 0; j < 10; ++j) {
            if (w5 + w[j] > wmax && s[j] <= s10) {
                wmax = w5 + w[j];
            }
        }
        if (d5 < 2) continue;
        for (int k = 0; k < 10; ++k)
            for (int j = k + 1; j < 10; ++j) {
                if (w5 + w[k] + w[j] > wmax && s[k] + s[j] <= s10) {
                    wmax = w5 + w[k] + w[j];
                }
            }
        if (d5 < 3) continue;
        for (int a = 0; a < 10; ++a)
            for (int k = a + 1; k < 10; ++k)
                for (int j = k + 1; j < 10; ++j) {
                    if (w5 + w[a] + w[k] + w[j] > wmax && s[a] + s[k] + s[j] <= s10) {
                        wmax = w5 + w[a] + w[k] + w[j];
                    }
                }
        if (d5 < 4) continue;
        for (int b = 0; b < 10; ++b)
            for (int a = b + 1; a < 10; ++a)
                for (int k = a + 1; k < 10; ++k)
                    for (int j = k + 1; j < 10; ++j) {
                        if (w5 + w[b] + w[a] + w[k] + w[j] > wmax && s[b] + s[a] + s[k] + s[j] <= s10) {
                            wmax = w5 + w[b] + w[a] + w[k] + w[j];
                        }
                    }
        if (d5 < 5) continue;
        for (int c = 0; c < 10; ++c)
            for (int b = c + 1; b < 10; ++b)
                for (int a = b + 1; a < 10; ++a)
                    for (int k = a + 1; k < 10; ++k)
                        for (int j = k + 1; j < 10; ++j) {
                            if (w5 + w[c] + w[b] + w[a] + w[k] + w[j] > wmax && s[c] + s[b] + s[a] + s[k] + s[j] <= s10) {
                                wmax = w5 + w[c] + w[b] + w[a] + w[k] + w[j];
                            }
                        }
    }
    cout << wmax << endl;
    return 0;
}
