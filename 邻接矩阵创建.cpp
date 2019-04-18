#include "iostream"
#include "malloc.h"
#include "cstdio"


using namespace std;


#define MAXNODE 100
#define INFINITY 65535 
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef char NodeType;  // 顶点的数据类型
typedef int EdgeType;  // 边上权重的数据类型

// 定义邻接矩阵的数据结构
typedef struct{
    NodeType nodes[MAXNODE];  // 顶点表一维数组表示
    EdgeType arc[MAXNODE][MAXNODE];  // 边表二维数组表示
    int numNodes, numEdges;
}MGraph;

// 建立无向图的邻接矩阵表示
void createMatrixGraph(MGraph *G){
    int i, j, k, w;
    cout << "输入顶点数和边数:";
    scanf("%d, %d", &G->numNodes, &G->numEdges);
    for(i = 0; i < G->numNodes; i++)
        scanf(&G->nodes[i]);  // 读入顶点信息,建立顶点表
        
    for(i=0; i < G->numNodes; i++)
        for(j = 0; j < G->numNodes; j++)
            G->arc[i][j] = INFINITY;  // 邻接矩阵初始化
    for(k = 0; k < G->numEdges; k++){  // 读入numEdges条边，建立邻接矩阵
        cout << "输入边(vi, vj)上的下标i,下标j和权w:\n";
        scanf("%d,%d,%d", &i, &j, &w);  // 输入边(vi,vj)上的权w
        G->arc[i][j] = w;
        G->arc[j][i] = G->arc[i][j];   // 无向图的邻接矩阵是对称矩阵！！！
    }  
}

int main(){
    MGraph G;
    createMatrixGraph(&G);
    return 0;
}