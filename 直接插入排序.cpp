#include "iostream"

using namespace std;

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 10

typedef int Status;
typedef struct
{
    int r[MAXSIZE];
    int len;
} Sqlist;

void show(Sqlist L)
{
    for (int i = 1; i < L.len; i++)
        cout << L.r[i] << " ";
    cout << endl;
}

// 直接插入排序
void InsertSort(Sqlist *L)
{
    int i, j;
    for (i = 2; i <= L->len; i++)
    { // 插入的元素从下标为2开始
        if (L->r[i] < L->r[i - 1])
        {                      // 插入的元素比之前的元素值小，就进行交换操作
            L->r[0] = L->r[i]; // 下标为0的位置存放的是哨兵
            for (j = i - 1; L->r[j] > L->r[0]; j--)
                L->r[j + 1] = L->r[j]; // 进行移动操作
            L->r[j + 1] = L->r[0];  // 插入新的元素到正确的位置
        }
    }
}

#define N 9

int main(){
    Sqlist L0;
    int d[N] = {9, 1, 5, 8, 3, 7, 4, 6, 2};
    for(int i = 0; i < N; i++)
        L0.r[i+1] = d[i];
    L0.len = N;
    cout << "直接插入排序前: ";
    show(L0);
    cout << "直接插入排序后: ";
    InsertSort(&L0);
    show(L0);
    return 0;
}