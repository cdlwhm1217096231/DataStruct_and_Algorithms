#include <iostream>
#include <string>

using namespace std;

// 目标：输入合法值时，输出为整数；不合法输入时，返回0

/*
1.指针是否为空指针以及字符串是否为空字符串
2.字符串对于正负号的处理
3.输入值是否为合法值，即小于等于'9'，大于等于'0'
4.int为32位，需要判断是否溢出
5.使用错误标志，区分合法值0和非法值0

*/

class Solution{
public:
    enum Status{KValid=0, KInValid};
    int g_nstatus = KValid;

    int StrToInt(string str){
        long long num = 0;
        const char* cstr = str.c_str();
        // 判断是否为指针和是否是空字符串
        if(cstr != nullptr && *cstr != '\0'){
            // 正负号标志位，默认是加号
            bool minus = false;
            if(*cstr == '+'){
                cstr++;
            }
            else if(*cstr == '-'){
                minus = true;
                cstr++;
            }

            if(*cstr != '\0'){
                num = StrToIntCore(cstr, minus);
            }
        }
        return (int) num;
    }

private:
    long long StrToIntCore(const char* cstr, bool minus){
        long long num=0;
        while(*cstr != '\0'){
            // 判断是否是非法值
            if(*cstr >= '0' && *cstr <= '9'){
                int flag = minus ? -1:1;
                num = num * 10 + flag * (*cstr - '0');
                // 判断是否溢出32位
                if((!minus && num > 0x7fffffff) || (minus && num < (signed int)0x80000000)){
                    num = 0;
                    break;
                }
                cstr++;
            }
            else{
                num = 0;
                break;
            }
        }
        // 判断是否正常结束
        if(*cstr == '\0'){
            g_nstatus = KValid;
        }
        return num;
    }
};