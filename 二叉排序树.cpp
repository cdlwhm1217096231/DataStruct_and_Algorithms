#include "iostream"
#include "malloc.h"
using namespace std;


#define ERROR 0
#define OK 1
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100

typedef int Status;

// ʹ�ö��������ʾһ���������Ľ��
typedef struct BiTNode{ 
    int data;
    BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

// �����������Ĳ��Ҳ���
Status BinaryTree_Search(BiTree T, int key, BiTree f, BiTree *p){
    // T:��ʾ��ǰ�Ľ��   key:��ʾҪ�����Ĺؼ��� f:��ʾT��˫�׽�㣬 p:�������ؽ��
    if(!T){  // ���T = NULL��˵����ǰ����Ǹ���㣬��˫�׽�㣬��ʱf = NULL
        *p = f; 
        return FALSE;
    }
    else if(key == T->data){  // ���ҳɹ�
        *p = T;
        return TRUE;
    }
    else if(key < T->data){
        return BinaryTree_Search(T->lchild, key, T, p);  // �ؼ���С�ڵ�ǰ����ֵ����˵���ؼ������������ϣ��ݹ���ö���������
    }
    else if(key > T->data){
        return BinaryTree_Search(T->rchild, key, T, p); // �ؼ��ִ��ڵ�ǰ����ֵ����˵���ؼ������������ϣ��ݹ���ö���������
    }
}

// �����������Ĳ������(�Ȳ��ҵ�ǰ�Ķ������������Ƿ��Ѿ���key,û�еĻ����в������������TRUE�����򷵻�FALSE������Ҫ����)
Status BinaryTree_Insert(BiTree *T, int key){
    BiTree p, s;
    if(!BinaryTree_Search(*T, key, NULL, &p)){  // ��ǰ������������û�в��ҵ����ԣ���Ҫ���в������
        s = (BiTree)malloc(sizeof(BiTNode));  // �²���Ľ��s
        s->data = key;
        s->lchild = s->rchild = NULL;
        if(!p)  // ��ǰ�Ķ�����Ϊ���������²���Ľ��s��Ϊ�����
            *T = s;
        else if(key < p->data)  // ��ǰ���pΪ�ڲ���㣬�����keyС�ڵ�ǰ���p->data,��s����p����������
            p->lchild = s;
        else
            p->rchild = s;
        return TRUE;  // ����ɹ�
    }  
    else
        return FALSE;   // ԭʼ�Ķ������������Ѿ�����key���Ͳ���Ҫ���в������������FALSE
}


// ������������ɾ������(���������)

// �����ɾ������----p������Ҫɾ���Ľ��
Status Delete(BiTree *p){
    BiTree q, s;
    if((*p)->lchild == NULL){  // ҪҪɾ���Ľ��pֻ�����������������2
        q = *p;
        *p = (*p)->rchild;
        free(q);
    }
    else if((*p)->rchild == NULL){  // Ҫɾ���Ľ��pֻ�����������������2
        q = *p;
        *p = (*p)->lchild;
        free(q);
    }  
    else{  // Ҫɾ���Ľ��pͬʱ�������������������3.��ʱ��ʹ��ɾ�����p��ֱ��ǰ����ֱ�Ӻ�̽ڵ�������Ҫɾ���Ľڵ�p
        q = *p;
        s = (*p)->lchild;  // ����Ҫɾ�����p���������еĵ�һ�����s
        while(s->rchild){  // ����s�����������ҵ�Ҫɾ�����p��ֱ��ǰ�����
            q = s;
            s = s->rchild;
        }
        (*p)->data = s->data;   // ��ɾ���ڵ�p��ֱ��ǰ�����s����Ҫɾ���Ľ��p
        if(q != *p)
            q->rchild = s->lchild;  // �������2����ǰ�ڵ�sֻ�������������
        else    
            q->lchild = s->lchild;
        free(s);
    }
    return TRUE;  // ɾ���ɹ���
}

Status BinaryTree_Delete(BiTree *T, int key){
    if(!*T)  // �����������в�������Ҫɾ���Ŀ��ԣ�ֱ�ӷ���FALSE
        return FALSE;   
    else{
        if(key == (*T)->data)  // ��ǰ�Ľ�����Ҫɾ����key
            return Delete(T);
        else if(key < (*T)->data)  // �ؼ���keyС�ڵ�ǰ�Ľ��T����ؼ����ڵ�ǰ������������
            return BinaryTree_Delete(&(*T)->lchild, key);
        else
            return BinaryTree_Delete(&(*T)->rchild, key);  // �ؼ���key���ڵ�ǰ�Ľ��T����ؼ����ڵ�ǰ������������
    }
}


int main(){
    // �����������Ĳ��Ҳ���
    int a[10] = {62,88,58,47,35,73,51,99,37,93};
    BiTree T = NULL;
    for(int i = 0; i < 10; i++)
        BinaryTree_Insert(&T, a[i]);  // ���β�����a[i]
    BinaryTree_Delete(&T, 93);
    BinaryTree_Delete(&T, 47);
    cout << "������ϵ���ٶ����������Ľṹ\n";
    return 0;
}