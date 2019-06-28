#include <iostream>
#include <string>

using namespace std;

class Solution{
public:
// 动态规划法：
    int LongestSubString(const string& str){
        int curLength = 0;  // 字符串中第一个字符的索引是0
        int maxLength = 0;
        int* position = new int[26];
        // 一维数组初始化
        for(int i=0; i < 26; ++i){
            position[i] = -1;
        }


        for(int i=0; i < str.length(); ++i){
            int prevIndex = position[str[i] - 'a']; 
            // 情况1：第i个字符之前出现过
            // 第i个字符与它上一次出现的位置prevIndex的距离d大于f(i-1),则f(i) = f(i-1) + 1
            if(prevIndex < 0 || i - prevIndex > curLength){  
                ++curLength; // f(i) = f(i-1)+1
            }else{ // 第i个字符与它上一次出现的位置prevIndex的距离d小于或等于f(i-1)，则f(i)=d
                if(curLength > maxLength)
                    maxLength = curLength;
                curLength = i - prevIndex;  // curLength相当于f(i)表示以第i个字符为结尾的不含重复字符的子字符串最大长度
            }
            position[str[i] - 'a'] = i;
        }

        // 情况2：第i个字符之前没有出现过，则f(i) = f(i-1) + 1
        if(curLength > maxLength){
            maxLength = curLength;
        }

        // 释放内存！
        delete[] position;
        return maxLength; 
    }
};