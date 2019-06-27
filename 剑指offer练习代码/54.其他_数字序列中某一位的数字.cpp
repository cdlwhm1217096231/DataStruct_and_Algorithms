#include <iostream>
#include <string>
#include <cmath>


using namespace std;

// ���������е�ĳһλ�������ǣ�

/*
    01234567891011121314151617.....
    һλ����10����ռ��10��λ�ã�0-9���
    ��λ����90����ռ��180��λ�ã�10-99���
    ��λ����900����ռ��2700��λ�ã�100-999���
*/

class Solution{
public:
    int digitAtIndex(int index){  // index����Ҫ������������е�ĳһλ������������������������е�1001λ��ʲô���֣���index=1001
        if(index < 0) 
            return -1;

        int digits = 1;
        while(true){
            int numbers = countOfIntegers(digits);  // ֪��ĳ��������digitsλ����digitsλ�ܹ��ж��ٸ�����
            if(index < numbers*digits){  // numbers*digits:��ʾ������digitsλ��������ռ�õ��ܵ�λ����������90����λ����ռ��180��λ��
                return digitAtIndexCore(index, digits); // �ҵ�index=1001λ����λ����ռ��λ���У���Ϊ��λ����900������ռ��λ��2700��
            }
            index -= digits * numbers;
            digits++;
        }
        return -1;
    }
    // ͳ��digitsλ�������ܹ��ж��ٸ�
    int countOfIntegers(int digits){
        if(digits == 1){
            return 10;
        }
        int count = (int)pow(10, digits-1);
        return 9 * count;
    }

    // �Ѿ�֪��1001λ����λ��digitsλ�����к�����ĺ��������ҳ�index=1001����Ӧ������
    int digitAtIndexCore(int index, int digits){
        int number = beginNumber(digits) + index / digits;  // �ҳ��Ǹ�����number�ˣ�
        int indexFromRight = digits - index % digits;  
        for(int i=1; i < indexFromRight; ++i){
            number /= 10;
        }
        return number % 10;
    }

    // �ҳ�digitsλ���ĵ�һ�����֣������ҳ���һ����λ����10����һ����λ����100
    int beginNumber(int digits){
        if(digits == 1){ // ��һ��һλ����0
            return 0;
        }
        return (int)pow(10, digits-1);
    }
};