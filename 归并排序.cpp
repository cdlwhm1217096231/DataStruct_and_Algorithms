#include <iostream>
#include <malloc.h>

using namespace std;


// ���������н��кϲ�����
// A�Ǵ����������  TempA����ʱ����洢�м���
// L��������  R:�ұ����  RightEnd:�ұ��յ�λ��
void Merge(int A[], int TempA[], int L, int R, int RightEnd)
{
    int LeftEnd, Tmp, NumElements;
    LeftEnd = R - 1;
    Tmp = L;  // ��Ž��������ĳ�ʼλ��
    NumElements = RightEnd - L + 1;  // Ԫ�ظ���
    while (L <= LeftEnd && R <= RightEnd)
    {
        if (A[L] <= A[R])
            TempA[Tmp++] = A[L++];
        else
            TempA[Tmp++] = A[R++];
    }
    while (L <= LeftEnd)   // ֱ�Ӹ��Ƶ����ʣ�µ�
        TempA[Tmp++] = A[L++];
    while (R <= RightEnd)  // ֱ�Ӹ��Ƶ��ұ�ʣ�µ�
        TempA[Tmp++] = A[R++];
    for (int i = 0; i < NumElements; i++, RightEnd--)  // ����ʱ����Ľ�����µ���A��
        A[RightEnd] = TempA[RightEnd];
}
// ����1
// �ݹ鷽��ʵ�ֹ鲢����
void Msort(int A[], int TempA[], int L, int RightEnd)
{
    int center;
    if (L < RightEnd)
    {
        center = (L + RightEnd) / 2;
        Msort(A, TempA, L, center);
        Msort(A, TempA, center + 1, RightEnd);
        Merge(A, TempA, L, center + 1, RightEnd);
    }
}

// ͳһ�����ӿڣ�����Msort()�������û������벻�Ѻã����Բ���ͳһ�ĺ����ӿڽ��з�װ
void Merge_Sort(int *A, int N)
{
    int *TempA = (int *)malloc(N * sizeof(int));
    if (TempA != NULL)
    {
        Msort(A, TempA, 0, N - 1);
        free(TempA);
    }
    else
    {
        cout << "�ռ䲻��!\n";
    }
}

// ����2
// �ǵݹ鷽��ʵ�ֹ鲢����
void Merge_Pass(int A[], int TempA[], int N, int length)
{
    int i;
    for (i = 0; i <= N - 2 * length; i += 2 * length)
        Merge(A, TempA, i, i + length, i + 2 * length - 1);   // ��A��Ԫ�ع鲢��TempA
    if (i + length < N)   // �鲢���2������
        Merge(A, TempA, i, i + length, N - 1);   // �ٽ�TempA��Ԫ�����µ��뵽A
    else  // ���ֻʣһ������
    {
        for (int j = i; j < N; j++)
            TempA[j] = A[j];
    }
}

// ͳһ�����ӿ�
void Merge_Sort2(int *A, int N)
{
    int length = 1;  // ��ʼ�����г���
    int *TempA = (int *)malloc(N * sizeof(int));
    if (TempA != NULL)   // ˳���������˿ռ�
    {
        while (length < N)
        {
            Merge_Pass(A, TempA, N, length);
            length *= 2;
            Merge_Pass(TempA, A, N, length);
            length *= 2;
        }
        free(TempA);  // �����٣�����
    }
    else
    {
        cout << "�ռ䲻��!\n";
    }
}

void show(int *A, int N){
    for(int i=0; i <N; i++)
        cout << A[i] << " ";
    cout << endl;
}

int main(){
    int A[] = {50,10,90,30,70,40,80,60,20};
    // cout << "�鲢����ǰ(�ݹ鷽��): ";
    // show(A, 9);
    // Merge_Sort(A, 9);
    // cout << "�鲢�����(�ݹ鷽��): ";
    // show(A, 9);
    cout << "-------------------------------------------\n";
    cout << "�鲢����ǰ(�ǵݹ鷽��): ";
    show(A, 9);
    Merge_Sort2(A, 9);
    cout << "�鲢�����(�ǵݹ鷽��): ";
    show(A, 9);
    return 0;
}