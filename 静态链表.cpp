#include "iostream"
#include "cstdio"
#include "cstdlib"
#include "cmath"

using namespace std;


#define MAXSIZE 1000



// ��̬���������������������������е�ÿ��Ԫ�ض�����������������ɵģ�data��cur�������ÿ���±궼��Ӧ
// һ��data��һ��cur��������data�����������Ԫ�أ��α�cur����ڵ������е�nextָ�룬��Ÿ�Ԫ�صĺ���������е��±�

// ��̬�������ݽṹ
typedef struct{
    int data;
    int cur;  // �α�,��cur=0ʱ����ָ��
}Component,staticLinkList[MAXSIZE];

// ��ӡ��Ԫ�ص�ֵ
int visit(int e){
    cout << "\t" << "e:" << e << " " << endl;
    return 1;
}

// ��ʼ�������״̬
int InitList(staticLinkList space){
    for(int i = 0; i < MAXSIZE-1; i++)
        space[i].cur = i + 1;
    space[MAXSIZE - 1].cur = 0;  // ���һ��Ԫ�ص�cur��ŵ��ǵ�һ������ֵԪ�ص��±�
    return 1;
}
// ������������ǿյģ��򷵻ط���Ľڵ���±�
int malloc_ssl(staticLinkList space){
    int i = space[0].cur;  // �����±�Ϊ0��Ԫ�ؼ�����ĵ�һ��Ԫ�أ�Ԫ�ص�cur�д�ŵ��Ǳ�������ĵ�һ�������±�
    if(space[0].cur)
        space[0].cur = space[i].cur;
    return i;
}

// ���±�Ϊk�Ŀ��н����յ�����������
void free_ssl(staticLinkList space , int k){
    space[k].cur = space[0].cur;  // �������һ��Ԫ�ص�cur��ŵ��Ǳ�������ĵ�һ�������±긳ֵ��Ҫ���յķ�����k
    space[0].cur = k;  
}

// ���ؾ�̬����L�е�Ԫ�ظ���
int ListLength(staticLinkList L){
    int j = 0;
    int i = L[MAXSIZE-1].cur;
    while(i){
        i = L[i].cur;
        j++;
    }
    return j;
}

// ��L�е�i��Ԫ��֮ǰ�����µ�Ԫ��e
int ListInsert(staticLinkList L, int i, int e){
    int j, k, l;
    k = MAXSIZE - 1;  // k�����һ��Ԫ�ص��±�
    if(i < 1 || i > ListLength(L) + 1)
        return 0;
    j = malloc_ssl(L);  // ��ñ���������±�j = 7,��ʱ�±�Ϊ0��Ԫ�ص�cur��ŵ��Ǳ��������2�������±�
    if(j){  // ��ΪҪ����Ҫ�����Ԫ�����ȷ��ڱ�������ĵ�һ����㴦�ݴ棬������Ҫmalloc_ssl(L)
        L[j].data = e; // ��Ҫ�����Ԫ�ط��ڱ�������ĵ�һ�������
        for(l = 1; l <= i-1; l++)  
            k = L[k].cur; // L[999].cur:�������һ��Ԫ�ص�cur��ŵ��ǵ�һ������ֵԪ�ص��±꼴1
            // ��L[1].cur��ŵ����±�Ϊ2�Ľ����±�2
        L[j].cur = L[k].cur;  // ���±�Ϊ2�Ľ���д�ŵ�cur��ֵ����������ĵ�һ���ڵ�
        L[k].cur = j;  // �����������һ���ڵ���±긳ֵ��L[2].cur�������͸ı��˵�2���ڵ���α�cur
        return 1;  // ��ŵĲ�����һ���ڵ���±�3�����Ǳ��������һ�������±�
    }
    return 0;
}
// ɾ����i��Ԫ��
int ListDelete(staticLinkList L, int i){
    int j, k;
    if (i < 1 || i > ListLength(L))
        return 0;
    k = MAXSIZE - 1;
    for(j = 1; j <= i-1; j++)
        k = L[k].cur;
    j = L[k].cur;
    L[k].cur = L[j].cur;
    free_ssl(L, j);
    return 1;
}

// ����������̬����
int ListTravel(staticLinkList L){
    int j= 0;
    int i = L[MAXSIZE-1].cur;
    while(i){
        visit(L[i].data);
        i = L[i].cur;
        j++;
    }
    return j;
    return 1;
}

int main(){
    staticLinkList L;
    int i;
    i = InitList(L);
    cout << "��ʼ����L�ĳ���: " << ListLength(L) << endl;
    i = ListInsert(L, 1, 'F');
    i = ListInsert(L, 1, 'E');
    i = ListInsert(L, 1, 'D');
    i = ListInsert(L, 1, 'B');
    i = ListInsert(L, 1, 'A');
    cout << "ͷ�巨��Ľ��: \n";
    ListTravel(L);


    i = ListInsert(L, 3, 'C');
    cout << "��B��D֮�����C�Ľ����: \n";
    ListTravel(L);

    i = ListDelete(L, 1);
    cout << "ɾ��A��Ľ��: \n";
    ListTravel(L);
    return 0;
}