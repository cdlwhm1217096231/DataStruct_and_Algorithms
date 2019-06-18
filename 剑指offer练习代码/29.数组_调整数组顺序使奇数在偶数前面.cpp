#include <iostream>
#include <vector>
#include <deque>

using namespace std;

// ʹ��˫�����deque���������飬������ǰ����룬ż���ں������

class Solution{
public:
    void reOrderArray(vector<int> &array){
        deque<int> result;
        int num = array.size();
        for(int i =0; i < num; ++i){
            if(array[num-i-1] % 2 == 1)
                result.push_front(array[num-i-1]);
            if(array[i] % 2 == 0)
                result.push_back(array[i]);
        }
        array.assign(result.begin(), result.end());  // ���ʹ��assign����ʵ�ֲ�ͬ���������ݵ����͸�ֵ��
    }

};


// ����2��ʹ��ָ��
void ReOrderOddEven(int *pData, unsigned int length){
    if(pData == nullptr || length == 0)
        return;
    int *pBegin = pData;
    int *pEnd = pData + length - 1;
    while(pBegin < pEnd){
        while(pBegin < pEnd && (*pBegin & 0x1) != 0){  // *pBegin��ʱ�������������н�������������ƶ�һ��λ��
            pBegin++;
        }
        while(pBegin < pEnd && (*pEnd & 0x1) == 0){   // *pEnd��ʱ��ż���������н�����������ǰ�ƶ�һ��λ��
            pEnd--;
        }
        if(pBegin < pEnd){  // ��ʼ������ʱ�䣺pBegin��ʱָ��ż����pEnd��ʱָ������
            int temp = *pBegin;
            *pBegin = *pEnd;
            *pEnd = temp;
        }
    }
}