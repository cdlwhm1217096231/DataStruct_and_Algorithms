#include "iostream"

using namespace std;

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100

typedef int Status;



// 顺序表查找---无哨兵顺序查找
int sequenceSearch(int *a, int n, int key){
    for(int i = 1; i <= n; i++){  // 数组的下标是从1开始的
        if(a[i] == key)
            return i;  // 查找成功
    }
    return 0;  // 查找失败
}


// 顺序表查找---有哨兵顺序查找
// 对上面的算法中的for循环每次都要判断下标是否越界进行优化，使用哨兵法，哨兵放在数组的尾部
int sequenceSearch2(int *a, int n, int key){
    a[n-1] = key;
    int i = 0;
    while(a[i] != key){
        ++i;
    }
    return i;  // 返回n-1时，说明0到n-2范围内查找失败
}

int main(){
    int a[MAXSIZE+1], i, result;  // a数组是含有11个数据元素的数组
    int array[10] = {0,1,16,24,35,47,59,62,73,88};
    for(int i = 0; i <=MAXSIZE; i++)
        a[i] = i; // 数组的初始化
    result = sequenceSearch(a, MAXSIZE, MAXSIZE);
    cout << "sequence Search: " << result << endl;
    result = sequenceSearch2(array, 10, 22);
    cout << "sequence Search2: " << result << endl;
    return 0;
}