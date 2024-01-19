// 输出嵌套十字图案
#include <iostream>
using namespace std;
char s[150][150];
int main() {
    int n;
    cin >> n;
    int x = 0, y = 0;
    // 初始化为'.'
    for(int i = 0; i < 4*n+5; i++) {
        for(int j = 0; j < 4*n+5; j++) {
            s[i][j] = '.';
        }
    }
    // 插入'$'
    for(int i = 0; i < n+1; i++) {
        for(int j = y+2; j <= y + 4*(n-i)+2; j++) {
            s[x][j] = '$';
        }
        for(int j = x; j <= x+2; j++) {
            s[j][y+2] = '$';
        }
        for(int j = x; j <= x+2; j++) {
            s[j][y+4*(n-i)+2] = '$';
        }
        for(int j = y; j <= y+2; j++) {
            s[x+2][j] = '$';
        }
        for(int j = y+4*(n-i)+2; j<= y+4*(n-i)+4; j++) {
            s[x+2][j] = '$';
        }
        for(int j = x+2; j <= x+4*(n-i)+2; j++) {
            s[j][y] = '$';
        }
        for(int j = x+2; j <= x+4*(n-i)+2; j++) {
            s[j][y+4*(n-i)+4] = '$';
        }
        for(int j = y; j <= y+2; j++) {
            s[x+4*(n-i)+2][j] = '$';
        }
        for(int j = y+4*(n-i)+2; j <= y+4*(n-i)+4; j++) {
            s[x+4*(n-i)+2][j] = '$';
        }
        for(int j = y+4*(n-i)+2; j <= y+4*(n-i)+4; j++) {
            s[j][y+2] = '$';
        }
        for(int j = y+4*(n-i)+2; j <= y+4*(n-i)+4; j++) {
            s[j][y+4*(n-i)+2] = '$';
        }
        for(int j = y+2; j <= y+4*(n-i)+2; j++) {
            s[x+4*(n-i)+4][j] = '$';
        }
        x += 2;
        y += 2;
    }
    for(int i = 0; i < 4*n+5; i++) {
        cout << s[i] << '\n';
    }
}