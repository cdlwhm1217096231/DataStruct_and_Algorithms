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
            for(int i=3;i<=number;++i){  // ���ݹ�ĳ�ѭ�������ʹ����ʱ�临�Ӷ�
                third = first + second;
                first = second;
                second = third;
            }
            return third;
        }
}