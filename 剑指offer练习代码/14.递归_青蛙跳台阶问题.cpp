#include <iostream>

using namespace std;

class Solution{
    public:
        int jumpFloor(int number){
            if(number <= 0)
                return 0;
            else if(number < 3)
                return number;
            int first = 1, second = 2, third = 0;
            for(int i=3;i<=number;++i){  // 将递归改成循环，降低代码的时间复杂度
                third = first + second;
                first = second;
                second = third;
            }
            return third;
        }
}