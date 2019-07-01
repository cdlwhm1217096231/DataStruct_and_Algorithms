#include <iostream>  


using namespace std;

class Solution{
public:
    int GetMissingNumber(const int *data, int length){
        if(data == nullptr || length <=0){
            return -1;
        }
        int left = 0;
        int right = length - 1;
        while(left <= right){
            int midIndex = (left + right) >> 1;
            if(data[midIndex] != midIndex){  // 中间元素的值不等于下标的值
                if(midIndex == 0 || data[midIndex - 1] == midIndex - 1){  // 中间元素的值不等于下标的值,并且它的前一个元素和它的下标相等，则中间元素正好是第一个值与下标不相等的元素
                    return midIndex;
                }else{  // 中间元素的值不等于下标的值,并且它的前一个元素和它的下标不相等，则下一轮查找左半边数组
                    right = midIndex - 1;
                }
            }else{  // 中间元素的值等于下标的值，下一轮查找右半边数组
                left = midIndex + 1;
            }
        }

        if(left == length){
            return length;
        }
        
        return -1;
    }
};