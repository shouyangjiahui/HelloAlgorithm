// 计算某年共有多少天假期
#include <iostream>
using namespace std;
int mm[10] = {1, 5, 10, 10, 10, 12};
int dd[10] = {1, 1, 1, 2, 3, 25};
int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main() {
    int y, w, m = 1, d = 1, springFestival = 0, ans = 0;
    cin >> y;
    for(int i = 6; i <= 9; i++) {
        cin >> mm[i] >> dd[i];  // 输入春节 清明 端午 中秋的阳历日期
    }
    cin >> w;  // 当年1月1日是星期几
    if(y % 400 == 0 || (y % 100 != 0 && y % 4 == 0)) {
        days[2]++;
    }
    while(m < 13) {
        // 春节特殊处理
        if(m == mm[6] && d == dd[6]) {
            ans++;
            springFestival = 2;
        } else if(springFestival) {
            ans++;
            springFestival--;
        } else if(w == 6 || w == 7) {
            ans++;
        } else {
            for(int i = 0; i < 10; i++) {
                if(m == mm[i] && d == dd[i]) {
                    ans++;
                    break;
                }
            }
        }
        d++;
        if(d == days[m] + 1) {
            d = 1;
            m++;
        }
        w++;
        if(w == 8) {
            w = 1;
        }
    }
    cout << "ans = " << ans << '\n';
    return 0;
}