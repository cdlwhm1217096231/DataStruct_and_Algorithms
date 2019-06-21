#include <iostream>
#include <vector>

using namespace std;

// ����һ�����飬���������ظ���Ԫ�أ��жϴ������Ƿ��Ƕ���������/�����������ĺ��������

class Solution{
public:
    bool VerifySequenceOfBST(vector<int> sequence){
        return bst(sequence, 0, sequence.size()-1);   // �õݹ�ķ��������ж����������Ƿ��Ƕ���������
    }

private:
    bool bst(vector<int> seq, int begin, int end){
        if(seq.empty() == 0 || begin > end){
            return false;
        }
        // seq:��ʾ��������飬begin�ĵ�һ��Ԫ�أ� end:��������һ��Ԫ�أ������Ǻ�����������Դ�Ԫ���Ƕ����������ĸ��ڵ�
        int root = seq[end];
        // �ڶ������������������е�Ԫ�أ���С�ڸ��ڵ�
        int i = begin;
        for(; i < end; ++i){
            if(seq[i] > root){
                break;
            }
        }
        // �ڶ������������������е�Ԫ�أ������ڸ��ڵ�
        for(int j = i; j < end; ++j){
            if(seq[j] < root){
                return false;
            }
        }

        // �ݹ�ķ������ж��������ǲ��Ƕ���������
        bool left = true;
        if(i > begin){
            left = bst(seq, begin, i-1);
        }

        // �ݹ�ķ������ж��������ǲ��Ƕ���������
        bool right = true;
        if(i < end-1){
            right = bst(seq, i, end-i);
        }
        return left && right;
    }
}