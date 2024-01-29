#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef int ElemType;
// 顺序表
typedef struct
{
    ElemType *data;
    int tableLength;
} SSTable;

// 初始化顺序查找表
void initSSTable(SSTable &st, int length)
{
    // [0]存储哨兵
    st.tableLength = length + 1;
    st.data = (ElemType *)malloc(sizeof(ElemType) * (st.tableLength));
    srand(time(NULL));
    for (int i = 1; i < st.tableLength; i++)
    {
        st.data[i] = rand() % 100;
    }
}

// 输出顺序查找表
void printSSTable(SSTable st)
{
    cout << "SSTable: ";
    for (int i = 1; i < st.tableLength; ++i)
    {
        cout << st.data[i] << " ";
    }
    cout << "\n";
}

// 冒泡排序
void bubbleSort(ElemType *data, int length)
{
    for (int i = 1; i < length; i++)
    {
        bool swaped = false;
        for (int j = 1; j < length - i + 1; j++)
        {
            if (data[j] > data[j + 1])
            {
                swap(data[j], data[j + 1]);
                swaped = true;
            }
        }
        if (!swaped)
            break;
    }
}

// 快速排序
int partition(ElemType *data, int begin, int end)
{
    int i = begin, j = end;
    ElemType tmp = data[i]; // 将[begin]位置的元素挖出
    while (i < j)
    {
        while (i < j && data[j] >= tmp) // 注意>=
            j--;
        if (i < j)
        {
            data[i] = data[j];
            i++;
        }
        while (i < j && data[i] < tmp) // 注意<
            i++;
        if (i < j)
        {
            data[j] = data[i];
            j--;
        }
    }
    data[i] = tmp; // 将begin位置的元素放回
    return i;
}
void quickSort(ElemType *data, int begin, int end)
{
    if (begin < end)
    {
        int pivot = partition(data, begin, end);
        quickSort(data, begin, pivot - 1);
        quickSort(data, pivot + 1, end);
    }
}

// 插入排序
void insertSort(ElemType *data, int length)
{
    for (int i = 1; i < length; ++i)
    {
        for (int j = i - 1; j >= 1; --j)
        {
            if (data[j] > data[j + 1])
            {
                swap(data[j], data[j + 1]);
            }
            else
            {
                break;
            }
        }
    }
}

int main()
{
    SSTable st;
    initSSTable(st, 10);
    printSSTable(st);
    // bubbleSort(st.data, st.tableLength);
    // quickSort(st.data, 1, 10);
    insertSort(st.data, st.tableLength);
    printSSTable(st);
    return 0;
}