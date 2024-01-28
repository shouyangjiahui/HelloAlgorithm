#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef int ElemType;
// 顺序查找表
typedef struct
{
    ElemType *data;
    int tableLength;
} SSTable;
// 二叉查找树
typedef struct BSTNode
{
    ElemType data;
    struct BSTNode *left, *right;
} BSTNode, *BiTree;

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

// 初始化二叉查找树
void initBiTree(BiTree &bt, const ElemType *data, const int length)
{
    for (int i = 0; i < length; ++i)
    {
        auto *bstn = (BSTNode *)malloc(sizeof(BSTNode));
        bstn->data = data[i];
        bstn->left = bstn->right = nullptr;
        if (bt == nullptr)
        {
            bt = bstn;
        }
        else
        {
            BSTNode *p = bt;
            while (p)
            {
                if (p->data > data[i])
                {
                    if (p->left == nullptr)
                    {
                        p->left = bstn;
                        break;
                    }
                    p = p->left;
                }
                else if (p->data < data[i])
                {
                    if (p->right == nullptr)
                    {
                        p->right = bstn;
                        break;
                    }
                    p = p->right;
                }
                else
                {
                    break; // 树节点中的元素不能重复
                }
            }
        }
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

// 删除二叉查找树节点
bool deleteBSTNode(BiTree &bt, const ElemType e)
{
    if (bt == nullptr)
        return false;
    else if (e < bt->data)
    {
        return deleteBSTNode(bt->left, e);
    }
    else if (e > bt->data)
    {
        return deleteBSTNode(bt->right, e);
    }
    else
    {
        // 左子树为空
        if (bt->left == nullptr)
        {
            BSTNode *temp = bt->right;
            free(bt);
            bt = temp;
        }
        // 右子树为空
        else if (bt->right == nullptr)
        {
            BSTNode *temp = bt->left;
            free(bt);
            bt = temp;
        }
        // 左右子树均不为空
        else
        {
            // 使用左子树的最大(右)节点 或 右子树的最小(左)节点替换
            BSTNode *t = bt->right;
            while (t->left != nullptr)
            {
                t = t->left;
            }
            bt->data = t->data;
            return deleteBSTNode(bt->right, t->data);
        }
        return true;
    }
}

// 顺序查找
int searchSSTable(SSTable &st, ElemType key)
{
    st.data[0] = key;
    int i;
    for (i = st.tableLength - 1; st.data[i] != key; --i)
        ;
    return i;
}

// 二分查找
int binarySSTable(SSTable st, ElemType key)
{
    sort(st.data, st.data + st.tableLength);
    printSSTable(st);
    int low = 1;
    int high = st.tableLength - 1;
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (st.data[mid] == key)
        {
            return mid;
        }
        else if (st.data[mid] > key)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return 0;
}

// 二叉树查找
BSTNode *BSTSearch(BiTree bt, ElemType key)
{
    BSTNode *p = bt;
    while (p)
    {
        if (p->data == key)
        {
            break;
        }
        else if (p->data > key)
        {
            p = p->left;
        }
        else
        {
            p = p->right;
        }
    }
    return p;
}

int main()
{
    SSTable st;
    BiTree bt = nullptr;
    // initSSTable(st, 10);
    ElemType data[] = {14, 67, 64, 13, 41, 75, 5, 16, 30, 85};
    initBiTree(bt, data, sizeof(data) / sizeof(ElemType));
    // printSSTable(st);
    cout << "Please input a key: ";
    ElemType key;
    cin >> key;
    // int pos = searchSSTable(st, key);
    // int pos = binarySSTable(st, key);

    // if (pos)
    // {
    //     cout << "search successful, pos = " << pos << "\n";
    // }
    // else
    // {
    //     cout << "search failed\n";
    // }
    BSTNode *p = BSTSearch(bt, key);
    if (p)
    {
        cout << "search success, p->data = " << p->data << endl;
    }
    else
    {
        cout << "search failed\n";
    }
    if (deleteBSTNode(bt, key))
    {
        p = BSTSearch(bt, key);
        if (p)
        {
            cout << "search success, p->data = " << p->data << endl;
        }
        else
        {
            cout << "search failed\n";
        }
    }
    return 0;
}