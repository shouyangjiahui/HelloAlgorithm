#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <vector>

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

// 选择排序
void selectSort(ElemType *data, int length)
{
    for (int i = 1; i < length; ++i)
    {
        int min_idx = i;
        for (int j = i + 1; j < length; ++j)
        {
            if (data[j] < data[min_idx])
            {
                min_idx = j;
            }
        }
        swap(data[i], data[min_idx]);
    }
}

// [考试] 堆排序
void max_heapify(ElemType *data, int start, int end)
{
    int dad = start;
    int son = dad * 2; // 左子
    while (son <= end)
    {
        // 比较两个子节点大小 son表示较大的一个
        if (son + 1 <= end && data[son + 1] > data[son])
        {
            son++;
        }
        // 比较父节点和较大的子节点
        if (data[dad] > data[son])
        {
            return;
        }
        else
        {
            swap(data[dad], data[son]);
            dad = son;
            son = son * 2;
        }
    }
}
void heapSort(ElemType *data, int length)
{
    // 建立初始的大根堆 从最后一个父节点开始
    // length表示数组实际数据元素的数量
    // 如果数据从[1]开始 第1个父节点是 length/2
    // 如果数据从[0]开始 第1个父节点是 length/2-1
    for (int i = length / 2; i >= 1; --i)
    {
        max_heapify(data, i, length);
    }
    // 排序
    for (int i = length; i >= 1; --i)
    {
        swap(data[1], data[i]); // 把堆顶元素交换到最后
        // 调整大根堆
        max_heapify(data, 1, i - 1);
    }
}

// 归并排序
void merge(ElemType *arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> L(n1);
    std::vector<int> R(n2);

    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(ElemType *arr, int left, int right)
{
    if (left < right)
    {
        int mid = (right + left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main()
{
    SSTable st;
    initSSTable(st, 10);
    printSSTable(st);
    // bubbleSort(st.data, st.tableLength);
    // quickSort(st.data, 1, 10);
    // insertSort(st.data, st.tableLength);
    // selectSort(st.data, st.tableLength);
    // heapSort(st.data, st.tableLength - 1);
    mergeSort(st.data, 1, 10);
    printSSTable(st);
    return 0;
}