#include "iostream"
#include "malloc.h"


using namespace std;


#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define FALSE 0
#define TRUE 1


typedef int Status;
typedef char ElemType;

typedef enum {Link, Thread} PointerTag;   // Link = 0;表示左右孩子的指针  Thread=1表示前驱和后继的指针
typedef struct BiThrNode{
    ElemType data;
    struct BiThrNode *lchild, *rchild;  // 左右孩子指针
    PointerTag LTag;  // 枚举类型PointerTag, LTag的取值是Link或者Thread
    PointerTag RTag;  // 枚举类型PointerTag, LTag的取值是Link或者Thread
}BiThrNode, *BiThrTree;  // BiThrTree表示的是指向结构体BiThrNode类型的指针类型

ElemType nil = '#';  // 字符型以空格符为空

Status visit(ElemType e){
    cout << "e:" << e << " ";
    return OK;
}

// 构造二叉线索树
Status createBiThrTree(BiThrTree *T){
    ElemType ch;
    cin >> ch;
    if(ch == nil)
        *T = NULL;
    else{
        *T = (BiThrTree)malloc(sizeof(BiThrNode));
        if(!*T)
            return ERROR;
        (*T)->data = ch;  // 生成根结点(前序)
        createBiThrTree(&(*T)->lchild);  // 左子树
        if((*T)->lchild)  // 有左孩子
            (*T)->LTag = Link;
        createBiThrTree(&(*T)->rchild);  // 右子树
        if((*T)->rchild)  // 有右孩子
            (*T)->RTag = Link;
    }
    return OK;
}

BiThrTree pre;  // 定义一个指向BiThrNode结构体类型的指针变量pre

void midThreading(BiThrTree p){
    if(p){
        midThreading(p->lchild);  // 递归左子树线索化
        if(!p->lchild){  // 没有左孩子
            p->LTag = Thread;
            p->lchild = pre;  // 左孩子指针指向结点的前驱
        }
        if(!pre->rchild){  // 前驱没有右孩子
            pre->RTag = Thread;
            pre->rchild = p;  //  前驱右孩子指针指向后继(当前结点p)
        }
        pre = p;  // 保证pre指向p的前驱
        midThreading(p->rchild);  // 递归右子树线索化
    }
}

// 中序遍历二叉树T，并将其进行中序线索化，Thrt指向头结点
Status midOrderThreading(BiThrTree *Thrt, BiThrTree T){
    *Thrt = (BiThrTree)malloc(sizeof(BiThrNode));
    if(!*Thrt)
        return ERROR;
    (*Thrt)->LTag = Link;  // 建立头结点
    (*Thrt)->RTag = Thread;
    (*Thrt)->rchild = (*Thrt);  // 右指针回指
    if(!T)  // 二叉树是空树，左指针回指
        (*Thrt)->lchild = *Thrt;
    else{
        (*Thrt)->lchild = T;
        pre = (*Thrt);
        midThreading(T);   // 中序遍历进行中序线索化
        pre->rchild = *Thrt;
        pre->RTag = Thread;  // 最后一个结点线索化
        (*Thrt)->rchild = pre;
    }
    return OK;
}

// 中序遍历二叉线索树T(头结点)的非递归算法
Status midOrderTravel(BiThrTree T){
    BiThrTree p;
    p = T->lchild;  // p指向根结点
    while(p!=T){  // p==T时，是空树或遍历结束
        while(p->LTag == Link)
            p = p->lchild;
        if(!visit(p->data))  // 访问其左子树为空的结点
            return ERROR;
        while(p->RTag == Thread && p->rchild != T){
            p = p->rchild;
            visit(p->data);  // 访问后继结点
        }
        p = p->rchild;
    }
    return OK;
}

int main(){

    BiThrTree H,T;
    cout << "请按前序输入二叉树(如:'ABDH##I##EJ###CF##G##')\n";
    createBiThrTree(&T);  // 按前序产生二叉树
    midOrderThreading(&H, T);  // 中序遍历,并中序线索化二叉树
    cout << "中序遍历输出二叉线索树:\n";
    midOrderTravel(H);  // 中序遍历输出二叉线索树
    return 0;
}