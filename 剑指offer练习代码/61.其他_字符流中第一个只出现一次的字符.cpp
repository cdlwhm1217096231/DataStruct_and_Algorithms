#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution{
public:
    // ���ַ����в���һ���ַ�
    void Insert(char ch){
        s += ch;
        count[ch]++;
    }
    // �����ַ����е�һ��ֻ����һ�ε��ַ���λ��
    char FirstChar(){
        int len = s.size();
        for(int i=0; i < len; ++i){
            if(count[s[i]] == 1){
                return s[i];
            }
        }
        return '#';  // �����ǰ�ַ���û�д��ڳ���һ�ε��ַ�������#�ַ�
    }


private:
    string s;
    int count[256] = {0};  // ����ĳ�ʼ����Ȼ��ӳ���һ����ϣ��
};