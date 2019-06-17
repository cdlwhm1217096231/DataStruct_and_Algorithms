#include <iostream>

using namespace std;


struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};



class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(pHead == NULL){
            return NULL;
        }
        // ָ��ǰ���ǰ������ʹ��Ĳ��ظ����
        ListNode* pPre = NULL;
        // ָ��ǰ����Ľ��
        ListNode* pCur = pHead;
        // ָ��ǰ������Ľ��
        ListNode* pNext = NULL;
        
        while(pCur != NULL){
            // �����ǰ�������һ�������ͬ
            if(pCur->next != NULL && pCur->val == pCur->next->val){
                pNext = pCur->next;
                // �ҵ����ظ������һ�����λ��
                while(pNext->next != NULL && pNext->next->val == pCur->val){
                    pNext = pNext->next;
                }
                // ���pCurָ�������е�һ��Ԫ�أ�pCur -> ... -> pNext ->... 
                // Ҫɾ��pCur��pNext, ��ָ�������һ��Ԫ�ص�ָ��pHeadָ��pNext->next��
                if(pCur == pHead){
                    pHead = pNext->next;
                }
                // ���pCur��ָ�������е�һ��Ԫ�أ�pPre -> pCur ->...->pNext ->... 
                // Ҫɾ��pCur��pNext����pPre->next = pNext->next
                else{
                    pPre->next = pNext->next;
                }
                // ��ǰ�ƶ�
                pCur = pNext->next;
            }
            // �����ǰ�������һ����㲻��ͬ
            else{
                pPre = pCur;
                pCur = pCur->next;
            }
        }
        return pHead;
    }
};