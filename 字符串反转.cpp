#include "iostream"
#include "cstring"
#include "malloc.h"

using namespace std;

int main()
{
    /*--------------------------------����1-----------------------------*/
    char *src = "hello,world"; // Դ��src
    cout << "Դ��src: " << src << endl;
    int len = strlen(src);
    char *dest = (char *)malloc(len + 1); // ΪĿ�괮dest�����ڴ�ռ䣬ע��Ҫ����\0
    char *d = dest;                       // ָ��Ŀ�괮��ָ����d
    char *s = &src[len - 1];              // ��ָ��sָ��Դ��src�е����һ���ַ�
    while (len-- != 0)
    {
        *d++ = *s--;
    }
    *d = 0; // ��Ŀ�괮dest��ĩβ����\0
    cout << "Ŀ�괮dest: " << dest << endl;
    free(dest); // �ͷ��ڴ棡
    /*------------------------------------------����2-------------------------------*/
    char str[] = "hello,world";
    cout << "Դ��src: " << str << endl;
    int len1 = strlen(str);
    char t;
    for (int i = 0; i < (len1 + 1) / 2; i++)  // ע��ѭ��������
    {
        t = str[i];
        str[i] = str[len1 - i - 1];
        str[len1 - i - 1] = t;
    }
    cout << "Ŀ�괮dest: " << str << endl;
    return 0;
}