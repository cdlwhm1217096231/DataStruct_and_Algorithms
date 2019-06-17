#include <iostream>

using namespace std;

/*

�ж����ַ�����ʾ�������Ƿ��Ƿ��ϱ�׼��ʽ�ĸ��������ͣ�
*/

class Solution{
public:
    // �������ı�ʾ�����������֣�С�����֣�ָ��������ɡ��������ֿ�����0-9��+��-
    // С������0-9����.��ô�ָ���ţ�ָ��������e\E��Ϊ��־�������0-9
    bool isNumberic(char *string){
        if(string == nullptr || *string == '\0')
            return 0;
        // �������ж�
        if(*string == '+' || *string == '-')
            ++string;
        bool numberic = true;
        scanDigits(&string);   // �˴�������ǵ�ַ��˵���β���һ������ָ�룡
        if(*string != '\0'){
            // С���ж�
            if(*string == '.'){
                ++string;
                scanDigits(&string);
                if(*string == 'e' || *string == 'E'){
                    numberic = isExponential(&string);
                }
            }
            // �����ж�
           else if(*string == 'e' || *string == 'E'){
               numberic = isExponential(&string);
           }
            else{
                numberic = false;
            }
        }
        return numberic && *string == '\0';
    }
private:
    // ɨ������,���ںϷ����֣�ֱ������
    void scanDigits(char **string){
        while(**string != '\0' && **string >= '0' && **string <= '9'){
            ++(*string);   // string�Ƕ���ָ�룬*string��һ��ָ�룬**string���ַ�����
        }
    }
    // �ÿ�ѧ��������ʾ����ֵ�Ƿ�Ϸ�
    bool isExponential(char **string){
        ++(*string);
        if(**string == '+' || **string == '-')
            ++(*string);
        if(**string == '\0')
            return false;
        scanDigits(string);
        // �ж��Ƿ��β��û�н�β��˵�����������Ƿ��ַ�
        return (**string == '\0') ? true:false;
    }
};