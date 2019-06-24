#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// �������������򣬺����ǰk����
class Solution1{
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k){
        vector<int> result;
        if(input.empty() || k > input.size()){
            return result;
        }
        sort(input.begin(), input.end());
        for(int i=0; i < k; ++i){
            result.push_back(input[i]);
        }
        return result;
    }
};

// �Ż�������ʹ�ö�����,�����ں�������
/*
���ȣ�����һ����СΪk�����������洢k����С������
Ȼ�����δ�����input�����ж�ȡһ���������������(���������е����ָ�������k��ʱ);��������Ѿ����ˣ����ܲ����µ����֣�ֻ�ܽ����滻���ֲ���
�����滻�������ҳ�k�������е����ֵ��Ȼ�������������ֽ��бȽϡ���������������С������ȥ�滻���ֵ�����������ֵ��
*/
class Solution2{
public:
    vector<int> GetNumbersLeast_Solution(vector<int> input, int k){
        vector<int> result;
        int length = result.size();
        if(length <= 0 || k > length || k <=0){
            return result;
        }
        for(int i = 0; i < length; ++i){
            if(result.size() < k){
                result.push_back(input[i]);
            }else{
                for(int j = k/2; j>=0; j--){
                    HeapAdjust(result, j, k);
                }
                for(int j = k-1; j>0; j--){
                    swap(result[0], result[j]);
                    HeapAdjust(result, 0, j);
                }
            }
        }
        return result;
    }
private:
    void HeapAdjust(vector<int> &input, int parent, int length){
        int temp = input[parent];  // ���ڵ��ֵ 
        int child = 2 * parent + 1;  // �������ĸ��ڵ�
        while(child < length){
            if(child+1 < length && input[child] < input[child+1]){
                child++;
            }
            if(temp >= input[child]){
                break;
            }
            input[parent] = input[child];
            parent = child;
            child = 2 * parent + 1;
        }
        input[parent] = temp;
    }
}