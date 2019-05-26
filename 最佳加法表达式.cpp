/*
 D:最佳加法表达式
 查看 提交 统计 提问
 总时间限制: 1000ms 内存限制: 65536kB
 描述
 给定n个1到9的数字，要求在数字之间摆放m个加号(加号两边必须有数字），使得所得到的加法表达式的值最小，并输出该值。例如，在1234中摆放1个加号，最好的摆法就是12+34,和为36
 
 输入
 有不超过15组数据
 每组数据两行。第一行是整数m，表示有m个加号要放( 0<=m<=50)
 第二行是若干个数字。数字总数n不超过50,且 m <= n-1
 输出
 对每组数据，输出最小加法表达式的值
 样例输入
 2
 123456
 1
 123456
 4
 12345
 样例输出
 102
 579
 15
 提示
 要用到高精度计算，即用数组来存放long long 都装不下的大整数，并用模拟列竖式的办法进行大整数的加法。
 */

#include <iostream>
#include <cstring>
using namespace std;
class Huge {
public:
    char bits[64];
    long long size;
    
    Huge() {size = 0;}
    Huge(const char * num, int begin, int end) {
        size = end - begin + 1;
        int src = end;
        int dest = 0;
        
        for (; src >= begin; --src, ++dest)
            bits[dest] = num[src];
    }
    Huge(const char * str) {
        size = strlen(str);
        
        for (long long i = 0, j = size - 1; j >= 0; ++i, --j)
            bits[i] = str[j];
    }
    
    void init() {
        size = 1;
        bits[0] = '0';
    }
    
    void inf() {
        size = 64;
    }
    
    Huge & operator = (const Huge & other) {
        this->size = other.size;
        for (int i = 0; i < size; ++i)
            bits[i] = other.bits[i];
        return *this;
    }
    
    Huge operator + (const Huge & other) {
        Huge tmp;
        int k = 0;
        long long carrier = 0;
        
        for (; k < this->size && k < other.size; ++k) {
            long long sum = this->bits[k] + other.bits[k] - 2 * '0' + carrier;
            tmp.bits[k] = sum % 10 + '0';
            carrier = sum / 10;
        }
        
        for (; k < this->size; ++k) {
            long long sum = this->bits[k] - '0' + carrier;
            tmp.bits[k] = sum % 10 + '0';
            carrier = sum / 10;
        }
        
        for (; k < other.size; ++k) {
            long long sum = other.bits[k] - '0' + carrier;
            tmp.bits[k] = sum % 10 + '0';
            carrier = sum / 10;
        }
        
        for (; carrier > 0; ++k) {
            tmp.bits[k] = carrier % 10 + '0';
            carrier /= 10;
        }
        
        tmp.size = k;
        return tmp;
    }
    
    bool operator > (const Huge & other) {
        if (this->size != other.size) {
            return this->size > other.size;
        }else {
            for (long long i = this->size - 1; i >= 0; --i) {
                if (this->bits[i] != other.bits[i]) return this->bits[i] > other.bits[i];
            }
            return false;
        }
    }
    
    bool operator < (const Huge & other) {
        if (this->size != other.size) {
            return this->size < other.size;
        }else {
            for (long long i = this->size - 1; i >= 0; --i) {
                if (this->bits[i] != other.bits[i]) return this->bits[i] < other.bits[i];
            }
            return false;
        }
    }
    
    bool operator == (const Huge & other) {
        if (this->size != other.size) {
            return false;
        }else {
            for (long long i = this->size - 1; i >= 0; --i) {
                if (this->bits[i] != other.bits[i]) return false;
            }
            return true;
        }
    }
};

ostream & operator << (ostream & os, const Huge & num) {
    for (long long i = num.size - 1; i >= 0; --i)
        os << num.bits[i];
    return os;
}

Huge f[64][64];
char buffer[64];
int m;

#define MIN(a, b) ((a < b) ? a : b)
int main() {
    while (cin >> m && cin >> buffer) {
        int size = (int)strlen(buffer);
        
        for (int i = 0; i <= size - 1; ++i)
            f[0][i] = Huge(buffer, 0, i);
        
        for (int k = 1; k <= m; ++k)
            for (int i = 0; i <= size - 1; ++i) {
                f[k][i].inf();
                for (int j = 0; j < i; ++j)
                    f[k][i] = MIN(f[k][i], f[k - 1][j] + Huge(buffer, j + 1, i));
            }
        
        cout << f[m][size - 1] << endl;
    }
    
    return 0;
}
