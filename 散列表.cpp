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

// 散列表的结构
typedef struct{
    int *elem;  // 数据元素存储基址，动态分配数组
    int count;  // 散列表中数据元素的个数 
}HashTable;


// 散列表的初始化
int m = 0;
Status InitHashTable(HashTable *H){
    m = HASHSIZE;
    H->count = m;
    H->elem = (int *)malloc(m * sizeof(int));
    for(int i = 0; i < m; i++)
        H->elem[i] = NULLKEY;
    return OK;
}
// 散列函数f
int HashFunction(int key){
    return key % m;  // 除留余数法，返回的是散列地址
}
// 插入关键字到散列表中
void InsertHashTable(HashTable *H, int key){
    int addr = HashFunction(key);  // 求散列地址
    while(H->elem[addr] != NULLKEY){  // 出现散列冲突
        addr = (addr + 1) % m;  // 使用开放定址法的线性探测解决散列冲突
    }
    H->elem[addr] = key;  // 插入关键字
}

// 从散列表中进行查找关键字
int SearchHashTable(HashTable H, int key, int *addr){
    *addr = HashFunction(key);  // 求散列地址
    while(H.elem[*addr] != NULLKEY){  // 出现散列冲突
        *addr = (*addr + 1) % m;  // 使用开放定址法的线性探测解决散列冲突
        if(H.elem[*addr] == NULLKEY || *addr == HashFunction(key))  // 如果循环回到原点,则说明关键字不存在
            return UNSUCCESS;
    }  
    return SUCCESS;       
}


int main(){
    int arr[HASHSIZE] = {12,67,56,16,25,37,22,29,15,47,48,34};
    int p, key, result;
    HashTable H;

    key = 39;  // 关键字
    InitHashTable(&H);  // 初始化散列表
    for(int i = 0; i < m; i++)
        InsertHashTable(&H, arr[i]);  // 插入关键字
    result = SearchHashTable(H, key, &p);
    if(result)
        cout << "查找散列" << key << "的地址为:" << p << endl;
    else    
        cout << "查找散列" << key << "失败.\n";
    
    for(int i = 0; i < m; i++){
        key = arr[i];
        SearchHashTable(H, key, &p);
        cout << "查找散列" << key << "的地址为:" << p << endl;
    }
    return 0;
}
