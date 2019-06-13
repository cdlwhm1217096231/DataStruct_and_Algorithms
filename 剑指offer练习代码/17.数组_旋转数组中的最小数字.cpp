#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int minNumberInRotateArray(vector<int> rotateArray){
        int size = rotateArray.size();
        if(size == 0)
            return 0;
        int low = 0;
        int high = size - 1;
        int mid = 0;
        while(rotateArray[low] >= rotateArray[high]){
            if(high - low == 1){  // ����ָ�����ڣ�������ָ��
                mid = high;
                break;
            }
            mid = low + (high - low) / 2;
            // ���������rotateArray�����е�һ�������һ�����м�Ԫ��ȫ����ȣ��޷�ȷ����СԪ����ǰ��ĵ������黹���ں���ĵ���������
            // ֻ��ʹ��˳����ң����ֲ���ʧ��
            if(rotateArray[low] == rotateArray[high] && rotateArray[mid] == rotateArray[low])
                return MinInOrder(rotateArray, low, high);
            // �м�Ԫ��λ��ǰ��ĵ��������У���ʱ��СԪ���ں���
            if(rotateArray[mid] >= rotateArray[low])
                low = mid;
            else  // �м�Ԫ��λ�ں���ĵ��������У���ʱ��С��Ԫ����ǰ��
                high = mid;
        }
        return rotateArray[mid];
    }
private:  // ˳�������Сֵ
    int MinInOrder(vector<int> &num, int low, int high){
        int result = num[low];
        for(int i = low + 1; i<high;++i){
            if(num[i] < result)
                result = num[i];
        }
        return result;
    }
};