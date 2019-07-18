#include <iostream>

using namespace std;

// 要求：将字符串中的空格全部替换成%20
class Solution{
    public:
        void replaceSpace(char *str, int len){
            if(str == nullptr || len <= 0)
                return;
            int original_len = 0;  // 原始字符串的长度
            int number_blank = 0;  // 原始字符串中的空格数目
            int i=0;
            while(str[i] != '\0'){  // 遍历字符串
                ++original_len;  // 统计原始字符串长度
                if(str[i] == ' ')
                    ++number_blank;   // 统计空格的数目
                ++i;
            }  
            
            int new_len = original_len + 2 * number_blank;  // 替换空格为20%后的字符串长度
            if(new_len > len){
                return;
            }

            int original_index = original_len;  // 原始字符串最后一个字符的索引
            int new_index = new_len;  // 替换后的字符串最后一个字符的索引
            while(original_index >= 0 && new_index > original_index){
                // index_original指针开始向前移动，如果遇到空格，替换成'%20'，否则进行移动操作
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


