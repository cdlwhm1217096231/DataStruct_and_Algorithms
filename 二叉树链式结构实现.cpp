#include "iostream"
#include "cstdlib"
#include "cstdio"
#include "cstring"
#include "malloc.h"

using namespace std;

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 100

typedef int Status;

// 用来构造二叉树
int index = 1;
typedef char String[24]; // 0号索引的位置存储的是串的长度，这一句是数组类型自定义别名
String str;              // 等价于 char str[24];

Status strAssign(String T, char *chars)
{ // String T 等价于 char T[24];
    int i;
    if (strlen(chars) > MAXSIZE)
        return ERROR;
    else
    {
        T[0] = strlen(chars);
        for (i = 1; i <= T[0]; i++)
            T[i] = *(chars + i - 1);
        return OK;
    }
}

typedef char ElemType;
ElemType nil = ' '; // 字符型以空格为空

Status visit(ElemType e)
{
    cout << "e:" << e << " ";
    return OK;
}

// 定义二叉树中的节点
typedef struct BiNode
{
    ElemType data;
    struct BiNode *lchild, *rchild; // 等价于 BiNode *lchild, *rchild;
} BiNode, *BiTree;                  // BiTree是指向结构体的指针
/*
typedef struct Binode{
    语句;
}BiNode   

struct Binode node;  // 等价于 BiNode node;
typede struct BiNode{
    语句;
}*BiTree;    

struct BiNode *p;   // 等价于 BiTree p;   
*/

// 构造空二叉树
Status initBiTree(BiTree *T)
{
    *T = NULL;
    return OK;
} // BiTree *T等价于 struct BiNode **T;  指向结构体BiNode类型的指针*T的指针T

// 如果二叉树T存在，销毁二叉树T
void destoryBiTree(BiTree *T)
{
    if (*T)
    {
        if ((*T)->lchild) // 有左孩子
            destoryBiTree(&(*T)->lchild);
        if ((*T)->rchild) // 有右孩子
            destoryBiTree(&(*T)->rchild);
        free(*T);  // 释放根结点
        *T = NULL; // 空指针赋0
    }
}

// 按前序输入二叉树中结点的值(一个字符),#表示空树，用二叉链表表示二叉树T
void createBiTree(BiTree *T)
{
    ElemType ch;
    ch = str[index++]; // char str[24]
    if (ch == '#')
        *T = NULL;
    else
    {
        *T = (BiTree)malloc(sizeof(BiNode));
        if (!*T)
            exit(-1);
        (*T)->data = ch;             // 生成根结点
        createBiTree(&(*T)->lchild); // 构造左子树
        createBiTree(&(*T)->rchild); // 构造右子树
    }
}

// 判断二叉树是否是空树,是空树返回TRUE
Status BiTreeEmpty(BiTree T)
{ // struct BiNode * 等价于BiTree,所以 BiTree T等价于 struct BiNode *T;
    if (T)
        return FALSE;
    else
        return TRUE;
}

// 清空二叉树
#define clearBiTree destoryBiTree

// 返回二叉树的深度T
int BiTreeDepth(BiTree T)
{
    int i, j;
    if (!T)
        return 0;
    if (T->lchild)
        i = BiTreeDepth(T->lchild);
    else
        i = 0;
    if (T->rchild)
        j = BiTreeDepth(T->rchild);
    else
        j = 0;
    return i>j? i+1:j+1;
}

// 返回T的根
ElemType root(BiTree T)
{
    if (BiTreeEmpty(T))
        return nil;
    else
        T->data;
}

// 返回二叉树中某个节点
ElemType vlaue(BiTree T)
{
    return T->data;
}

// 给T指向的结点赋值为value
void assign(BiTree T, ElemType e)
{
    T->data = e;
}

// 前序遍历
void preOderTravel(BiTree T)
{
    if (T == NULL)
        return;
    cout << T->data << " "; // 根节点
    preOderTravel(T->lchild);                // 左子树
    preOderTravel(T->rchild);                // 右子树
}

// 中序遍历
void midOrderTravel(BiTree T)
{
    if (T == NULL)
        return;
    midOrderTravel(T->lchild);
    cout << T->data << " ";
    midOrderTravel(T->rchild);
}

// 后序遍历
void afterOrderTravel(BiTree T)
{
    if (T == NULL)
        return;
    afterOrderTravel(T->lchild);
    afterOrderTravel(T->rchild);
    cout << T->data << " ";
}

int main()
{
    int i;
    BiTree T;
    ElemType e;
    initBiTree(&T);

    strAssign(str, "ABDH#K###E##CFI###G#J##");
    createBiTree(&T);

    cout << "构造空二叉树后，树是否为空(1:是,0:否):" << BiTreeEmpty(T) << ",树的深度: " << BiTreeDepth(T) << endl;

    e = root(T);
    cout << "二叉树的根结点是: " << e << endl;

    cout << "前序遍历结果: ";
    preOderTravel(T);
    cout << endl;
    cout << "中序遍历结果: ";
    midOrderTravel(T);
    cout << endl;
    cout << "后序遍历结果: ";
    afterOrderTravel(T);
    cout << endl;

    clearBiTree(&T);
    cout << "清空二叉树后，树是否为空(1:是,0:否):" << BiTreeEmpty(T) << ",树的深度: " << BiTreeDepth(T) << endl;
    i = root(T);
    if (!i)
        cout << "空二叉树,无根结点\n";
    return 0;
}