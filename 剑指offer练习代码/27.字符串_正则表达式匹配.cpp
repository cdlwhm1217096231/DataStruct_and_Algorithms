#include <iostream>

using namespace std;


class Solution{
public:
    bool match(char *str, char *pattern){
        // str:字符串  pattern:模式串
        if(str == nullptr || pattern == nullptr)
            return false;
        return matchCore(str, pattern);
    }
private:
    bool matchCore(char *str, char *pattern){
        // 字符串和模式串都到了结尾，返回true
        if(*str == '\0' && *pattern == '\0')
            return true;
        // 字符串没有到结尾，但是模式串到了结尾，则返回false
        // 字符串到了结尾，模式串没到结尾，则继续后面的判断，对'*'进行处理
        if(*str != '\0' && *pattern == '\0')
            return false;
        // 模式串的下一个字符是'*'，则进入状态机的匹配
        if(*(pattern+1) == '*'){
            // 如果字符串与模式串相等，或者模式串是'.',而且字符串没有到末尾，则继续匹配
            if(*str == *pattern || (*pattern == '.' && *str != '\0')){
                // 进入下一个字符，就是上一个字符已经匹配上了
                return matchCore(str+1, pattern+2) || matchCore(str+1, pattern) || matchCore(str, pattern+2);
            }else{  // 如果字符串和模式串不相等，则跳过模式串的当前字符和'*'，进入下一轮的匹配
                return matchCore(str, pattern+2);
            }
        }
        // 如果子串串和模式串字符相等，或者模式串是'.',并且字符串没有到结尾，则继续匹配下一个字符
        if(*str == *pattern || (*pattern == '.' && *str != '\0')){
            return matchCore(str+1, pattern+1);
        }
        return false;
    }
};