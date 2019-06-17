#include <iostream>
#include <memory.h>
#include <cstring>

using namespace std;


// 递归方法实现
class Solution{
public:
    void print1ToMaxofNDigits(int n){
        if(n <= 0)
            return;
        char *number = new char[n+1];
        number[n] = '\0';
        for(int i=0; i < 10; ++i){
            number[0] = i + '0';
            print1ToMaxofNDigitsRecursively(number, n, 0);
        }
        delete[] number;
    }
private:
    void printNumber(char *number){
        bool isBeginning0 = true;
        int nLength = strlen(number);
        for(int i=0; i<nLength;++i){
            if(isBeginning0 && number[i] != '0')
                isBeginning0 = false;
            if(!isBeginning0)
                cout << "number[i] = " << number[i] << " ";
        }
    }
    void print1ToMaxofNDigitsRecursively(char *number, int len, int index){
        if(index == len - 1)
            printNumber(number);
        for(int i=0; i<10;++i){
            number[index+1] = i + '0';
            print1ToMaxofNDigitsRecursively(number, len, index+1);
        }
    }
};