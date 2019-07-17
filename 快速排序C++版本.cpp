#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


// ��С������׼Ԫ�أ����������������������ѡһ��Ԫ������׼����С�ڻ�׼��Ԫ�ط��ڻ�׼֮ǰ�����ڻ�׼��Ԫ�ط��ڻ�׼֮���ٷֱ��С�������������������
// ��������˼·��
// 1. ѡȡ��һ����Ϊ��׼
// 2. ���Ȼ�׼С����������ǰ�棬�Ȼ�׼���������������
// 3. �����������ظ��ڶ�����ֱ��������ֻ��һ����


// �ݹ鷽��ʵ��
void QuickSort(vector<int>& v, int low, int high){
    if(low >= high)
        return;
    int first = low;
    int last = high;
    int key = v[first];   // ��һ��Ԫ����Ϊ��Ԫ

    while(first < last){
        while(first < last && v[last] >= key){
            last--;
        }

        if(first < last){  // ����������ʱ��������Ԫ�ر�ǰ���Ԫ��Сʱ�����н�������!
            v[first++] = v[last];
        }

        while(first < last && v[first] <= key){
            first++;
        }

        if(first < last){
            v[last--] = v[first];
        }
    }

    // ��׼λ��
    v[first] = key;
    QuickSort(v, low, first-1);  // ǰ�벿�ֵݹ�
    QuickSort(v, first+1, high);  // ��벿�ֵݹ�
}


// ���һ��Ԫ����Ϊ��Ԫ
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