#include <iostream>

using namespace std;

#define N 9
#define MAXSIZE 10
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef struct{
    int r[MAXSIZE+1];
    int len;
}Sqlist;

void show(Sqlist L){
    for(int i = 1; i <= L.len; i++)
        cout << L.r[i] << " ";
    cout << endl;
}

void Swap(Sqlist *L, int i, int j){
    int temp = L->r[i];
    L->r[i] = L->r[j];
    L->r[j] = temp;
}
// 堆排序需要考虑的两个问题：
/*
    1.如何将一个无序的序列构造成一个大/小顶堆
    2.在输出堆顶元素后，怎么调整剩余的元素，使剩余的元素成为一个新的大/小顶堆
*/
// 堆调整函数
// 已知L->r[s..m]中的记录的关键字除L->r[s]之外均满足堆的定义，需要调整的关键字是L->r[s],使L->r[s...m]成为一个大顶堆
void HeapAdjust(Sqlist *L, int s, int m){
    int temp, j;
    temp = L->r[s];  // L->r[s]不满足堆的条件，需要调整的关键字是L->r[s]
    for(j = 2*s; j <= m; j*=2){  // 循环遍历当前结点s的左右孩子j，因为是完全二叉树，所以左孩子的序号是2*s，右孩子的序号是2*s+1
        if(j < m && L->r[j] < L->r[j+1])  // L->r[j]是左孩子,L->r[j+1]是右孩子,j<m说明当前的孩子结点不是最后一个结点
            ++j;  // L->r[j] < L->r[j+1]说明左孩子小于右孩子,说明最大值在右孩子结点上
        if(temp >= L->r[j])  // 当前的结点s就是最大值，不需要调整，直接跳出循环
            break;
        L->r[s] = L->r[j];  // 将当前结点s与左右孩子结点j进行交换，调整成大顶堆
        s = j;
    }
    L->r[s] = temp;
}

// 下面的程序是以大顶堆为例！！！
// 堆排序函数
void HeapSort(Sqlist *L){
    int i;
    // 构建成一个大顶堆,时间复杂度是O(n)
    for(i = L->len / 2; i >0; i--)  // 将L中的r[i]构造成一个大顶堆，i从L->len / 2开始是因为它们都是有左右孩子的结点
        HeapAdjust(L, i, L->len);
    // 重建成一个大顶堆，时间复杂度是O(nlogn)
    for(i = L->len; i > 1; i--){    // 逐步将每个最大值的根结点与完全二叉树中的末尾元素进行交换，并且再调整使其成为一个新的大顶堆
        Swap(L, 1, i);   // 将堆顶元素1与当前未经排序的子序列的最后一个元素i进行交换
        HeapAdjust(L, 1, i-1);  // 将L->r[1...i-1]重新调整为大顶堆
    }
}



int main(){
    Sqlist L;
    int d[N] = {50, 10, 90, 30, 70, 40, 80, 60, 20};
    for(int i = 0; i < N; i++)
        L.r[i+1] = d[i];
    L.len = N;
    cout << "堆排序前: ";
    show(L);
    cout << "堆排序后: ";
    HeapSort(&L);
    show(L);
    return 0;
}