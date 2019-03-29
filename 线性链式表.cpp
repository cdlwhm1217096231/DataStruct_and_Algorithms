#include "iostream"
#include "cstdio"
#include "cstdlib"
#include "io.h"
#include "cstring"


using namespace std;

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20  // 存储空间的初始分配量

typedef int ElemType;  // 数据元素的类型别名
typedef int Status;  // 函数的返回值类型别名(返回值有两种状态OK ERROR)

// 利用结构体定义单链表中单个结点的数据结构
typedef struct Node{
    ElemType data;  // 节点的数据域
    struct Node *next;  // 节点的指针域：使用指向结构体Node类型的指针变量next来表示！
}Node;  
typedef struct Node * LinkList;  // 将struct Node *类型自定义为LinkList

Node N;  // 声明一个struct Node类型的变量N，等价于struct Node N;
LinkList ptr;  // 声明一个struct Node *类型的指针变量ptr,等价于struct Node *ptr; 

// 访问某个节点的数据域
Status visit(ElemType e){
    cout << e << " ";
    return OK;
}

// LinkList *L;  等价于struct Node **L;  L是指向Node类型结构体指针的指针;*L是指向Node类型结构体的指针;**L是Node类型的结构体
// LinkList L; 等价于struct Node *L;L是指向Node类型结构体的指针;*L是Node类型的结构体
// 初始化节点
Status InitList(LinkList *L){
    *L = (LinkList)malloc(sizeof(Node));
    if (!*L)
        return ERROR;
    (*L)->next = NULL;  // 指针域为NULL
    return OK; 
}

// 判断是否是空链表
Status ListEmpty(LinkList L){
    if(L->next)
        return FALSE;
    else    
        return TRUE;
}

// 清空链表
Status clearList(LinkList *L){
    LinkList p, q;
    p = (*L)->next;  // 指针p作为链表的头指针，指向的是链表L中的第一个结点
    while(p){  // 还没有到达链表的末尾
        q = p->next;
        free(p);
        p = q;
    }
    (*L)->next = NULL;  // 头结点的指针域是空时，表示此时的链表L的空表
    return OK;
}

// 返回链表中的元素个数
int ListLength(LinkList L){
    int i = 0;
    LinkList p;
    p = L->next;  // p指向的是链表L中的第一个结点，即P是头指针
    while(p){ // 判断p是否到达链表L的末尾
        i++;
        p = p->next;
    }
    return i;
}

// 查找链表L中的第i个数据元素的值
Status GetElem(LinkList L, int i, ElemType *e){
    int j = 1;  // j记录的是位置信息
    LinkList p;
    p = L->next;
    while(p && j < i){
        p = p->next;
        ++j;
    }
    // 查找元素出现错误的情况
    if(!p || j > i)
        return ERROR;
    *e = p->data;
    return OK;
}

// 定位某个元素
int LocateElem(LinkList L, ElemType e){
    int i = 0;
    LinkList p;
    p = L->next;
    while(p){
        i++;
        if(p->data == e)  // 找到了第i个元素e
            return i;
        p = p->next;
    }
    return 0;
}

// 插入一个结点
Status InsertElem(LinkList *L, int i, ElemType e){
    int j = 1;
    LinkList p, s;  
    p = (*L); // 声明一个指针p指向链表L的第一个节点
    while(p && j < i){
        p = p->next;
        ++j;
    }
    if(!p || j > i)
        return ERROR;
    s = (LinkList)malloc(sizeof(Node)); // 在内存中寻找一块类型与Node一样大小的空间，实际上是生成一个新的结点s
    s->data = e;
    s->next = p->next; //将p的后继结点赋值给s的后继节点
    p->next = s;  // 将s赋值给p的后继节点
    return OK;
}

// 删除第i个数据元素
Status DeleteElem(LinkList *L, int i, ElemType *e){
    int j = 1;
    LinkList p, q;
    p = *L;
    while(p->next || j < i){  // 寻找第i个元素，这里的p->next可以改成p吗？
        p = p->next;
        ++j;
    }
    if(!(p->next) || j > i)
        return ERROR;
    q = p->next;
    p->next = q->next;
    *e = q->data;
    free(q);  // 让系统回收此节点，释放内存
    return OK;
}

// 遍历链表
Status TravelList(LinkList L){
    LinkList p;
    p = L->next;
    while(p){
        visit(p->data);
        p = p->next;
    }
    cout << endl;
    return OK;
}



int main(){
    LinkList L;
    ElemType e;
    Status i, k;
    i = InitList(&L);
    cout << "初始化后,L的长度是: " << ListLength(L) << endl;

    for(int j = 1; j <= 5; j++)
        i = InsertElem(&L, 1, j);  // 头插法
    cout << "头插法后的结果L.data = ";
    TravelList(L);
    cout << "头插法后,L的长度是: " << ListLength(L) << endl;

    i = ListEmpty(L);
    cout << "L是否为空(1:是,0:否): " << i << endl;

    i = clearList(&L);
    cout << "清空后,L的长度是: " << ListLength(L) << endl;
    i = ListEmpty(L);
    cout << "L是否为空(1:是,0:否): " << i << endl;

    for(int j = 1; j <=10; j++)
        i = InsertElem(&L, j, j);
    cout << "尾插法后的结果L.data = ";
    TravelList(L);
    cout << "尾插法后,L的长度是: " << ListLength(L) << endl;

    InsertElem(&L, 1, 0);
    cout << "在第一个位置插入元素0,结果是L.data = ";
    TravelList(L);

    GetElem(L, 7, &e);
    cout << "第7个元素的值是: " << e << endl;

    for(int j = 3; j <=4; j++){
        k = LocateElem(L, j);
        if (k)
            cout << "第" << k << "个元素的值是: " << j << endl; 
        else    
            cout << "没有值是" << j << "的元素\n";
    }

    k = ListLength(L);
    for(int j = k+1; j>k; j--){
        i = DeleteElem(&L, j, &e);
        if(i == ERROR)
            cout << "删除第" << j << "个元素失败!\n";
        else    
            cout << "删除第" << j << "个元素，元素的值是: " << e << endl;
    }
    cout << "依次打印出元素的值: ";
    TravelList(L);

    int j = 5;
    DeleteElem(&L, 5, &e);
    cout << "删除第" << j << "个元素，元素的值是: " << e << endl;
    cout << "依次打印出元素的值: ";
    TravelList(L);
    return 0;
}

