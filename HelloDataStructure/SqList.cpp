// 顺序表
// 索引为0留空 索引为1的位置保存第1个元素
#include <iostream>

#define MAXSIZE 50
using namespace std;
typedef int ElemType;
// 静态内存分配
typedef struct {
    ElemType data[MAXSIZE];
    int length;
} SqList;
// 向顺序表插入元素
bool ListInsert(SqList& L, int pos, ElemType element) {
    // 判断pos是否合法
    if(pos < 1 || pos > L.length + 1) {
        return false;
    }
    // 判断存储空间是否可以存储新的数据
    if(L.length == MAXSIZE) {
        return false;
    }
    // 第pos个元素及之后的元素全部向后移动一个位置
    for(int i = L.length; i >= pos; i--) {
        L.data[i+1] = L.data[i];
    }
    L.data[pos] = element;
    L.length++;
    return true;
}
// 打印顺序表
void PrintList(SqList L) {
    cout << "SqList Length: " << L.length << endl;
    for(int i = 1; i <= L.length; i++) {
        cout << i << " : " << L.data[i] << '\t';
    }
    cout << endl;
}
// 删除顺序表元素
bool ListDelete(SqList& L, int pos, ElemType& del) {
    // 判断pos是否合法
    if(pos < 1 || pos > L.length) {
        return false;
    }
    del = L.data[pos];
    for(int i = pos; i <= L.length-1; i++) {
        L.data[i] = L.data[i+1];
    }
    L.length--;
    return true;
}
// 查找顺序表元素
int LocateList(SqList L, ElemType element) {
    for(int i = 1; i <= L.length; i++) {
        if(L.data[i] == element) {
            return i;
        }
    }
    return 0;
}
int main() {
    SqList L;
    // InsertList Test
    // L.data[1] = 1;
    // L.data[2] = 2;
    // L.data[3] = 3;
    // L.length = 3;
    // if(ListInsert(L, 4, 9)) {
    //     cout << "insert success" << endl;
    //     PrintList(L);
    // } else {
    //     cout << "insert failed" << endl;
    // }
    // ListDelete Test
    // ElemType del;  // 保存删除的元素
    // L.data[1] = 1;
    // L.data[2] = 2;
    // L.data[3] = 3;
    // L.length = 3;
    // if(ListDelete(L, 3, del)) {
    //     cout << "delete " << del << " success" << endl;
    //     PrintList(L);
    // } else {
    //     cout << "delete failed" << endl;
    // }
    // LocateElem Test
    L.data[1] = 1;
    L.data[2] = 2;
    L.data[3] = 3;
    L.length = 3;
    int pos = LocateList(L, 4);
    if(pos) {
        cout << "find " << pos << " success" << endl;
        PrintList(L);
    } else {
        cout << "find failed" << endl;
    }

    return 0;
}
