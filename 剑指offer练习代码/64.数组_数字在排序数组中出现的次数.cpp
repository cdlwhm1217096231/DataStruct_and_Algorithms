#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int GetNumberOfK(vector<int> data, int k){
        int len = data.size();
        if(len == 0){
            return 0;
        }
        int first = GetFirstK(data, k, 0, len-1);
        int last = GetLastK(data, k, 0, len-1);
        if(first != -1 && last != -1){
            return last - first + 1;  // 返回重复数字k出现的次数
        }
        return 0;
    }
private:
    // 基于二分法的递归方式，找出第一次出现数字K的位置
    int GetFirstK(vector<int> data, int k, int begin, int end){
        if(begin > end){
            return -1;
        }
        int midIndex = (begin + end) >> 1;
        int midData = data[midIndex];
        // 中间数字就是数字K，但是中间数字的前一个数字不等于k，说明第一次出现k的位置就是中间位置
        if(midData == k){
            if((midIndex > 0 && data[midIndex-1] != k) || midIndex == 0){  // midIndex==0表示递归终止的条件
                return midIndex;
            }else{   // 中间数字就是数字K，但是中间数字的前一个数字等于k，说明第一次出现k的位置在左半边数组
                end = midIndex - 1;
            }
        }
        else if(midData > k){  // 中间数字大于数字k，表示数字k第一次出现的位置位于左半边数组
            end = midIndex - 1;
        }else{  // 中间数字小于数字k，表示数字k第一次出现的位置位于右半边数组
            begin = midIndex + 1;
        }
        return GetFirstK(data, k, begin, end);  
    }
    // 基于二分法的递归方式，找出最后一次出现数字K的位置
    int GetLastK(vector<int> data, int k, int begin, int end){
        int len = data.size();
        int midIndex = (begin + end) >> 1;
        int midData = data[midIndex];
        while(begin <= end){
            if(midData == k){  // 中间数字就是数字K，但是中间数字的后一个数字不等于k，说明最后一次出现k的位置就是中间位置
                if((midIndex < len-1 && data[midIndex + 1] != k) || midIndex == len - 1){   // midIndex==len-1表示递归终止的条件 
                    return midIndex;
                }else{  // 中间数字就是数字K，但是中间数字的后一个数字等于k，说明最后一次出现k的位置在右半边数组
                    begin = midIndex + 1;
                }
            }
            else if(midData > k){   // 中间数字大于数字k，表示数字k最后一次出现的位置位于左半边数组
                end = midIndex - 1;
            }else{    // 中间数字小于数字k，表示数字k最后一次出现的位置位于右半边数组
                begin = midIndex + 1;
            }
            midIndex = (begin + end) >> 1;
            midData = data[midIndex];
        }
        return -1;
    }
};