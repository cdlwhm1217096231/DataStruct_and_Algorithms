#include <iostream>

using namespace std;

class Solution{
    public:
        int rectCover(int number){
            if(number <= 2)
                return number;
            int first = 1, second = 2, third = 0;
            for(int i = 3; i<=number;++i){
                third = first + second;
                first = second;
                second = third;
            }
            return third;
        }
};
