/*
 A:Boolean Expressions
 查看 提交 统计 提问
 总时间限制: 1000ms 内存限制: 65536kB
 描述
 The objective of the program you are going to produce is to evaluate boolean expressions as the one shown next:
 Expression: ( V | V ) & F & ( F | V )
 
 where V is for True, and F is for False. The expressions may include the following operators: ! for not , & for and, | for or , the use of parenthesis for operations grouping is also allowed.
 
 To perform the evaluation of an expression, it will be considered the priority of the operators, the not having the highest, and the or the lowest. The program must yield V or F , as the result for each expression in the input file.
 输入
 The expressions are of a variable length, although will never exceed 100 symbols. Symbols may be separated by any number of spaces or no spaces at all, therefore, the total length of an expression, as a number of characters, is unknown.
 
 The number of expressions in the input file is variable and will never be greater than 20. Each expression is presented in a new line, as shown below.
 输出
 For each test expression, print "Expression " followed by its sequence number, ": ", and the resulting value of the corresponding test expression. Separate the output for consecutive test expressions with a new line.
 
 Use the same format as that shown in the sample output shown below.
 样例输入
 ( V | V ) & F & ( F| V)
 !V | V & V & !F & (F | V ) & (!F | F | !V & V)
 (F&F|V|!V&!F&!(F|F&V))
 样例输出
 Expression 1: F
 Expression 2: V
 Expression 3: V
 */

#include <iostream>
using namespace std;
bool previous;
bool expression();
bool item() {
    while (true) {
        int c = cin.peek();
        if (c == ' ') {cin.get(); continue;}
        else if (c == '!') {cin.get(); return !item();}
        else if (c == '(') {
            cin.get();
            bool res = expression();
            while (true) {
                int c = cin.peek();
                if (c == ')') {cin.get(); break;}
                else if (c == ' ') {cin.get(); continue;}
                else throw;
            }
            return res;
        }else if (c == 'V') {cin.get(); return true;}
        else if (c == 'F') {cin.get(); return false;}
        else exit(0); // 空表达式
    }
}
bool factor() {
    bool first = item();
    while (true) {
        int c = cin.peek();
        if (c == ' ') {cin.get(); continue;}
        else if (c == '\n') return first;
        else if (c == EOF) return first;
        else if (c == '&') {
            cin.get();
            bool second = factor();
            return first && second;
        }else {
            return first;
        }
    }
}
bool expression() {
    bool first = factor();
    while (true) {
        int c = cin.peek();
        if (c == ' ') {cin.get(); continue;}
        else if (c == '\n') return first;
        else if (c == EOF) return first;
        else if (c == '|') {
            cin.get();
            bool second = expression();
            return first || second;
        }else {
            return first;
        }
    }
}
int main() {
    int cnt = 0;
    while (true) {
        previous = expression();
        ++cnt;
        char c;
        if (previous) c = 'V';
        else c = 'F';
        cout << "Expression " << cnt << ": " << c << endl;
        while (true) {
            int c = cin.peek();
            if (c == ' ') {cin.get(); continue;}
            else if (c == '\n') {cin.get(); break;}
            else if (c == EOF) {return 0;}
            else throw;
        }
    }
}
