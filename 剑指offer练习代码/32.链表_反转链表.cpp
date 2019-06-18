#include <iostream>

using namespace std;

struct ListNode{
    int m_pValue;
    ListNode *m_pNext;
};

// ʹ������ָ��������
class Solution{
public:
    ListNode *ReverseList(ListNode *pHead){
        ListNode *pReversedHead = nullptr;   // ��ת����ͷ�ڵ�ĳ�ʼ��
        ListNode *pNode = pHead;  // ��ǰ�ڵ�
        ListNode *pPrev = nullptr;  // ��ǰ�ڵ��ǰһ���ڵ�ĳ�ʼ��
        ListNode *pNext = nullptr;   //  ��ǰ�ڵ�ĺ�һ���ڵ�ĳ�ʼ��
        // ��ת����
        while(pNode != nullptr){
            pNext = pNode->m_pNext;   // ��������
            if(pNext == nullptr)   // �ж�pNode�Ƿ������һ���ڵ�
                pReversedHead = pNode;  // ��ת�������ͷ�ڵ����ԭʼ�����β�ڵ�
            // ָ�뷴ת
            pNode->m_pNext = pPrev;
            pPrev = pNode;
            pNode = pNext;
        }
        return pReversedHead;
    }
};