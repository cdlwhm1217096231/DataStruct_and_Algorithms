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
typedef char NodeType;  // �������������
typedef int EdgeType;  // ����Ȩ�ص���������

// �����ڽӾ�������ݽṹ
typedef struct{
    NodeType nodes[MAXNODE];  // �����һά�����ʾ
    EdgeType arc[MAXNODE][MAXNODE];  // �߱��ά�����ʾ
    int numNodes, numEdges;
}MGraph;

// ��������ͼ���ڽӾ����ʾ
void createMatrixGraph(MGraph *G){
    int i, j, k, w;
    cout << "���붥�����ͱ���:";
    scanf("%d, %d", &G->numNodes, &G->numEdges);
    for(i = 0; i < G->numNodes; i++)
        scanf(&G->nodes[i]);  // ���붥����Ϣ,���������
        
    for(i=0; i < G->numNodes; i++)
        for(j = 0; j < G->numNodes; j++)
            G->arc[i][j] = INFINITY;  // �ڽӾ����ʼ��
    for(k = 0; k < G->numEdges; k++){  // ����numEdges���ߣ������ڽӾ���
        cout << "�����(vi, vj)�ϵ��±�i,�±�j��Ȩw:\n";
        scanf("%d,%d,%d", &i, &j, &w);  // �����(vi,vj)�ϵ�Ȩw
        G->arc[i][j] = w;
        G->arc[j][i] = G->arc[i][j];   // ����ͼ���ڽӾ����ǶԳƾ��󣡣���
    }  
}

int main(){
    MGraph G;
    createMatrixGraph(&G);
    return 0;
}