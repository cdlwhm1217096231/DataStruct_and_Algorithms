#include <iostream>

using namespace std;

// Ҫ�󣺽��ַ����еĿո�ȫ���滻��%20
class Solution{
    public:
        void replaceSpace(char *str, int len){
            if(str == nullptr || len <= 0)
                return;
            int original_len = 0;  // ԭʼ�ַ����ĳ���
            int number_blank = 0;  // ԭʼ�ַ����еĿո���Ŀ
            int i=0;
            while(str[i] != '\0'){  // �����ַ���
                ++original_len;  // ͳ��ԭʼ�ַ�������
                if(str[i] == ' ')
                    ++number_blank;   // ͳ�ƿո����Ŀ
                ++i;
            }  
            
            int new_len = original_len + 2 * number_blank;  // �滻�ո�Ϊ20%����ַ�������
            if(new_len > len){
                return;
            }

            int original_index = original_len;  // ԭʼ�ַ������һ���ַ�������
            int new_index = new_len;  // �滻����ַ������һ���ַ�������
            while(original_index >= 0 && new_index > original_index){
                // index_originalָ�뿪ʼ��ǰ�ƶ�����������ո��滻��'%20'����������ƶ�����
                if(str[original_index] == ' '){  
                    str[new_index--] = '0';
                    str[new_index--] = '2';
                    str[new_index--] = '%';
                }else{
                    str[new_index--] = str[original_index];
                }
                --original_index;
            }
        }
};


