/*
 A:UNIMODAL PALINDROMIC DECOMPOSITIONS
 查看 提交 统计 提问
 总时间限制: 1000ms 内存限制: 65536kB
 描述
 A sequence of positive integers is Palindromic if it reads the same forward and backward. For example:
 23 11 15 1 37 37 1 15 11 23
 1 1 2 3 4 7 7 10 7 7 4 3 2 1 1
 A Palindromic sequence is Unimodal Palindromic if the values do not decrease up to the middle value and then (since the sequence is palindromic) do not increase from the middle to the end For example, the first example sequence above is NOT Unimodal Palindromic while the second example is.
 A Unimodal Palindromic sequence is a Unimodal Palindromic Decomposition of an integer N, if the sum of the integers in the sequence is N. For example, all of the Unimodal Palindromic Decompositions of the first few integers are given below:
 1: (1)
 2: (2), (1 1)
 3: (3), (1 1 1)
 4: (4), (1 2 1), (2 2), (1 1 1 1)
 5: (5), (1 3 1), (1 1 1 1 1)
 6: (6), (1 4 1), (2 2 2), (1 1 2 1 1), (3 3),
 (1 2 2 1), ( 1 1 1 1 1 1)
 7: (7), (1 5 1), (2 3 2), (1 1 3 1 1), (1 1 1 1 1 1 1)
 8: (8), (1 6 1), (2 4 2), (1 1 4 1 1), (1 2 2 2 1),
 (1 1 1 2 1 1 1), ( 4 4), (1 3 3 1), (2 2 2 2),
 (1 1 2 2 1 1), (1 1 1 1 1 1 1 1)
 
 Write a program, which computes the number of Unimodal Palindromic Decompositions of an integer.
 
 输入
 Input consists of a sequence of positive integers, one per line ending with a 0 (zero) indicating the end.
 输出
 For each input value except the last, the output is a line containing the input value followed by a space, then the number of Unimodal Palindromic Decompositions of the input value. See the example on the next page.
 样例输入
 2
 3
 4
 5
 6
 7
 8
 10
 23
 24
 131
 213
 92
 0
 样例输出
 2 2
 3 2
 4 4
 5 3
 6 7
 7 5
 8 11
 10 17
 23 104
 24 199
 131 5010688
 213 1055852590
 92 331143
 提示
 N < 250
 来源
 Greater New York 2002
 */

#include <iostream>
using namespace std;
#define MAX 300
long long f[MAX][MAX];
int main() {
    int x_max = 0;
    f[0][0] = 1;
    while (1) {
        int x; cin >> x;
        if (x == 0) break;
        
        for (int y = x_max + 1; y <= x; ++y)
            for (int a = 1; a <= y; ++a) {
                int i;
                f[y][a] = 0;
                for (i = 0; i <= a && 2 * i <= y; ++i)
                    f[y][a] += f[y - i][i];
                for (; i <= a; ++i)
                    f[y][a] += f[y - i][y - i];
            }
        
        long long N = 0;
        int i;
        for (i = 0; 2 * i <= x && 3 * i < x; ++i)
            N += f[i][i];
        for (; 2 * i <= x; ++i)
            N += f[i][x - 2 * i];
        
        if (x % 2 == 0) N += f[x >> 1][x >> 1];
        
        cout << x << ' ' << N << endl;
        
        if (x_max < x) x_max = x;
    }
    return 0;
}
