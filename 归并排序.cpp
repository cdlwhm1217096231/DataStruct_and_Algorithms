#include <iostream>
#include <malloc.h>

using namespace std;


// 有序子序列进行合并过程
// A是待排序的序列  TempA是临时数组存储中间结果
// L：左边起点  R:右边起点  RightEnd:右边终点位置
void Merge(int A[], int TempA[], int L, int R, int RightEnd)
{
    int LeftEnd, Tmp, NumElements;
    LeftEnd = R - 1;
    Tmp = L;  // 存放结果的数组的初始位置
    NumElements = RightEnd - L + 1;  // 元素个数
    while (L <= LeftEnd && R <= RightEnd)
    {
        if (A[L] <= A[R])
            TempA[Tmp++] = A[L++];
        else
            TempA[Tmp++] = A[R++];
    }
    while (L <= LeftEnd)   // 直接复制到左边剩下的
        TempA[Tmp++] = A[L++];
    while (R <= RightEnd)  // 直接复制到右边剩下的
        TempA[Tmp++] = A[R++];
    for (int i = 0; i < NumElements; i++, RightEnd--)  // 将临时数组的结果重新倒回A中
        A[RightEnd] = TempA[RightEnd];
}
// 方法1
// 递归方法实现归并排序
void Msort(int A[], int TempA[], int L, int RightEnd)
{
    int center;
    if (L < RightEnd)
    {
        center = (L + RightEnd) / 2;
        Msort(A, TempA, L, center);
        Msort(A, TempA, center + 1, RightEnd);
        Merge(A, TempA, L, center + 1, RightEnd);
    }
}

// 统一函数接口：由于Msort()函数对用户的输入不友好，所以采用统一的函数接口进行封装
void Merge_Sort(int *A, int N)
{
    int *TempA = (int *)malloc(N * sizeof(int));
    if (TempA != NULL)
    {
        Msort(A, TempA, 0, N - 1);
        free(TempA);
    }
    else
    {
        cout << "空间不足!\n";
    }
}

// 方法2
// 非递归方法实现归并排序
void Merge_Pass(int A[], int TempA[], int N, int length)
{
    int i;
    for (i = 0; i <= N - 2 * length; i += 2 * length)
        Merge(A, TempA, i, i + length, i + 2 * length - 1);   // 将A中元素归并到TempA
    if (i + length < N)   // 归并最后2个子列
        Merge(A, TempA, i, i + length, N - 1);   // 再将TempA中元素重新倒入到A
    else  // 最后只剩一个子列
    {
        for (int j = i; j < N; j++)
            TempA[j] = A[j];
    }
}

// 统一函数接口
void Merge_Sort2(int *A, int N)
{
    int length = 1;  // 初始化子列长度
    int *TempA = (int *)malloc(N * sizeof(int));
    if (TempA != NULL)   // 顺利的申请了空间
    {
        while (length < N)
        {
            Merge_Pass(A, TempA, N, length);
            length *= 2;
            Merge_Pass(TempA, A, N, length);
            length *= 2;
        }
        free(TempA);  // 不能少！！！
    }
    else
    {
        cout << "空间不足!\n";
    }
}

void show(int *A, int N){
    for(int i=0; i <N; i++)
        cout << A[i] << " ";
    cout << endl;
}

int main(){
    int A[] = {50,10,90,30,70,40,80,60,20};
    // cout << "归并排序前(递归方法): ";
    // show(A, 9);
    // Merge_Sort(A, 9);
    // cout << "归并排序后(递归方法): ";
    // show(A, 9);
    cout << "-------------------------------------------\n";
    cout << "归并排序前(非递归方法): ";
    show(A, 9);
    Merge_Sort2(A, 9);
    cout << "归并排序后(非递归方法): ";
    show(A, 9);
    return 0;
}