#include "iostream"

using namespace std;

#define MAXSIZE  1000
#define ERROR 0
#define OK 1

typedef int Status;
typedef int ElemType;
// 定义顺序栈的数据结构
typedef struct{
    ElemType data[MAXSIZE];
    int top;
}SeqStack;

// 栈的顺序存储结构---PUSH操作
Status Push(SeqStack *s, ElemType e){
    if(s->top == MAXSIZE - 1)
        return ERROR;   // 栈的元素已经满了，再PUSH就报错
    s->top++;
    s->data[s->top] = e;  // 移动top指针后，给入栈的元素分配一个top指针
    return OK;
}

// 栈的顺序存储结构---POP操作
Status Pop(SeqStack *s, ElemType *e){
    if(s->top == -1)  // 原来的栈就是空栈，无法出栈新的元素
        return ERROR;
    *e = s->data[s->top];  // 把将要出栈的元素赋值给*e进行保存
    s->top--;
    return OK;        
}
