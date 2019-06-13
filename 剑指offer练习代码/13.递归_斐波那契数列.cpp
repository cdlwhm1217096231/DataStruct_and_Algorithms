#include <iostream>

using namespace std;

class Solution{
public:
    int Fib(int n){
        if(n<=0)
            return 0;
        if(n==1)
            return 1;
        int first = 0, second = 1, third = 0;
        for(int i=2;i<=n;++i){
            third = first + second;
            first = second;
            second = third;
        }
        return third;
    }
};