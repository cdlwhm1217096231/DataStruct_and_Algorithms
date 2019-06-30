#include <iostream>
#include <vector>

using namespace std;

// 逆序对总数 = 左边数组中的逆序对数目 + 右边数组中的逆序对数目 + 左右合成新的数组时出现的逆序对数目

// 使用归并排序的思想！！！
class Solution{
public:
    int InversePairs(vector<int> data){
        if(data.size() == 0){
            return 0;
        }
        // 排序的辅助数组
        vector<int> copy;
        for(int i=0; i<data.size(); ++i){
            copy.push_back(data[i]);
        }
        return InversePairsCore(data, copy, 0, data.size()-1) % 1000000007;
    }

    long InversePairsCore(vector<int>& data, vector<int>& copy, int left, int right){
        // 如果指向相同位置，没有逆序对
        if(left == right){
            copy[left] = copy[right];
            return 0;
        }
        // 求划分中点处的位置
        int mid = (left + right) >> 1;
        // 使得左边数组有序，并返回左边数组逆序对的数目
        long leftCount = InversePairsCore(copy, data, left, mid);
        // 使得右边数组有序，并返回右边数组逆序对的数目
        long rightCount = InversePairsCore(copy, data, mid+1, right);
        
        int i = mid;  // i初始化为前半段最后一个数字的下标
        int j = right;  // j初始化为后半段最后一个数字的下标
        int indexCopy = right;   // 辅助数组的最后一个数字的下标
        long count = 0;  // 计数逆序对的个数，注意类型

        while(i >= left && j >= mid+1){
            if(data[i] > data[j]){
                copy[indexCopy--] = data[i--];
                count += j - mid;
            }else{
                copy[indexCopy--] = data[j--];
            }
        }

        for(; i >= left; --i){
            copy[indexCopy--] = data[i];
        }

        for(; j >= mid+1; --j){
            copy[indexCopy--] = data[j];
        }
        return leftCount + rightCount + count;
    }
};