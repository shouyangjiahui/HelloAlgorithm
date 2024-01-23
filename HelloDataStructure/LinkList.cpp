// 链表
// 头节点留空
#include <iostream>
using namespace std;
typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;
// 头插法建立链表
void ListHeadInsert(LinkList &L)
{
    L = (LinkList)malloc(sizeof(LNode));
    L->next = nullptr;
    LNode *s = nullptr;
    ElemType e;
    cout << "please input element: ";
    while (cin >> e && e != 9999)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = e;
        s->next = L->next;
        L->next = s;
    }
}
// 打印链表
void PrintList(LinkList L)
{
    if (L->next == nullptr)
    {
        return;
    }
    LNode *s = L->next;
    cout << "LinkList: ";
    while (s != nullptr)
    {
        cout << s->data << ' ';
        s = s->next;
    }
    cout << endl;
}
// 尾插法建立链表
void ListTailInsert(LinkList &L)
{
    L = (LinkList)malloc(sizeof(LNode));
    L->next = nullptr;
    LNode *s = nullptr;
    LNode *r = L; // 尾指针
    ElemType e;
    cout << "please input element: ";
    while (cin >> e && e != 9999)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = e;
        s->next = nullptr;
        r->next = s;
        r = s;
    }
}
// 按位置查找
LNode *GetElement(LinkList L, int pos)
{
    int cnt = 1;
    LNode *s = L->next;
    while (cnt <= pos && s != nullptr)
    {
        if (cnt == pos)
        {
            return s;
        }
        s = s->next;
        cnt++;
    }
    return nullptr;
}
// 按值查找
LNode *LocateElem(LinkList L, ElemType e)
{
    LNode *s = L->next;
    while (s != nullptr)
    {
        if (s->data == e)
        {
            return s;
        }
        s = s->next;
    }
    return nullptr;
}
// 按位置插入 (实现：在第pos-1个元素之后插入新元素 所以可以实现在末尾插入元素)
bool ListInsert(LinkList &L, int pos, ElemType e)
{
    int cnt = 0;
    LNode *s = L;
    while (cnt < pos && s != nullptr)
    {
        if (cnt == pos - 1)
        {
            LNode *t = (LNode *)malloc(sizeof(LNode));
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
// 删除第i个位置的元素
bool ListDelete(LinkList &L, int pos)
{
    int cnt = 0;
    LNode *s = L;
    while (cnt < pos && s != nullptr)
    {
        if (cnt == pos - 1)
        {
            LNode *t = s->next;
            s->next = t->next;
            free(t); // 释放被删除节点的空间
            t = nullptr;
            return true;
        }
        s = s->next;
        cnt++;
    }
    return false;
}
// 快慢指针法 将链表等分为两部分 返回第2部分的头指针
LinkList FindMiddle(LinkList L)
{
    LNode *p = L->next, *q = L->next; // p每次移动两个节点 q每次移动一个节点
    while (p->next != nullptr && p->next->next != nullptr)
    {
        p = p->next->next;
        q = q->next;
    }
    LinkList tmpL = (LNode *)malloc(sizeof(LNode));
    tmpL->next = q->next;
    q->next = nullptr;
    return tmpL;
}
// 单链表反转
LinkList ListReverse(LinkList &L)
{
    if (L->next == nullptr || L->next->next == nullptr)
    {
        return L;
    }
    if (L->next->next != nullptr && L->next->next->next == nullptr)
    {
        LNode *p = L->next;
        LNode *q = L->next->next;
        L->next = q;
        q->next = p;
        p->next = nullptr;
        return L;
    }
    LNode *p = L->next;
    LNode *q = L->next->next;
    LNode *r = L->next->next->next;
    while (r != nullptr)
    {
        q->next = p;
        if (p == L->next)
        { // 如果是第一个元素节点
            p->next = nullptr;
        }
        p = q;
        q = r;
        r = r->next;
    }
    q->next = p;
    L->next = q;
    return L;
}
// 两个单链表合并
LinkList ListMerge(LinkList &L1, LinkList &L2)
{
    LNode *p = L1->next;
    LNode *q = L2->next;
    LinkList current = L1;
    while (p != nullptr && q != nullptr)
    {
        current->next = p;
        current = current->next;
        p = p->next;
        current->next = q;
        current = current->next;
        q = q->next;
    }
    if (p != nullptr)
    {
        current->next = p;
    }
    if (q != nullptr)
    {
        current->next = q;
    }
    return L1;
}

int main()
{
    LinkList L;
    // ListHeadInsert(L);
    ListTailInsert(L);
    // LNode* s = GetElement(L, 2);
    // cout << "L[2] = " << s->data << endl;
    // s = LocateElem(L, 2);
    // cout << "L[2] = " << s->data << endl;
    // ListInsert(L, 3, 3);
    // ListDelete(L, 3);
    LinkList tmpL = FindMiddle(L);
    ListReverse(tmpL);
    PrintList(L);
    PrintList(tmpL);
    ListMerge(L, tmpL);
    PrintList(L);
    return 0;
}