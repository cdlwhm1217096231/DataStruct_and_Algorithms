#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ����  |   ��С��

class Solution{
public:
    void Insert(int num){
        // ��������ܸ�����ż�������µ����ݲ��뵽��С����
        if(((max.size() + min.size()) & 1) == 0){
            // ����²��������С�������е����ֵ����ֱ�Ӳ��������С�Ȼ�������е����ֵ���뵽��С���С�������֤����С���е�����ʼ���Ǵ��������е�����
            if(max.size() > 0 && num < max[0]){
                // ���µ����ݲ��뵽������
                max.push_back(num);
                // ��������
                push_heap(max.begin(), max.end(), less<int>());
                // �ó������е����ֵ
                num = max[0];
                // ɾ�������еĶѶ�Ԫ��
                pop_heap(max.begin(), max.end(), less<int>());
                max.pop_back();
            }
            // �����ݲ��뵽��С����
            min.push_back(num);
            // ������С��
            push_heap(min.begin(), min.end(), greater<int>());
        }
        // ����������������������µ����ݲ��뵽������
        else{
            if(min.size() > 0 && num > min[0]){
                // �����ݲ��뵽��С����
                min.push_back(num);
                // ������С��
                push_heap(min.begin(), min.end(), greater<int>());
                // �ó���С���е���Сֵ
                num = min[0];
                // ɾ����С���еĶѶ�Ԫ��
                pop_heap(min.begin(), min.end(), greater<int>());
                min.pop_back();
            }
            // �����ݲ��뵽������
            max.push_back(num);
            push_heap(max.begin(), max.end(), less<int>());
        }
    }

    double GetMedian(){
        // ͳ�����ݴ�С
        int size = min.size() + max.size();
        if(size == 0){
            return 0;
        }
        // ���������ż��
        if((size & 1) == 0){
            return (min[0] + max[0]) / 2.0;
        }else{  // ����
            return min[0];
        }

    }


private:
// ʹ��vector������С��min������max����
    vector<int> min;
    vector<int> max;
};