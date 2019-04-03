#include "iostream"

using namespace std;

#define MAXSIZE  1000
#define ERROR 0
#define OK 1

typedef int Status;
typedef int ElemType;
// ����˳��ջ�����ݽṹ
typedef struct{
    ElemType data[MAXSIZE];
    int top;
}SeqStack;

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
