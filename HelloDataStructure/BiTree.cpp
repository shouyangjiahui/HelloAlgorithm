#include <iostream>
#include <queue>
using namespace std;

typedef char ElemType;

typedef struct BiNode
{
    ElemType data;
    struct BiNode *left, *right;
} BiNode, *BiTree;

// 二叉树的层序建立
void buildBiTree(BiTree &bt)
{
    char c;            // 节点数据
    queue<BiNode *> q; // 保存树节点的队列
    cout << "please input chars, use '$' as end sign: ";
    while (cin >> c && c != '$')
    {
        if (bt == nullptr)
        {
            bt = (BiNode *)malloc(sizeof(BiNode));
            bt->data = c;
            bt->left = bt->right = nullptr;
            q.push(bt);
        }
        else
        {
            BiNode *pbn = (BiNode *)malloc(sizeof(BiNode));
            pbn->data = c;
            pbn->left = pbn->right = nullptr;
            q.push(pbn);
            BiNode *tmp = q.front();
            if (tmp->left == nullptr)
            {
                tmp->left = pbn;
            }
            else if (tmp->right == nullptr)
            {
                tmp->right = pbn;
            }
            else
            {
                q.pop();
                BiNode *t = q.front();
                t->left = pbn;
            }
        }
    }
}

// 前序遍历
void preOrder(BiTree bt)
{
    if (bt)
    {
        cout << bt->data << " ";
        preOrder(bt->left);
        preOrder(bt->right);
    }
}

// 中序遍历
void inOrder(BiTree bt)
{
    if (bt)
    {
        inOrder(bt->left);
        cout << bt->data << " ";
        inOrder(bt->right);
    }
}

// 后序遍历
void postOrder(BiTree bt)
{
    if (bt)
    {
        postOrder(bt->left);
        postOrder(bt->right);
        cout << bt->data << " ";
    }
}

// 层序遍历
void levelOrder(BiTree bt)
{
    queue<BiNode *> q;
    if (bt == nullptr)
    {
        return;
    }
    q.push(bt);
    while (!q.empty())
    {
        BiNode *p = q.front();
        q.pop();
        cout << p->data << " ";
        if (p->left)
        {
            q.push(p->left);
        }
        if (p->right)
        {
            q.push(p->right);
        }
    }
}

// wpl
int wplPreOrder(BiTree bt, int deep)
{
    static int wpl = 0;
    if (bt)
    {
        if (bt->left == nullptr && bt->right == nullptr)
        {
            wpl += bt->data * deep;
        }
        wplPreOrder(bt->left, deep + 1);
        wplPreOrder(bt->right, deep + 1);
    }
    return wpl;
}

int main()
{
    BiTree bt = nullptr;
    buildBiTree(bt);
    cout << "Build Tree Successful" << endl;
    cout << "preOrder: ";
    preOrder(bt);
    cout << "\ninOrder: ";
    inOrder(bt);
    cout << "\npostOrder: ";
    postOrder(bt);
    cout << "\nlevelOrder: ";
    levelOrder(bt);
    cout << "\n";
    cout << "wpl: " << wplPreOrder(bt, 0) << "\n";
    return 0;
}