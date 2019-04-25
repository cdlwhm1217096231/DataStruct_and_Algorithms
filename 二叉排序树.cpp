#include "iostream"
#include "malloc.h"
using namespace std;


#define ERROR 0
#define OK 1
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100

typedef int Status;

// 使用二叉链表表示一个二叉树的结点
typedef struct BiTNode{ 
    int data;
    BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

// 二叉排序树的查找操作
Status BinaryTree_Search(BiTree T, int key, BiTree f, BiTree *p){
    // T:表示当前的结点   key:表示要搜索的关键字 f:表示T的双亲结点， p:用来返回结果
    if(!T){  // 如果T = NULL，说明当前结点是根结点，无双亲结点，此时f = NULL
        *p = f; 
        return FALSE;
    }
    else if(key == T->data){  // 查找成功
        *p = T;
        return TRUE;
    }
    else if(key < T->data){
        return BinaryTree_Search(T->lchild, key, T, p);  // 关键字小于当前结点的值，则说明关键字在左子树上，递归调用二叉排序树
    }
    else if(key > T->data){
        return BinaryTree_Search(T->rchild, key, T, p); // 关键字大于当前结点的值，则说明关键字在右子树上，递归调用二叉排序树
    }
}

// 二叉排序树的插入操作(先查找当前的二叉排序树中是否已经有key,没有的话进行插入操作，返回TRUE；否则返回FALSE，不需要插入)
Status BinaryTree_Insert(BiTree *T, int key){
    BiTree p, s;
    if(!BinaryTree_Search(*T, key, NULL, &p)){  // 当前二叉排序树中没有查找到可以，需要进行插入操作
        s = (BiTree)malloc(sizeof(BiTNode));  // 新插入的结点s
        s->data = key;
        s->lchild = s->rchild = NULL;
        if(!p)  // 当前的二叉树为空树，即新插入的结点s作为根结点
            *T = s;
        else if(key < p->data)  // 当前结点p为内部结点，插入的key小于当前结点p->data,则将s插入p的左子树中
            p->lchild = s;
        else
            p->rchild = s;
        return TRUE;  // 插入成功
    }  
    else
        return FALSE;   // 原始的二叉排序树中已经存在key，就不需要进行插入操作，返回FALSE
}


// 二叉排序树的删除操作(分三种情况)

// 具体的删除操作----p结点就是要删除的结点
Status Delete(BiTree *p){
    BiTree q, s;
    if((*p)->lchild == NULL){  // 要要删除的结点p只有右子树，属于情况2
        q = *p;
        *p = (*p)->rchild;
        free(q);
    }
    else if((*p)->rchild == NULL){  // 要删除的结点p只有左子树，属于情况2
        q = *p;
        *p = (*p)->lchild;
        free(q);
    }  
    else{  // 要删除的结点p同时有左右子树，属于情况3.此时，使用删除结点p的直接前驱或直接后继节点来代替要删除的节点p
        q = *p;
        s = (*p)->lchild;  // 到达要删除结点p的左子树中的第一个结点s
        while(s->rchild){  // 到达s的右子树，找到要删除结点p的直接前驱结点
            q = s;
            s = s->rchild;
        }
        (*p)->data = s->data;   // 用删除节点p的直接前驱结点s代替要删除的结点p
        if(q != *p)
            q->rchild = s->lchild;  // 属于情况2，当前节点s只有左子树的情况
        else    
            q->lchild = s->lchild;
        free(s);
    }
    return TRUE;  // 删除成功！
}

Status BinaryTree_Delete(BiTree *T, int key){
    if(!*T)  // 二叉排序树中不存在需要删除的可以，直接返回FALSE
        return FALSE;   
    else{
        if(key == (*T)->data)  // 当前的结点就是要删除的key
            return Delete(T);
        else if(key < (*T)->data)  // 关键字key小于当前的结点T，则关键字在当前结点的左子树中
            return BinaryTree_Delete(&(*T)->lchild, key);
        else
            return BinaryTree_Delete(&(*T)->rchild, key);  // 关键字key大于当前的结点T，则关键字在当前结点的右子树中
    }
}


int main(){
    // 二叉排序树的查找操作
    int a[10] = {62,88,58,47,35,73,51,99,37,93};
    BiTree T = NULL;
    for(int i = 0; i < 10; i++)
        BinaryTree_Insert(&T, a[i]);  // 依次插入结点a[i]
    BinaryTree_Delete(&T, 93);
    BinaryTree_Delete(&T, 47);
    cout << "建议设断点跟踪二叉排序树的结构\n";
    return 0;
}