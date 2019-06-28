#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution{
public:
    int GetUglyNumber(int index){
        if(index < 7){
            return index;  // 1，2，3，4，5，6都是丑数。所以当index小于7的时候，直接返回index即可
        }
        vector<int> res(index);  // 初始有index个元素，初始化为0
        for(int i=0; i < 6; ++i){
            res[i] = i+1;
        }
        int t2 = 3, t3 = 2, t5 = 1;
        for(int i=6; i < index; ++i){
            res[i] = min(res[t2]*2, min(res[t3]*3, res[5]*5));
            while(res[i] >= res[t2]*2)
                t2++;
            while(res[i] >= res[t3]*3)
                t3++;
            while(res[i] >= res[t5]*5)
                t5++;
        }
        return res[index-1];
    }
};
