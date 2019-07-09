#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution{
public:
    string ReverseSentence(string str){
        string result = str;
        int length = str.size();
        if(length == 0){
            return "";
        }

        // 增加一个空格，作为翻转标志位
        result += ' ';
        int mark = 0;
        // 根据空格，逐一翻转每个单词
        for(int i=0; i < length+1; i++){
            if(result[i] == ' '){
                Reverse(result, mark, i-1);
                mark = i + 1;
            }
        }
        // 去掉添加的空格
        result = result.substr(0, length);  // 返回[0,0+length)范围内的子串
        // 2.整体翻转
        Reverse(result, 0, length-1);
        return result;
    }
private:
    // 1.翻转单个单词
    void Reverse(string& str, int begin, int end){
        while(begin < end){
            swap(str[begin++], str[end--]);
        }
    }
};