#include <iostream>
#include <vector>

using namespace std;

// ��������� = ��������е��������Ŀ + �ұ������е��������Ŀ + ���Һϳ��µ�����ʱ���ֵ��������Ŀ

// ʹ�ù鲢�����˼�룡����
class Solution{
public:
    int InversePairs(vector<int> data){
        if(data.size() == 0){
            return 0;
        }
        // ����ĸ�������
        vector<int> copy;
        for(int i=0; i<data.size(); ++i){
            copy.push_back(data[i]);
        }
        return InversePairsCore(data, copy, 0, data.size()-1) % 1000000007;
    }

    long InversePairsCore(vector<int>& data, vector<int>& copy, int left, int right){
        // ���ָ����ͬλ�ã�û�������
        if(left == right){
            copy[left] = copy[right];
            return 0;
        }
        // �󻮷��е㴦��λ��
        int mid = (left + right) >> 1;
        // ʹ������������򣬲����������������Ե���Ŀ
        long leftCount = InversePairsCore(copy, data, left, mid);
        // ʹ���ұ��������򣬲������ұ���������Ե���Ŀ
        long rightCount = InversePairsCore(copy, data, mid+1, right);
        
        int i = mid;  // i��ʼ��Ϊǰ������һ�����ֵ��±�
        int j = right;  // j��ʼ��Ϊ�������һ�����ֵ��±�
        int indexCopy = right;   // ������������һ�����ֵ��±�
        long count = 0;  // ��������Եĸ�����ע������

        while(i >= left && j >= mid+1){
            if(data[i] > data[j]){
                copy[indexCopy--] = data[i--];
                count += j - mid;
            }else{
                copy[indexCopy--] = data[j--];
            }
        }

        for(; i >= left; --i){
            copy[indexCopy--] = data[i];
        }

        for(; j >= mid+1; --j){
            copy[indexCopy--] = data[j];
        }
        return leftCount + rightCount + count;
    }
};