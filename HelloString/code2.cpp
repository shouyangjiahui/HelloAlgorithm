// 输出字符串
// 为了方便找规律写成如下形式 实际不存在前缀空格
//        A
//       ABA
//     ABACABA
// ABACABADABACABA
#include <iostream>
#include <cstring>
using namespace std;
char res[10000] = {0};
int main() {
    int n = 0;
    cin >> n;
    int len = 0;
    for(int i = 1; i <= n; i++) {
        strcat(res+len+1, res);
        res[len] = 'A' + i - 1;
        len = strlen(res);
    }
    printf("%s\n", res);
    return 0;
}