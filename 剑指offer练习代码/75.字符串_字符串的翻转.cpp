#include "iostream"
#include "cstring"
#include "malloc.h"

using namespace std;

int main()
{
    /*------------------------------------------����1-------------------------------*/
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