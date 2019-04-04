#include "iostream"

using namespace std;

#define MAXSIZE  20
#define ERROR 0
#define OK 1
#define TRUE 1
#define FALSE 0


typedef int Status;
typedef int ElemType;

// 定义顺序栈的数据结构
typedef struct{
    ElemType data[MAXSIZE];
    int top;
}SeqStack;

// 访问一个元素
Status visit(ElemType e){
    cout << "e: " << e << " ";
}

// 构造一个空的顺序栈
Status InitStack(SeqStack *s){
    s->top = -1;
    return OK;
}

// 清空一个顺序栈
Status ClearStack(SeqStack *s){
    s->top = -1;
    return OK;
}
// 判断是否是空栈
Status isEmpty(SeqStack s){
    if(s.top == -1)
        return TRUE;
    else    
        return FALSE;
}
// 获取栈中元素的个数，栈的长度
Status stackLength(SeqStack s){
    return s.top + 1;
}

// 获取某个元素
Status getElem(SeqStack *s, ElemType *e){
    if(s->top == -1)
        return ERROR;
    else
        *e = s->data[s->top];
        return OK;
}   

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
// 遍历栈
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
    cout << "依次输出栈中的元素是: ";
    TravelStack(s);
    Pop(&s, &e);
    cout << "\n出栈的栈顶元素是: " << e << endl;
    cout << "是否是空顺序栈[是:1,否:0] = " << isEmpty(s) << endl;
    getElem(&s, &e);
    cout << "栈顶元素是: " << e << ", 栈的长度是: " << stackLength(s) << endl;
    ClearStack(&s);
    cout << "清空栈后,是否是空顺序栈[是:1,否:0] = " << isEmpty(s) << endl;
    return 0; 
}