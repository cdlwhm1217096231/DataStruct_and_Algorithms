#include "iostream"
#include "cstring"

using namespace std;

// ģʽ�������ƶ�����ļ��㼴ָ��j���ݵľ��룺��ĳ���ַ�ƥ��ʧ�ܺ�jָ����ݵ�λ�ã�

void Next(char *t, int *next)
{
    int i = 1;
    next[1] = 0; // next�������Ǵ��±�Ϊ1��ʼ�洢Ԫ�صģ�next[0]һ�������洢����ĳ���
    int j = 0;
    while (i < strlen(t))
    {
        if (j == 0 || t[i - 1] == t[j - 1])
        { // ģʽ���Ĵ洢�Ǵ������±�0��ʼ�ģ�������t[i-1] = t[j-1]
            i++;
            j++;
            next[i] = j;  // j==0������if�����������ִ��һ�Σ���next[2] = 1;
        }
        else
        {
            j = next[j]; // ģʽ��������sƥ��ʧ�ܺ�ģʽ��t�е�ָ��j���ݵ�λ��
        }
    }
}

// KMP�㷨
int KMP(char *s, char *t)
{
    int next[10];  // next������±�Ϊ1��ʼ�洢Ԫ�أ�Ԫ�ص�ֵ�ǵ�ģʽ��ʧ��ʱ��ָ��j���ݵ�λ��
    Next(t, next); // ����ģʽ��t����ʼ��next������
    int i = 1;
    int j = 1;
    while (i <= strlen(s) && j <= strlen(t))
    {
        if (j == 0 || s[i - 1] == t[j - 1])
        {        // j==0:����ģʽ��t�ĵ�һ���ַ��ͺ�ָ��iָ����ַ�����ȣ�
            i++; // s[i-1]==s[j-1],�����Ӧλ���ַ���ȣ���������£�ָ��ǰ���Ե�����ָ���±�i��j�������
            j++;
        }
        else
        {
            j = next[j]; // ������Ե������ַ�����ȣ�i������j��Ϊ��ǰ�����ַ�����nextֵ
        }
    }
    if (j > strlen(t)) // �������Ϊ�棬˵��ƥ��ɹ�
        return i - (int)strlen(t);
    else // ��ȫû��ƥ����
        return -1;
}

// �������next
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
    cout << "�Ӵ�T������S�е�λ��:" << i << endl;
    return 0;
}