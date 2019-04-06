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

// ���е���ʽ�洢�ṹ

// �����еĵ������Ľṹ
typedef struct queueNode{
    ElemType data;
    struct queueNode *next;
}queueNode,*queuePtr;  // typedef struct queueNode{���;}queueNode;��queueNode���ǽṹ��queueNode���͵ı���
                       // typedef struct{���;}* queuePtr;��queuePtr��ָ��ṹ��queueNode���͵�ָ��ı���
// �����Ķ��е���ʽ�洢�ṹ
typedef struct{
    queuePtr front, rear;
}linkQueue;

// ��ӡһ��Ԫ��
Status visit(ElemType e){
    cout << "e = " << e << " ";
    return OK;
}
// ����һ���յĶ���
Status InitQueue(linkQueue *Q){
    Q->front = Q->rear = (queuePtr)malloc(sizeof(queueNode));
    if(!(Q->front))
        exit(1);
    Q->front->next = NULL;
    return OK;
}

// ���ٶ���
Status destroyQueue(linkQueue *Q){
    while(Q->front){
        Q->rear = Q->front->next;
        free(Q->front);
        Q->front = Q->rear;
    }
    return OK;
}

// ��ն���
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

// �ж϶����Ƿ��ǿ�
Status isEmpty(linkQueue Q){
    if(Q.front == Q.rear)
        return TRUE;
    else
        return FALSE;
}

// ����еĳ���
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

// ��ö��еĶ�ͷԪ��
Status getHead(linkQueue Q, ElemType *e){
    queuePtr p;
    if(Q.front == Q.rear)   // �յĶ���
        return ERROR;
    p = Q.front->next;
    *e = p->data;
    return OK;
}

// ����Ԫ��---��β(���))
Status insertQueue(linkQueue *Q, ElemType e){
    queuePtr s = (queuePtr)malloc(sizeof(queueNode));
    if(!s)
        exit(1);
    s->data = e;
    s->next = NULL;
    Q->rear->next = s;  // ��ӵ��Ԫ��e���½��s��ֵ��ԭ��β���ĺ��
    Q->rear = s;  // �ѵ�ǰ��s����Ϊ��β���
    return OK;
}    

// ɾ��Ԫ��---��ͷ(����)
Status deleteQueue(linkQueue *Q, ElemType *e){
    queuePtr p;
    if(Q->front == Q->rear)   // �ն�ɾ������
        return ERROR;
    p = Q->front->next;  // ��Ҫɾ���Ķ�ͷ�����ʱ����p��
    *e = p->data;  // ��Ҫɾ���Ķ�ͷ����ֵ��ֵ��e
    Q->front->next = p->next;  // ��ԭʼ��ͷ���ĺ�̸�ֵ��ͷ���ĺ��
    if(Q->rear == p)  // �����ͷ�Ƕ�β����ɾ����rearָ��ͷ���
        Q->rear = Q->front;
    free(p);
    return OK;
}

// ���������е�ÿ��Ԫ��
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
        cout << "�ɹ��Ĺ�����һ���յĶ���\n";
    cout << "�Ƿ��ǿն���?(1:��,0:��),����: " << isEmpty(Q) << endl;
    cout << "���еĳ�����: " << queueLength(Q) << endl;

    insertQueue(&Q, -5);
    insertQueue(&Q, 5);
    insertQueue(&Q, 10);
    cout << "����3��Ԫ��(-5,5,10)��,���еĳ�����: " << queueLength(Q) << endl;
    cout << "����Ԫ�غ�,�Ƿ��ǿն���?(1:��,0:��),����: " << isEmpty(Q) << endl;
    cout << "���е�Ԫ��������: ";
    travelQueue(Q);
    
    i = getHead(Q, &e);
    if(i == OK)
        cout << "��ͷԪ����: " << e << endl;
    
    deleteQueue(&Q, &e);
    cout << "ɾ����ͷԪ��: " << e << endl;

    i = getHead(Q, &e);
    if(i == OK)
        cout << "�µĶ�ͷԪ����: " << e << endl;
    
    ClearQueue(&Q);
    cout << "��ն��к�,Q.front = " << Q.front << ", Q.rear = " << Q.rear << ", Q.front->next = " << Q.front->next << endl;
    destroyQueue(&Q);
    cout << "���ٶ��к�,Q.front = " << Q.front << ", Q.rear = " << Q.rear << endl;
    return 0;
}