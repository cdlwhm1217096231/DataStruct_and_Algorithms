#include "iostream"
#include "malloc.h"
#include "cmath"

using namespace std;

#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAX_TREE_SIZE 100   // �����������������

typedef int Status;
typedef int ElemType;
typedef ElemType seqBiTree[MAX_TREE_SIZE];  // �����±�Ϊ0��Ԫ�ر�ʾ���Ǹ����

typedef struct{
    int level, order;  // ������Ĳ�ͱ������(��������������)
}position;

ElemType nil = 0;  // ��ʾ�ý��Ϊ��

// ��ӡһ�����
Status visit(ElemType e){
    cout << "e:" << e << " ";
    return OK;
}
// ����һ���յĶ�����
Status initBiTree(seqBiTree T){  // seqBiTree T�ȼ��� int T[MAX_TREE_SIZE];
    for(int i = 0; i < MAX_TREE_SIZE; i++)
        T[i] = nil;
    return OK;
}
// ����������������н���ֵ������˳��洢�Ķ�����T
Status createBiTree(seqBiTree T){
    int i = 0;
    cout << "�밴�����������ֵ(����),0��ʾ�ս�㣬����999����.�����<=" << MAX_TREE_SIZE << endl;
    while(i < 10){  // �����д洢1��10��ʮ������
        T[i] = i + 1;  // Ϊÿ����㸳ֵ
        // ���з������ж�
        if(i!=0 && T[(i+1)/2-1] == nil && T[i] != nil){
            cout << "������˫�׵ķǸ����:" << T[i] << endl;
            exit(ERROR);
        }
        i++;
    }

    while(i < MAX_TREE_SIZE){
        T[i] = nil;  // ��ʣ�µĽ�㸳ֵΪ��
        i++;
    }
    return OK;
}

// ��������˳��洢�ṹ�У���ն�������ͬ�ڳ�ʼ��������
#define clearBiTree initBiTree

// �ж϶������Ƿ��ǿյ�
Status isEmpty(seqBiTree T){
    if(T[0] == nil)
        return TRUE;
    else    
        return FALSE;
}

// ������������μ��������depth,һ������i����������powl(2, i-1)�����
int BiTreeDepth(seqBiTree T){
    int i, j = -1;
    for(i = MAX_TREE_SIZE -1; i >= 0; i--){  // �ҵ����һ�����,i�������һ��Ԫ�ص��±꣬j�����Ĳ���
        if(T[i] != nil)  
            break;
    }
    i++;  // ���Ľ������1
    /*
    ����      �ò�����
    1            1
    2            2
    3            4
    4            8
    ���i = 7,��Ϊ4 < 7 < 8,���Ըý���ڵ�4��
    */
    do{
        j++;  // �������
    }while(i >= powl(2, j));  // 2��j�η�
    return j;  // ���ؽ�����ڵĲ���
}

// ���ض������ĸ����
Status root(seqBiTree T, ElemType *e){
    if(isEmpty(T))  // �յĶ�������û�и����
        return ERROR;  
    else{
        *e = T[0];  // ��������ֵ��ֵ��e
        return OK;
    }
}

// ���ش���ĳ����ĳ������ֵ
ElemType value(seqBiTree T, position e){  // e��ĳ����ĳ������λ��,�������ص��Ǵ��ڱ�����ĳ��λ��e���Ľ���ֵ
    return T[(int)powl(2, e.level-1) + e.order -2];  // ��i����������powl(2, i-1)�����,order�ǽ���ڱ����е����
}

// ������ĳ����λ��e���Ľ�㸳��ֵ
Status assign(seqBiTree T, position e, ElemType  value){
    int i = (int)powl(2, e.level-1) + e.order -2;  
    if(value != nil && T[(i+1)/2-1]==nil) // ��ֹ������Ҷ�ӽ�㸳�ǿ�ֵ��˫��Ϊ��
        return ERROR;
    else if(value == nil && (T[i*2+1] != nil || T[i*2+2] != nil))  // ��˫�׸���ֵ����Ҷ�ӽ��
        return ERROR;
    T[i] = value;
    return OK;
}

// ������e��ĳһ����Ҳ��ǷǸ����ʱ����������˫�ף����򷵻ؿյ�
ElemType parent(seqBiTree T, ElemType e){
    if(T[0] == nil)  // ����
        return nil;
    for(int i = 1; i <=MAX_TREE_SIZE-1;i++){
        if(T[i] == e)  // �ҵ����e
            return T[(i+1)/2-1];
    }
    return nil;  // û�ҵ�e   
}

// ������������ڣ�e�����е�ĳ����㣬����e������
ElemType leftChild(seqBiTree T, ElemType e){
    if(T[0] == nil)
        return nil;
    for(int i = 0; i <= MAX_TREE_SIZE-1; i++)
        if(T[i] == e)  // �ҵ�e
            return T[2*i+1];
    return nil;  // û�ҵ�e
}

// ����������ǿյĶ�������e�����е�ĳ����㣬����e���Һ���
ElemType rightChild(seqBiTree T, ElemType e){
    if(T[0] == nil)
        return nil;
    for(int i=0; i <= MAX_TREE_SIZE-1; i++)
        if(T[i] == e)
            return T[i*2 +2];
    return nil;
}

