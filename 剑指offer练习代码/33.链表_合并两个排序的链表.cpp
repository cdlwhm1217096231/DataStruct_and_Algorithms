#include <iostream>

using namespace std;


struct ListNode{
    int m_pVal;
    ListNode *m_pNext;
};

// 使用归并排序的思想

class Solution{
public:
    ListNode *Merge(ListNode *pHead1, ListNode *pHead2){
        if(pHead1 == nullptr)
            return pHead2;
        else if(pHead2 == nullptr)
            return pHead1;
        ListNode *pMergeHead = nullptr;
        if(pHead1->m_pVal < pHead2->m_pVal){
            pMergeHead = pHead1;
            pMergeHead->m_pNext = Merge(pHead1->m_pNext, pHead2);
        }else{
            pMergeHead = pHead2;
            pMergeHead->m_pNext = Merge(pHead1, pHead2->m_pNext);
        }
        return pMergeHead;
    }
};