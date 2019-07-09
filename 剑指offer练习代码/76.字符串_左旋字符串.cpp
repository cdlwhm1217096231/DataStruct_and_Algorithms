#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


class Solution{
public:
    string LeftRotateString(string str, int n){
        string result = str;
        int length = result.size();
        if(length < 0){
            return nullptr;
        }

        if(0 <= n <= length){
            // 第一部分
            int pFirstBegin = 0;
            int pFirstEnd = n-1;
            // 第二部分
            int pSecondBegin = n;
            int pSecondEnd = length - 1;
            // 1.第一部分和第二部分翻转

            // 第一部分翻转
            ReverseString(result, pFirstBegin, pFirstEnd);
            // 第二部分翻转
            ReverseString(result, pSecondBegin, pSecondEnd);
            // 2.整体再翻转
            ReverseString(result, pFirstBegin, pSecondEnd);
        }
        return result;
    }
private:
    void ReverseString(string& str, int begin, int end){
        while(begin < end){
            swap(str[begin++], str[end--]);
        }
    }
};
