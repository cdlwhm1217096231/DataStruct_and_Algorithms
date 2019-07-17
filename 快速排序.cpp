#include <iostream>
#include <malloc.h>

using namespace std;

#define MAXSIZE 10
#define N 9
#define MAX_LENGTH_INSERT_SORT 7 // 快速排序设定的阈值

typedef struct
{
    int r[MAXSIZE + 1];
    int len;
} Sqlist;

void show(Sqlist L)
{
    for (int i = 1; i <= L.len; i++)
        cout << L.r[i] << " ";
    cout << endl;
}

void Swap(Sqlist *L, int i, int j)
{
    int temp = L->r[i];
    L->r[i] = L->r[j];
    L->r[j] = temp;
}

// 确定主元
int Partition(Sqlist *L, int low, int high)
{
    int pivotkey; // 主元
    pivotkey = L->r[low];
    while (low < high)
    {
        while (low < high && L->r[high] >= pivotkey) // 比主元大的放在主元的右边，不交换
            high--;
        Swap(L, low, high);                         // 比主元小的放在主元的右边，进行交换
        while (low < high && L->r[low] <= pivotkey) // 比主元小的放在主元的左边，不交换
            low++;
        Swap(L, low, high); // 比主元大的放在主元的左边，进行交换
    }
    return low;
}

// 快速排序
void Qsort(Sqlist *L, int low, int high)
{
    int pivot; // 主元位置
    if (low < high)
    {
        pivot = Partition(L, low, high);
        Qsort(L, low, pivot - 1);
        Qsort(L, pivot + 1, high);
    }
}

// 统一函数接口
void QuickSort(Sqlist *L)
{
    Qsort(L, 1, L->len);
}

// 快速排序的优化
int Partition1(Sqlist *L, int low, int high)
{
    // 确定主元位置---三数取中法
    int pivotkey;
    int center = low + (high - low) / 2; // 计算中间元素的下标
    // 对左 中 右三个数进行排序
    if (L->r[low] > L->r[high])    // 如果左边的数大于右边的数，进行交换操作
        Swap(L, low, high);        // 保证左边的数较小
    if (L->r[center] > L->r[high]) // 如果中间的数大于右边的数，进行交换操作
        Swap(L, center, high);     // 保证中间的值较小
    if (L->r[center] > L->r[low])  // 如果中间的数大于左边的数，进行交换操作
        Swap(L, center, low);      // 保证左边的值较小
    pivotkey = L->r[low];          // L->r[low]已经成为整个序列左中右三个关键字的中间值
    L->r[0] = pivotkey;
    while (low < high)
    {
        while (low < high && L->r[high] >= pivotkey)
            high--;
        L->r[low] = L->r[high]; // 使用的是替换不是交换
        while (low < high && L->r[low] <= pivotkey)
            low++;
        L->r[high] = L->r[low]; // 使用的是替换不是交换
    }
    L->r[low] = L->r[0]; // 将暂存的主元替换回L->r[row]
    return low;          // 返回主元的位置
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
            L->r[j + 1] = L->r[0];     // 插入新的元素到正确的位置
        }
    }
}

// 因为快速排序适合由于待排序的序列很大的情况，所以设置一个阈值
void Qsort1(Sqlist *L, int low, int high)
{
    int pivot;
    if ((high - low) > MAX_LENGTH_INSERT_SORT)
    {
        pivot = Partition1(L, low, high);
        Qsort1(L, low, pivot - 1);
        Qsort1(L, pivot + 1, high);
    }
    else
    {
        InsertSort(L);
    }
}
// 由于Qsort1()函数在其尾部有两次的递归操作，如果待排序的序列划分极不平衡时，递归深度将趋于n，浪费栈空间
// 使用尾递归
void Qsort2(Sqlist *L, int low, int high)
{
    int pivot;
    if ((high - low) > MAX_LENGTH_INSERT_SORT)
    {
        while (low < high)
        {
            pivot = Partition1(L, low, high);
            Qsort2(L, low, pivot - 1);
            low = pivot + 1;  // 尾递归
        }
    }
    else
    {
        InsertSort(L);
    }
}

// 统一函数接口:改进后的快速排序
void QuickSort1(Sqlist *L){
    Qsort1(L, 1, L->len);
}

// 统一函数接口：改进后的快速排序使用尾递归
void QuickSort2(Sqlist *L){
    Qsort2(L, 1, L->len);
}

int main()
{
    Sqlist L;
    int d[N] = {50, 10, 90, 30, 70, 40, 80, 60, 20};
    for (int i = 0; i < N; i++)
        L.r[i + 1] = d[i];
    L.len = N;
    cout << "快速排序前: ";
    show(L);
    cout << "快速排序后: ";
    QuickSort(&L);
    show(L);

    cout << "改进的快速排序后: ";
    QuickSort1(&L);
    show(L);
    
    cout << "改进的快速排序(尾递归)后: ";
    QuickSort2(&L);
    show(L);
    return 0;
}