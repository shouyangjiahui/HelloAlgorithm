// 链表
// 头节点留空
#include <iostream>
using namespace std;
typedef int ElemType;
typedef struct LNode {
    ElemType data;
    struct LNode* next;
}LNode, * LinkList;
// 头插法建立链表
void ListHeadInsert(LinkList& L) {
    L = (LinkList)malloc(sizeof(LNode));
    L->next = nullptr;
    LNode* s = nullptr;
    ElemType e;
    cout << "please input element: ";
    while(cin >> e && e != 9999) {
        s = (LNode*)malloc(sizeof(LNode));
        s->data = e;
        s->next = L->next;
        L->next = s;
    }
}
// 打印链表
void PrintList(LinkList L) {
    if(L->next == nullptr) {
        return;
    }
    LNode* s = L->next;
    cout << "LinkList: ";
    while(s != nullptr) {
        cout << s->data << ' ';
        s = s->next;
    }
    cout << endl;
}
// 尾插法建立链表
void ListTailInsert(LinkList& L) {
    L = (LinkList)malloc(sizeof(LNode));
    L->next = nullptr;
    LNode* s = nullptr;
    LNode* r = L;  // 尾指针
    ElemType e;
    cout << "please input element: ";
    while(cin >> e && e != 9999) {
        s = (LNode*)malloc(sizeof(LNode));
        s->data = e;
        s->next = nullptr;
        r->next = s;
        r = s;
    }
}
// 按位置查找
LNode* GetElement(LinkList L, int pos) {
    int cnt = 1;
    LNode* s = L->next;
    while(cnt <= pos && s != nullptr) {
        if(cnt == pos) {
            return s;
        }
        s = s->next;
        cnt++;
    }
    return nullptr;
}
// 按值查找
LNode* LocateElem(LinkList L, ElemType e) {
    LNode* s = L->next;
    while(s != nullptr) {
        if(s->data == e) {
            return s;
        }
        s = s->next;
    }
    return nullptr;
}
// 按位置插入 (实现：在第pos-1个元素之后插入新元素 所以可以实现在末尾插入元素)
bool ListInsert(LinkList& L, int pos, ElemType e) {
    int cnt = 0;
    LNode* s = L;
    while(cnt < pos && s != nullptr) {
        if(cnt == pos-1) {
            LNode* t = (LNode*)malloc(sizeof(LNode));
            t->data = e;
            t->next = s->next;
            s->next = t;
            return true;
        }
        s = s->next;
        cnt++;
    }
    return false;
}
int main() {
    LinkList L;
    // ListHeadInsert(L);
    ListTailInsert(L);
    // LNode* s = GetElement(L, 2);
    // cout << "L[2] = " << s->data << endl;
    // s = LocateElem(L, 2);
    // cout << "L[2] = " << s->data << endl;
    ListInsert(L, 3, 3);
    PrintList(L);
    return 0;
}