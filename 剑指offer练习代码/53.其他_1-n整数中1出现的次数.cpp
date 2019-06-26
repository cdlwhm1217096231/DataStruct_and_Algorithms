#include <iostream>
#include <vector>

using namespace std;


// 普通解法
class Solution{
public:
    int Count1BetweenN(int n){
        int count = 0;
        for(int i=1; i<=n; ++i){
            count += CountOne(i);
        }
        return count;
    }

    int CountOne(int n){
        int count = 0;
        while(n){
            if(n % 10 == 1){  // 统计每个数字个位上出现1的次数
                count++;
            }
            n /= 10;
        }
        return count;
    }
};