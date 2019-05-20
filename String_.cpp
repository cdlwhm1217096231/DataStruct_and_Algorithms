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

#define MAXSIZE 40 /* �洢�ռ��ʼ������ */

typedef int Status;   /* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
typedef int ElemType; /* ElemType���͸���ʵ������������������Ϊint */

typedef char String[MAXSIZE + 1]; /*  0�ŵ�Ԫ��Ŵ��ĳ��� */

// ����һ������ΪT��chars
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

// �ɴ�S���Ƶ���T
Status StrCopy(String S, String T)
{
    for (int i = 0; i <= S[0]; i++)
        T[i] = S[i];
    return OK;
}

// ���S�Ƿ��ǿմ�
Status StrEmpty(String S)
{
    if (S[0] == 0)
        return TRUE;
    else
        return FALSE;
}

// �Ƚϴ�S��T����S>T,�򷵻�ֵ>0;��S=T,�򷵻�ֵ=0;��S<T,�򷵻�ֵ<0
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

// �����ַ������е��ַ�����
int StrLength(String S)
{
    int len;
    len = S[0];
    return len;
}

// ����ַ���S
Status StrClear(String S)
{
    S[0] == 0;
    return OK;
}

// ��T����S1��S2���Ӷ��ɵ��´�����δ�ضϣ��򷵻�TRUE������FALSE
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

// ��Sub���ش�S�ĵ�pos���ַ��𳤶�Ϊlen���Ӵ�
Status StrSub(String Sub, String S, int pos, int len){
    if(pos < 1 || pos > S[0] || len < 0 || len > S[0]-pos+1)
        return ERROR;
    for(int i = 1; i<=S[0];i++)
        Sub[i] = S[pos-i+1];
    Sub[0] = len;
    return OK;
}

// �����Ӵ�T������S�е�pos���ַ�֮���λ�á���������,��������ֵΪ0
Status Index(String S, String T, int pos){
    int i = pos;  // i���ڱ�ʾ����S�е�ǰλ���±�ֵ����pos��Ϊ1�����posλ�ÿ�ʼƥ��
    int j = 1;   // j���ڱ�ʾ�Ӵ�T�е�ǰλ���±�ֵ
    while(i<=S[0] && j<=T[0]){  // ��iС��S�ĳ��Ȳ���jС��T�ĳ���ʱ��ѭ������
        if (S[i] == T[j]){   // ����ĸ��������
            ++i;
            ++j;
        }else{   // ָ��������¿�ʼƥ��, i�˻ص��ϴ�ƥ����λ����һλ
           i = i+j-2;         // j�˻ص��Ӵ�T����λ
           j = 1;
        }
    }
    if (j > T[0]) 
		return i-T[0];
	else 
		return 0;
}

// TΪ�ǿմ���������S�е�pos���ַ�֮�������T��ȵ��Ӵ����򷵻ص�һ���������Ӵ���S�е�λ�ã����򷵻�0
