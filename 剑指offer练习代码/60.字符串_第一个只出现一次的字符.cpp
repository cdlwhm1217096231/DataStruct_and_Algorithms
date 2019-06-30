#include <iostream>
#include <string>
#include <map>

using namespace std;


// 建立一个hash表，第一次扫描时统计每个字符的出现次数；第二次扫描时，如果该字符的出现次数为1，则返回这个字符的位置。

class Solution{
public:
    int FirstNoRepeatChar(string str){
        int len = str.length();
        if (len == 0){
            return -1;
        }
        map<char, int> item;

        
        for(int i=0; i < len; ++i){
            item[str[i]]++;
        }

        for(int i=0; i < len; ++i){
            if(item[str[i]] == 1){
                return i;
            }
        }
        return -1;
    }
};