#include <iostream>

using namespace std;


class Solution{
public:
    bool match(char *str, char *pattern){
        // str:�ַ���  pattern:ģʽ��
        if(str == nullptr || pattern == nullptr)
            return false;
        return matchCore(str, pattern);
    }
private:
    bool matchCore(char *str, char *pattern){
        // �ַ�����ģʽ�������˽�β������true
        if(*str == '\0' && *pattern == '\0')
            return true;
        // �ַ���û�е���β������ģʽ�����˽�β���򷵻�false
        // �ַ������˽�β��ģʽ��û����β�������������жϣ���'*'���д���
        if(*str != '\0' && *pattern == '\0')
            return false;
        // ģʽ������һ���ַ���'*'�������״̬����ƥ��
        if(*(pattern+1) == '*'){
            // ����ַ�����ģʽ����ȣ�����ģʽ����'.',�����ַ���û�е�ĩβ�������ƥ��
            if(*str == *pattern || (*pattern == '.' && *str != '\0')){
                // ������һ���ַ���������һ���ַ��Ѿ�ƥ������
                return matchCore(str+1, pattern+2) || matchCore(str+1, pattern) || matchCore(str, pattern+2);
            }else{  // ����ַ�����ģʽ������ȣ�������ģʽ���ĵ�ǰ�ַ���'*'��������һ�ֵ�ƥ��
                return matchCore(str, pattern+2);
            }
        }
        // ����Ӵ�����ģʽ���ַ���ȣ�����ģʽ����'.',�����ַ���û�е���β�������ƥ����һ���ַ�
        if(*str == *pattern || (*pattern == '.' && *str != '\0')){
            return matchCore(str+1, pattern+1);
        }
        return false;
    }
};