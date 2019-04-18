#include "iostream"
#include "malloc.h"


using namespace std;


#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define FALSE 0
#define TRUE 1


typedef int Status;
typedef char ElemType;

typedef enum {Link, Thread} PointerTag;   // Link = 0;��ʾ���Һ��ӵ�ָ��  Thread=1��ʾǰ���ͺ�̵�ָ��
typedef struct BiThrNode{
    ElemType data;
    struct BiThrNode *lchild, *rchild;  // ���Һ���ָ��
    PointerTag LTag;  // ö������PointerTag, LTag��ȡֵ��Link����Thread
    PointerTag RTag;  // ö������PointerTag, LTag��ȡֵ��Link����Thread
}BiThrNode, *BiThrTree;  // BiThrTree��ʾ����ָ��ṹ��BiThrNode���͵�ָ������

ElemType nil = '#';  // �ַ����Կո��Ϊ��

Status visit(ElemType e){
    cout << "e:" << e << " ";
    return OK;
}

// �������������
Status createBiThrTree(BiThrTree *T){
    ElemType ch;
    cin >> ch;
    if(ch == nil)
        *T = NULL;
    else{
        *T = (BiThrTree)malloc(sizeof(BiThrNode));
        if(!*T)
            return ERROR;
        (*T)->data = ch;  // ���ɸ����(ǰ��)
        createBiThrTree(&(*T)->lchild);  // ������
        if((*T)->lchild)  // ������
            (*T)->LTag = Link;
        createBiThrTree(&(*T)->rchild);  // ������
        if((*T)->rchild)  // ���Һ���
            (*T)->RTag = Link;
    }
    return OK;
}

BiThrTree pre;  // ����һ��ָ��BiThrNode�ṹ�����͵�ָ�����pre

void midThreading(BiThrTree p){
    if(p){
        midThreading(p->lchild);  // �ݹ�������������
        if(!p->lchild){  // û������
            p->LTag = Thread;
            p->lchild = pre;  // ����ָ��ָ�����ǰ��
        }
        if(!pre->rchild){  // ǰ��û���Һ���
            pre->RTag = Thread;
            pre->rchild = p;  //  ǰ���Һ���ָ��ָ����(��ǰ���p)
        }
        pre = p;  // ��֤preָ��p��ǰ��
        midThreading(p->rchild);  // �ݹ�������������
    }
}

// �������������T�����������������������Thrtָ��ͷ���
Status midOrderThreading(BiThrTree *Thrt, BiThrTree T){
    *Thrt = (BiThrTree)malloc(sizeof(BiThrNode));
    if(!*Thrt)
        return ERROR;
    (*Thrt)->LTag = Link;  // ����ͷ���
    (*Thrt)->RTag = Thread;
    (*Thrt)->rchild = (*Thrt);  // ��ָ���ָ
    if(!T)  // �������ǿ�������ָ���ָ
        (*Thrt)->lchild = *Thrt;
    else{
        (*Thrt)->lchild = T;
        pre = (*Thrt);
        midThreading(T);   // ���������������������
        pre->rchild = *Thrt;
        pre->RTag = Thread;  // ���һ�����������
        (*Thrt)->rchild = pre;
    }
    return OK;
}

// �����������������T(ͷ���)�ķǵݹ��㷨
Status midOrderTravel(BiThrTree T){
    BiThrTree p;
    p = T->lchild;  // pָ������
    while(p!=T){  // p==Tʱ���ǿ������������
        while(p->LTag == Link)
            p = p->lchild;
        if(!visit(p->data))  // ������������Ϊ�յĽ��
            return ERROR;
        while(p->RTag == Thread && p->rchild != T){
            p = p->rchild;
            visit(p->data);  // ���ʺ�̽��
        }
        p = p->rchild;
    }
    return OK;
}

int main(){

    BiThrTree H,T;
    cout << "�밴ǰ�����������(��:'ABDH##I##EJ###CF##G##')\n";
    createBiThrTree(&T);  // ��ǰ�����������
    midOrderThreading(&H, T);  // �������,������������������
    cout << "��������������������:\n";
    midOrderTravel(H);  // ��������������������
    return 0;
}