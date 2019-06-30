#include <iostream>
#include <string>
#include <map>

using namespace std;


// ����һ��hash����һ��ɨ��ʱͳ��ÿ���ַ��ĳ��ִ������ڶ���ɨ��ʱ��������ַ��ĳ��ִ���Ϊ1���򷵻�����ַ���λ�á�

class Solution{
public:
    int FirstNoRepeatChar(string str){
        int len = str.length();
        if (len == 0){
            return -1;
        }
        map<char, int> item;

        
        for(int i=0; i < len; ++i){
            item[str[i]]++;
        }

        for(int i=0; i < len; ++i){
            if(item[str[i]] == 1){
                return i;
            }
        }
        return -1;
    }
};