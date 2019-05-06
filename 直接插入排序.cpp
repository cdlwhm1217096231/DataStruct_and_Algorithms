#include "iostream"

using namespace std;

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 10

typedef int Status;
typedef struct
{
    int r[MAXSIZE];
    int len;
} Sqlist;

void show(Sqlist L)
{
    for (int i = 1; i < L.len; i++)
        cout << L.r[i] << " ";
    cout << endl;
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
            L->r[j + 1] = L->r[0];  // �����µ�Ԫ�ص���ȷ��λ��
        }
    }
}

#define N 9

int main(){
    Sqlist L0;
    int d[N] = {9, 1, 5, 8, 3, 7, 4, 6, 2};
    for(int i = 0; i < N; i++)
        L0.r[i+1] = d[i];
    L0.len = N;
    cout << "ֱ�Ӳ�������ǰ: ";
    show(L0);
    cout << "ֱ�Ӳ��������: ";
    InsertSort(&L0);
    show(L0);
    return 0;
}