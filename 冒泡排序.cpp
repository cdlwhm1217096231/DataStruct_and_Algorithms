#include "iostream"
#include <malloc.h>

using namespace std;

#define MAXSIZE 10
#define FALSE 0
#define TRUE 1
#define OK 1
#define ERROR 0

// 定义一个顺序表结构用于排序

typedef int Status;

typedef struct
{
    int r[MAXSIZE + 1]; // r[0]用来存储哨兵位置
    int len;            // 记录顺序表的长度
} Sqlist;

// 交换两个元素
void Swap(Sqlist *L, int i, int j)
{
    int temp = L->r[i];
    L->r[i] = L->r[j];
    L->r[j] = temp;
}

// 依次打印出元素
void show(Sqlist L)
{
    for (int i = 1; i <= L.len; i++)
        cout << L.r[i] << " ";
    cout << endl;
}

// 冒泡排序----初级版实现
void BubbleSort(Sqlist *L)
{
    for (int i = 1; i < L->len; i++)
    {
        for (int j = i + 1; j <= L->len; j++)
        {
            if (L->r[i] > L->r[j])
                Swap(L, i, j);
        }
    }
}
// 冒泡排序----正宗版实现
/*
    顺序表L = {9, 1, 5, 8, 3, 7, 4, 6, 2}，下标L[0]存储的是哨兵或临时变量
    顺序表L的下标的从1开始的{1, 2, 3, 4, 5, 6, 7, 8, 9}
    故len(L) = 9
*/
void BubbleSort1(Sqlist *L){
    for(int i = 1; i < L->len; i++){
        for(int j = L->len-1; j >= i; j--){
            if(L->r[j] > L->r[j+1])
                Swap(L, j, j+1);
        }
    }
}

// 冒泡排序----改进版实现
void BubbleSort2(Sqlist *L){
    Status flag = TRUE;   // flag用来作为标记
    for(int i = 1; i < L->len && flag; i++){
        flag = FALSE;  // 初始的标记为FALSE
        for(int j = L->len - 1; j >=i; j--){
            if(L->r[j] > L->r[j+1]){  // 发生了交换后，将标记的值进行改变
                Swap(L, j, j+1);
                flag = TRUE;
            }
        }
    }
}

#define N 9

int main()
{
    Sqlist L0;
    int d[N] = {9, 1, 5, 8, 3, 7, 4, 6, 2}; // d[0]用作哨兵或者临时变量,不参与排序
    for (int i = 0; i < N; i++)
        L0.r[i+1] = d[i];
    L0.len = N;
    cout << "冒泡排序前: ";
    show(L0);
    BubbleSort(&L0);
    cout << "初级版冒泡排序后: ";
    show(L0);
    Sqlist L1 = L0;
    cout << "冒泡排序前: ";
    show(L1);
    BubbleSort1(&L1);
    cout << "正宗版冒泡排序后: ";
    show(L1);
    Sqlist L2 = L0;
    cout << "冒泡排序前: ";
    show(L2);
    BubbleSort2(&L2);
    cout << "改进版冒泡排序后: ";
    show(L2);
    return 0;
}