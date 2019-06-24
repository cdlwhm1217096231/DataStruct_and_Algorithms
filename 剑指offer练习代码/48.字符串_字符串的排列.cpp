#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;


class Solution{
public:
    vector<string> Permutation(string str){
    // �ж�����
        if(str.length() == 0){
            return result;
        }
        PermutationCore(str, 0);
        // �Խ����������
        sort(result.begin(), result.end());
        return result;
    }

private:
    void PermutationCore(string str, int begin){
        // �ݹ��������������һλ�����һλ�������
        if(begin == str.length()){
            result.push_back(str);
            return;
        }
        for(int i = begin; i < str.length(); ++i){
            // ����ַ�����ͬ���򲻽���
            if(i != begin && str[i] == str[begin]){
                continue;
            }
            // λ�ý���
            swap(str[begin], str[i]);
            // �ݹ���ã�ǰbegin+1��λ�ò��䣬������ַ���ȫ����
            PermutationCore(str, begin+1);
        }
    }
    vector<string> result;
    
};