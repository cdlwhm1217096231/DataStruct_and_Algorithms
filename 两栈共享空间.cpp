#include "iostream"

using namespace std;

#define MAXSIZE 20
#define ERROR 0
#define OK 1
#define TRUE 1
#define FALSE 0


typedef int Status;
typedef int sElemType;

// 两栈共享空间数据结构
typedef struct{
    sElemType data[MAXSIZE];
    int top1;
    int top2;
}doubleStack;

// 访问当中的一个元素
Status visit(sElemType e){
    cout << "e: " << e << " ";
    return OK;
}
// 构造一个空的两栈共享空间
Status InitStack(doubleStack *s){
    s->top1 = -1;
    s->top2 = MAXSIZE;
    return OK;
}
// 清空栈
Status clearStack(doubleStack *s){
    s->top1 = -1;
    s->top2 = MAXSIZE;
    return OK;
}
// 判断是否是空栈
Status isEmpty(doubleStack s){
    if(s.top1 == -1 && s.top2 == MAXSIZE)
        return TRUE;
    else
        return FALSE;
}
// 返回共享栈的元素个数即栈的长度
Status stackLength(doubleStack s){
    return (s.top1+1) + (MAXSIZE - s.top2);
}


// 插入元素e为新的栈顶元素----PUSH
// stackNumber是栈号参数，用来判断是栈1还是栈2
Status Push(doubleStack *s, sElemType e, int stackNumber){
    if(s->top1 + 1 == s->top2)  // 两个栈已经元素满啦
        return ERROR;
    if(stackNumber == 1)
        s->data[++s->top1] = e;  // 栈1插入元素则先将top指针加1，然后在将top指针指向新入栈的元素
    else if (stackNumber == 2)   // 栈2插入元素则先将top指针减1，然后将top指针指向新入栈的元素
        s->data[--s->top2] = e;
    return OK;
}

// 删除元素-----即POP出栈操作
Status Pop(doubleStack *s, sElemType *e, int stackNumber){
    if(stackNumber == 1){
        if(s->top1 == -1)
            return ERROR;
        *e = s->data[s->top1--]; // 对于栈1来说，pop出栈时，top1指针先将当前位置的值保存下来，然后将top1减1，向栈1的栈底位置移动1次
    }
    else if(stackNumber == 2){  // 对于栈2来说，pop出栈时，top2指针先将当前位置的值保存下来，然后将top2加1，向栈2的栈顶位置移动1次
        if(s->top2 == MAXSIZE)
            return ERROR;
        *e = s->data[s->top2++];
    }
    return OK;
}

// 遍历共享栈
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
    cout << "栈中的元素依次为: ";
    TravelStack(ds);
    cout << "\n当前栈中的元素个数: " << stackLength(ds) << endl;

    Pop(&ds, &e, 2);
    cout << "出栈的栈顶元素是: " << e << endl;
    cout << "是否是空栈[是:1,否:0] = " << isEmpty(ds) << endl;
    
    for(int j = 6; j <= MAXSIZE-2;j++)
        Push(&ds, j, 1);
    cout << "栈中的元素依次为: ";
    TravelStack(ds);
    cout << "\n是否是空栈[是:1,否:0] = " << isEmpty(ds) << endl;

    clearStack(&ds);
    cout << "清空栈后，是否是空栈[是:1,否:0] = " << isEmpty(ds) << endl;
    return 0;
}