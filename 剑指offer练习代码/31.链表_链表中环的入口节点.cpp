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
        ListNode *meetingNode = MeetingNode(pHead);   // �����Ľڵ��¼���������濪ʼ��¼�ӵ�һ���������ٴ������м�ڵ���
        if(meetingNode == nullptr){  // �����ڻ���û�������Ľڵ�
            return nullptr;
        }
        int nodesLoopCount = 1;  // ���нڵ������
        ListNode *pNode1 = meetingNode;   // pNode1ָ���һ�������Ľڵ�
        while(pNode1->m_pNext != meetingNode){  // �ҵ����нڵ����
            pNode1 = pNode1->m_pNext;
            nodesLoopCount++;
        }
        pNode1 = pHead;
        // ��һ��ָ����ǰ�ƶ�nodesLoopCount��
        for(int i = 0; i < nodesLoopCount; ++i){
            pNode1 = pNode1->m_pNext;
        }
        // ����ָ��ͬʱ����ƶ����ҵ������
        ListNode *pNode2 = pHead;
        while(pNode1 != pNode2){
            pNode1 = pNode1->m_pNext;
            pNode2 = pNode2->m_pNext;
        }
        return pNode1;
    }
private:
// ����ĺ������������д��ڻ�������£��ҵ�һ��һ������ָ�������Ľڵ�
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