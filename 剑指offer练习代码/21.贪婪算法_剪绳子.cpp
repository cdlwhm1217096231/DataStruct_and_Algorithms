#include <iostream>
#include <cmath>

using namespace std;

class Solution{
public:
    int maxProductAfterCutting(int length){
        if(length < 2)
            return 0;
        if(length == 2)
            return 1;
        if(length == 3)
            return 2;
        int timesofThree = length / 3;   // 长度为3的绳子段数目
        // 当剩余绳子长度为4时，有两种减法，2*2 和 1*3，此时选择2*2
        if(length - timesofThree * 3 == 1)  // 剩下一段绳子的长度等于4
            timesofThree -= 1;  // 将只计算前面timesofThree-1段长度为3的绳子长度乘积 
        int timesofTwo = (length - 3*timesofThree) / 2;  // 剩余一段绳子长度为4，可以划分成两个长度为2的！
        return (int)(pow(3, timesofThree)) * (int)(pow(2, timesofTwo));
    }
};