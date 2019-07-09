#include <iostream>
#include <vector>


using namespace std;


class Solution{
public:
    vector<vector<int> > FindContinuousSequence(vector<int> array, int sum){
        vector<vector<int> > result;
        int pleft = 1;  // ���ָ��
        int pright = 2;  // �ұ�ָ��
        while(pright > pleft){
            // ��ǰ��
            int curSum = (pright + pleft) * (pright - pleft + 1) >> 1;
            if(curSum < sum){
                pright++;
            }
            if(curSum == sum){
                vector<int> temp;
                for(int i=pleft; i <= pright; ++i){
                    temp.push_back(i);
                }
                result.push_back(temp);
                pleft++;
            }
            if(curSum > sum){
                pleft++;
            }
        }
        return result;
    }
};