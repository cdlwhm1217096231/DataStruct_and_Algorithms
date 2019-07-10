#include <iostream>
#include <string>

using namespace std;

// Ŀ�꣺����Ϸ�ֵʱ�����Ϊ���������Ϸ�����ʱ������0

/*
1.ָ���Ƿ�Ϊ��ָ���Լ��ַ����Ƿ�Ϊ���ַ���
2.�ַ������������ŵĴ���
3.����ֵ�Ƿ�Ϊ�Ϸ�ֵ����С�ڵ���'9'�����ڵ���'0'
4.intΪ32λ����Ҫ�ж��Ƿ����
5.ʹ�ô����־�����ֺϷ�ֵ0�ͷǷ�ֵ0

*/

class Solution{
public:
    enum Status{KValid=0, KInValid};
    int g_nstatus = KValid;

    int StrToInt(string str){
        long long num = 0;
        const char* cstr = str.c_str();
        // �ж��Ƿ�Ϊָ����Ƿ��ǿ��ַ���
        if(cstr != nullptr && *cstr != '\0'){
            // �����ű�־λ��Ĭ���ǼӺ�
            bool minus = false;
            if(*cstr == '+'){
                cstr++;
            }
            else if(*cstr == '-'){
                minus = true;
                cstr++;
            }

            if(*cstr != '\0'){
                num = StrToIntCore(cstr, minus);
            }
        }
        return (int) num;
    }

private:
    long long StrToIntCore(const char* cstr, bool minus){
        long long num=0;
        while(*cstr != '\0'){
            // �ж��Ƿ��ǷǷ�ֵ
            if(*cstr >= '0' && *cstr <= '9'){
                int flag = minus ? -1:1;
                num = num * 10 + flag * (*cstr - '0');
                // �ж��Ƿ����32λ
                if((!minus && num > 0x7fffffff) || (minus && num < (signed int)0x80000000)){
                    num = 0;
                    break;
                }
                cstr++;
            }
            else{
                num = 0;
                break;
            }
        }
        // �ж��Ƿ���������
        if(*cstr == '\0'){
            g_nstatus = KValid;
        }
        return num;
    }
};