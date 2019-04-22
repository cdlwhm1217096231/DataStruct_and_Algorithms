#include "iostream"

using namespace std;

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100

typedef int Status;



// ˳������---���ڱ�˳�����
int sequenceSearch(int *a, int n, int key){
    for(int i = 1; i <= n; i++){  // ������±��Ǵ�1��ʼ��
        if(a[i] == key)
            return i;  // ���ҳɹ�
    }
    return 0;  // ����ʧ��
}


// ˳������---���ڱ�˳�����
// ��������㷨�е�forѭ��ÿ�ζ�Ҫ�ж��±��Ƿ�Խ������Ż���ʹ���ڱ������ڱ����������β��
int sequenceSearch2(int *a, int n, int key){
    a[n-1] = key;
    int i = 0;
    while(a[i] != key){
        ++i;
    }
    return i;  // ����n-1ʱ��˵��0��n-2��Χ�ڲ���ʧ��
}

int main(){
    int a[MAXSIZE+1], i, result;  // a�����Ǻ���11������Ԫ�ص�����
    int array[10] = {0,1,16,24,35,47,59,62,73,88};
    for(int i = 0; i <=MAXSIZE; i++)
        a[i] = i; // ����ĳ�ʼ��
    result = sequenceSearch(a, MAXSIZE, MAXSIZE);
    cout << "sequence Search: " << result << endl;
    result = sequenceSearch2(array, 10, 22);
    cout << "sequence Search2: " << result << endl;
    return 0;
}