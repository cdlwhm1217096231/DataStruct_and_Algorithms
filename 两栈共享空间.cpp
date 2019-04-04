#include "iostream"

using namespace std;

#define MAXSIZE 20
#define ERROR 0
#define OK 1
#define TRUE 1
#define FALSE 0


typedef int Status;
typedef int sElemType;

// ��ջ����ռ����ݽṹ
typedef struct{
    sElemType data[MAXSIZE];
    int top1;
    int top2;
}doubleStack;

// ���ʵ��е�һ��Ԫ��
Status visit(sElemType e){
    cout << "e: " << e << " ";
    return OK;
}
// ����һ���յ���ջ����ռ�
Status InitStack(doubleStack *s){
    s->top1 = -1;
    s->top2 = MAXSIZE;
    return OK;
}
// ���ջ
Status clearStack(doubleStack *s){
    s->top1 = -1;
    s->top2 = MAXSIZE;
    return OK;
}
// �ж��Ƿ��ǿ�ջ
Status isEmpty(doubleStack s){
    if(s.top1 == -1 && s.top2 == MAXSIZE)
        return TRUE;
    else
        return FALSE;
}
// ���ع���ջ��Ԫ�ظ�����ջ�ĳ���
Status stackLength(doubleStack s){
    return (s.top1+1) + (MAXSIZE - s.top2);
}


// ����Ԫ��eΪ�µ�ջ��Ԫ��----PUSH
// stackNumber��ջ�Ų����������ж���ջ1����ջ2
Status Push(doubleStack *s, sElemType e, int stackNumber){
    if(s->top1 + 1 == s->top2)  // ����ջ�Ѿ�Ԫ������
        return ERROR;
    if(stackNumber == 1)
        s->data[++s->top1] = e;  // ջ1����Ԫ�����Ƚ�topָ���1��Ȼ���ڽ�topָ��ָ������ջ��Ԫ��
    else if (stackNumber == 2)   // ջ2����Ԫ�����Ƚ�topָ���1��Ȼ��topָ��ָ������ջ��Ԫ��
        s->data[--s->top2] = e;
    return OK;
}

// ɾ��Ԫ��-----��POP��ջ����
Status Pop(doubleStack *s, sElemType *e, int stackNumber){
    if(stackNumber == 1){
        if(s->top1 == -1)
            return ERROR;
        *e = s->data[s->top1--]; // ����ջ1��˵��pop��ջʱ��top1ָ���Ƚ���ǰλ�õ�ֵ����������Ȼ��top1��1����ջ1��ջ��λ���ƶ�1��
    }
    else if(stackNumber == 2){  // ����ջ2��˵��pop��ջʱ��top2ָ���Ƚ���ǰλ�õ�ֵ����������Ȼ��top2��1����ջ2��ջ��λ���ƶ�1��
        if(s->top2 == MAXSIZE)
            return ERROR;
        *e = s->data[s->top2++];
    }
    return OK;
}

// ��������ջ
Status TravelStack(doubleStack s){
    int i = 0;
    while(i <= s.top1)
        visit(s.data[i++]);
    i = s.top2;
    while(i < MAXSIZE)
        visit(s.data[i++]);
    return OK;
}

int main(){
    doubleStack ds;
    int e;
    if(InitStack(&ds) == OK){
        for(int j = 1; j<5;j++)
            Push(&ds,j, 1);
        for(int j = MAXSIZE;j>=MAXSIZE-2;j--)
            Push(&ds, j, 2);
    }
    cout << "ջ�е�Ԫ������Ϊ: ";
    TravelStack(ds);
    cout << "\n��ǰջ�е�Ԫ�ظ���: " << stackLength(ds) << endl;

    Pop(&ds, &e, 2);
    cout << "��ջ��ջ��Ԫ����: " << e << endl;
    cout << "�Ƿ��ǿ�ջ[��:1,��:0] = " << isEmpty(ds) << endl;
    
    for(int j = 6; j <= MAXSIZE-2;j++)
        Push(&ds, j, 1);
    cout << "ջ�е�Ԫ������Ϊ: ";
    TravelStack(ds);
    cout << "\n�Ƿ��ǿ�ջ[��:1,��:0] = " << isEmpty(ds) << endl;

    clearStack(&ds);
    cout << "���ջ���Ƿ��ǿ�ջ[��:1,��:0] = " << isEmpty(ds) << endl;
    return 0;
}