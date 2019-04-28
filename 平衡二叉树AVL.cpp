#include "iostream"
#include "malloc.h"

using namespace std;

// 平衡二叉树----AVL树

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100

typedef int Status;
// 改进二叉排序树中的结点结构
typedef struct BiTNode
{
    int data;
    int bf; // 平衡因子BF
    BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

// 右旋转---顺时针旋转
void R_Rotate(BiTree *p)
{
    BiTree L;
    L = (*p)->lchild;         // L是当前根结点p左子树的根结点
    (*p)->lchild = L->rchild; // 经过旋转后，将L的右子树挂接到p的左子树上
    L->rchild = *p;           // 原始的根结点p现在变成当前根结点R的右子树的根结点
    *p = L;                   // 原始根结点p变成L
}

// 向左旋转---逆时针旋转
void L_Rotate(BiTree *p)
{
    BiTree R;
    R = (*p)->rchild;         // R是当前根结点p右子树的根结点
    (*p)->rchild = R->lchild; // 经过旋转后，将R的左子树挂接到p的右子树上
    (*p) = R->lchild;         // 原始的根结点p现在变成当前根结点R的左子树的根结点
    *p = R;                   // 原始根结点p变成R
}

#define LH +1 // 左高
#define EH 0  // 等高
#define RH -1 // 右高

// 左平衡处理--先左旋再右旋

void LeftBalance(BiTree *T)
{
    BiTree L, Lr;
    L = (*T)->lchild;
    switch (L->bf)
    {
    case LH: // 新结点N插入在T的左孩子的左子树上，只需要单独进行右旋转
        (*T)->bf = L->bf = EH;
        R_Rotate(T);
        break;
    case RH:
        Lr = L->rchild; // Lr指向T的左孩子L的右子树Lr上，需要先左旋再右旋
        switch (Lr->bf)
        { // 修改T及其左孩子的平衡因子
        case LH:
            (*T)->bf = RH;
            L->bf = EH;
            break;
        case EH:
            (*T)->bf = L->bf = EH;
            break;
        case RH:
            (*T)->bf = EH;
            L->bf = LH;
            break;
        }
        Lr->bf = EH;
        L_Rotate(&(*T)->lchild); // 对T的左子树L做左旋处理
        R_Rotate(T);             // 对根结点T做右旋处理
    }
}

// 右平衡处理---先右旋，再左旋
void RightBalance(BiTree *T)
{
    BiTree R, Rl;
    R = (*T)->rchild;
    switch (R->bf)
    {
    case RH: // 新结点N插入在根节点T的右孩子的右子树上，直接进行左旋处理
        (*T)->bf = R->bf = EH;
        L_Rotate(T);
        break;
    case LH:
        Rl = R->lchild; // Rl指向的是根节点T的右孩子的左子树Rl上，需要先右旋再左旋
        switch (Rl->bf)
        { // 修改T及其右孩子的平衡因子
        case RH:
            (*T)->bf = LH;
            R->bf = EH;
            break;
        case EH:
            (*T)->bf = R->bf = EH;
            break;
        case LH:
            (*T)->bf = EH;
            R->bf = RH;
            break;
        }
        Rl->bf = EH;
        R_Rotate(&(*T)->rchild); // 对根节点T的右子树R进行右旋处理
        L_Rotate(T);             // 对根节点T再进行左旋
    }
}

// 插入操作
Status InsertAVL(BiTree *T, int e, Status *taller)
{
    if (!*T)
    { // 是空树时，执行下面的代码
        *T = (BiTree)malloc(sizeof(BiTNode));
        (*T)->data = e;
        (*T)->lchild = (*T)->rchild = NULL;
        (*T)->bf = EH;
        *taller = TRUE;
    }
    else
    { // 不是空树
        if ((*T)->data == e)
        { // 关键字已经存在于二叉排序中
            *taller = FALSE;
            return FALSE;
        }
        // 关键字不在二叉排序树中，执行插入操作
        if (e < (*T)->data)
        {                                             // 关键字小于当前根节点的值，在当前根节点T的左子树中进行搜索并插入
            if (!InsertAVL(&(*T)->lchild, e, taller)) // 未插入
                return FALSE;
            if (*taller) // 已插入到T的左子树中且左子树“长高”
                switch ((*T)->bf)
                {        // 检查T的平衡因子
                case LH: // 原本左子树比右子树高，需要作左平衡处理
                    LeftBalance(T);
                    *taller = FALSE;
                    break;
                case EH: // 原本左、右子树等高，现因左子树增高而使树增高
                    (*T)->bf = LH;
                    *taller = TRUE;
                    break;
                case RH: // 原本右子树比左子树高，现左、右子树等高
                    (*T)->bf = EH;
                    *taller = FALSE;
                    break;
                }
        }
        else
        {                                             // 关键字大于当前根节点的值,继续在T的右子树中进行搜索
            if (!InsertAVL(&(*T)->rchild, e, taller)) // 未插入
                return FALSE;
            if (*taller) // 已插入到T的右子树且右子树“长高”
                switch ((*T)->bf)
                {        // 检查T的平衡因子
                case LH: // 原本左子树比右子树高，现左、右子树等高
                    (*T)->bf = EH;
                    *taller = FALSE;
                    break;
                case EH: // 原本左、右子树等高，现因右子树增高而使树增高
                    (*T)->bf = RH;
                    *taller = TRUE;
                    break;
                case RH: // 原本右子树比左子树高，需要作右平衡处理
                    RightBalance(T);
                    *taller = FALSE;
                    break;
                }
        }
    }
    return TRUE;
}

int main()
{
    int a[MAXSIZE] = {3, 2, 1, 4, 5, 6, 7, 10, 9, 8};
    BiTree T=NULL;
    Status taller;
    for(int i=0; i < 10; i++){
        InsertAVL(&T, a[i], &taller);
    }
    cout << "使用断点跟踪查看平衡二叉树AVL的结构\n";
    return 0;
}
