#include "iostream"
#include "malloc.h"

using namespace std;

#define MAXSIZE 20
#define ERROR 0
#define OK 1
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int ElemType;

// 队列的链式存储结构

// 队列中的单个结点的结构
typedef struct queueNode{
    ElemType data;
    struct queueNode *next;
}queueNode,*queuePtr;  // typedef struct queueNode{语句;}queueNode;即queueNode就是结构体queueNode类型的别名
                       // typedef struct{语句;}* queuePtr;即queuePtr是指向结构体queueNode类型的指针的别名
// 完整的队列的链式存储结构
typedef struct{
    queuePtr front, rear;
}linkQueue;

// 打印一个元素
Status visit(ElemType e){
    cout << "e = " << e << " ";
    return OK;
}
// 构造一个空的队列
Status InitQueue(linkQueue *Q){
    Q->front = Q->rear = (queuePtr)malloc(sizeof(queueNode));
    if(!(Q->front))
        exit(1);
    Q->front->next = NULL;
    return OK;
}

// 销毁队列
Status destroyQueue(linkQueue *Q){
    while(Q->front){
        Q->rear = Q->front->next;
        free(Q->front);
        Q->front = Q->rear;
    }
    return OK;
}

// 清空队列
Status ClearQueue(linkQueue *Q)
{
	queuePtr p,q;
	Q->rear=Q->front;
	p = Q->front->next;
	Q->front->next = NULL;
	while(p)
	{
		 q=p;
		 p = p->next;
		 free(q);
	}
	return OK;
}

// 判断队列是否是空
Status isEmpty(linkQueue Q){
    if(Q.front == Q.rear)
        return TRUE;
    else
        return FALSE;
}

// 求队列的长度
int queueLength(linkQueue Q){
    int i = 0;
    queuePtr p;
    p = Q.front;
    while(Q.rear != p){
        i++;
        p = p->next;
    }
    return  i;
}

// 获得队列的队头元素
Status getHead(linkQueue Q, ElemType *e){
    queuePtr p;
    if(Q.front == Q.rear)   // 空的队列
        return ERROR;
    p = Q.front->next;
    *e = p->data;
    return OK;
}

// 插入元素---队尾(入队))
Status insertQueue(linkQueue *Q, ElemType e){
    queuePtr s = (queuePtr)malloc(sizeof(queueNode));
    if(!s)
        exit(1);
    s->data = e;
    s->next = NULL;
    Q->rear->next = s;  // 把拥有元素e的新结点s赋值给原队尾结点的后继
    Q->rear = s;  // 把当前的s设置为队尾结点
    return OK;
}    

// 删除元素---队头(出队)
Status deleteQueue(linkQueue *Q, ElemType *e){
    queuePtr p;
    if(Q->front == Q->rear)   // 空队删除出错
        return ERROR;
    p = Q->front->next;  // 将要删除的队头结点暂时存在p中
    *e = p->data;  // 将要删除的队头结点的值赋值给e
    Q->front->next = p->next;  // 将原始队头结点的后继赋值给头结点的后继
    if(Q->rear == p)  // 如果队头是队尾，则删除后将rear指向头结点
        Q->rear = Q->front;
    free(p);
    return OK;
}

// 遍历队列中的每个元素
Status travelQueue(linkQueue Q){
    queuePtr p;
    p = Q.front->next;
    while(p){
        visit(p->data);
        p = p->next;
    }
    cout << endl;
    return OK;
}

int main(){
    int i;
    ElemType e;
    linkQueue Q;
    i = InitQueue(&Q);
    if(i)
        cout << "成功的构造了一个空的队列\n";
    cout << "是否是空队列?(1:空,0:是),答案是: " << isEmpty(Q) << endl;
    cout << "队列的长度是: " << queueLength(Q) << endl;

    insertQueue(&Q, -5);
    insertQueue(&Q, 5);
    insertQueue(&Q, 10);
    cout << "插入3个元素(-5,5,10)后,队列的长度是: " << queueLength(Q) << endl;
    cout << "插入元素后,是否是空队列?(1:空,0:是),答案是: " << isEmpty(Q) << endl;
    cout << "队列的元素依次是: ";
    travelQueue(Q);
    
    i = getHead(Q, &e);
    if(i == OK)
        cout << "队头元素是: " << e << endl;
    
    deleteQueue(&Q, &e);
    cout << "删除队头元素: " << e << endl;

    i = getHead(Q, &e);
    if(i == OK)
        cout << "新的队头元素是: " << e << endl;
    
    ClearQueue(&Q);
    cout << "清空队列后,Q.front = " << Q.front << ", Q.rear = " << Q.rear << ", Q.front->next = " << Q.front->next << endl;
    destroyQueue(&Q);
    cout << "销毁队列后,Q.front = " << Q.front << ", Q.rear = " << Q.rear << endl;
    return 0;
}