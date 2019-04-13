#include "iostream"
#include "malloc.h"
#include "cmath"

using namespace std;

#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAX_TREE_SIZE 100   // 二叉树的最大结点数量

typedef int Status;
typedef int ElemType;
typedef ElemType seqBiTree[MAX_TREE_SIZE];  // 数组下标为0的元素表示的是根结点

typedef struct{
    int level, order;  // 定义结点的层和本层序号(按满二叉树计算)
}position;

ElemType nil = 0;  // 表示该结点为空

// 打印一个结点
Status visit(ElemType e){
    cout << "e:" << e << " ";
    return OK;
}
// 构造一个空的二叉树
Status initBiTree(seqBiTree T){  // seqBiTree T等价于 int T[MAX_TREE_SIZE];
    for(int i = 0; i < MAX_TREE_SIZE; i++)
        T[i] = nil;
    return OK;
}
// 按层序输入二叉树中结点的值，构造顺序存储的二叉树T
Status createBiTree(seqBiTree T){
    int i = 0;
    cout << "请按层序输入结点的值(整型),0表示空结点，输入999结束.结点数<=" << MAX_TREE_SIZE << endl;
    while(i < 10){  // 往树中存储1到10这十个数字
        T[i] = i + 1;  // 为每个结点赋值
        // 进行防出错判断
        if(i!=0 && T[(i+1)/2-1] == nil && T[i] != nil){
            cout << "出现无双亲的非根结点:" << T[i] << endl;
            exit(ERROR);
        }
        i++;
    }

    while(i < MAX_TREE_SIZE){
        T[i] = nil;  // 将剩下的结点赋值为空
        i++;
    }
    return OK;
}

// 二叉树的顺序存储结构中，清空二叉树等同于初始化二叉树
#define clearBiTree initBiTree

// 判断二叉树是否是空的
Status isEmpty(seqBiTree T){
    if(T[0] == nil)
        return TRUE;
    else    
        return FALSE;
}

// 返回树的最大层次即树的深度depth,一个树第i层上至多有powl(2, i-1)个结点
int BiTreeDepth(seqBiTree T){
    int i, j = -1;
    for(i = MAX_TREE_SIZE -1; i >= 0; i--){  // 找到最后一个结点,i是树最后一个元素的下标，j是树的层数
        if(T[i] != nil)  
            break;
    }
    i++;  // 树的结点数加1
    /*
    层数      该层结点数
    1            1
    2            2
    3            4
    4            8
    如果i = 7,因为4 < 7 < 8,所以该结点在第4层
    */
    do{
        j++;  // 计算层数
    }while(i >= powl(2, j));  // 2的j次方
    return j;  // 返回结点所在的层数
}

// 返回二叉树的根结点
Status root(seqBiTree T, ElemType *e){
    if(isEmpty(T))  // 空的二叉树，没有根结点
        return ERROR;  
    else{
        *e = T[0];  // 将根结点的值赋值给e
        return OK;
    }
}

// 返回处于某层中某个结点的值
ElemType value(seqBiTree T, position e){  // e是某层中某个结点的位置,函数返回的是处于本层中某个位置e处的结点的值
    return T[(int)powl(2, e.level-1) + e.order -2];  // 第i层上至多有powl(2, i-1)个结点,order是结点在本层中的序号
}

// 给处于某层中位置e处的结点赋新值
Status assign(seqBiTree T, position e, ElemType  value){
    int i = (int)powl(2, e.level-1) + e.order -2;  
    if(value != nil && T[(i+1)/2-1]==nil) // 防止出错，给叶子结点赋非空值但双亲为空
        return ERROR;
    else if(value == nil && (T[i*2+1] != nil || T[i*2+2] != nil))  // 给双亲赋空值但有叶子结点
        return ERROR;
    T[i] = value;
    return OK;
}

// 如果结点e是某一结点且不是非根结点时，返回它的双亲，否则返回空的
ElemType parent(seqBiTree T, ElemType e){
    if(T[0] == nil)  // 空树
        return nil;
    for(int i = 1; i <=MAX_TREE_SIZE-1;i++){
        if(T[i] == e)  // 找到结点e
            return T[(i+1)/2-1];
    }
    return nil;  // 没找到e   
}

// 如果二叉树存在，e是树中的某个结点，返回e的左孩子
ElemType leftChild(seqBiTree T, ElemType e){
    if(T[0] == nil)
        return nil;
    for(int i = 0; i <= MAX_TREE_SIZE-1; i++)
        if(T[i] == e)  // 找到e
            return T[2*i+1];
    return nil;  // 没找到e
}

// 如果二叉树非空的二叉树，e是树中的某个结点，返回e的右孩子
ElemType rightChild(seqBiTree T, ElemType e){
    if(T[0] == nil)
        return nil;
    for(int i=0; i <= MAX_TREE_SIZE-1; i++)
        if(T[i] == e)
            return T[i*2 +2];
    return nil;
}

