#include "iostream"
#include "cstdio"
#include "cstdlib"
#include "cmath"

using namespace std;


#define MAXSIZE 1000



// 静态链表：用数组来描述的链表；数组中的每个元素都是由两个数据域组成的，data和cur。数组的每个下标都对应
// 一个data和一个cur。数据域data用来存放数据元素，游标cur相对于单链表中的next指针，存放该元素的后继在数组中的下标

// 静态链表数据结构
typedef struct{
    int data;
    int cur;  // 游标,当cur=0时，无指向
}Component,staticLinkList[MAXSIZE];

// 打印出元素的值
int visit(int e){
    cout << "\t" << "e:" << e << " " << endl;
    return 1;
}

// 初始化数组的状态
int InitList(staticLinkList space){
    for(int i = 0; i < MAXSIZE-1; i++)
        space[i].cur = i + 1;
    space[MAXSIZE - 1].cur = 0;  // 最后一个元素的cur存放的是第一个有数值元素的下标
    return 1;
}
// 如果备用链表不是空的，则返回分配的节点的下标
int malloc_ssl(staticLinkList space){
    int i = space[0].cur;  // 数组下标为0的元素即数组的第一个元素，元素的cur中存放的是备用链表的第一个结点的下标
    if(space[0].cur)
        space[0].cur = space[i].cur;
    return i;
}

// 将下标为k的空闲结点回收到备用链表中
void free_ssl(staticLinkList space , int k){
    space[k].cur = space[0].cur;  // 将数组第一个元素的cur存放的是备用链表的第一个结点的下标赋值给要回收的分量看k
    space[0].cur = k;  
}

// 返回静态链表L中的元素个数
int ListLength(staticLinkList L){
    int j = 0;
    int i = L[MAXSIZE-1].cur;
    while(i){
        i = L[i].cur;
        j++;
    }
    return j;
}

// 在L中第i个元素之前插入新的元素e
int ListInsert(staticLinkList L, int i, int e){
    int j, k, l;
    k = MAXSIZE - 1;  // k是最后一个元素的下标
    if(i < 1 || i > ListLength(L) + 1)
        return 0;
    j = malloc_ssl(L);  // 获得备用链表的下标j = 7,此时下标为0的元素的cur存放的是备用链表第2个结点的下标
    if(j){  // 因为要将需要插入的元素首先放在备用链表的第一个结点处暂存，所以需要malloc_ssl(L)
        L[j].data = e; // 将要插入的元素放在备用链表的第一个结点上
        for(l = 1; l <= i-1; l++)  
            k = L[k].cur; // L[999].cur:数组最后一个元素的cur存放的是第一个有数值元素的下标即1
            // 而L[1].cur存放的是下标为2的结点的下标2
        L[j].cur = L[k].cur;  // 将下标为2的结点中存放的cur赋值给备用链表的第一个节点
        L[k].cur = j;  // 将备用链表第一个节点的下标赋值给L[2].cur，这样就改变了第2个节点的游标cur
        return 1;  // 存放的不是下一个节点的下标3，而是备用链表第一个结点的下标
    }
    return 0;
}
// 删除第i个元素
int ListDelete(staticLinkList L, int i){
    int j, k;
    if (i < 1 || i > ListLength(L))
        return 0;
    k = MAXSIZE - 1;
    for(j = 1; j <= i-1; j++)
        k = L[k].cur;
    j = L[k].cur;
    L[k].cur = L[j].cur;
    free_ssl(L, j);
    return 1;
}

// 遍历整个静态链表
int ListTravel(staticLinkList L){
    int j= 0;
    int i = L[MAXSIZE-1].cur;
    while(i){
        visit(L[i].data);
        i = L[i].cur;
        j++;
    }
    return j;
    return 1;
}

int main(){
    staticLinkList L;
    int i;
    i = InitList(L);
    cout << "初始化后L的长度: " << ListLength(L) << endl;
    i = ListInsert(L, 1, 'F');
    i = ListInsert(L, 1, 'E');
    i = ListInsert(L, 1, 'D');
    i = ListInsert(L, 1, 'B');
    i = ListInsert(L, 1, 'A');
    cout << "头插法后的结果: \n";
    ListTravel(L);


    i = ListInsert(L, 3, 'C');
    cout << "在B与D之间插入C的结果是: \n";
    ListTravel(L);

    i = ListDelete(L, 1);
    cout << "删除A后的结果: \n";
    ListTravel(L);
    return 0;
}