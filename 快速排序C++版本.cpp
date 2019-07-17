#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


// （小数，基准元素，大数）。在区间中随机挑选一个元素作基准，将小于基准的元素放在基准之前，大于基准的元素放在基准之后，再分别对小数区与大数区进行排序。
// 快速排序思路：
// 1. 选取第一个数为基准
// 2. 将比基准小的数交换到前面，比基准大的数交换到后面
// 3. 对左右区间重复第二步，直到各区间只有一个数


// 递归方法实现
void QuickSort(vector<int>& v, int low, int high){
    if(low >= high)
        return;
    int first = low;
    int last = high;
    int key = v[first];   // 第一个元素作为主元

    while(first < last){
        while(first < last && v[last] >= key){
            last--;
        }

        if(first < last){  // 不符合条件时，即后面元素比前面的元素小时，进行交换操作!
            v[first++] = v[last];
        }

        while(first < last && v[first] <= key){
            first++;
        }

        if(first < last){
            v[last--] = v[first];
        }
    }

    // 基准位置
    v[first] = key;
    QuickSort(v, low, first-1);  // 前半部分递归
    QuickSort(v, first+1, high);  // 后半部分递归
}


// 最后一个元素作为主元
template<typename T>
void QuickSortRecursiveCore(T arr[], int start, int end){
    if (start >= end)
        return;
    T mid = arr[end];
    int left = start, right = end-1;
    while(left < right){
        while(arr[left] < mid && left < right){
            left++;
        }
        while(arr[right] >= mid && left < right){
            right--;
        }
        swap(arr[left], arr[right]);
    }

    if(arr[left] >= arr[end]){
        swap(arr[left], arr[end]);
    }
    else{
        left++;
    }

    QuickSortRecursiveCore(arr, start, left-1);
    QuickSortRecursiveCore(arr, left+1, end);
}

template<typename T>
void QuickSortRecursive(T arr[], int len){
    QuickSortRecursiveCore(arr, 0, len-1);
}