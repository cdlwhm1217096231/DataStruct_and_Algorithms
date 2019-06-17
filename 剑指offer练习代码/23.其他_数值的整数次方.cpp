#include <iostream>

using namespace std;

class Solution{
public:
    double Power(double base, int exponent){
        // base:底数，exponent：指数
        if(equal(base, 0.0))
            return 0;
        unsigned int absExponent = 0;
        if(exponent > 0)
            absExponent = (unsigned int)exponent;  // 指数大于0
        else
            absExponent = (unsigned int) -exponent;  // 指数小于0
        double result = PowerWithUnsignedExponent(base, exponent);
        if(exponent < 0)
            result = 1.0 / result;   // 指数小于0时，取倒数，得到最终的结果
        return result;
    }
private:
// 下面函数具体一般性，用来比较两个浮点数是否相等，不能使用==直接比较！
    bool equal(double num1, double num2){
        if((num1 - num2) > -0.0000001 && (num1 - num2) < 0.0000001)
            return true;
        else    
            return false;
    }
// 核心函数，计算浮点数的整数次方
    double PowerWithUnsignedExponent(double base, unsigned int exponent){
        if(exponent == 0)
            return 1;
        if(exponent == 1)
            return base;
        double result = PowerWithUnsignedExponent(base, exponent>>1);
        result *= result;
        if((exponent & 0x1) == 1)
            result *= base;
        return result;
    }
};