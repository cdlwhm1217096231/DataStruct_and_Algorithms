#include "iostream"

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
    for(int i = 1; i < L.len; i++)
        cout << L.r[i] << " ";
    cout << endl;
}

// ϣ������
void ShellSort(Sqlist *L){
    int i, j;
    int increment = L->len;  // �����ĳ�ʼ��
    do{ // ÿִ��һ��do-whileѭ���ͻ�����һ�������У�ÿ�������е�����ʹ�õ�����increment�ǲ�ͬ�ģ��������н�ԭ��Խ��Խ���Ż�������ķ���չ
        increment = increment / 3 +1;
        for(i = increment+1; i<=L->len; i++){
            if(L->r[i] < L->r[i-increment]){  // �����Ԫ����L->r[i]�����бȽ�
                L->r[0] = L->r[i];   // ����Ҫ�Ĳ����Ԫ����ʱ�洢���ڱ���
                for(j = i-increment; j>0 && L->r[j] > L->r[0];j-=increment)
                    L->r[j+increment] = L->r[j];   // ���н�������
                L->r[j+increment] = L->r[0];
            }  
        }
    }while(increment > 1);  // ��Ծʽ���ƶ�����ֱ����������ʹ��increment=1�̶��ģ�
}

int main(){
    Sqlist L;
    int d[N] = {9, 1, 5, 8, 3, 7, 4, 6, 2};
    for(int i = 0; i < N; i++)
        L.r[i+1] = d[i];
    L.len = N;
    cout << "ϣ������ǰ: ";
    show(L);
    cout << "ϣ�������: ";
    ShellSort(&L);
    show(L);
    return 0;
}




