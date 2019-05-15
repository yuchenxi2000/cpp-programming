/*
 B:拨钟问题
 查看 提交 统计 提问
 总时间限制: 1000ms 内存限制: 65536kB
 描述
 有9个时钟，排成一个3*3的矩阵。
 
 |-------|    |-------|    |-------|
 |       |    |       |    |   |   |
 |---O   |    |---O   |    |   O   |
 |       |    |       |    |       |
 |-------|    |-------|    |-------|
 A            B            C
 
 |-------|    |-------|    |-------|
 |       |    |       |    |       |
 |   O   |    |   O   |    |   O   |
 |   |   |    |   |   |    |   |   |
 |-------|    |-------|    |-------|
 D            E            F
 
 |-------|    |-------|    |-------|
 |       |    |       |    |       |
 |   O   |    |   O---|    |   O   |
 |   |   |    |       |    |   |   |
 |-------|    |-------|    |-------|
 G            H            I
 (图 1)
 现在需要用最少的移动，将9个时钟的指针都拨到12点的位置。共允许有9种不同的移动。如下表所示，每个移动会将若干个时钟的指针沿顺时针方向拨动90度。
 
 
 
 移动    影响的时钟
 
 1         ABDE
 2         ABC
 3         BCEF
 4         ADG
 5         BDEFH
 6         CFI
 7         DEGH
 8         GHI
 9         EFHI
 输入
 9个整数，表示各时钟指针的起始位置，相邻两个整数之间用单个空格隔开。其中，0=12点、1=3点、2=6点、3=9点。
 输出
 输出一个最短的移动序列，使得9个时钟的指针都指向12点。按照移动的序号从小到大输出结果。相邻两个整数之间用单个空格隔开。
 样例输入
 3 3 0
 2 2 2
 2 1 2
 样例输出
 4 5 8 9
 
 */
/*
 本来以为要用队列，没想到直接枚举就行了。
 十分愚蠢的题目。。。
 
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
// a b d = 0
// a b c e = 1
// b c f = 2
// a d e g = 3
// a c e g i = 4
// c e f i = 5
// d g h = 6
// e g h i = 7
// f h i = 8
#define For(a) for(int a = 0; a < 4; ++a)
#define Output(a, s, index) for(int k = 0; k < a; ++k) {\
                                s += char('0' + index);\
                                s += ' ';\
                            }

void Solve(int board[9]) {
    For(a)
    For(b)
    For(d) {
        if ((a + b + d) % 4 != board[0]) continue;
        For(c)
        For(e) {
            if ((a + b + c + e) % 4 != board[1]) continue;
            For(f) {
                if ((b + c + f) % 4 != board[2]) continue;
                For(g) {
                    if ((a + d + e + g) % 4 != board[3]) continue;
                    For(h) {
                        if ((d + g + h) % 4 != board[6]) continue;
                        For(i) {
                            if ((a + c + e + g + i) % 4 != board[4]) continue;
                            else if ((c + e + f + i) % 4 != board[5]) continue;
                            else if ((e + g + h + i) % 4 != board[7]) continue;
                            else if ((f + h + i) % 4 != board[8]) continue;
                            else {
                                string s;
                                Output(a, s, 1);
                                Output(b, s, 2);
                                Output(c, s, 3);
                                Output(d, s, 4);
                                Output(e, s, 5);
                                Output(f, s, 6);
                                Output(g, s, 7);
                                Output(h, s, 8);
                                Output(i, s, 9);
                                long long len = s.size();
                                cout << s.substr(0, len - 1);
                                return;
                            }
                        }
                    }
                }
            }
        }
    }
    
}

int main() {
    int board[9];
    for (int i = 0; i < 9; ++i) {
        cin >> board[i];
        switch (board[i]) {
            case 0:
                board[i] = 0;
                break;
                
            case 1:
                board[i] = 3;
                break;
                
            case 2:
                board[i] = 2;
                break;
                
            default:
                board[i] = 1;
                break;
        }
    }
    Solve(board);
}
