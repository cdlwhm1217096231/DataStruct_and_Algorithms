#include <iostream>

struct ListNode{
    int m_pValue;
    ListNode *m_pNext;
};

class Solution{
public:
    ListNode *EntryNodeOfLoop(ListNode *pHead){
        if(pHead == nullptr)
            return nullptr;
        ListNode *meetingNode = MeetingNode(pHead);   // 相遇的节点记录下来，下面开始记录从第一次相遇到再次相遇中间节点数
        if(meetingNode == nullptr){  // 不存在环，没有相遇的节点
            return nullptr;
        }
        int nodesLoopCount = 1;  // 环中节点的数量
        ListNode *pNode1 = meetingNode;   // pNode1指向第一次相遇的节点
        while(pNode1->m_pNext != meetingNode){  // 找到环中节点个数
            pNode1 = pNode1->m_pNext;
            nodesLoopCount++;
        }
        pNode1 = pHead;
        // 第一个指针向前移动nodesLoopCount步
        for(int i = 0; i < nodesLoopCount; ++i){
            pNode1 = pNode1->m_pNext;
        }
        // 两个指针同时向后移动，找到环入口
        ListNode *pNode2 = pHead;
        while(pNode1 != pNode2){
            pNode1 = pNode1->m_pNext;
            pNode2 = pNode2->m_pNext;
        }
        return pNode1;
    }
private:
// 下面的函数是在链表中存在环的情况下，找到一快一慢两个指针相遇的节点
    ListNode *MeetingNode(ListNode *pHead){
        ListNode *pSlow = pHead;
        if(pSlow == nullptr)
            return nullptr;
        ListNode *pFast = pSlow->m_pNext;
        while(pFast != nullptr && pSlow != nullptr){
            if(pFast == pSlow)
                return pFast;
            pSlow = pSlow->m_pNext;
            pFast = pFast->m_pNext;
            if(pFast != nullptr)
                pFast = pFast->m_pNext;
        }
        return nullptr;
    }
};