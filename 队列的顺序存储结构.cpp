#include "iostream"
#include "cstdio"
#include "cstdlib"


using namespace std;

#define MAXSIZE 20
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int ElemType;

// ѭ�����е�˳��洢�ṹ
typedef struct{
    ElemType data[MAXSIZE];
    int front;  // ��ͷָ��
    int rear;  // ��βָ��
}sqQueue;

// ��ʾһ��Ԫ��
Status visit(ElemType e){
    cout << "e: " << e << " ";
    return OK;
}

// ��ʼ��һ���ն���
Status InitQueue(sqQueue *q){
    q->front = 0;
    q->rear = 0;
    return OK;
}

// ���һ������
Status ClearQueue(sqQueue *q){
    q->front = q->rear = 0;
    return OK;
}

// �ж϶����Ƿ��ǿն���q.font == q.rear?
Status isEmpty(sqQueue q){
    if(q.front == q.rear)
        return TRUE;
    else
        return FALSE;
}

// ���ض��еĳ��ȣ���Ԫ�صĸ���
int queueLength(sqQueue q){
    return (q.rear - q.front + MAXSIZE) % MAXSIZE;
}

// ��ö��еĶ�ͷԪ��
Status getHead(sqQueue q, ElemType *e){
    if(q.front == q.rear)
        return ERROR;
    *e = q.data[q.front];
    return OK;
}

// ����Ԫ�أ��Ӷ�β��ʼ
Status insertQueue(sqQueue *q, ElemType e){
    if((q->rear+1) % MAXSIZE == q->front)  // ��������
        return ERROR;
    q->data[q->rear] = e;  // ��Ԫ�ظ�ֵ����β
    q->rear = (q->rear + 1) % MAXSIZE;  // rear��βָ������ƶ�һ��λ�ã�����ƶ���������������Ҫת�������ͷ��
    return OK;
}

// ɾ��Ԫ�أ��Ӷ�ͷ��ʼ
Status deleteQueue(sqQueue *q, ElemType *e){
    if(q->front == q->rear)  // �����ǿյģ�����ɾ��Ԫ��
        return ERROR;
    *e = q->data[q->front];  // �Ӷ�ͷ��ʼɾ��Ԫ��
    q->front = (q->front + 1) % MAXSIZE; // front��ͷָ������ƶ�һ��λ�ã�����ƶ���������������Ҫת�������ͷ��
    return OK;
}   

// ��������
int TravelQueue(sqQueue q){
    int i;
    i = q.front;
    while((i+q.front) != q.rear){   // �ж϶����Ƿ������ͷ��
        visit(q.data[i]);
        i = (i+1) % MAXSIZE;
    }
    return OK;
} 

int main(){
    int i = 0;
    int e;
    sqQueue q;
    InitQueue(&q);
    cout << "��ʼ�����к󣬶����Ƿ�Ϊ��(��:1,��:0)?,��: " << isEmpty(q) << endl;

    cout << "���������Ͷ���Ԫ�أ�����������" << MAXSIZE - 1 << "����-1����ǰ������\n";
    do{
        e = i + 100;
        if(e == -1)
            break;
        i++;
        insertQueue(&q, e);
    }while(i < MAXSIZE - 1);
    cout << "���еĳ�����: " << queueLength(q) << endl;
    cout << "����Ԫ�غ����ڶ����Ƿ�Ϊ��(��:1,��:0)?,��: " << isEmpty(q) << endl;
    
    cout << "����" << MAXSIZE << "���ɶ�ͷɾ��Ԫ�أ���β����Ԫ��\n";
    for(int l = 1; l <= MAXSIZE; l++){
        deleteQueue(&q, &e);
        cout << "ɾ����Ԫ����: " << e << ",�����Ԫ����: " << l + 1000 << endl;
        e = l + 1000;
        insertQueue(&q, e);
    }
    int l;
    l = queueLength(q);
    cout << "���ڶ����е�Ԫ��Ϊ:\n ";
    TravelQueue(q);

    cout << "\nһ�����β����" << i + MAXSIZE << "��Ԫ��\n";
    
    if(l-2 > 0)
        cout << "�����ɶ�ͷɾ��"  << l-2 << "��Ԫ��\n";
    while(queueLength(q) > 2){
        deleteQueue(&q, &e);
        cout << "ɾ����Ԫ��ֵ��: " << e << endl;
    }

    int j;
    j = getHead(q, &e);
    if(j)
        cout << "���ڶ�ͷԪ����: " << e << endl;

    ClearQueue(&q);
    cout << "��ն��к����ڶ����Ƿ�Ϊ��(��:1,��:0)?,��: " << isEmpty(q) << endl;
    return 0;
}
