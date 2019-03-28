#include "cstdio"
#include "cstring"
#include "iostream"
#include "ctime"
#include "cstdlib"
#include "io.h"  
#include "math.h"  
#include "time.h"



using namespace std;
// ����һ������˳���

#define MAX_SIZE 20   // �洢�ռ�ĳ�ʼ�����С
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;   //  �����ķ���ֵ���ͱ���
typedef int ElemType;  // ���Ա�Ԫ�ص��������ͱ���

// ����һ������˳���
typedef struct sqList{  
    ElemType data[MAX_SIZE];  // �洢�ռ����ʼλ�ã�����data
    int length;  // ���Ա�ĵ�ǰ����
}sqList;

Status GetElem(sqList L, int i, ElemType *e);    // ��������
Status ListInsert(sqList *L, int i, ElemType e);
Status ListDelete(sqList *L, int i, ElemType *e);
Status visit(ElemType e);
Status InitList(sqList *L);
Status IsEmpty(sqList *L);
Status ClearList(sqList *L);
Status ListLength(sqList L);
Status LocateElem(sqList L, ElemType e);
Status TravelElem(sqList L);
Status UnionSet(sqList *La, sqList Lb);



int main(){
    sqList L;
    sqList Lb;
    ElemType e;
    Status i, k;
    i = InitList(&L);
    cout << "��ʼ����L�ĳ���: " << L.length << endl;
    for (int j = 1; j <= 5; j++)
        i = ListInsert(&L, 1, j);  // ͷ������
    cout << "��Lͷ������Ԫ�غ�,L.data = ";
    TravelElem(L);
    cout << "����Ԫ�غ�����˳���ĳ���: " << L.length << endl;
    
    i = IsEmpty(&L);
    cout << "L�Ƿ�Ϊ��(1:��;0:��),�����: " << i << endl;

    i = ClearList(&L);
    cout << "��ձ��ĳ���: " << L.length << endl;
    
    i = IsEmpty(&L);
    cout << "L�Ƿ�Ϊ��(1:��;0:��),�����: " << i << endl;

    for (int j = 1; j <= 10; j++)
        ListInsert(&L, j, j);
    cout << "��Lβ������Ԫ�غ�,L.data = ";
    TravelElem(L);
    cout << "����Ԫ�غ�����˳���ĳ���: " << L.length << endl;

    ListInsert(&L, 1, 666);
    cout << "��L�ı�ͷ����Ԫ��666,L.data = ";
    TravelElem(L);
    cout << "����Ԫ�غ�����˳���ĳ���: " << L.length << endl;

    GetElem(L, 7, &e);  // ��õ�7��Ԫ��
    cout << "��7��Ԫ�ص�ֵ��: " << e << endl;

    for (int j = 3; j <= 6; j++){
        k = LocateElem(L, j);
        if(k)
            cout << "��" << k << "��Ԫ�ص�ֵ��: " << j << endl;
        else    
            cout << "û��ֵΪ" << j << "��Ԫ��\n";
    }


    k = ListLength(L);
    for(int j = k+1; j >= k; j--){
        i = ListDelete(&L, j, &e);
        if (i == ERROR)
            cout << "ɾ����" << j << "��Ԫ��ʧ��" << endl;
        else    
            cout << "ɾ����" << j << "��Ԫ��," << "Ԫ�ص�ֵ��: " << e << endl;
    }
    cout << "���α���ÿ��Ԫ��: ";
    TravelElem(L);

    k =5;
    ListDelete(&L, k, &e);
    cout << "��" << k << "��Ԫ��" << e << "�Ѿ���ɾ��.\n";

    // ����һ������B
    i = InitList(&Lb);
    for (int j = 6; j<=15; j++)
        i = ListInsert(&Lb, 1, j);  // ��ͷ�����β���6-15��Щ����
    cout << "���α���Lb�е�ÿ��Ԫ��: ";
    TravelElem(Lb);
    UnionSet(&L, Lb);
    cout << "���α���ÿ��Ԫ��: ";
    TravelElem(L);
    return 0;
}

// ��ʼ������˳���
Status InitList(sqList *L){
    L->length = 0;
    return OK;
}

// �ж�һ�����Ա��Ƿ��ǿձ�
Status IsEmpty(sqList *L){
    if (L->length == 0)
        return TRUE;
    else
        return FALSE;
}

// ��ӡÿ��Ԫ��
Status visit(ElemType e){
    cout << e << " ";
    return OK;
}

// �������˳���
Status ClearList(sqList *L){
    L->length = 0;
    return OK;
}

// ��������˳����е�Ԫ�ظ���
Status ListLength(sqList L){
    return L.length;
}

// ���ĳ��Ԫ��i�Ĳ���
Status GetElem(sqList L, int i, ElemType *e){
    if (L.length == 0 || i < 1 || i > L.length)
        return ERROR;
    *e = L.data[i-1];
    return OK;
}

// ����Ԫ�ز���
Status ListInsert(sqList *L, int i, ElemType e){
    int k; // k��ʾ��������
    if(L->length == MAX_SIZE)
        return ERROR;   // ��ʱ���Ա��Ѿ�����
    if(i < 1 || i > L->length+1)  // ���ֻ�е�length��Ԫ�أ�����lengthԪ�ؽ��ᱨ��
        return ERROR;
    if(i <= L->length){
        for(k = L->length-1;k >= i-1;k--)
            L->data[k+1] = L->data[k];
    }
    L->data[i-1] = e;  // �����Ԫ��
    L->length++;
    return OK;
}

// ɾ��Ԫ�ز���
Status ListDelete(sqList *L, int i, ElemType *e){
    int k;
    if (L->length == 0)
        return ERROR;
    if (i < 1 || i > L->length)
        return ERROR;
    *e = L->data[i-1];
    if (i < L->length){
        for(k = i; i < L->length; k++)
            L->data[k] = L->data[k+1];
    }
    L->length--;
    return OK;
}

// ��λ����˳�����ĳ��Ԫ�ص�λ��
Status LocateElem(sqList L, ElemType e){
    int i;  // i��ʾԪ�ص�����
    if (L.length == 0)
        return 0;
    for(i = 0; i < L.length; i++){
        if (L.data[i] == e)
            break;
    }
    if (i >= L.length)
        return 0;
    return i+1;    // ��i+1��Ԫ�ص�������i 
}

// �������Ա��е�ÿ��Ԫ��
Status TravelElem(sqList L){
    for (int i = 0; i < L.length; i++)
        visit(L.data[i]);
    cout << endl;
    return OK;
}

// ���������ϵĲ���:�ȶ�һ������B����ÿ��Ԫ�صı�����Ȼ�󽫱����õ���Ԫ���뼯��A�е�����Ԫ�ؽ��жԱȣ��������ȣ�������ӵ�����A��
Status UnionSet(sqList *La, sqList Lb){
    int La_len, Lb_len;
    ElemType e;
    La_len = ListLength(*La);
    Lb_len = ListLength(Lb);
    for(int i = 1; i <=Lb_len; i++){
        GetElem(Lb, i, &e);
        if(!LocateElem(*La,e))
            ListInsert(La, ++La_len, e);
    }
}