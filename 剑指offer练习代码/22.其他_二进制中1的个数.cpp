#include <iostream>

using namespace std;


class Solution{
public:
// 基本解法---可能会导致死循环！
    int numberOfone(int n){
        int count = 0;
        while(n){
            if(n & 1){
                count++;
                n = n >> 1;
            }
        }
        return count;
    }
    // 常规解法
    int numberOfone1(int n){
        int count = 0;
        unsigned int flag = 1;
        while(flag){
            if(n & flag){
                count++;
                flag = flag << 1;
            }
        }
        return count;
    }
    // 新式解法
    int numberOfone2(int n){
        int count = 0;
        while(n){
            ++count;
            n = (n-1) & n;
        }
        return count;
    }
};