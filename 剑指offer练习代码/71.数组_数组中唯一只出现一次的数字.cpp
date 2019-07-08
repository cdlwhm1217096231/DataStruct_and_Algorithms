#include <iostream>

using namespace std;

// ˼·
/*
�����������ǳ�һ������ֻ����һ���⣬�������ֶ�����3��
���һ�����ֳ��������������Ķ����Ʊ�ʾ�У�0��1Ҳ�����3�Ρ����ԣ������г������ε����ֵĶ����Ʊ�ʾ��ÿһλ������������
ÿһλ�ĺͶ��ܱ�3���������һ������ֻ����һ�Σ����ܱ�3��������һλһ����0��������1
*/

class Solution{
public:
    int FindNumsAppearingOnce(int numbers[], int length){
        if(numbers == nullptr || length <= 0){
            return -1;
        }
        // ����һ�������������Ԫ�ظ�λ�ϵ�ֵ�ĺ�
        int bitSum[32] = {0};
        for(int i=0; i < length; ++i){
            int bitMask = 1;  // λ����
            for(int j=31; j>=0; j--){
                int bit = numbers[i] & bitMask;
                if(bit != 0){
                    bitSum[j] += 1;
                }
                bitMask = bitMask << 1;
            }
        }

        // �������Ԫ�ظ�λ�ϵĺͳ���3����¼���ܱ�3����������ֻ����һ�ε���
        int result = 0;
        for(int k=0; k <32; k++){
            result = result << 1;
            result += bitSum[k] % 3;
        }
        return result;
    }
};