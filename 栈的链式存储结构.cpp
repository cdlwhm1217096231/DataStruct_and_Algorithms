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


// ˳��ջ�����ݽṹ
typedef struct{
    sElemType data[MAXSIZE];
    int top; 
}seqStack;

// ��ջ�����ݽṹ
typedef struct stackNode{
    sElemType data;
    struct stackNode *next;  // ָ��stackNode���͵Ľṹ���ָ�����next, �ȼ��� linkStackPtr next;
}stackNode, *linkStackPtr;

// typedef struct stackNode{} stackNode;  ����struct stackNode{};�ṹ�������Զ���һ������stackNode
// typedef struct stackNode{} * linkStackPtr; ��ָ��stackNode���ͽṹ���ָ���Զ���һ�����ͱ���linkStackPtr;


typedef struct linkStack{
    linkStackPtr top;  // �ȼ���struct stackNode * top;ָ��stackNode���ͽṹ���ָ�����top
    int count;
}linkStack;


// ����ջ�е�һ��Ԫ��
Status visit(sElemType e){
    cout << "e: " << e << " ";
    return OK;
}

// ����һ����ջ
Status InitStack(linkStack *s){
    s->top = (linkStackPtr)malloc(sizeof(stackNode));
    if(!s->top)  // �Ѿ��ǿյ���ջ
        return ERROR;
    s->top = NULL;
    s->count = 0;
    return OK;
}


// ���һ��ջ
Status clearStack(linkStack *s){
    linkStackPtr p, q;
    p = s->top;  // ջ��ָ��
    while(p){
        q = p;
        p = p->next;
        free(q);
    }
    return OK;
}

// �ж��Ƿ��ǿ�ջ
Status isEmpty(linkStack s){
    if(s.count == 0)
        return True;
    else    
        return False;
}

// ����ջ��Ԫ�صĸ���----ջ�ĳ���
Status stackLength(linkStack s){
    return s.count;
}

// ����ջ����Ԫ��
Status getTop(linkStack s, sElemType *e){
    if(s.top == NULL)  // ��ջ
        return ERROR;
    else   
        *e = s.top->data;
        return OK;
}
// ��ջ�Ĳ���Ԫ�ز���----PUSH��ջ����
Status Push(linkStack *s, sElemType e){
    linkStackPtr p = (linkStackPtr)malloc(sizeof(stackNode));  // Ϊ�²����Ԫ�ط���һ���ڴ��ַ,����ָ��p���д洢
    p->data = e;
    p->next = s->top;  // �ѵ�ǰ��ջ��Ԫ�ص�ֵ�����½��p��ֱ�Ӻ��
    s->top = p;  // �ٰ��µĽ��p�����µ�ջ��ָ��
    s->count++;  // count��ͳ�Ʋ����Ԫ�ظ���
    return OK;
}

// ��ջ��ɾ��Ԫ�ز���-----POP��ջ����
Status Pop(linkStack *s, sElemType *e){
    linkStackPtr p;
    if(isEmpty(*s))  // ����ջ
        return ERROR;
    *e = s->top->data;   // ����Ҫ��ջ��Ԫ��
    p = s->top;  // ��ջ��Ԫ�ظ�ֵ��p
    s->top = s->top->next;  // ��ǰ�ڵ��ֱ�Ӻ�̽����Ϊ�µ�ջ��ָ��
    free(p);
    s->count--;
    return OK;
}

// ������ջ
Status TravelStack(linkStack s){
    linkStackPtr p;
    p = s.top;  // ��ջ��ָ�븳ֵ��ָ��p
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
    cout << "������ջ��Ԫ����: ";
    TravelStack(s);
    Pop(&s, &e);
    cout << "\n��ջ��ջ��Ԫ����: " << e << endl;
    cout << "�Ƿ��ǿ���ջ[��:1,��:0] = " << isEmpty(s) << endl;
    getTop(s, &e);
    cout << "ջ��Ԫ����: " << e << ",ջ�ĳ�����: " << stackLength(s) << endl;
    clearStack(&s);
    cout << "���ջ��,�Ƿ��ǿ���ջ[��:1,��:0] = " << isEmpty(s) << endl;
    return 0;
}