#include "iostream"
#include "malloc.h"

using namespace std;

// ƽ�������----AVL��

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100

typedef int Status;
// �Ľ������������еĽ��ṹ
typedef struct BiTNode
{
    int data;
    int bf; // ƽ������BF
    BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

// ����ת---˳ʱ����ת
void R_Rotate(BiTree *p)
{
    BiTree L;
    L = (*p)->lchild;         // L�ǵ�ǰ�����p�������ĸ����
    (*p)->lchild = L->rchild; // ������ת�󣬽�L���������ҽӵ�p����������
    L->rchild = *p;           // ԭʼ�ĸ����p���ڱ�ɵ�ǰ�����R���������ĸ����
    *p = L;                   // ԭʼ�����p���L
}

// ������ת---��ʱ����ת
void L_Rotate(BiTree *p)
{
    BiTree R;
    R = (*p)->rchild;         // R�ǵ�ǰ�����p�������ĸ����
    (*p)->rchild = R->lchild; // ������ת�󣬽�R���������ҽӵ�p����������
    (*p) = R->lchild;         // ԭʼ�ĸ����p���ڱ�ɵ�ǰ�����R���������ĸ����
    *p = R;                   // ԭʼ�����p���R
}

#define LH +1 // ���
#define EH 0  // �ȸ�
#define RH -1 // �Ҹ�

// ��ƽ�⴦��--������������

void LeftBalance(BiTree *T)
{
    BiTree L, Lr;
    L = (*T)->lchild;
    switch (L->bf)
    {
    case LH: // �½��N������T�����ӵ��������ϣ�ֻ��Ҫ������������ת
        (*T)->bf = L->bf = EH;
        R_Rotate(T);
        break;
    case RH:
        Lr = L->rchild; // Lrָ��T������L��������Lr�ϣ���Ҫ������������
        switch (Lr->bf)
        { // �޸�T�������ӵ�ƽ������
        case LH:
            (*T)->bf = RH;
            L->bf = EH;
            break;
        case EH:
            (*T)->bf = L->bf = EH;
            break;
        case RH:
            (*T)->bf = EH;
            L->bf = LH;
            break;
        }
        Lr->bf = EH;
        L_Rotate(&(*T)->lchild); // ��T��������L����������
        R_Rotate(T);             // �Ը����T����������
    }
}

// ��ƽ�⴦��---��������������
void RightBalance(BiTree *T)
{
    BiTree R, Rl;
    R = (*T)->rchild;
    switch (R->bf)
    {
    case RH: // �½��N�����ڸ��ڵ�T���Һ��ӵ��������ϣ�ֱ�ӽ�����������
        (*T)->bf = R->bf = EH;
        L_Rotate(T);
        break;
    case LH:
        Rl = R->lchild; // Rlָ����Ǹ��ڵ�T���Һ��ӵ�������Rl�ϣ���Ҫ������������
        switch (Rl->bf)
        { // �޸�T�����Һ��ӵ�ƽ������
        case RH:
            (*T)->bf = LH;
            R->bf = EH;
            break;
        case EH:
            (*T)->bf = R->bf = EH;
            break;
        case LH:
            (*T)->bf = EH;
            R->bf = RH;
            break;
        }
        Rl->bf = EH;
        R_Rotate(&(*T)->rchild); // �Ը��ڵ�T��������R������������
        L_Rotate(T);             // �Ը��ڵ�T�ٽ�������
    }
}

// �������
Status InsertAVL(BiTree *T, int e, Status *taller)
{
    if (!*T)
    { // �ǿ���ʱ��ִ������Ĵ���
        *T = (BiTree)malloc(sizeof(BiTNode));
        (*T)->data = e;
        (*T)->lchild = (*T)->rchild = NULL;
        (*T)->bf = EH;
        *taller = TRUE;
    }
    else
    { // ���ǿ���
        if ((*T)->data == e)
        { // �ؼ����Ѿ������ڶ���������
            *taller = FALSE;
            return FALSE;
        }
        // �ؼ��ֲ��ڶ����������У�ִ�в������
        if (e < (*T)->data)
        {                                             // �ؼ���С�ڵ�ǰ���ڵ��ֵ���ڵ�ǰ���ڵ�T���������н�������������
            if (!InsertAVL(&(*T)->lchild, e, taller)) // δ����
                return FALSE;
            if (*taller) // �Ѳ��뵽T�����������������������ߡ�
                switch ((*T)->bf)
                {        // ���T��ƽ������
                case LH: // ԭ�����������������ߣ���Ҫ����ƽ�⴦��
                    LeftBalance(T);
                    *taller = FALSE;
                    break;
                case EH: // ԭ�����������ȸߣ��������������߶�ʹ������
                    (*T)->bf = LH;
                    *taller = TRUE;
                    break;
                case RH: // ԭ�����������������ߣ������������ȸ�
                    (*T)->bf = EH;
                    *taller = FALSE;
                    break;
                }
        }
        else
        {                                             // �ؼ��ִ��ڵ�ǰ���ڵ��ֵ,������T���������н�������
            if (!InsertAVL(&(*T)->rchild, e, taller)) // δ����
                return FALSE;
            if (*taller) // �Ѳ��뵽T���������������������ߡ�
                switch ((*T)->bf)
                {        // ���T��ƽ������
                case LH: // ԭ�����������������ߣ������������ȸ�
                    (*T)->bf = EH;
                    *taller = FALSE;
                    break;
                case EH: // ԭ�����������ȸߣ��������������߶�ʹ������
                    (*T)->bf = RH;
                    *taller = TRUE;
                    break;
                case RH: // ԭ�����������������ߣ���Ҫ����ƽ�⴦��
                    RightBalance(T);
                    *taller = FALSE;
                    break;
                }
        }
    }
    return TRUE;
}

int main()
{
    int a[MAXSIZE] = {3, 2, 1, 4, 5, 6, 7, 10, 9, 8};
    BiTree T=NULL;
    Status taller;
    for(int i=0; i < 10; i++){
        InsertAVL(&T, a[i], &taller);
    }
    cout << "ʹ�öϵ���ٲ鿴ƽ�������AVL�Ľṹ\n";
    return 0;
}
