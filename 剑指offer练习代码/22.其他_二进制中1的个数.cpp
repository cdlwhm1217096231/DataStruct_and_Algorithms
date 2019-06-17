#include <iostream>

using namespace std;


class Solution{
public:
// �����ⷨ---���ܻᵼ����ѭ����
    int numberOfone(int n){
        int count = 0;
        while(n){
            if(n & 1){
                count++;
                n = n >> 1;
            }
        }
        return count;
    }
    // ����ⷨ
    int numberOfone1(int n){
        int count = 0;
        unsigned int flag = 1;
        while(flag){
            if(n & flag){
                count++;
                flag = flag << 1;
            }
        }
        return count;
    }
    // ��ʽ�ⷨ
    int numberOfone2(int n){
        int count = 0;
        while(n){
            ++count;
            n = (n-1) & n;
        }
        return count;
    }
};