#include "iostream"

using namespace std;




#define MAXSIZE 100
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0

typedef int Status;

// 二分查找/折半查找

Status Binary_Search(int *a, int n, int key){
    int left, right, mid;
    left = 1;
    right = n;
    while(left <= right){
        mid = (left + right) / 2;
        if(key < a[mid])
            right = mid-1;
        else if(key > a[mid])
            left = mid + 1;
        else
            return mid;
    }
    return ERROR;  // 有序表中没有找到关键字
}

// 插值查找
Status Interpolation_Search(int *a, int n, int key){
    int left, right, mid;
    left = 1;
    right = n;
    while(left <= right){
        mid = left + (right-left)*(key - a[left])/(a[right]-a[left]);  // 插值
        if(key < a[mid])
            right = mid - 1;
        else if(key > a[mid])
            left = mid + 1;
        else    
            return mid;
    }
    return ERROR;
}

// 斐波那契查找

int F[100];  // 斐波那契数列
int Fibonacci_Search(int *a, int n, int key){
    int left, right, mid;
    int k = 0;
    left = 1;
    right = n;
    while(n > F[k]-1)   // 查找的有序表长度n必须等于F[k]-1
        k++;
    for(int i = n; i < F[k]-1; i++)  // 当有序表的长度n小于F[k]-1时，需要将n增长到F[k]-1
        a[i] = a[n];   
    while(left <= right){
        mid = left + F[k-1] + 1;
        if(key < a[mid]){
            right = mid - 1;
            k = k-1;
        }
        else if(key > a[mid]){
            left = mid + 1;
            k = k -2;
        }
        else{
            if(mid <= n)
                return mid;
            else 
                return n;
        }
    }
    return ERROR;
}


int main(){
    int result;
    int arr[MAXSIZE]={0,1,16,24,35,47,59,62,73,88,99};

    result = Binary_Search(arr, 10, 62);
    cout << "Binary_Search:" << result << endl;
    result = Interpolation_Search(arr, 10, 62);
    cout << "Interpolation_Search:" << result << endl;
    F[0] = 0;
    F[1] = 1;
    for(int i = 2; i < 100; i++){
        F[i] = F[i-1] + F[i-2];  // 构建斐波那契数列
    }
    result = Fibonacci_Search(arr, 10, 62);
    cout << "Fibonacci_Search:" << result << endl;
    return 0;
}