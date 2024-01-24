#include <iostream>
#define MAXSIZE 10

using namespace std;

typedef int ElemType;
typedef struct {
    // Queue最多可以存储 MAXSIZE-1 个元素 
    // 当head==rear的时候表示队空
    // 当head==rear+1的时候表示队满
    ElemType data[MAXSIZE];
    int head, rear;
}SqQueue;
typedef struct LNode {
    ElemType data;
    struct LNode *next;
}LNode;
typedef struct {
    LNode * head, * rear;
}LinkQueue;

// 初始化
void initQueue(SqQueue &q) {
    q.head = q.rear = 0;
}

void initLinkQueue(LinkQueue &lq) {
    lq.head = lq.rear = (LNode*)malloc(sizeof(LNode));
    lq.head->next = nullptr;
}

// 判断队列是否为空
bool empty(const SqQueue &q) {
    return q.head == q.rear;
}

bool emptyLinkQueue(const LinkQueue &lq) {
    return lq.head == lq.rear;
}

// 入队
bool push_back(SqQueue &q, ElemType e) {
    // 判断队列是否满
    if((q.rear+1)%MAXSIZE == q.head) return false;
    q.data[q.rear] = e;
    q.rear = (q.rear+1)%MAXSIZE;
    return true;
}

void push(LinkQueue &lq, ElemType e) {
    LNode * p = (LNode*)malloc(sizeof(LNode));
    p->data = e;
    p->next = nullptr;
    lq.rear->next = p;
    lq.rear = p;
}

// 出队
bool pop_front(SqQueue &q, ElemType &e) {
    // 判断队列是否空
    if(q.head == q.rear) return false;
    e = q.data[q.head];
    q.head = (q.head+1)%MAXSIZE;
    return true;
}

bool pop(LinkQueue &lq, ElemType &e) {
    if(lq.head == lq.rear) return false;
    LNode * p = lq.head->next;
    e = p->data;
    lq.head->next = p->next;
    // 特别注意 队列只剩一个元素 且这个元素出队需要特别处理
    if(lq.head->next == lq.rear) lq.rear = lq.head;
    free(p);
    p = nullptr;
    return true;
}

int main() {
    // 循环队列测试
    // SqQueue q;
    // initQueue(q);
    // empty(q);
    // push_back(q, 1);
    // push_back(q, 2);
    // push_back(q, 3);
    // cout << "rear: " << q.rear << endl;
    // ElemType e;
    // if(pop_front(q, e)) cout << "e: " << e << " head: " << q.head << endl;

    // 链队列测试
    LinkQueue lq;
    initLinkQueue(lq);
    push(lq, 1);
    push(lq, 2);
    push(lq, 3);
    ElemType e;
    if(pop(lq, e)) cout << "e: " << e << " other: " << lq.head->next->data << " " << lq.head->next->next->data << endl;
    return 0;
}