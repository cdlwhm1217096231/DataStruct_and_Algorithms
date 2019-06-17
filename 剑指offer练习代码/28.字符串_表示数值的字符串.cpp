#include <iostream>

using namespace std;

/*

判断用字符串表示的数字是否是符合标准格式的浮点数类型！
*/

class Solution{
public:
    // 浮点数的表示，有整数部分，小数部分，指数部分组成。整数部分可能有0-9和+、-
    // 小数部分0-9，以.怎么分割符号；指数部分以e\E作为标志，后面结0-9
    bool isNumberic(char *string){
        if(string == nullptr || *string == '\0')
            return 0;
        // 正负号判断
        if(*string == '+' || *string == '-')
            ++string;
        bool numberic = true;
        scanDigits(&string);   // 此处传入的是地址，说明形参是一个二级指针！
        if(*string != '\0'){
            // 小数判断
            if(*string == '.'){
                ++string;
                scanDigits(&string);
                if(*string == 'e' || *string == 'E'){
                    numberic = isExponential(&string);
                }
            }
            // 整数判断
           else if(*string == 'e' || *string == 'E'){
               numberic = isExponential(&string);
           }
            else{
                numberic = false;
            }
        }
        return numberic && *string == '\0';
    }
private:
    // 扫描数字,对于合法数字，直接跳过
    void scanDigits(char **string){
        while(**string != '\0' && **string >= '0' && **string <= '9'){
            ++(*string);   // string是二级指针，*string是一级指针，**string是字符本身
        }
    }
    // 用科学计数法表示的数值是否合法
    bool isExponential(char **string){
        ++(*string);
        if(**string == '+' || **string == '-')
            ++(*string);
        if(**string == '\0')
            return false;
        scanDigits(string);
        // 判断是否结尾，没有结尾，说明还有其他非法字符
        return (**string == '\0') ? true:false;
    }
};