#include <iostream>
#include <malloc.h>

using namespace std;

#define N 9
#define MAXSIZE 10

typedef struct
{
    int r[MAXSIZE + 1];
    int len;
} Sqlist;

void show(Sqlist L)
{
    for (int i = 1; i < L.len; i++)
        cout << L.r[i] << " ";
    cout << endl;
}

// �鲢����
void Merge(int A[], int TempA[], int L, int LeftEnd, int RightEnd)
{                // L����������е���㣻LeftEnd����������е��յ�
    int R, k, j; // k������tempA�����㣬j���ұ������еĵ���㣬RightEnd:�ұ������е��յ�
    for (j = LeftEnd + 1, k = L; L <= LeftEnd && j <= RightEnd; k++)
    {
        if (A[L] < A[j])
            TempA[k] = A[L++];
        else
            TempA[k] = A[j++];
    }
    if (L <= LeftEnd)
    {
        for (int l = 0; l <= LeftEnd - L; l++)
            TempA[k + l] = A[L + l];
    }
    if (j <= RightEnd)
    {
        for (int r = 0; r <= RightEnd - j; r++)
            TempA[k + r] = A[j + r];
    }
}
// �ݹ鷽��ʵ��
// �鲢������������
void Msort(int A[], int TempA[], int L, int RightEnd)
{
    int center;
    int TempA2[MAXSIZE + 1];
    if (L == RightEnd)
        TempA[L] = A[L];
    else
    {
        center = (L + RightEnd) / 2;
        Msort(A, TempA2, L, center);
        Msort(A, TempA2, center + 1, RightEnd);
        Merge(TempA2, TempA, L, center, RightEnd);
    }
}

// ͳһ�����ӿ�
void MergeSort(Sqlist *L)
{
    Msort(L->r, L->r, 1, L->len);
}

// �ǵݹ鷽��ʵ��
void MergePass(int A[], int TempA[], int length, int n)
{
    // length:��ǰ�����еĳ���  n:���������е�Ԫ�ظ���
    int i = 1;
    while (i <= n - 2 * length - 1)
    { // �����еĸ�����ż����
        Merge(A, TempA, i, i + length - 1, i + 2 * length - 1);
        i = i + 2 * length;
    }
    if (i < n - length + 1) // �鲢�������������
        Merge(A, TempA, i, i + length - 1, n);
    else
    { // ���ֻʣ��һ��������
        for (int j = i; j <= n; j++)
            TempA[j] = A[j];
    }
}

// ͳһ�����ӿ�
void MergeSort1(Sqlist *L)
{
    int *TempA = (int *)malloc(L->len * sizeof(int));
    int length = 1; // ��ʼ�����еĳ���
   
    while (length < L->len)
    {
        MergePass(L->r, TempA, length, L->len);
        length *= 2;
        MergePass(TempA, L->r, length, L->len);
        length *= 2;
    }
}

int main()
{
    Sqlist L;
    int d[N] = {50, 10, 90, 30, 70, 40, 80, 60, 20};
    for (int i = 0; i < N; i++)
        L.r[i + 1] = d[i];
    L.len = N;
    // cout << "�鲢����ǰ(�ݹ鷽��): ";
    // show(L);
    // cout << "�鲢�����(�ݹ鷽��): ";
    // MergeSort(&L);
    // show(L);
    cout << "-------------------------------------------------\n";
    cout << "�鲢����ǰ(�ǵݹ鷽��): ";
    show(L);
    cout << "�鲢�����(�ǵݹ鷽��): ";
    MergeSort1(&L);
    show(L);

    return 0;
}