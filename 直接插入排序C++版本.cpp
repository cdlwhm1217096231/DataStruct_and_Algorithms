#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


// 插入排序思路:
    // 1.从第一个元素开始，该元素可以认为已经被排序
    // 2.取出下一个元素，在已经排序的元素序列中从后向前扫描
    // 3.如果该元素（已排序）大于新元素，将该元素移到下一位置
    // 4.重复步骤3，直到找到已排序的元素小于或者等于新元素的位置
    // 5.将新元素插入到该位置后
    // 6. 重复步骤2~5


void InsertSort(vector<int>& v){
    int n = v.size();
    for(int i=1; i < n; ++i){  
        int temp = v[i]; // 新元素
        for(int j = i-1; j>=0; --j){  // 已排序的元素v[j]从后向前扫描
            if(v[j] > temp){
                v[j+1] = v[j];
                v[j] = temp;
            }
            else{
                break;
            }
        }
    }
}

// 打印元素
void PrintV(vector<int>& v){
    for(auto &e: v){
        cout << e << ' ';
    }
    cout << endl;
}

int main(){
    vector<int> v{7, 30, 16, 4, 1, 2, 9};
    cout << "直接插入排序前: ";
    PrintV(v);
    InsertSort(v);
    cout << "直接插入排序后: ";
    PrintV(v);
    return 0;
}
