#include "iostream"
#include "cstdio"
#include "cstdlib"
#include "ctime"



using namespace std;

#define MAXSIZE 20
#define OK 1
#define ERROR 0
#define True 1
#define False 0



typedef int Status;
typedef int sElemType;


// 顺序栈的数据结构
typedef struct{
    sElemType data[MAXSIZE];
    int top; 
}seqStack;

// 链栈的数据结构
typedef struct stackNode{
    sElemType data;
    struct stackNode *next;  // 指向stackNode类型的结构体的指针变量next, 等价于 linkStackPtr next;
}stackNode, *linkStackPtr;

// typedef struct stackNode{} stackNode;  即将struct stackNode{};结构体类型自定义一个别名stackNode
// typedef struct stackNode{} * linkStackPtr; 将指向stackNode类型结构体的指针自定义一个类型别名linkStackPtr;


typedef struct linkStack{
    linkStackPtr top;  // 等价于struct stackNode * top;指向stackNode类型结构体的指针变量top
    int count;
}linkStack;


// 访问栈中的一个元素
Status visit(sElemType e){
    cout << "e: " << e << " ";
    return OK;
}

// 构造一个空栈
Status InitStack(linkStack *s){
    s->top = (linkStackPtr)malloc(sizeof(stackNode));
    if(!s->top)  // 已经是空的链栈
        return ERROR;
    s->top = NULL;
    s->count = 0;
    return OK;
}


// 清空一个栈
Status clearStack(linkStack *s){
    linkStackPtr p, q;
    p = s->top;  // 栈顶指针
    while(p){
        q = p;
        p = p->next;
        free(q);
    }
    return OK;
}

// 判断是否是空栈
Status isEmpty(linkStack s){
    if(s.count == 0)
        return True;
    else    
        return False;
}

// 返回栈中元素的个数----栈的长度
Status stackLength(linkStack s){
    return s.count;
}

// 返回栈顶的元素
Status getTop(linkStack s, sElemType *e){
    if(s.top == NULL)  // 空栈
        return ERROR;
    else   
        *e = s.top->data;
        return OK;
}
// 链栈的插入元素操作----PUSH入栈操作
Status Push(linkStack *s, sElemType e){
    linkStackPtr p = (linkStackPtr)malloc(sizeof(stackNode));  // 为新插入的元素分配一个内存地址,并用指针p进行存储
    p->data = e;
    p->next = s->top;  // 把当前的栈顶元素的值赋给新结点p的直接后继
    s->top = p;  // 再把新的结点p当作新的栈顶指针
    s->count++;  // count来统计插入的元素个数
    return OK;
}

// 链栈的删除元素操作-----POP出栈操作
Status Pop(linkStack *s, sElemType *e){
    linkStackPtr p;
    if(isEmpty(*s))  // 空链栈
        return ERROR;
    *e = s->top->data;   // 保存要出栈的元素
    p = s->top;  // 将栈顶元素赋值给p
    s->top = s->top->next;  // 当前节点的直接后继结点作为新的栈顶指针
    free(p);
    s->count--;
    return OK;
}

// 遍历链栈
Status TravelStack(linkStack s){
    linkStackPtr p;
    p = s.top;  // 将栈顶指针赋值给指针p
    while(p){
        visit(p->data);
        p = p->next;
    }
    return OK;
}

int main(){
    linkStack s;
    int e;
    if(InitStack(&s) == OK)
        for(int j = 1; j <= 10; j++)
            Push(&s, j);
    cout << "依次入栈的元素是: ";
    TravelStack(s);
    Pop(&s, &e);
    cout << "\n出栈的栈顶元素是: " << e << endl;
    cout << "是否是空链栈[是:1,否:0] = " << isEmpty(s) << endl;
    getTop(s, &e);
    cout << "栈顶元素是: " << e << ",栈的长度是: " << stackLength(s) << endl;
    clearStack(&s);
    cout << "清空栈后,是否是空链栈[是:1,否:0] = " << isEmpty(s) << endl;
    return 0;
}