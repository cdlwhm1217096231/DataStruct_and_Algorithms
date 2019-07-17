#include <iostream>

using namespace std;

#define MAXSIZE 10
#define N 9
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0

typedef int Status;
typedef struct{
    int r[MAXSIZE+1];  // 共11个元素，但是r[0]是哨兵或临时变量的位置
    int len;
}Sqlist;

// 交换两个元素的值
void Swap(Sqlist *L, int i, int j){
    int temp = L->r[i];
    L->r[i] = L->r[j];
    L->r[j] = temp;
}

// 打印元素的值
void show(Sqlist L){
    for(int i = 1; i <= L.len; i++)
        cout << L.r[i] << " ";
    cout << endl;
}

// 简单选择排序
void SelectSort(Sqlist *L){
    int min;
    for(int i = 1; i < L->len; i++){
        min = i;  // 将当前的下标作为最小值所对应的下标
        for(int j = i+1; j <= L->len; j++){
            if(L->r[min] > L->r[j])  // 如果有小于当前最小值的关键字存在，就把该关键字的下标赋值给min
                min = j;
        }
        if(i != min)  // 如果min不等于i，说明找到了最小值，交换L->[min]与L->[i]的值
            Swap(L, i, min);

    }
}

int main(){
    Sqlist L0;
    int d[N] = {9, 1, 5, 8, 3, 7, 4, 6, 2};
    for(int i = 0; i < N; i++){
        L0.r[i+1] = d[i];
    }
    L0.len = N;
    cout << "简单选择排序前: ";
    show(L0);
    cout << "简单选择排序后: ";
    SelectSort(&L0);
    show(L0);
    return 0;
}
