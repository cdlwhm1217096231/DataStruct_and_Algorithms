#include <iostream>
#include <malloc.h>

using namespace std;

#define MAXSIZE 10
#define N 9
#define MAX_LENGTH_INSERT_SORT 7 // ���������趨����ֵ

typedef struct
{
    int r[MAXSIZE + 1];
    int len;
} Sqlist;

void show(Sqlist L)
{
    for (int i = 1; i <= L.len; i++)
        cout << L.r[i] << " ";
    cout << endl;
}

void Swap(Sqlist *L, int i, int j)
{
    int temp = L->r[i];
    L->r[i] = L->r[j];
    L->r[j] = temp;
}

// ȷ����Ԫ
int Partition(Sqlist *L, int low, int high)
{
    int pivotkey; // ��Ԫ
    pivotkey = L->r[low];
    while (low < high)
    {
        while (low < high && L->r[high] >= pivotkey) // ����Ԫ��ķ�����Ԫ���ұߣ�������
            high--;
        Swap(L, low, high);                         // ����ԪС�ķ�����Ԫ���ұߣ����н���
        while (low < high && L->r[low] <= pivotkey) // ����ԪС�ķ�����Ԫ����ߣ�������
            low++;
        Swap(L, low, high); // ����Ԫ��ķ�����Ԫ����ߣ����н���
    }
    return low;
}

// ��������
void Qsort(Sqlist *L, int low, int high)
{
    int pivot; // ��Ԫλ��
    if (low < high)
    {
        pivot = Partition(L, low, high);
        Qsort(L, low, pivot - 1);
        Qsort(L, pivot + 1, high);
    }
}

// ͳһ�����ӿ�
void QuickSort(Sqlist *L)
{
    Qsort(L, 1, L->len);
}

// ����������Ż�
int Partition1(Sqlist *L, int low, int high)
{
    // ȷ����Ԫλ��---����ȡ�з�
    int pivotkey;
    int center = low + (high - low) / 2; // �����м�Ԫ�ص��±�
    // ���� �� ����������������
    if (L->r[low] > L->r[high])    // �����ߵ��������ұߵ��������н�������
        Swap(L, low, high);        // ��֤��ߵ�����С
    if (L->r[center] > L->r[high]) // ����м���������ұߵ��������н�������
        Swap(L, center, high);     // ��֤�м��ֵ��С
    if (L->r[center] > L->r[low])  // ����м����������ߵ��������н�������
        Swap(L, center, low);      // ��֤��ߵ�ֵ��С
    pivotkey = L->r[low];          // L->r[low]�Ѿ���Ϊ�������������������ؼ��ֵ��м�ֵ
    L->r[0] = pivotkey;
    while (low < high)
    {
        while (low < high && L->r[high] >= pivotkey)
            high--;
        L->r[low] = L->r[high]; // ʹ�õ����滻���ǽ���
        while (low < high && L->r[low] <= pivotkey)
            low++;
        L->r[high] = L->r[low]; // ʹ�õ����滻���ǽ���
    }
    L->r[low] = L->r[0]; // ���ݴ����Ԫ�滻��L->r[row]
    return low;          // ������Ԫ��λ��
}

// ֱ�Ӳ�������
void InsertSort(Sqlist *L)
{
    int i, j;
    for (i = 2; i <= L->len; i++)
    { // �����Ԫ�ش��±�Ϊ2��ʼ
        if (L->r[i] < L->r[i - 1])
        {                      // �����Ԫ�ر�֮ǰ��Ԫ��ֵС���ͽ��н�������
            L->r[0] = L->r[i]; // �±�Ϊ0��λ�ô�ŵ����ڱ�
            for (j = i - 1; L->r[j] > L->r[0]; j--)
                L->r[j + 1] = L->r[j]; // �����ƶ�����
            L->r[j + 1] = L->r[0];     // �����µ�Ԫ�ص���ȷ��λ��
        }
    }
}

// ��Ϊ���������ʺ����ڴ���������кܴ���������������һ����ֵ
void Qsort1(Sqlist *L, int low, int high)
{
    int pivot;
    if ((high - low) > MAX_LENGTH_INSERT_SORT)
    {
        pivot = Partition1(L, low, high);
        Qsort1(L, low, pivot - 1);
        Qsort1(L, pivot + 1, high);
    }
    else
    {
        InsertSort(L);
    }
}
// ����Qsort1()��������β�������εĵݹ�������������������л��ּ���ƽ��ʱ���ݹ���Ƚ�����n���˷�ջ�ռ�
// ʹ��β�ݹ�
void Qsort2(Sqlist *L, int low, int high)
{
    int pivot;
    if ((high - low) > MAX_LENGTH_INSERT_SORT)
    {
        while (low < high)
        {
            pivot = Partition1(L, low, high);
            Qsort2(L, low, pivot - 1);
            low = pivot + 1;  // β�ݹ�
        }
    }
    else
    {
        InsertSort(L);
    }
}

// ͳһ�����ӿ�:�Ľ���Ŀ�������
void QuickSort1(Sqlist *L){
    Qsort1(L, 1, L->len);
}

// ͳһ�����ӿڣ��Ľ���Ŀ�������ʹ��β�ݹ�
void QuickSort2(Sqlist *L){
    Qsort2(L, 1, L->len);
}

int main()
{
    Sqlist L;
    int d[N] = {50, 10, 90, 30, 70, 40, 80, 60, 20};
    for (int i = 0; i < N; i++)
        L.r[i + 1] = d[i];
    L.len = N;
    cout << "��������ǰ: ";
    show(L);
    cout << "���������: ";
    QuickSort(&L);
    show(L);

    cout << "�Ľ��Ŀ��������: ";
    QuickSort1(&L);
    show(L);
    
    cout << "�Ľ��Ŀ�������(β�ݹ�)��: ";
    QuickSort2(&L);
    show(L);
    return 0;
}