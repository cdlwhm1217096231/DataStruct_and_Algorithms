#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 暴力法：先排序，后遍历前k个数
class Solution1{
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k){
        vector<int> result;
        if(input.empty() || k > input.size()){
            return result;
        }
        sort(input.begin(), input.end());
        for(int i=0; i < k; ++i){
            result.push_back(input[i]);
        }
        return result;
    }
};

// 优化方法：使用堆排序,适用于海量数据
/*
首先，创建一个大小为k的容器用来存储k个最小的数字
然后，依次从输入input数组中读取一个数组放入容器中(容器中已有的数字个数少于k个时);如果容器已经满了，不能插入新的数字，只能进行替换数字操作
具体替换操作：找出k个数字中的最大值，然后与待插入的数字进行比较。如果待插入的数字小就拿它去替换最大值，否则丢弃这个值。
*/
class Solution2{
public:
    vector<int> GetNumbersLeast_Solution(vector<int> input, int k){
        vector<int> result;
        int length = result.size();
        if(length <= 0 || k > length || k <=0){
            return result;
        }
        for(int i = 0; i < length; ++i){
            if(result.size() < k){
                result.push_back(input[i]);
            }else{
                for(int j = k/2; j>=0; j--){
                    HeapAdjust(result, j, k);
                }
                for(int j = k-1; j>0; j--){
                    swap(result[0], result[j]);
                    HeapAdjust(result, 0, j);
                }
            }
        }
        return result;
    }
private:
    void HeapAdjust(vector<int> &input, int parent, int length){
        int temp = input[parent];  // 根节点的值 
        int child = 2 * parent + 1;  // 左子树的根节点
        while(child < length){
            if(child+1 < length && input[child] < input[child+1]){
                child++;
            }
            if(temp >= input[child]){
                break;
            }
            input[parent] = input[child];
            parent = child;
            child = 2 * parent + 1;
        }
        input[parent] = temp;
    }
}