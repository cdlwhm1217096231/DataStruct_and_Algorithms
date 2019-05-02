#include "iostream"
#include <malloc.h>

using namespace std;


#define SUCCESS 1
#define UNSUCCESS 0
#define HASHSIZE 12
#define OK 1
#define ERROR 0
#define FALSE 0
#define TRUE 1
#define NULLKEY  -32768

typedef int Status;

// ɢ�б�Ľṹ
typedef struct{
    int *elem;  // ����Ԫ�ش洢��ַ����̬��������
    int count;  // ɢ�б�������Ԫ�صĸ��� 
}HashTable;


// ɢ�б�ĳ�ʼ��
int m = 0;
Status InitHashTable(HashTable *H){
    m = HASHSIZE;
    H->count = m;
    H->elem = (int *)malloc(m * sizeof(int));
    for(int i = 0; i < m; i++)
        H->elem[i] = NULLKEY;
    return OK;
}
// ɢ�к���f
int HashFunction(int key){
    return key % m;  // ���������������ص���ɢ�е�ַ
}
// ����ؼ��ֵ�ɢ�б���
void InsertHashTable(HashTable *H, int key){
    int addr = HashFunction(key);  // ��ɢ�е�ַ
    while(H->elem[addr] != NULLKEY){  // ����ɢ�г�ͻ
        addr = (addr + 1) % m;  // ʹ�ÿ��Ŷ�ַ��������̽����ɢ�г�ͻ
    }
    H->elem[addr] = key;  // ����ؼ���
}

// ��ɢ�б��н��в��ҹؼ���
int SearchHashTable(HashTable H, int key, int *addr){
    *addr = HashFunction(key);  // ��ɢ�е�ַ
    while(H.elem[*addr] != NULLKEY){  // ����ɢ�г�ͻ
        *addr = (*addr + 1) % m;  // ʹ�ÿ��Ŷ�ַ��������̽����ɢ�г�ͻ
        if(H.elem[*addr] == NULLKEY || *addr == HashFunction(key))  // ���ѭ���ص�ԭ��,��˵���ؼ��ֲ�����
            return UNSUCCESS;
    }  
    return SUCCESS;       
}


int main(){
    int arr[HASHSIZE] = {12,67,56,16,25,37,22,29,15,47,48,34};
    int p, key, result;
    HashTable H;

    key = 39;  // �ؼ���
    InitHashTable(&H);  // ��ʼ��ɢ�б�
    for(int i = 0; i < m; i++)
        InsertHashTable(&H, arr[i]);  // ����ؼ���
    result = SearchHashTable(H, key, &p);
    if(result)
        cout << "����ɢ��" << key << "�ĵ�ַΪ:" << p << endl;
    else    
        cout << "����ɢ��" << key << "ʧ��.\n";
    
    for(int i = 0; i < m; i++){
        key = arr[i];
        SearchHashTable(H, key, &p);
        cout << "����ɢ��" << key << "�ĵ�ַΪ:" << p << endl;
    }
    return 0;
}
