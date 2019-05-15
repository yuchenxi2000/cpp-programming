/*
 C:特殊密码锁
 查看 提交 统计 提问
 总时间限制: 1000ms 内存限制: 1024kB
 描述
 有一种特殊的二进制密码锁，由n个相连的按钮组成（n<30），按钮有凹/凸两种状态，用手按按钮会改变其状态。
 
 然而让人头疼的是，当你按一个按钮时，跟它相邻的两个按钮状态也会反转。当然，如果你按的是最左或者最右边的按钮，该按钮只会影响到跟它相邻的一个按钮。
 
 当前密码锁状态已知，需要解决的问题是，你至少需要按多少次按钮，才能将密码锁转变为所期望的目标状态。
 
 输入
 两行，给出两个由0、1组成的等长字符串，表示当前/目标密码锁状态，其中0代表凹，1代表凸。
 输出
 至少需要进行的按按钮操作次数，如果无法实现转变，则输出impossible。
 样例输入
 011
 000
 样例输出
 1
 */

#include <iostream>
#include <climits>
#include <string>
using namespace std;
bool init_board[30];
bool board[30];
bool dest[30];
int N;
void flip(bool board[], int i) {
    board[i] = !board[i];
    if (i > 0) board[i - 1] = !board[i - 1];
    if (i < N - 1) board[i + 1] = !board[i + 1];
}
int main() {
    string s;
    cin >> s;
    N = (int)s.size();
    for (int i = 0; i < N; ++i) {
        init_board[i] = s[i] - '0';
        board[i] = init_board[i];
    }
    
    cin >> s;
    for (int i = 0; i < N; ++i) {
        dest[i] = s[i] - '0';
    }
    
    int cnt1 = 0;
    flip(board, 0);
    ++cnt1;
    for (int i = 1; i < N; ++i) {
        if (board[i - 1] != dest[i - 1]) {flip(board, i); ++cnt1;}
    }
    if (board[N - 1] != dest[N - 1]) cnt1 = INT_MAX;
    
    int cnt2 = 0;
    for (int i = 1; i < N; ++i) {
        if (init_board[i - 1] != dest[i - 1]) {flip(init_board, i); ++cnt2;}
    }
    if (init_board[N - 1] != dest[N - 1]) cnt2 = INT_MAX;
    
    int cnt_min = (cnt1 > cnt2) ? cnt2 : cnt1;
    
    if (cnt_min == INT_MAX) cout << "impossible" << endl;
    else cout << cnt_min << endl;
}