// ����������Ƿǿն�������e�����е�ĳ����㣬����e�����ֵܣ����e��T�����ӻ������ֵܣ��򷵻ؿ�
ElemType leftsibling(seqBiTree T, ElemType e){
    if(T[0] == nil)
        return nil;
    for(int i=1; i <=MAX_TREE_SIZE-1; i++)
        if(T[i]==e&&i%2==0)  // �ҵ�e�����Ϊż��(e���Һ���)
            return T[i-1];  // ��������
    return nil;  // û�ҵ�e
}

// ����������Ƿǿն�������e�����е�ĳ����㣬����e�����ֵܣ����e��T���Һ��ӻ������ֵܣ��򷵻ؿ�
ElemType rightsibling(seqBiTree T, ElemType e){
    if(T[0] == nil)
        return nil;
    for(int i=1; i < MAX_TREE_SIZE-1; i++)
        if(T[i] == e && i % 2) // �ҵ�e�������Ϊ����(e������)
            return T[i+1];
    return nil;
}

// ǰ�������������˳��
void preTravelTree(seqBiTree T, int e){
    visit(T[e]);
    if(T[2*e+1] != nil)  // ����������
        preTravelTree(T, 2*e+1);  // �ݹ����
    if(T[2*e+2] != nil)  // ����������
        preTravelTree(T, 2*e+2);
}


// ǰ�����
Status preOrderTravel(seqBiTree T){
    if(!isEmpty(T))   // �ǿն�����
        preTravelTree(T, 0);
    cout << endl;
    return OK;
}

// ���������������˳��
void midTravelTree(seqBiTree T, int e){
    if(T[2*e+1] != nil)  // ����������
        midTravelTree(T, 2*e+1);
    visit(T[e]);
    if(T[2*e+2] != nil)  // ����������
        midTravelTree(T, 2*e+2);
}

// �������
Status midOrderTravel(seqBiTree T){
    if(!isEmpty(T))
        midTravelTree(T, 0);
    cout << endl;
    return OK;
}

// ��������������е�˳��
void afterTravelTree(seqBiTree T, int e){
    if(T[2*e+1] != nil)  // ����������
        afterTravelTree(T, 2*e+1);
    if(T[2*e+2] != nil)  // ����������
        afterTravelTree(T, 2*e+2);
    visit(T[e]);
}

// �������
Status afterOrderTravel(seqBiTree T){
    if(!isEmpty(T))
        afterTravelTree(T, 0);
    cout << endl;
    return OK;
}

// �������
void levelOrderTravel(seqBiTree T){
    int i = MAX_TREE_SIZE-1,j;
    while(T[i] == nil)  // �ж�ĳ������Ƿ��ǿս��
        i--;   // �ҵ����һ���ǿս������
    for(j = 0; j <=i; j++)  // �Ӹ�����𣬰��������������
        if(T[j] != nil)
            visit(T[j]);  // ֻ�����ǿյĽ��
    cout << endl;
}

// ��㡢������������������
void printTree(seqBiTree T){
    int j, k;
    position p;
    ElemType e;
    for(j=1;j <= BiTreeDepth(T);j++){
        p.level = j;  // ����
        p.order = k;  // ĳ����ĳ������ڵ�ǰ���е����
        e = value(T, p);  // ����ĳ�����
        if(e!=nil)
            cout << "k:" << k << ",e:" << e;
    }
    cout << endl;
}

int main(){
    int i;
    position p;
    ElemType e;
    seqBiTree T;
    initBiTree(T);
    createBiTree(T);
    cout << "������������,���Ƿ��ǿ���(1:��,0:��):" << isEmpty(T) << ",���������:" << BiTreeDepth(T) << endl;
    i = root(T, &e);
    if(i)
        cout << "�������ĸ������: " << e << endl;
    else    
        cout << "�������޸�\n";
    cout << "�������������:";
    levelOrderTravel(T);
    cout << "ǰ�����������:";
    preOrderTravel(T);
    cout << "�������������:";
    midOrderTravel(T);
    cout << "�������������:";
    afterOrderTravel(T);
    cout << "�޸Ĳ��3�����������2�Ľ��\n";
    p.level = 3;
    p.order = 2;
    e = value(T, p);
    cout << "���޸Ľ���ԭʼֵ��:" << e << ",��������ֵ:50\n";
    e = 50;
    assign(T, p, e);
    cout << "ǰ�����������:";
    preOrderTravel(T);
    cout << "���" << e << "��˫��Ϊ:" << parent(T, e) << ",���Һ��ӷֱ�Ϊ:" << leftChild(T, e) << "," << rightChild(T, e) << ",";
    cout << "�����ֱֵܷ�Ϊ: " << leftsibling(T, e) << "," << rightsibling(T, e) << endl;
    clearBiTree(T);
    cout << "�����������,���Ƿ��ǿ���(1:��,0:��):" << isEmpty(T) << ",���������:" << BiTreeDepth(T) << endl;
    i = root(T, &e);
    if(i)
        cout << "�������ĸ������:" << e << endl;
    else
        cout << "�������޸�\n";
    return 0;
}