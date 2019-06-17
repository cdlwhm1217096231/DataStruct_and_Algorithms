#include <iostream>

using namespace std;

/*

删除链表中的一个节点：可以将要删除节点的下一个节点的值复制出来，然后覆盖到要删除节点上，最后删除下一个节点
*/

// 链表中节点的定义
struct ListNode{
    int m_value;
    ListNode *m_pNext;
};

class Solution{
public:
    void deleteNode(ListNode **pHead, ListNode *pToBeDelete){
        if(!pHead || !pToBeDelete)   // 如果是空链表或删除的节点是空节点时，则返回值为空
            return;
        // 要删除的节点不是尾部节点
        if(pToBeDelete->m_pNext != nullptr){
            ListNode *pNode = pToBeDelete->m_pNext;
            pToBeDelete->m_value = pNode->m_value;
            pToBeDelete->m_pNext = pNode->m_pNext;

            delete pNode;
            pNode = nullptr; 
        }
        // 链表中只有一个节点，删除的是头结点也是尾节点
        else if(*pHead == pToBeDelete){
            delete pToBeDelete;
            pToBeDelete = nullptr;
            *pHead = nullptr;
        }
        // 链表中有多个节点，删除的是尾部节点
        else{
            ListNode *pNode1 = *pHead;
            while(pNode1->m_pNext != pToBeDelete){
                pNode1 = pNode1->m_pNext;
            } 
            pNode1->m_pNext = nullptr;
            delete pToBeDelete;
            pToBeDelete == nullptr;
        }
    }
};