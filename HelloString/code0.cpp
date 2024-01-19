// 打印字母三角形
// 使用string的构造快速实现字母三角形
#include <iostream>
#include <string>
using namespace std;
int main() {
    int n = 0;  // 三角形的高度
    cin >> n;
    for(int i = 1; i <= n; i++) {
        string space(n-i, ' ');
        string ch(2*i-1, 'A'+i-1);
        cout << space << ch << endl;
    }
    return 0;
}