// 如果二叉树是非空二叉树，e是树中的某个结点，返回e的左兄弟；如果e是T的左孩子或无左兄弟，则返回空
ElemType leftsibling(seqBiTree T, ElemType e){
    if(T[0] == nil)
        return nil;
    for(int i=1; i <=MAX_TREE_SIZE-1; i++)
        if(T[i]==e&&i%2==0)  // 找到e且序号为偶数(e是右孩子)
            return T[i-1];  // 返回左孩子
    return nil;  // 没找到e
}

// 如果二叉树是非空二叉树，e是树中的某个结点，返回e的右兄弟；如果e是T的右孩子或无右兄弟，则返回空
ElemType rightsibling(seqBiTree T, ElemType e){
    if(T[0] == nil)
        return nil;
    for(int i=1; i < MAX_TREE_SIZE-1; i++)
        if(T[i] == e && i % 2) // 找到e且其序号为奇数(e是左孩子)
            return T[i+1];
    return nil;
}

// 前序遍历二叉树的顺序
void preTravelTree(seqBiTree T, int e){
    visit(T[e]);
    if(T[2*e+1] != nil)  // 左子树不空
        preTravelTree(T, 2*e+1);  // 递归调用
    if(T[2*e+2] != nil)  // 右子树不空
        preTravelTree(T, 2*e+2);
}


// 前序遍历
Status preOrderTravel(seqBiTree T){
    if(!isEmpty(T))   // 非空二叉树
        preTravelTree(T, 0);
    cout << endl;
    return OK;
}

// 中序遍历二叉树的顺序
void midTravelTree(seqBiTree T, int e){
    if(T[2*e+1] != nil)  // 左子树不空
        midTravelTree(T, 2*e+1);
    visit(T[e]);
    if(T[2*e+2] != nil)  // 右子树不空
        midTravelTree(T, 2*e+2);
}

// 中序遍历
Status midOrderTravel(seqBiTree T){
    if(!isEmpty(T))
        midTravelTree(T, 0);
    cout << endl;
    return OK;
}

// 后序遍历二叉树中的顺序
void afterTravelTree(seqBiTree T, int e){
    if(T[2*e+1] != nil)  // 左子树不空
        afterTravelTree(T, 2*e+1);
    if(T[2*e+2] != nil)  // 右子树不空
        afterTravelTree(T, 2*e+2);
    visit(T[e]);
}

// 后序遍历
Status afterOrderTravel(seqBiTree T){
    if(!isEmpty(T))
        afterTravelTree(T, 0);
    cout << endl;
    return OK;
}

// 层序遍历
void levelOrderTravel(seqBiTree T){
    int i = MAX_TREE_SIZE-1,j;
    while(T[i] == nil)  // 判断某个结点是否是空结点
        i--;   // 找到最后一个非空结点的序号
    for(j = 0; j <=i; j++)  // 从根结点起，按层序遍历二叉树
        if(T[j] != nil)
            visit(T[j]);  // 只遍历非空的结点
    cout << endl;
}

// 逐层、按本层序号输出二叉树
void printTree(seqBiTree T){
    int j, k;
    position p;
    ElemType e;
    for(j=1;j <= BiTreeDepth(T);j++){
        p.level = j;  // 层数
        p.order = k;  // 某层中某个结点在当前层中的序号
        e = value(T, p);  // 返回某个结点
        if(e!=nil)
            cout << "k:" << k << ",e:" << e;
    }
    cout << endl;
}

int main(){
    int i;
    position p;
    ElemType e;
    seqBiTree T;
    initBiTree(T);
    createBiTree(T);
    cout << "建立二叉树后,树是否是空树(1:是,0:否):" << isEmpty(T) << ",树的深度是:" << BiTreeDepth(T) << endl;
    i = root(T, &e);
    if(i)
        cout << "二叉树的根结点是: " << e << endl;
    else    
        cout << "空树，无根\n";
    cout << "层序遍历二叉树:";
    levelOrderTravel(T);
    cout << "前序遍历二叉树:";
    preOrderTravel(T);
    cout << "中序遍历二叉树:";
    midOrderTravel(T);
    cout << "后序遍历二叉树:";
    afterOrderTravel(T);
    cout << "修改层号3，本层序号是2的结点\n";
    p.level = 3;
    p.order = 2;
    e = value(T, p);
    cout << "待修改结点的原始值是:" << e << ",请输入新值:50\n";
    e = 50;
    assign(T, p, e);
    cout << "前序遍历二叉树:";
    preOrderTravel(T);
    cout << "结点" << e << "的双亲为:" << parent(T, e) << ",左右孩子分别为:" << leftChild(T, e) << "," << rightChild(T, e) << ",";
    cout << "左右兄弟分别为: " << leftsibling(T, e) << "," << rightsibling(T, e) << endl;
    clearBiTree(T);
    cout << "清除二叉树后,树是否是空树(1:是,0:否):" << isEmpty(T) << ",树的深度是:" << BiTreeDepth(T) << endl;
    i = root(T, &e);
    if(i)
        cout << "二叉树的根结点是:" << e << endl;
    else
        cout << "空树，无根\n";
    return 0;
}