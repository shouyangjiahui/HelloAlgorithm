// 打印字母或数字三角形 每行字符先增后减
//   A
//  ABA
// ABCBA
//      1
//     121
//    12321
//   1234321
//  123454321
// 12345654321
#include <iostream>
using namespace std;
int main() {
    char c = 0;
    cin >> c;
    if(c >= 'A' && c <= 'Z') {
        // 遍历每一行 (行数 = c - 'A' + 1)
        for(int i = 1; i <= c - 'A' + 1; i++) {
            // 输出空格
            for(int j = 1; j <= c - 'A' + 1 - i; j++) {
                cout << ' ';
            }
            // 输出正序字母
            for(int j = 1; j <= i; j++) {
                cout << (char)('A' + j - 1);
            }
            // 输出逆序字母
            for(int j = i - 1; j >= 1; j--) {
                cout << (char)('A' + j - 1);
            }
            cout << endl;
        }
    } else if(c >= '1' && c <= '9') {
        for(int i = 1; i <= c - '1' + 1; i++) {
            // 输出空格
            for(int j = 1; j <= c - '1' + 1 - i; j++) {
                cout << ' ';
            }
            // 输出正序数字
            for(int j = 1; j <= i; j++) {
                cout << (char)('1' + j - 1);
            }
            // 输出逆序数字
            for(int j = i - 1; j >= 1; j--) {
                cout << (char)('1' + j - 1);
            }
            cout << endl;
        }
    }
    return 0;
}