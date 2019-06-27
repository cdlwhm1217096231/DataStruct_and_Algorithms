#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 给定一个数组，将数组中的所有的数字拼接成一个最小的数

class Solution{
public:
    string PrintMinNumber(vector<int> numbers){
        int len = numbers.size();
        if(len == 0){
            return "";
        }
        sort(numbers.begin(), numbers.end(), cmp);
        string res;
        for(int i=0; i < len; ++i){
            res += to_string(numbers[i]);
        }
        return res;
    }

private:
// 两个数字拼接成ab、ba后转化成字符串,接着进行比较，返回最小的字符串
    static bool cmp(int a, int b){
        string A = to_string(a) + to_string(b);  
        string B = to_string(b) + to_string(a);
        return A < B; 
    } 
};