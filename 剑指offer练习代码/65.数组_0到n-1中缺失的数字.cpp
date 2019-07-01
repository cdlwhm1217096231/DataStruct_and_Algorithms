#include <iostream>  


using namespace std;

class Solution{
public:
    int GetMissingNumber(const int *data, int length){
        if(data == nullptr || length <=0){
            return -1;
        }
        int left = 0;
        int right = length - 1;
        while(left <= right){
            int midIndex = (left + right) >> 1;
            if(data[midIndex] != midIndex){  // �м�Ԫ�ص�ֵ�������±��ֵ
                if(midIndex == 0 || data[midIndex - 1] == midIndex - 1){  // �м�Ԫ�ص�ֵ�������±��ֵ,��������ǰһ��Ԫ�غ������±���ȣ����м�Ԫ�������ǵ�һ��ֵ���±겻��ȵ�Ԫ��
                    return midIndex;
                }else{  // �м�Ԫ�ص�ֵ�������±��ֵ,��������ǰһ��Ԫ�غ������±겻��ȣ�����һ�ֲ�����������
                    right = midIndex - 1;
                }
            }else{  // �м�Ԫ�ص�ֵ�����±��ֵ����һ�ֲ����Ұ������
                left = midIndex + 1;
            }
        }

        if(left == length){
            return length;
        }
        
        return -1;
    }
};