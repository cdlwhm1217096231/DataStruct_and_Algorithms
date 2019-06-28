#include <iostream>
#include <string>

using namespace std;

class Solution{
public:
// ��̬�滮����
    int LongestSubString(const string& str){
        int curLength = 0;  // �ַ����е�һ���ַ���������0
        int maxLength = 0;
        int* position = new int[26];
        // һά�����ʼ��
        for(int i=0; i < 26; ++i){
            position[i] = -1;
        }


        for(int i=0; i < str.length(); ++i){
            int prevIndex = position[str[i] - 'a']; 
            // ���1����i���ַ�֮ǰ���ֹ�
            // ��i���ַ�������һ�γ��ֵ�λ��prevIndex�ľ���d����f(i-1),��f(i) = f(i-1) + 1
            if(prevIndex < 0 || i - prevIndex > curLength){  
                ++curLength; // f(i) = f(i-1)+1
            }else{ // ��i���ַ�������һ�γ��ֵ�λ��prevIndex�ľ���dС�ڻ����f(i-1)����f(i)=d
                if(curLength > maxLength)
                    maxLength = curLength;
                curLength = i - prevIndex;  // curLength�൱��f(i)��ʾ�Ե�i���ַ�Ϊ��β�Ĳ����ظ��ַ������ַ�����󳤶�
            }
            position[str[i] - 'a'] = i;
        }

        // ���2����i���ַ�֮ǰû�г��ֹ�����f(i) = f(i-1) + 1
        if(curLength > maxLength){
            maxLength = curLength;
        }

        // �ͷ��ڴ棡
        delete[] position;
        return maxLength; 
    }
};