#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution{
public:
    // 向字符流中插入一个字符
    void Insert(char ch){
        s += ch;
        count[ch]++;
    }
    // 返回字符流中第一个只出现一次的字符的位置
    char FirstChar(){
        int len = s.size();
        for(int i=0; i < len; ++i){
            if(count[s[i]] == 1){
                return s[i];
            }
        }
        return '#';  // 如果当前字符流没有存在出现一次的字符，返回#字符
    }


private:
    string s;
    int count[256] = {0};  // 数组的初始化，然后映射成一个哈希表
};