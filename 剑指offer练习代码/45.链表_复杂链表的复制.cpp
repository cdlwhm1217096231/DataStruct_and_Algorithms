#include <iostream>


using namespace std;


// 复杂链表的定义：复杂的定义是在原有单向链表的基础上，加上一个指针random指向任意一个节点或者nullptr

struct RandomListNode{
    int label;  // 数据域
    struct RandomListNode *next, *random;  // 指针域
    RandomListNode(int x):label(x), next(nullptr),random(nullptr) {}  // 构造函数
};


/*
不使用辅助空间的方法：
1.首先根据原始链表的每个节点N创建对应的节点N',新创建的节点放在后面
2.设置复制出来的节点random
3.将长链表切分成两个链表，将奇数位置的节点构成一个链表即原始链表，偶数位置的节点构成一个链表即复制链表
*/

class Solution{
public:
    // 第一步：复制原始链表中的每个节点，将其放入到原始链表节点的后面
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
    // 第二步：处理复制指针random
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
    // 第三步:拆分复制链表
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