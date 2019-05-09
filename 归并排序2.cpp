#include <iostream>
#include <malloc.h>

using namespace std;

#define N 9
#define MAXSIZE 10

typedef struct
{
    int r[MAXSIZE + 1];
    int len;
} Sqlist;

void show(Sqlist L)
{
    for (int i = 1; i < L.len; i++)
        cout << L.r[i] << " ";
    cout << endl;
}

// 归并操作
void Merge(int A[], int TempA[], int L, int LeftEnd, int RightEnd)
{                // L：左边子序列的起点；LeftEnd：左边子序列的终点
    int R, k, j; // k是数组tempA左边起点，j是右边子序列的的起点，RightEnd:右边子序列的终点
    for (j = LeftEnd + 1, k = L; L <= LeftEnd && j <= RightEnd; k++)
    {
        if (A[L] < A[j])
            TempA[k] = A[L++];
        else
            TempA[k] = A[j++];
    }
    if (L <= LeftEnd)
    {
        for (int l = 0; l <= LeftEnd - L; l++)
            TempA[k + l] = A[L + l];
    }
    if (j <= RightEnd)
    {
        for (int r = 0; r <= RightEnd - j; r++)
            TempA[k + r] = A[j + r];
    }
}
// 递归方法实现
// 归并排序整个操作
void Msort(int A[], int TempA[], int L, int RightEnd)
{
    int center;
    int TempA2[MAXSIZE + 1];
    if (L == RightEnd)
        TempA[L] = A[L];
    else
    {
        center = (L + RightEnd) / 2;
        Msort(A, TempA2, L, center);
        Msort(A, TempA2, center + 1, RightEnd);
        Merge(TempA2, TempA, L, center, RightEnd);
    }
}

// 统一函数接口
void MergeSort(Sqlist *L)
{
    Msort(L->r, L->r, 1, L->len);
}

// 非递归方法实现
void MergePass(int A[], int TempA[], int length, int n)
{
    // length:当前子序列的长度  n:待排序列中的元素个数
    int i = 1;
    while (i <= n - 2 * length - 1)
    { // 子序列的个数是偶数个
        Merge(A, TempA, i, i + length - 1, i + 2 * length - 1);
        i = i + 2 * length;
    }
    if (i < n - length + 1) // 归并最后两个子序列
        Merge(A, TempA, i, i + length - 1, n);
    else
    { // 最后只剩下一个子序列
        for (int j = i; j <= n; j++)
            TempA[j] = A[j];
    }
}

// 统一函数接口
void MergeSort1(Sqlist *L)
{
    int *TempA = (int *)malloc(L->len * sizeof(int));
    int length = 1; // 初始子序列的长度
   
    while (length < L->len)
    {
        MergePass(L->r, TempA, length, L->len);
        length *= 2;
        MergePass(TempA, L->r, length, L->len);
        length *= 2;
    }
}

int main()
{
    Sqlist L;
    int d[N] = {50, 10, 90, 30, 70, 40, 80, 60, 20};
    for (int i = 0; i < N; i++)
        L.r[i + 1] = d[i];
    L.len = N;
    // cout << "归并排序前(递归方法): ";
    // show(L);
    // cout << "归并排序后(递归方法): ";
    // MergeSort(&L);
    // show(L);
    cout << "-------------------------------------------------\n";
    cout << "归并排序前(非递归方法): ";
    show(L);
    cout << "归并排序后(非递归方法): ";
    MergeSort1(&L);
    show(L);

    return 0;
}