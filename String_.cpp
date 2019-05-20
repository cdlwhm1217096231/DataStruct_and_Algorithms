#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "io.h"
#include "math.h"
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 40 /* 存储空间初始分配量 */

typedef int Status;   /* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int ElemType; /* ElemType类型根据实际情况而定，这里假设为int */

typedef char String[MAXSIZE + 1]; /*  0号单元存放串的长度 */

// 生成一个长度为T的chars
Status StrAssign(char *chars, String T)
{
    if (strlen(chars) > MAXSIZE)
        return ERROR;
    else
    {
        T[0] = strlen(chars);
        for (int i = 1; i <= T[0]; i++)
        {
            T[i] = *(chars + i - 1);
        }
        return OK;
    }
}

// 由串S复制到串T
Status StrCopy(String S, String T)
{
    for (int i = 0; i <= S[0]; i++)
        T[i] = S[i];
    return OK;
}

// 检测S是否是空串
Status StrEmpty(String S)
{
    if (S[0] == 0)
        return TRUE;
    else
        return FALSE;
}

// 比较串S和T，若S>T,则返回值>0;若S=T,则返回值=0;若S<T,则返回值<0
Status StrCamp(String S, String T)
{
    for (int i = 1; i <= S[0] && i <= T[0]; i++)
    {
        if (S[i] != T[i])
            return S[i] - T[i];
        else
            return S[0] - T[0];
    }
}

// 返回字符串含有的字符个数
int StrLength(String S)
{
    int len;
    len = S[0];
    return len;
}

// 清空字符串S
Status StrClear(String S)
{
    S[0] == 0;
    return OK;
}

// 用T返回S1和S2联接而成的新串。若未截断，则返回TRUE，否则FALSE
Status StringCat(String S1, String S2, String T)
{
    if (S1[0] + S2[0] <= MAXSIZE)
    {
        for (int i = 1; i <= S1[0]; i++)
            T[i] = S1[i];
        for (int i = 1; i <= S2[0]; i++)
            T[S1[0] + i] = S2[i];
        return TRUE;
    }
    else
    {
        for (int i = 1; i <= S1[0]; i++)
            T[i] = S1[i];
        for (int i = 1; i <= S2[0]; i++)
             T[S1[0] + i] = S2[i];
        T[0] = MAXSIZE;
        return FALSE;
    }
}

// 用Sub返回串S的第pos个字符起长度为len的子串
Status StrSub(String Sub, String S, int pos, int len){
    if(pos < 1 || pos > S[0] || len < 0 || len > S[0]-pos+1)
        return ERROR;
    for(int i = 1; i<=S[0];i++)
        Sub[i] = S[pos-i+1];
    Sub[0] = len;
    return OK;
}

// 返回子串T在主串S中第pos个字符之后的位置。若不存在,则函数返回值为0
Status Index(String S, String T, int pos){
    int i = pos;  // i用于表示主串S中当前位置下标值，若pos不为1，则从pos位置开始匹配
    int j = 1;   // j用于表示子串T中当前位置下标值
    while(i<=S[0] && j<=T[0]){  // 若i小于S的长度并且j小于T的长度时，循环继续
        if (S[i] == T[j]){   // 两字母相等则继续
            ++i;
            ++j;
        }else{   // 指针后退重新开始匹配, i退回到上次匹配首位的下一位
           i = i+j-2;         // j退回到子串T的首位
           j = 1;
        }
    }
    if (j > T[0]) 
		return i-T[0];
	else 
		return 0;
}

// T为非空串。若主串S中第pos个字符之后存在与T相等的子串，则返回第一个这样的子串在S中的位置，否则返回0
