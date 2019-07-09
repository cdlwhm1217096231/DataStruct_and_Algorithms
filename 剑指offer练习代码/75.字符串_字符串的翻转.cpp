#include "iostream"
#include "cstring"
#include "malloc.h"

using namespace std;

int main()
{
    /*------------------------------------------方法1-------------------------------*/
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