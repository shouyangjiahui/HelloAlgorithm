#include <iostream>
#define MAXSIZE 100

using namespace std;

typedef int ElemType;
typedef struct {
    ElemType data[MAXSIZE];
    int top;
}SqStack;

// 初始化
void initStack(SqStack &s) {
    s.top = -1;
}

// 判断栈是否为空
bool empty(SqStack &s) {
    return s.top == -1;
}

// 入栈
bool push(SqStack &s, ElemType e) {
    // 判断栈是否满
    if(s.top == MAXSIZE-1) return false;
    s.data[++s.top] = e;
    return true;
}

// 出栈
bool pop(SqStack &s, ElemType &e) {
    if(s.top == -1) return false;
    e = s.data[s.top];
    s.top--;
    return true;
}
int main() {
    SqStack s;
    initStack(s);
    cout << boolalpha << empty(s) << endl;
    push(s, 1);
    push(s, 2);
    push(s, 3);
    ElemType e;
    if(pop(s, e)) {
        cout << "e: " << e << endl;
    }
    return 0;
}