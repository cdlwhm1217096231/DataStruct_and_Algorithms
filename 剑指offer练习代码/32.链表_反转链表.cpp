#include <iostream>

using namespace std;

struct ListNode{
    int m_pValue;
    ListNode *m_pNext;
};

// 使用三个指针来操作
class Solution{
public:
    ListNode *ReverseList(ListNode *pHead){
        ListNode *pReversedHead = nullptr;   // 反转链表头节点的初始化
        ListNode *pNode = pHead;  // 当前节点
        ListNode *pPrev = nullptr;  // 当前节点的前一个节点的初始化
        ListNode *pNext = nullptr;   //  当前节点的后一个节点的初始化
        // 反转链表
        while(pNode != nullptr){
            pNext = pNode->m_pNext;   // 建立连接
            if(pNext == nullptr)   // 判断pNode是否是最后一个节点
                pReversedHead = pNode;  // 反转后链表的头节点就是原始链表的尾节点
            // 指针反转
            pNode->m_pNext = pPrev;
            pPrev = pNode;
            pNode = pNext;
        }
        return pReversedHead;
    }
};