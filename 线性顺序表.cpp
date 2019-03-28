#include "cstdio"
#include "cstring"
#include "iostream"
#include "ctime"
#include "cstdlib"
#include "io.h"  
#include "math.h"  
#include "time.h"



using namespace std;
// 定义一个线性顺序表

#define MAX_SIZE 20   // 存储空间的初始分配大小
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;   //  函数的返回值类型别名
typedef int ElemType;  // 线性表元素的数据类型别名

// 定义一个线性顺序表
typedef struct sqList{  
    ElemType data[MAX_SIZE];  // 存储空间的起始位置：数组data
    int length;  // 线性表的当前长度
}sqList;

Status GetElem(sqList L, int i, ElemType *e);    // 函数声明
Status ListInsert(sqList *L, int i, ElemType e);
Status ListDelete(sqList *L, int i, ElemType *e);
Status visit(ElemType e);
Status InitList(sqList *L);
Status IsEmpty(sqList *L);
Status ClearList(sqList *L);
Status ListLength(sqList L);
Status LocateElem(sqList L, ElemType e);
Status TravelElem(sqList L);
Status UnionSet(sqList *La, sqList Lb);



int main(){
    sqList L;
    sqList Lb;
    ElemType e;
    Status i, k;
    i = InitList(&L);
    cout << "初始化后L的长度: " << L.length << endl;
    for (int j = 1; j <= 5; j++)
        i = ListInsert(&L, 1, j);  // 头部插入
    cout << "在L头部插入元素后,L.data = ";
    TravelElem(L);
    cout << "插入元素后，线性顺序表的长度: " << L.length << endl;
    
    i = IsEmpty(&L);
    cout << "L是否为空(1:是;0:否),结果是: " << i << endl;

    i = ClearList(&L);
    cout << "清空表后的长度: " << L.length << endl;
    
    i = IsEmpty(&L);
    cout << "L是否为空(1:是;0:否),结果是: " << i << endl;

    for (int j = 1; j <= 10; j++)
        ListInsert(&L, j, j);
    cout << "在L尾部插入元素后,L.data = ";
    TravelElem(L);
    cout << "插入元素后，线性顺序表的长度: " << L.length << endl;

    ListInsert(&L, 1, 666);
    cout << "在L的表头插入元素666,L.data = ";
    TravelElem(L);
    cout << "插入元素后，线性顺序表的长度: " << L.length << endl;

    GetElem(L, 7, &e);  // 获得第7个元素
    cout << "第7个元素的值是: " << e << endl;

    for (int j = 3; j <= 6; j++){
        k = LocateElem(L, j);
        if(k)
            cout << "第" << k << "个元素的值是: " << j << endl;
        else    
            cout << "没有值为" << j << "的元素\n";
    }


    k = ListLength(L);
    for(int j = k+1; j >= k; j--){
        i = ListDelete(&L, j, &e);
        if (i == ERROR)
            cout << "删除第" << j << "个元素失败" << endl;
        else    
            cout << "删除第" << j << "个元素," << "元素的值是: " << e << endl;
    }
    cout << "依次遍历每个元素: ";
    TravelElem(L);

    k =5;
    ListDelete(&L, k, &e);
    cout << "第" << k << "个元素" << e << "已经被删除.\n";

    // 构造一个集合B
    i = InitList(&Lb);
    for (int j = 6; j<=15; j++)
        i = ListInsert(&Lb, 1, j);  // 从头部依次插入6-15这些数字
    cout << "依次遍历Lb中的每个元素: ";
    TravelElem(Lb);
    UnionSet(&L, Lb);
    cout << "依次遍历每个元素: ";
    TravelElem(L);
    return 0;
}

// 初始化线性顺序表
Status InitList(sqList *L){
    L->length = 0;
    return OK;
}

// 判断一个线性表是否是空表
Status IsEmpty(sqList *L){
    if (L->length == 0)
        return TRUE;
    else
        return FALSE;
}

// 打印每个元素
Status visit(ElemType e){
    cout << e << " ";
    return OK;
}

// 清空线性顺序表
Status ClearList(sqList *L){
    L->length = 0;
    return OK;
}

// 返回线性顺序表中的元素个数
Status ListLength(sqList L){
    return L.length;
}

// 获得某个元素i的操作
Status GetElem(sqList L, int i, ElemType *e){
    if (L.length == 0 || i < 1 || i > L.length)
        return ERROR;
    *e = L.data[i-1];
    return OK;
}

// 插入元素操作
Status ListInsert(sqList *L, int i, ElemType e){
    int k; // k表示的是索引
    if(L->length == MAX_SIZE)
        return ERROR;   // 此时线性表已经满了
    if(i < 1 || i > L->length+1)  // 最多只有第length个元素，超过length元素将会报错
        return ERROR;
    if(i <= L->length){
        for(k = L->length-1;k >= i-1;k--)
            L->data[k+1] = L->data[k];
    }
    L->data[i-1] = e;  // 插入的元素
    L->length++;
    return OK;
}

// 删除元素操作
Status ListDelete(sqList *L, int i, ElemType *e){
    int k;
    if (L->length == 0)
        return ERROR;
    if (i < 1 || i > L->length)
        return ERROR;
    *e = L->data[i-1];
    if (i < L->length){
        for(k = i; i < L->length; k++)
            L->data[k] = L->data[k+1];
    }
    L->length--;
    return OK;
}

// 定位线性顺序表中某个元素的位置
Status LocateElem(sqList L, ElemType e){
    int i;  // i表示元素的索引
    if (L.length == 0)
        return 0;
    for(i = 0; i < L.length; i++){
        if (L.data[i] == e)
            break;
    }
    if (i >= L.length)
        return 0;
    return i+1;    // 第i+1个元素的索引是i 
}

// 遍历线性表中的每个元素
Status TravelElem(sqList L){
    for (int i = 0; i < L.length; i++)
        visit(L.data[i]);
    cout << endl;
    return OK;
}

// 求两个集合的并集:先对一个集合B进行每个元素的遍历，然后将遍历得到的元素与集合A中的所有元素进行对比，如果不相等，则将其添加到集合A中
Status UnionSet(sqList *La, sqList Lb){
    int La_len, Lb_len;
    ElemType e;
    La_len = ListLength(*La);
    Lb_len = ListLength(Lb);
    for(int i = 1; i <=Lb_len; i++){
        GetElem(Lb, i, &e);
        if(!LocateElem(*La,e))
            ListInsert(La, ++La_len, e);
    }
}