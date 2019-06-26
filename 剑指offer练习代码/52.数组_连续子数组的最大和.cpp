#include <iostream>
#include <vector>

using namespace std;


class Solution{
public:
    int FindGreatestSumOfSubArray(vector<int> array){
        if(array.empty()){
            return 0;
        }
        // 初始化变量,maxSum为最大累加和，curSum是当前和
        int maxSum = array[0];
        int curSum = array[0];
        for(int i=1; i < array.size(); ++i){
            // 如果当前和小于等于0，说明之前的加的数是负数，丢弃前面的和，重新计算当前和
            if(curSum <= 0){
                curSum = array[i];
            }
            // 如果没有问题，直接累加
            else{
                curSum += array[i];
            }
            // 当前和与最大累加和进行比较，更新最大累加和
            if(curSum > maxSum){
                maxSum = curSum;
            }
        }
        return maxSum;
    }

};