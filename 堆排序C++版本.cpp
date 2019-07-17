#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
// 堆排序：（最大堆，有序区）。从堆顶把堆顶元素弹出来放在有序区，再恢复堆。


// 打印元素
void PrintV(vector<int>& v){
    for(auto &e: v){
        cout << e << ' ';
    }
    cout << endl;
}

// 堆排序核心代码
void HeapSortCore(vector<int>& v, int start, int end){
    // 建立父节点和子节点指针
    int parent = start;
    int son = parent * 2 + 1;
    while(son <= end){  // 子节点在范围内才做比较
        if(son + 1 <= end && v[son] < v[son+1]){  // 先比较两个子节点大小，选择最大的
            son++;
        }

        if(v[parent] > v[son]){  // 如果父节点大于子节点，代表堆调整完毕，跳出循环
            return;
        }
        else{  // 否则，交换父子节点的内容，再继续子节点和孙节点比较
            swap(v[parent], v[son]);
            parent = son;
            son = parent * 2 + 1;
        }
    }
}


// 堆排序----外部调用接口
void HeapSort(vector<int>& v){
    // 初始化，i从最后一个父节点从下向上开始调整
    int n = v.size();
    for(int i = n/2 - 1; i>=0; --i){
        HeapSortCore(v, i, n-1);
    }
    // 先将第一个元素和已经排好序的元素前一位做交换，再重新调整堆
    for(int i=n-1; i > 0; --i){
        swap(v[0], v[i]);
        HeapSortCore(v, 0, i-1);
    }
}


int main(){
    vector<int> v{7, 30, 16, 4, 1, 2, 9};
    cout << "堆排序前: ";
    PrintV(v);
    HeapSort(v);
    cout << "堆排序后: ";
    PrintV(v);
    return 0;
}