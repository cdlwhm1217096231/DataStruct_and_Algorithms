#include "iostream"
#include "cstdlib"
#include "cstdio"
#include "cstring"
#include "malloc.h"

using namespace std;

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 100

typedef int Status;

// �������������
int index = 1;
typedef char String[24]; // 0��������λ�ô洢���Ǵ��ĳ��ȣ���һ�������������Զ������
String str;              // �ȼ��� char str[24];

Status strAssign(String T, char *chars)
{ // String T �ȼ��� char T[24];
    int i;
    if (strlen(chars) > MAXSIZE)
        return ERROR;
    else
    {
        T[0] = strlen(chars);
        for (i = 1; i <= T[0]; i++)
            T[i] = *(chars + i - 1);
        return OK;
    }
}

typedef char ElemType;
ElemType nil = ' '; // �ַ����Կո�Ϊ��

Status visit(ElemType e)
{
    cout << "e:" << e << " ";
    return OK;
}

// ����������еĽڵ�
typedef struct BiNode
{
    ElemType data;
    struct BiNode *lchild, *rchild; // �ȼ��� BiNode *lchild, *rchild;
} BiNode, *BiTree;                  // BiTree��ָ��ṹ���ָ��
/*
typedef struct Binode{
    ���;
}BiNode   

struct Binode node;  // �ȼ��� BiNode node;
typede struct BiNode{
    ���;
}*BiTree;    

struct BiNode *p;   // �ȼ��� BiTree p;   
*/

// ����ն�����
Status initBiTree(BiTree *T)
{
    *T = NULL;
    return OK;
} // BiTree *T�ȼ��� struct BiNode **T;  ָ��ṹ��BiNode���͵�ָ��*T��ָ��T

// ���������T���ڣ����ٶ�����T
void destoryBiTree(BiTree *T)
{
    if (*T)
    {
        if ((*T)->lchild) // ������
            destoryBiTree(&(*T)->lchild);
        if ((*T)->rchild) // ���Һ���
            destoryBiTree(&(*T)->rchild);
        free(*T);  // �ͷŸ����
        *T = NULL; // ��ָ�븳0
    }
}

// ��ǰ������������н���ֵ(һ���ַ�),#��ʾ�������ö��������ʾ������T
void createBiTree(BiTree *T)
{
    ElemType ch;
    ch = str[index++]; // char str[24]
    if (ch == '#')
        *T = NULL;
    else
    {
        *T = (BiTree)malloc(sizeof(BiNode));
        if (!*T)
            exit(-1);
        (*T)->data = ch;             // ���ɸ����
        createBiTree(&(*T)->lchild); // ����������
        createBiTree(&(*T)->rchild); // ����������
    }
}

// �ж϶������Ƿ��ǿ���,�ǿ�������TRUE
Status BiTreeEmpty(BiTree T)
{ // struct BiNode * �ȼ���BiTree,���� BiTree T�ȼ��� struct BiNode *T;
    if (T)
        return FALSE;
    else
        return TRUE;
}

// ��ն�����
#define clearBiTree destoryBiTree

// ���ض����������T
int BiTreeDepth(BiTree T)
{
    int i, j;
    if (!T)
        return 0;
    if (T->lchild)
        i = BiTreeDepth(T->lchild);
    else
        i = 0;
    if (T->rchild)
        j = BiTreeDepth(T->rchild);
    else
        j = 0;
    return i>j? i+1:j+1;
}

// ����T�ĸ�
ElemType root(BiTree T)
{
    if (BiTreeEmpty(T))
        return nil;
    else
        T->data;
}

// ���ض�������ĳ���ڵ�
ElemType vlaue(BiTree T)
{
    return T->data;
}

// ��Tָ��Ľ�㸳ֵΪvalue
void assign(BiTree T, ElemType e)
{
    T->data = e;
}

// ǰ�����
void preOderTravel(BiTree T)
{
    if (T == NULL)
        return;
    cout << T->data << " "; // ���ڵ�
    preOderTravel(T->lchild);                // ������
    preOderTravel(T->rchild);                // ������
}

// �������
void midOrderTravel(BiTree T)
{
    if (T == NULL)
        return;
    midOrderTravel(T->lchild);
    cout << T->data << " ";
    midOrderTravel(T->rchild);
}

// �������
void afterOrderTravel(BiTree T)
{
    if (T == NULL)
        return;
    afterOrderTravel(T->lchild);
    afterOrderTravel(T->rchild);
    cout << T->data << " ";
}

int main()
{
    int i;
    BiTree T;
    ElemType e;
    initBiTree(&T);

    strAssign(str, "ABDH#K###E##CFI###G#J##");
    createBiTree(&T);

    cout << "����ն����������Ƿ�Ϊ��(1:��,0:��):" << BiTreeEmpty(T) << ",�������: " << BiTreeDepth(T) << endl;

    e = root(T);
    cout << "�������ĸ������: " << e << endl;

    cout << "ǰ��������: ";
    preOderTravel(T);
    cout << endl;
    cout << "����������: ";
    midOrderTravel(T);
    cout << endl;
    cout << "����������: ";
    afterOrderTravel(T);
    cout << endl;

    clearBiTree(&T);
    cout << "��ն����������Ƿ�Ϊ��(1:��,0:��):" << BiTreeEmpty(T) << ",�������: " << BiTreeDepth(T) << endl;
    i = root(T);
    if (!i)
        cout << "�ն�����,�޸����\n";
    return 0;
}