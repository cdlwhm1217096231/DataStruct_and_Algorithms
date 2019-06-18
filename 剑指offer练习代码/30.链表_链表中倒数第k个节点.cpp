#include <iostream>

using namespace std;


// ������ĳ�ڵ�Ķ���
struct ListNode{
    int m_pValue;
    ListNode *m_pNext;
};


class Solution{
public:
    ListNode *FindKthToTail(ListNode *pListHead, unsigned int k){
        if(pListHead == nullptr || k == 0)
            return nullptr;
        ListNode *pAhead = pListHead;  // ǰ���ָ��
        ListNode *pBhead = pListHead;  // �����ָ��
        for(unsigned int i=0; i < k-1; ++i){
            if(pAhead->m_pNext != nullptr){
                pAhead = pAhead->m_pNext;
            }else{
                return nullptr;
            }
        }
        while(pAhead->m_pNext != nullptr){
            pAhead = pAhead->m_pNext;
            pBhead = pBhead->m_pNext;
        }
        return pBhead;
    }
};