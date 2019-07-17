#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 选择排序思路：
// 1. 在未排序序列中找到最小（大）元素，存放到排序序列的起始位置
// 2. 从剩余未排序元素中继续寻找最小（大）元素，然后放到已排序序列的末尾
// 3. 以此类推，直到所有元素均排序完毕


// 打印元素
void PrintV(vector<int>& v){
    for(auto &e: v){
        cout << e << ' ';
    }
    cout << endl;
}

// 选择排序
void SelectSort(vector<int>& v){
    int n = v.size();
    for(int i=0; i < n-1;++i){
        int min = i;
        for(int j=i+1; j < n; ++j){
            if(v[j] < v[min]){
                min = j;
            }
        }

        if(i != min){
            swap(v[i], v[min]);
        }

    }
}


// 函数模板实现
template <typename T>
void SelectSort1(vector<T>& arr){
    int n = arr.size();
    for(int i=0; i < n-1; ++i){
        int min = i;
        for(int j=i+1; j < n; ++j){
            if(arr[j] < arr[min]){
                min = j;
            }
        }

        if(i != min){
            swap(arr[i], arr[min]);
        }
    }
}


int main(){
    vector<int> v{7, 30, 16, 4, 1, 2, 9};
    cout << "选择排序前: ";
    PrintV(v);
    SelectSort(v);
    cout << "选择排序后: ";
    PrintV(v);
    return 0;
}