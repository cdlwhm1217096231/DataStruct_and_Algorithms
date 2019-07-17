#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

//  希尔排序：每一轮按照事先决定的间隔进行插入排序，间隔会依次缩小，最后一次一定要是1。



// 打印元素
void PrintV(vector<int>& v){
    for(auto &e: v){
        cout << e << ' ';
    }
    cout << endl;
}


// 希尔排序
void ShellSort(vector<int>& v){
    int n = v.size();
    int h = 1;   // 间隔

    while(h < n / 3){
        h = 3 * h + 1;
    }

    while(h >= 1){
        for(int i=h; i < n; ++i){
            for(int j=i; j >= h && v[j] < v[j-h]; j-=h){
                swap(v[j], v[j-h]);
            }
        }
        h = h / 3;
    }
}



int main(){
    vector<int> v{7, 30, 16, 4, 1, 2, 9};
    cout << "希尔排序前: ";
    PrintV(v);
    ShellSort(v);
    cout << "希尔排序后: ";
    PrintV(v);
    return 0;
}