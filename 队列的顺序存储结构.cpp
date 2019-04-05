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

// 循环队列的顺序存储结构
typedef struct{
    ElemType data[MAXSIZE];
    int front;  // 队头指针
    int rear;  // 队尾指针
}sqQueue;

// 显示一个元素
Status visit(ElemType e){
    cout << "e: " << e << " ";
    return OK;
}

// 初始化一个空队列
Status InitQueue(sqQueue *q){
    q->front = 0;
    q->rear = 0;
    return OK;
}

// 清空一个队列
Status ClearQueue(sqQueue *q){
    q->front = q->rear = 0;
    return OK;
}

// 判断队列是否是空队列q.font == q.rear?
Status isEmpty(sqQueue q){
    if(q.front == q.rear)
        return TRUE;
    else
        return FALSE;
}

// 返回队列的长度，即元素的个数
int queueLength(sqQueue q){
    return (q.rear - q.front + MAXSIZE) % MAXSIZE;
}

// 获得队列的队头元素
Status getHead(sqQueue q, ElemType *e){
    if(q.front == q.rear)
        return ERROR;
    *e = q.data[q.front];
    return OK;
}

// 插入元素，从队尾开始
Status insertQueue(sqQueue *q, ElemType e){
    if((q->rear+1) % MAXSIZE == q->front)  // 队列满啦
        return ERROR;
    q->data[q->rear] = e;  // 将元素赋值给队尾
    q->rear = (q->rear + 1) % MAXSIZE;  // rear队尾指针向后移动一个位置，如果移动到达数组的最后，则要转到数组的头部
    return OK;
}

// 删除元素，从队头开始
Status deleteQueue(sqQueue *q, ElemType *e){
    if(q->front == q->rear)  // 队列是空的，不能删除元素
        return ERROR;
    *e = q->data[q->front];  // 从队头开始删除元素
    q->front = (q->front + 1) % MAXSIZE; // front队头指针向后移动一个位置，如果移动到达数组的最后，则要转到数组的头部
    return OK;
}   

// 遍历队列
int TravelQueue(sqQueue q){
    int i;
    i = q.front;
    while((i+q.front) != q.rear){   // 判断队列是否遍历到头了
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
    cout << "初始化队列后，队列是否为空(是:1,否:0)?,答案: " << isEmpty(q) << endl;

    cout << "请输入整型队列元素，个数不超过" << MAXSIZE - 1 << "个，-1是提前结束符\n";
    do{
        e = i + 100;
        if(e == -1)
            break;
        i++;
        insertQueue(&q, e);
    }while(i < MAXSIZE - 1);
    cout << "队列的长度是: " << queueLength(q) << endl;
    cout << "插入元素后，现在队列是否为空(是:1,否:0)?,答案: " << isEmpty(q) << endl;
    
    cout << "连续" << MAXSIZE << "次由队头删除元素，队尾插入元素\n";
    for(int l = 1; l <= MAXSIZE; l++){
        deleteQueue(&q, &e);
        cout << "删除的元素是: " << e << ",插入的元素是: " << l + 1000 << endl;
        e = l + 1000;
        insertQueue(&q, e);
    }
    int l;
    l = queueLength(q);
    cout << "现在队列中的元素为:\n ";
    TravelQueue(q);

    cout << "\n一共向队尾插入" << i + MAXSIZE << "个元素\n";
    
    if(l-2 > 0)
        cout << "现在由队头删除"  << l-2 << "个元素\n";
    while(queueLength(q) > 2){
        deleteQueue(&q, &e);
        cout << "删除的元素值是: " << e << endl;
    }

    int j;
    j = getHead(q, &e);
    if(j)
        cout << "现在队头元素是: " << e << endl;

    ClearQueue(&q);
    cout << "清空队列后，现在队列是否为空(是:1,否:0)?,答案: " << isEmpty(q) << endl;
    return 0;
}
