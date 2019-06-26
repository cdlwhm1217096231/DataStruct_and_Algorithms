#include <iostream>
#include <vector>

using namespace std;


class Solution{
public:
    int FindGreatestSumOfSubArray(vector<int> array){
        if(array.empty()){
            return 0;
        }
        // ��ʼ������,maxSumΪ����ۼӺͣ�curSum�ǵ�ǰ��
        int maxSum = array[0];
        int curSum = array[0];
        for(int i=1; i < array.size(); ++i){
            // �����ǰ��С�ڵ���0��˵��֮ǰ�ļӵ����Ǹ���������ǰ��ĺͣ����¼��㵱ǰ��
            if(curSum <= 0){
                curSum = array[i];
            }
            // ���û�����⣬ֱ���ۼ�
            else{
                curSum += array[i];
            }
            // ��ǰ��������ۼӺͽ��бȽϣ���������ۼӺ�
            if(curSum > maxSum){
                maxSum = curSum;
            }
        }
        return maxSum;
    }

};