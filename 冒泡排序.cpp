#include "iostream"
#include <malloc.h>

using namespace std;

#define MAXSIZE 10
#define FALSE 0
#define TRUE 1
#define OK 1
#define ERROR 0

// ����һ��˳���ṹ��������

typedef int Status;

typedef struct
{
    int r[MAXSIZE + 1]; // r[0]�����洢�ڱ�λ��
    int len;            // ��¼˳���ĳ���
} Sqlist;

// ��������Ԫ��
void Swap(Sqlist *L, int i, int j)
{
    int temp = L->r[i];
    L->r[i] = L->r[j];
    L->r[j] = temp;
}

// ���δ�ӡ��Ԫ��
void show(Sqlist L)
{
    for (int i = 1; i <= L.len; i++)
        cout << L.r[i] << " ";
    cout << endl;
}

// ð������----������ʵ��
void BubbleSort(Sqlist *L)
{
    for (int i = 1; i < L->len; i++)
    {
        for (int j = i + 1; j <= L->len; j++)
        {
            if (L->r[i] > L->r[j])
                Swap(L, i, j);
        }
    }
}
// ð������----���ڰ�ʵ��
/*
    ˳���L = {9, 1, 5, 8, 3, 7, 4, 6, 2}���±�L[0]�洢�����ڱ�����ʱ����
    ˳���L���±�Ĵ�1��ʼ��{1, 2, 3, 4, 5, 6, 7, 8, 9}
    ��len(L) = 9
*/
void BubbleSort1(Sqlist *L){
    for(int i = 1; i < L->len; i++){
        for(int j = L->len-1; j >= i; j--){
            if(L->r[j] > L->r[j+1])
                Swap(L, j, j+1);
        }
    }
}

// ð������----�Ľ���ʵ��
void BubbleSort2(Sqlist *L){
    Status flag = TRUE;   // flag������Ϊ���
    for(int i = 1; i < L->len && flag; i++){
        flag = FALSE;  // ��ʼ�ı��ΪFALSE
        for(int j = L->len - 1; j >=i; j--){
            if(L->r[j] > L->r[j+1]){  // �����˽����󣬽���ǵ�ֵ���иı�
                Swap(L, j, j+1);
                flag = TRUE;
            }
        }
    }
}

#define N 9

int main()
{
    Sqlist L0;
    int d[N] = {9, 1, 5, 8, 3, 7, 4, 6, 2}; // d[0]�����ڱ�������ʱ����,����������
    for (int i = 0; i < N; i++)
        L0.r[i+1] = d[i];
    L0.len = N;
    cout << "ð������ǰ: ";
    show(L0);
    BubbleSort(&L0);
    cout << "������ð�������: ";
    show(L0);
    Sqlist L1 = L0;
    cout << "ð������ǰ: ";
    show(L1);
    BubbleSort1(&L1);
    cout << "���ڰ�ð�������: ";
    show(L1);
    Sqlist L2 = L0;
    cout << "ð������ǰ: ";
    show(L2);
    BubbleSort2(&L2);
    cout << "�Ľ���ð�������: ";
    show(L2);
    return 0;
}