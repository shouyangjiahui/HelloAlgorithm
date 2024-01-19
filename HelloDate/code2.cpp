// 计算指定日期指定天数之后的日期
#include <iostream>
using namespace std;
int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main() {
    int y, m, d, k;
    cin >> y >> m >> d >> k;
    for(int i = 1; i <= k; i++) {
        if(y % 400 == 0 || (y % 100 != 0 && y % 4 == 0)) {
            days[2] = 29;
        } else {
            days[2] = 28;
        }
        d++;
        if(d == days[m] + 1) {
            d = 1;
            m++;
        }
        if(m == 13) {
            m = 1;
            y++;
        }
    }
    printf("%4d-%02d-%02d\n", y, m, d);
    return 0;
}