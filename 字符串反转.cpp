#include "iostream"
#include "cstring"
#include "malloc.h"

using namespace std;

int main()
{
    /*--------------------------------方法1-----------------------------*/
    char *src = "hello,world"; // 源串src
    cout << "源串src: " << src << endl;
    int len = strlen(src);
    char *dest = (char *)malloc(len + 1); // 为目标串dest分配内存空间，注意要加上\0
    char *d = dest;                       // 指向目标串的指针是d
    char *s = &src[len - 1];              // 将指针s指向源串src中的最后一个字符
    while (len-- != 0)
    {
        *d++ = *s--;
    }
    *d = 0; // 将目标串dest的末尾加上\0
    cout << "目标串dest: " << dest << endl;
    free(dest); // 释放内存！
    /*------------------------------------------方法2-------------------------------*/
    char str[] = "hello,world";
    cout << "源串src: " << str << endl;
    int len1 = strlen(str);
    char t;
    for (int i = 0; i < (len1 + 1) / 2; i++)  // 注意循环的条件
    {
        t = str[i];
        str[i] = str[len1 - i - 1];
        str[len1 - i - 1] = t;
    }
    cout << "目标串dest: " << str << endl;
    return 0;
}