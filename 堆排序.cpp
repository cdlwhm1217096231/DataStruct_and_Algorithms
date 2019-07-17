#include <iostream>

using namespace std;

#define N 9
#define MAXSIZE 10
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef struct{
    int r[MAXSIZE+1];
    int len;
}Sqlist;

void show(Sqlist L){
    for(int i = 1; i <= L.len; i++)
        cout << L.r[i] << " ";
    cout << endl;
}

void Swap(Sqlist *L, int i, int j){
    int temp = L->r[i];
    L->r[i] = L->r[j];
    L->r[j] = temp;
}
// ��������Ҫ���ǵ��������⣺
/*
    1.��ν�һ����������й����һ����/С����
    2.������Ѷ�Ԫ�غ���ô����ʣ���Ԫ�أ�ʹʣ���Ԫ�س�Ϊһ���µĴ�/С����
*/
// �ѵ�������
// ��֪L->r[s..m]�еļ�¼�Ĺؼ��ֳ�L->r[s]֮�������ѵĶ��壬��Ҫ�����Ĺؼ�����L->r[s],ʹL->r[s...m]��Ϊһ���󶥶�
void HeapAdjust(Sqlist *L, int s, int m){
    int temp, j;
    temp = L->r[s];  // L->r[s]������ѵ���������Ҫ�����Ĺؼ�����L->r[s]
    for(j = 2*s; j <= m; j*=2){  // ѭ��������ǰ���s�����Һ���j����Ϊ����ȫ���������������ӵ������2*s���Һ��ӵ������2*s+1
        if(j < m && L->r[j] < L->r[j+1])  // L->r[j]������,L->r[j+1]���Һ���,j<m˵����ǰ�ĺ��ӽ�㲻�����һ�����
            ++j;  // L->r[j] < L->r[j+1]˵������С���Һ���,˵�����ֵ���Һ��ӽ����
        if(temp >= L->r[j])  // ��ǰ�Ľ��s�������ֵ������Ҫ������ֱ������ѭ��
            break;
        L->r[s] = L->r[j];  // ����ǰ���s�����Һ��ӽ��j���н����������ɴ󶥶�
        s = j;
    }
    L->r[s] = temp;
}

// ����ĳ������Դ󶥶�Ϊ��������
// ��������
void HeapSort(Sqlist *L){
    int i;
    // ������һ���󶥶�,ʱ�临�Ӷ���O(n)
    for(i = L->len / 2; i >0; i--)  // ��L�е�r[i]�����һ���󶥶ѣ�i��L->len / 2��ʼ����Ϊ���Ƕ��������Һ��ӵĽ��
        HeapAdjust(L, i, L->len);
    // �ؽ���һ���󶥶ѣ�ʱ�临�Ӷ���O(nlogn)
    for(i = L->len; i > 1; i--){    // �𲽽�ÿ�����ֵ�ĸ��������ȫ�������е�ĩβԪ�ؽ��н����������ٵ���ʹ���Ϊһ���µĴ󶥶�
        Swap(L, 1, i);   // ���Ѷ�Ԫ��1�뵱ǰδ������������е����һ��Ԫ��i���н���
        HeapAdjust(L, 1, i-1);  // ��L->r[1...i-1]���µ���Ϊ�󶥶�
    }
}



int main(){
    Sqlist L;
    int d[N] = {50, 10, 90, 30, 70, 40, 80, 60, 20};
    for(int i = 0; i < N; i++)
        L.r[i+1] = d[i];
    L.len = N;
    cout << "������ǰ: ";
    show(L);
    cout << "�������: ";
    HeapSort(&L);
    show(L);
    return 0;
}