#include "iostream"

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
    for(int i = 1; i < L.len; i++)
        cout << L.r[i] << " ";
    cout << endl;
}

// 希尔排序
void ShellSort(Sqlist *L){
    int i, j;
    int increment = L->len;  // 增量的初始化
    do{ // 每执行一次do-while循环就会生成一个子序列，每个子序列的生成使用的增量increment是不同的！但是序列将原来越来越朝着基本有序的方向发展
        increment = increment / 3 +1;
        for(i = increment+1; i<=L->len; i++){
            if(L->r[i] < L->r[i-increment]){  // 插入的元素是L->r[i]，进行比较
                L->r[0] = L->r[i];   // 将需要的插入的元素暂时存储在哨兵中
                for(j = i-increment; j>0 && L->r[j] > L->r[0];j-=increment)
                    L->r[j+increment] = L->r[j];   // 进行交换操作
                L->r[j+increment] = L->r[0];
            }  
        }
    }while(increment > 1);  // 跳跃式的移动，而直接排序中是使用increment=1固定的！
}

int main(){
    Sqlist L;
    int d[N] = {9, 1, 5, 8, 3, 7, 4, 6, 2};
    for(int i = 0; i < N; i++)
        L.r[i+1] = d[i];
    L.len = N;
    cout << "希尔排序前: ";
    show(L);
    cout << "希尔排序后: ";
    ShellSort(&L);
    show(L);
    return 0;
}




