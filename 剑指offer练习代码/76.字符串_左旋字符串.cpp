#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


class Solution{
public:
    string LeftRotateString(string str, int n){
        string result = str;
        int length = result.size();
        if(length < 0){
            return nullptr;
        }

        if(0 <= n <= length){
            // ��һ����
            int pFirstBegin = 0;
            int pFirstEnd = n-1;
            // �ڶ�����
            int pSecondBegin = n;
            int pSecondEnd = length - 1;
            // 1.��һ���ֺ͵ڶ����ַ�ת

            // ��һ���ַ�ת
            ReverseString(result, pFirstBegin, pFirstEnd);
            // �ڶ����ַ�ת
            ReverseString(result, pSecondBegin, pSecondEnd);
            // 2.�����ٷ�ת
            ReverseString(result, pFirstBegin, pSecondEnd);
        }
        return result;
    }
private:
    void ReverseString(string& str, int begin, int end){
        while(begin < end){
            swap(str[begin++], str[end--]);
        }
    }
};
