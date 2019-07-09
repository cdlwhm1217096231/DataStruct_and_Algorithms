#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution{
public:
    string ReverseSentence(string str){
        string result = str;
        int length = str.size();
        if(length == 0){
            return "";
        }

        // ����һ���ո���Ϊ��ת��־λ
        result += ' ';
        int mark = 0;
        // ���ݿո���һ��תÿ������
        for(int i=0; i < length+1; i++){
            if(result[i] == ' '){
                Reverse(result, mark, i-1);
                mark = i + 1;
            }
        }
        // ȥ����ӵĿո�
        result = result.substr(0, length);  // ����[0,0+length)��Χ�ڵ��Ӵ�
        // 2.���巭ת
        Reverse(result, 0, length-1);
        return result;
    }
private:
    // 1.��ת��������
    void Reverse(string& str, int begin, int end){
        while(begin < end){
            swap(str[begin++], str[end--]);
        }
    }
};