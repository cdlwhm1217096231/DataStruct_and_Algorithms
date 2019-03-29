#include "iostream"
#include "cstdio"
#include "cstdlib"
#include "io.h"
#include "cstring"


using namespace std;

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20  // �洢�ռ�ĳ�ʼ������

typedef int ElemType;  // ����Ԫ�ص����ͱ���
typedef int Status;  // �����ķ���ֵ���ͱ���(����ֵ������״̬OK ERROR)

// ���ýṹ�嶨�嵥�����е����������ݽṹ
typedef struct Node{
    ElemType data;  // �ڵ��������
    struct Node *next;  // �ڵ��ָ����ʹ��ָ��ṹ��Node���͵�ָ�����next����ʾ��
}Node;  
typedef struct Node * LinkList;  // ��struct Node *�����Զ���ΪLinkList

Node N;  // ����һ��struct Node���͵ı���N���ȼ���struct Node N;
LinkList ptr;  // ����һ��struct Node *���͵�ָ�����ptr,�ȼ���struct Node *ptr; 

// ����ĳ���ڵ��������
Status visit(ElemType e){
    cout << e << " ";
    return OK;
}

// LinkList *L;  �ȼ���struct Node **L;  L��ָ��Node���ͽṹ��ָ���ָ��;*L��ָ��Node���ͽṹ���ָ��;**L��Node���͵Ľṹ��
// LinkList L; �ȼ���struct Node *L;L��ָ��Node���ͽṹ���ָ��;*L��Node���͵Ľṹ��
// ��ʼ���ڵ�
Status InitList(LinkList *L){
    *L = (LinkList)malloc(sizeof(Node));
    if (!*L)
        return ERROR;
    (*L)->next = NULL;  // ָ����ΪNULL
    return OK; 
}

// �ж��Ƿ��ǿ�����
Status ListEmpty(LinkList L){
    if(L->next)
        return FALSE;
    else    
        return TRUE;
}

// �������
Status clearList(LinkList *L){
    LinkList p, q;
    p = (*L)->next;  // ָ��p��Ϊ�����ͷָ�룬ָ���������L�еĵ�һ�����
    while(p){  // ��û�е��������ĩβ
        q = p->next;
        free(p);
        p = q;
    }
    (*L)->next = NULL;  // ͷ����ָ�����ǿ�ʱ����ʾ��ʱ������L�Ŀձ�
    return OK;
}

// ���������е�Ԫ�ظ���
int ListLength(LinkList L){
    int i = 0;
    LinkList p;
    p = L->next;  // pָ���������L�еĵ�һ����㣬��P��ͷָ��
    while(p){ // �ж�p�Ƿ񵽴�����L��ĩβ
        i++;
        p = p->next;
    }
    return i;
}

// ��������L�еĵ�i������Ԫ�ص�ֵ
Status GetElem(LinkList L, int i, ElemType *e){
    int j = 1;  // j��¼����λ����Ϣ
    LinkList p;
    p = L->next;
    while(p && j < i){
        p = p->next;
        ++j;
    }
    // ����Ԫ�س��ִ�������
    if(!p || j > i)
        return ERROR;
    *e = p->data;
    return OK;
}

// ��λĳ��Ԫ��
int LocateElem(LinkList L, ElemType e){
    int i = 0;
    LinkList p;
    p = L->next;
    while(p){
        i++;
        if(p->data == e)  // �ҵ��˵�i��Ԫ��e
            return i;
        p = p->next;
    }
    return 0;
}

// ����һ�����
Status InsertElem(LinkList *L, int i, ElemType e){
    int j = 1;
    LinkList p, s;  
    p = (*L); // ����һ��ָ��pָ������L�ĵ�һ���ڵ�
    while(p && j < i){
        p = p->next;
        ++j;
    }
    if(!p || j > i)
        return ERROR;
    s = (LinkList)malloc(sizeof(Node)); // ���ڴ���Ѱ��һ��������Nodeһ����С�Ŀռ䣬ʵ����������һ���µĽ��s
    s->data = e;
    s->next = p->next; //��p�ĺ�̽�㸳ֵ��s�ĺ�̽ڵ�
    p->next = s;  // ��s��ֵ��p�ĺ�̽ڵ�
    return OK;
}

// ɾ����i������Ԫ��
Status DeleteElem(LinkList *L, int i, ElemType *e){
    int j = 1;
    LinkList p, q;
    p = *L;
    while(p->next || j < i){  // Ѱ�ҵ�i��Ԫ�أ������p->next���Ըĳ�p��
        p = p->next;
        ++j;
    }
    if(!(p->next) || j > i)
        return ERROR;
    q = p->next;
    p->next = q->next;
    *e = q->data;
    free(q);  // ��ϵͳ���մ˽ڵ㣬�ͷ��ڴ�
    return OK;
}

// ��������
Status TravelList(LinkList L){
    LinkList p;
    p = L->next;
    while(p){
        visit(p->data);
        p = p->next;
    }
    cout << endl;
    return OK;
}



int main(){
    LinkList L;
    ElemType e;
    Status i, k;
    i = InitList(&L);
    cout << "��ʼ����,L�ĳ�����: " << ListLength(L) << endl;

    for(int j = 1; j <= 5; j++)
        i = InsertElem(&L, 1, j);  // ͷ�巨
    cout << "ͷ�巨��Ľ��L.data = ";
    TravelList(L);
    cout << "ͷ�巨��,L�ĳ�����: " << ListLength(L) << endl;

    i = ListEmpty(L);
    cout << "L�Ƿ�Ϊ��(1:��,0:��): " << i << endl;

    i = clearList(&L);
    cout << "��պ�,L�ĳ�����: " << ListLength(L) << endl;
    i = ListEmpty(L);
    cout << "L�Ƿ�Ϊ��(1:��,0:��): " << i << endl;

    for(int j = 1; j <=10; j++)
        i = InsertElem(&L, j, j);
    cout << "β�巨��Ľ��L.data = ";
    TravelList(L);
    cout << "β�巨��,L�ĳ�����: " << ListLength(L) << endl;

    InsertElem(&L, 1, 0);
    cout << "�ڵ�һ��λ�ò���Ԫ��0,�����L.data = ";
    TravelList(L);

    GetElem(L, 7, &e);
    cout << "��7��Ԫ�ص�ֵ��: " << e << endl;

    for(int j = 3; j <=4; j++){
        k = LocateElem(L, j);
        if (k)
            cout << "��" << k << "��Ԫ�ص�ֵ��: " << j << endl; 
        else    
            cout << "û��ֵ��" << j << "��Ԫ��\n";
    }

    k = ListLength(L);
    for(int j = k+1; j>k; j--){
        i = DeleteElem(&L, j, &e);
        if(i == ERROR)
            cout << "ɾ����" << j << "��Ԫ��ʧ��!\n";
        else    
            cout << "ɾ����" << j << "��Ԫ�أ�Ԫ�ص�ֵ��: " << e << endl;
    }
    cout << "���δ�ӡ��Ԫ�ص�ֵ: ";
    TravelList(L);

    int j = 5;
    DeleteElem(&L, 5, &e);
    cout << "ɾ����" << j << "��Ԫ�أ�Ԫ�ص�ֵ��: " << e << endl;
    cout << "���δ�ӡ��Ԫ�ص�ֵ: ";
    TravelList(L);
    return 0;
}

