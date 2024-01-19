#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char s1[100] = "Hello World";
    char s2[100] = "Hello World\n";
    printf("s1 = %s\n", s1);
    printf("s2 = %s", s2);
    printf("len1 = %d, len2 = %d", strlen(s1), strlen(s2));
    return 0;
}