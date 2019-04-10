#include "iostream"
#include "cstring"

using namespace std;

// 模式串向右移动距离的计算即指针j回溯的距离：当某个字符匹配失败后，j指针回溯的位置！

void Next(char *t, int *next)
{
    int i = 1;
    next[1] = 0; // next的数组是从下标为1开始存储元素的，next[0]一般用来存储数组的长度
    int j = 0;
    while (i < strlen(t))
    {
        if (j == 0 || t[i - 1] == t[j - 1])
        { // 模式串的存储是从数组下标0开始的，所以是t[i-1] = t[j-1]
            i++;
            j++;
            next[i] = j;  // j==0成立后，if里面的语句必须执行一次，故next[2] = 1;
        }
        else
        {
            j = next[j]; // 模式串与主串s匹配失败后，模式串t中的指针j回溯的位置
        }
    }
}

// KMP算法
int KMP(char *s, char *t)
{
    int next[10];  // next数组从下标为1开始存储元素，元素的值是当模式串失配时，指针j回溯的位置
    Next(t, next); // 根据模式串t，初始化next的数组
    int i = 1;
    int j = 1;
    while (i <= strlen(s) && j <= strlen(t))
    {
        if (j == 0 || s[i - 1] == t[j - 1])
        {        // j==0:代表模式串t的第一个字符就和指针i指向的字符不相等；
            i++; // s[i-1]==s[j-1],如果对应位置字符相等，两种情况下，指向当前测试的两个指针下标i和j都向后移
            j++;
        }
        else
        {
            j = next[j]; // 如果测试的两个字符不相等，i不动，j变为当前测试字符串的next值
        }
    }
    if (j > strlen(t)) // 如果条件为真，说明匹配成功
        return i - (int)strlen(t);
    else // 完全没有匹配上
        return -1;
}

// 升级版的next
void Next1(char *t, int *next)
{
    int i = 1;
    next[1] = 0;
    int j = 0;
    while (i < strlen(t))
    {
        if (j == 0 || t[i - 1] == t[j - 1])
        {
            i++;
            j++;
            if (t[i - 1] != t[j - 1])
            {
                next[i] = j;
            }
            else
            {
                next[i] = next[j];
            }
        }
        else
        {
            j = next[j];
        }
    }
}

int main()
{
    int i = 0;
    i = KMP("ababcabcacbab", "abcac");
    cout << "子串T在主串S中的位置:" << i << endl;
    return 0;
}