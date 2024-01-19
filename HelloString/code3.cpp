// 查找子串出现次数
#include <cstdio>
#include <cstring>
char s1[1005], s2[1005];
int main() {
    fgets(s1, 1004, stdin);
    fgets(s2, 1004, stdin);
    // 字符串的结束标志 '\0'
    // fget()遇到'\n'或EOF终止输入 fgets()读取'\n'不读取EOF 使用strlen()计算长度时需要减去'\n'
    int len1 = strlen(s1) - 1, len2 = strlen(s2) - 1;
    printf("len1 = %d, len2 = %d\n", len1, len2);
    int ans = 0;
    for(int i = 0; i + len2 - 1 < len1; i++) {
        bool matched = true;
        for(int j = 0; j < len2; j++) {
            if(s1[i+j] != s2[j]) {
                matched = false;
                break;
            }
        }
        if(matched) {
            ans++;
        }
    }
    printf("%d", ans);
    return 0;
}