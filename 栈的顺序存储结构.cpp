#include "iostream"

using namespace std;

#define MAXSIZE  20
#define ERROR 0
#define OK 1
#define TRUE 1
#define FALSE 0


typedef int Status;
typedef int ElemType;

// ����˳��ջ�����ݽṹ
typedef struct{
    ElemType data[MAXSIZE];
    int top;
}SeqStack;

// ����һ��Ԫ��
Status visit(ElemType e){
    cout << "e: " << e << " ";
}

// ����һ���յ�˳��ջ
Status InitStack(SeqStack *s){
    s->top = -1;
    return OK;
}

// ���һ��˳��ջ
Status ClearStack(SeqStack *s){
    s->top = -1;
    return OK;
}
// �ж��Ƿ��ǿ�ջ
Status isEmpty(SeqStack s){
    if(s.top == -1)
        return TRUE;
    else    
        return FALSE;
}
// ��ȡջ��Ԫ�صĸ�����ջ�ĳ���
Status stackLength(SeqStack s){
    return s.top + 1;
}

// ��ȡĳ��Ԫ��
Status getElem(SeqStack *s, ElemType *e){
    if(s->top == -1)
        return ERROR;
    else
        *e = s->data[s->top];
        return OK;
}   

// ջ��˳��洢�ṹ---PUSH����
Status Push(SeqStack *s, ElemType e){
    if(s->top == MAXSIZE - 1)
        return ERROR;   // ջ��Ԫ���Ѿ����ˣ���PUSH�ͱ���
    s->top++;
    s->data[s->top] = e;  // �ƶ�topָ��󣬸���ջ��Ԫ�ط���һ��topָ��
    return OK;
}

// ջ��˳��洢�ṹ---POP����
Status Pop(SeqStack *s, ElemType *e){
    if(s->top == -1)  // ԭ����ջ���ǿ�ջ���޷���ջ�µ�Ԫ��
        return ERROR;
    *e = s->data[s->top];  // �ѽ�Ҫ��ջ��Ԫ�ظ�ֵ��*e���б���
    s->top--;
    return OK;        
}
// ����ջ
Status TravelStack(SeqStack s){
    int i = 0;
    while( i <= s.top)
        visit(s.data[i++]);
    return OK;
}

int main(){
    int e;
    SeqStack s;
    if(InitStack(&s) == OK)
        for(int j = 1; j <= 10; j++)
            Push(&s, j);
    cout << "�������ջ�е�Ԫ����: ";
    TravelStack(s);
    Pop(&s, &e);
    cout << "\n��ջ��ջ��Ԫ����: " << e << endl;
    cout << "�Ƿ��ǿ�˳��ջ[��:1,��:0] = " << isEmpty(s) << endl;
    getElem(&s, &e);
    cout << "ջ��Ԫ����: " << e << ", ջ�ĳ�����: " << stackLength(s) << endl;
    ClearStack(&s);
    cout << "���ջ��,�Ƿ��ǿ�˳��ջ[��:1,��:0] = " << isEmpty(s) << endl;
    return 0; 
}