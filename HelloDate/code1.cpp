// 假设1年1月1日是星期一 计算给定日期的星期
#include <iostream>
using namespace std;
string weeks[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
// 计算星期函数
int whatDay(int y, int m, int d) {
    int ans = 0;
    // 模拟年
    // for(int i = 1; i < y; i++) {
    //     if(i % 400 == 0 || (i % 100 != 0 && i % 4 == 0)) {
    //         ans += 366 % 7;
    //         ans %= 7;
    //     } else {
    //         ans += 365 % 7;
    //         ans %= 7;
    //     }
    // }
    // 模拟月
    // for(int i = 1; i < m; i++) {
    //     if(i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) {
    //         ans += 31 % 7;
    //         ans %= 7;
    //     } else if(i == 4 || i == 6 || i == 9 || i == 11){
    //         ans += 30 % 7;
    //         ans %= 7;
    //     } else if(y % 400 == 0 || (y % 100 != 0 && y % 4 == 0)) {
    //         ans += 29 % 7;
    //         ans %= 7;
    //     } else {
    //         ans += 28 % 7;
    //         ans %= 7;
    //     }
    // }
    // 模拟日
    // ans += (d - 1) % 7;
    // ans %= 7;

    // 公式计算
    if(m <= 2) {
        m += 12;
        y--;
    }
    ans = (d + 2*m + 3*(m+1)/5 + y + y/4 - y/100 + y/400) % 7;
    return ans;
}
int main() {
    int y, m, d;
    cin >> y >> m >> d;
    int ans = whatDay(y, m, d);
    cout << "today is " << weeks[ans] << endl;
    return 0;
}