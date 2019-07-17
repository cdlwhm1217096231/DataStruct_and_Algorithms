#include <iostream>

using namespace std;

#define MAXSIZE 10
#define N 9
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0

typedef int Status;
typedef struct{
    int r[MAXSIZE+1];  // ��11��Ԫ�أ�����r[0]���ڱ�����ʱ������λ��
    int len;
}Sqlist;

// ��������Ԫ�ص�ֵ
void Swap(Sqlist *L, int i, int j){
    int temp = L->r[i];
    L->r[i] = L->r[j];
    L->r[j] = temp;
}

// ��ӡԪ�ص�ֵ
void show(Sqlist L){
    for(int i = 1; i <= L.len; i++)
        cout << L.r[i] << " ";
    cout << endl;
}

// ��ѡ������
void SelectSort(Sqlist *L){
    int min;
    for(int i = 1; i < L->len; i++){
        min = i;  // ����ǰ���±���Ϊ��Сֵ����Ӧ���±�
        for(int j = i+1; j <= L->len; j++){
            if(L->r[min] > L->r[j])  // �����С�ڵ�ǰ��Сֵ�Ĺؼ��ִ��ڣ��ͰѸùؼ��ֵ��±긳ֵ��min
                min = j;
        }
        if(i != min)  // ���min������i��˵���ҵ�����Сֵ������L->[min]��L->[i]��ֵ
            Swap(L, i, min);

    }
}

int main(){
    Sqlist L0;
    int d[N] = {9, 1, 5, 8, 3, 7, 4, 6, 2};
    for(int i = 0; i < N; i++){
        L0.r[i+1] = d[i];
    }
    L0.len = N;
    cout << "��ѡ������ǰ: ";
    show(L0);
    cout << "��ѡ�������: ";
    SelectSort(&L0);
    show(L0);
    return 0;
}
