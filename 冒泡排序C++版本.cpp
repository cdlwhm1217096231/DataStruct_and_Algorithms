#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


// 冒泡排序思路：
// 1. 比较相邻的元素。如果第一个比第二个大，就交换它们两个。
// 2. 对每一对相邻元素作同样的工作，从开始第一对到结尾的最后一对。这步做完后，最后的元素会是最大的数。
// 3. 针对所有的元素重复以上的步骤，除了最后一个。
// 4. 持续每次对越来越少的元素重复上面的步骤，直到没有任何一对数字需要比较。


// 打印元素
void PrintV(vector<int>& v){
    for(auto &e: v){
        cout << e << ' ';
    }
    cout << endl;
}


// 冒泡排序基本版本
void BubbleSort(vector<int>& v){
    int n = v.size();
    for(int i=0; i < n-1; ++i){
        for(int j=0; j < n-1-i; ++j){
            if(v[j] > v[j+1]){
                swap(v[j], v[j+1]);
            }
        }
    }
}

// 函数模板来实现
template<typename T>   // 模板头
void BubbleSort1(T arr[], int len){
    for(int i=0; i < len-1; ++i){
        for(int j=0; j < len-1-i; ++j){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}



// 冒泡排序优化版本
void BubbleSort2(vector<int>& v){
    int n = v.size();
    bool flag = false;  // flag标志：表示序列是否有序
    for(int i=0; i < n-1 && !flag; ++i){
        flag = true;
        for(int j=0; j < n-1-i; ++j){
            if(v[j] > v[j+1]){
                flag = false;  // 发生交换则仍非有序
                swap(v[j], v[j+1]);
            }
        }
    }
}



// 自己实现两个数的交换
void Swap(int& a, int& b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}


int main(){
    vector<int> v{7, 30, 16, 4, 1, 2, 9};
    cout << "冒泡排序前: ";
    PrintV(v);
    BubbleSort2(v);
    cout << "冒泡排序后: ";
    PrintV(v);
    return 0;
}