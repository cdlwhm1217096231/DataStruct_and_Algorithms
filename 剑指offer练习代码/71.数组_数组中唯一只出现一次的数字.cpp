#include <iostream>

using namespace std;

// 思路
/*
给定的数组是除一个数字只出现一次外，其余数字都出现3次
如果一个数字出现三个，则它的二进制表示中，0和1也会出现3次。所以，将所有出现三次的数字的二进制表示的每一位都加起来，则
每一位的和都能被3整除；如果一个数字只出现一次，则能被3整除的那一位一定是0，否则是1
*/

class Solution{
public:
    int FindNumsAppearingOnce(int numbers[], int length){
        if(numbers == nullptr || length <= 0){
            return -1;
        }
        // 定义一个数组存放数组各元素各位上的值的和
        int bitSum[32] = {0};
        for(int i=0; i < length; ++i){
            int bitMask = 1;  // 位掩码
            for(int j=31; j>=0; j--){
                int bit = numbers[i] & bitMask;
                if(bit != 0){
                    bitSum[j] += 1;
                }
                bitMask = bitMask << 1;
            }
        }

        // 用数组各元素各位上的和除以3，记录不能被3整除的数即只出现一次的数
        int result = 0;
        for(int k=0; k <32; k++){
            result = result << 1;
            result += bitSum[k] % 3;
        }
        return result;
    }
};