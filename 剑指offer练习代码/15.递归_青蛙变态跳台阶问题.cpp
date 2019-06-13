#include <iostream>

using namespace std;


class Solution{
    public:
        int jumpFloor(int number){
            if(number == 0)
                return 0;
            int total = 1;
            for(int i = 1; i < number;++i){
                total *= 2;
            }
            return total;
        }
};