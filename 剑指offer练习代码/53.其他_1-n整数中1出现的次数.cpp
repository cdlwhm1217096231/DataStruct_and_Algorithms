#include <iostream>
#include <vector>

using namespace std;


// ��ͨ�ⷨ
class Solution{
public:
    int Count1BetweenN(int n){
        int count = 0;
        for(int i=1; i<=n; ++i){
            count += CountOne(i);
        }
        return count;
    }

    int CountOne(int n){
        int count = 0;
        while(n){
            if(n % 10 == 1){  // ͳ��ÿ�����ָ�λ�ϳ���1�Ĵ���
                count++;
            }
            n /= 10;
        }
        return count;
    }
};