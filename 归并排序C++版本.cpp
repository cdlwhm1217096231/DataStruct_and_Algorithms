#include <iostream>

using namespace std;

// 归并排序：把数据分为两段，从两段中逐个选最小的元素移入新数据段的末尾。可从上到下或从下到上进行。

// 迭代方法实现
template<typename T>
void MergeSort(T arr[], int len){
    T* a = arr;  // 指针a指向原始数组
    T* b = new T[len];  // 指针b指向新创建的一个数组
    for(int seg=1; seg < len; seg+=seg){
        for(int start=0; start < len; start += seg + seg){
            int low = start;
            int mid = min(start+seg, len);
            int high = min(start+seg+seg, len);
            int k = low;
            int start1 = low, end1 = mid;
            int start2 = mid+1, end2 = high;
            while(start1 < end1 && start2 < end2){
                b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
            }

            while(start1 < end1){
                b[k++] = a[start1++];
            }

            while(start2 < end2){
                b[k++] = a[start2++];
            }
        }
        T* temp = a;
        a = b;
        b = temp;
    }
    if(a != arr){
        for(int i=0; i < len; i++){
            b[i] = a[i];
        }
        b = a;
    }
    delete[] b;
}

// 递归方法实现
template<typename T>
void MergeSortRecursiveCore(T arr[], T reg[], int start, int end){
    if(start >= end){
        return;
    }
    int len = end - start;
    int mid = start + (len >> 1);
    int start1 = start, end1 = mid;
    int start2 = mid+1, end2 = end;
    MergeSortRecursiveCore(arr, reg, start1, end1);
    MergeSortRecursiveCore(arr, reg, start2, end2);
    int k = start;
    while(start1 <= end1 && start2 <= end2){
        reg[k++] = arr[start1] < arr[start2] ? arr[start1++] : arr[start2++];
    }

    while(start1 <= end1){
        reg[k++] = arr[start1++];
    }

    while(start2 <= end2){
        reg[k++] = arr[start2++];
    }

    for(k = start; k<=end; k++){
        arr[k] = reg[k];
    }
}

template<typename T>
void MergeSortRecursive(T arr[], const int len){
    T* reg = new T[len];
    MergeSortRecursiveCore(arr, reg, 0, len-1);
    delete[] reg;
}