#include <iostream>


using namespace std;


// ��������Ķ��壺���ӵĶ�������ԭ�е�������Ļ����ϣ�����һ��ָ��randomָ������һ���ڵ����nullptr

struct RandomListNode{
    int label;  // ������
    struct RandomListNode *next, *random;  // ָ����
    RandomListNode(int x):label(x), next(nullptr),random(nullptr) {}  // ���캯��
};


/*
��ʹ�ø����ռ�ķ�����
1.���ȸ���ԭʼ�����ÿ���ڵ�N������Ӧ�Ľڵ�N',�´����Ľڵ���ں���
2.���ø��Ƴ����Ľڵ�random
3.���������зֳ���������������λ�õĽڵ㹹��һ������ԭʼ����ż��λ�õĽڵ㹹��һ��������������
*/

class Solution{
public:
    // ��һ��������ԭʼ�����е�ÿ���ڵ㣬������뵽ԭʼ����ڵ�ĺ���
    void ClonedNodes(RandomListNode *pHead){
        RandomListNode *pNode = pHead;
        while(pNode != nullptr){
            RandomListNode *pCloned = new RandomListNode(0);
            pCloned->label = pNode->label;
            pCloned->next = pNode->next;
            pCloned->random = nullptr;

            pNode->next = pCloned;
            pNode = pCloned->next;
        }
    }
    // �ڶ�����������ָ��random
    void ConnectSiblingNodes(RandomListNode *pHead){
        RandomListNode *pNode = pHead;
        while(pNode != nullptr){
            RandomListNode *pCloned = pNode->next;
            if(pNode->random != nullptr){
                pCloned->random = pNode->random->next;
            }
            pNode = pCloned->next;
        }
    }
    // ������:��ָ�������
    RandomListNode * ReconnectNodes(RandomListNode *pHead){
        RandomListNode *pNode = pHead;
        RandomListNode *pClonedHead = nullptr;
        RandomListNode *pClonedNode = nullptr;

        if(pNode != nullptr){
            pClonedHead = pClonedNode = pNode->next;
            pNode->next = pClonedHead->next;
            pNode = pNode->next;
        }
        while(pNode != nullptr){
            pClonedNode->next = pNode->next;
            pClonedNode = pClonedNode->next;
            pNode->next = pClonedNode->next;
            pNode = pNode->next;
        }
        return pClonedHead;
    }

    RandomListNode * Clone(RandomListNode *pHead){
        ClonedNodes(pHead);
        ConnectSiblingNodes(pHead);
        return ReconnectNodes(pHead);
    }
};