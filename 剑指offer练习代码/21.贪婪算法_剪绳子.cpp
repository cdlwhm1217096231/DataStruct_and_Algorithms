#include <iostream>
#include <cmath>

using namespace std;

class Solution{
public:
    int maxProductAfterCutting(int length){
        if(length < 2)
            return 0;
        if(length == 2)
            return 1;
        if(length == 3)
            return 2;
        int timesofThree = length / 3;   // ����Ϊ3�����Ӷ���Ŀ
        // ��ʣ�����ӳ���Ϊ4ʱ�������ּ�����2*2 �� 1*3����ʱѡ��2*2
        if(length - timesofThree * 3 == 1)  // ʣ��һ�����ӵĳ��ȵ���4
            timesofThree -= 1;  // ��ֻ����ǰ��timesofThree-1�γ���Ϊ3�����ӳ��ȳ˻� 
        int timesofTwo = (length - 3*timesofThree) / 2;  // ʣ��һ�����ӳ���Ϊ4�����Ի��ֳ���������Ϊ2�ģ�
        return (int)(pow(3, timesofThree)) * (int)(pow(2, timesofTwo));
    }
};