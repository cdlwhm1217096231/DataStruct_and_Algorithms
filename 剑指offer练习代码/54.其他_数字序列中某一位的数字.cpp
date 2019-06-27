#include <iostream>
#include <string>
#include <cmath>


using namespace std;

// 数字序列中的某一位的数字是？

/*
    01234567891011121314151617.....
    一位数有10个，占用10个位置：0-9组成
    两位数有90个，占用180个位置：10-99组成
    三位数有900个，占用2700个位置：100-999组成
*/

class Solution{
public:
    int digitAtIndex(int index){  // index是所要求的数字序列中的某一位的索引，例如求出数字序列中第1001位是什么数字，则index=1001
        if(index < 0) 
            return -1;

        int digits = 1;
        while(true){
            int numbers = countOfIntegers(digits);  // 知道某个数字有digits位，则digits位总共有多少个数字
            if(index < numbers*digits){  // numbers*digits:表示数字是digits位的数字所占用的总的位置数，例如90个两位数共占用180个位置
                return digitAtIndexCore(index, digits); // 找到index=1001位于三位数所占的位置中，因为三位数共900个，所占的位置2700个
            }
            index -= digits * numbers;
            digits++;
        }
        return -1;
    }
    // 统计digits位的数字总共有多少个
    int countOfIntegers(int digits){
        if(digits == 1){
            return 10;
        }
        int count = (int)pow(10, digits-1);
        return 9 * count;
    }

    // 已经知道1001位数字位于digits位数当中后，下面的函数则是找出index=1001所对应的数字
    int digitAtIndexCore(int index, int digits){
        int number = beginNumber(digits) + index / digits;  // 找出那个数字number了！
        int indexFromRight = digits - index % digits;  
        for(int i=1; i < indexFromRight; ++i){
            number /= 10;
        }
        return number % 10;
    }

    // 找出digits位数的第一个数字，例如找出第一个两位数是10，第一个三位数是100
    int beginNumber(int digits){
        if(digits == 1){ // 第一个一位数是0
            return 0;
        }
        return (int)pow(10, digits-1);
    }
};