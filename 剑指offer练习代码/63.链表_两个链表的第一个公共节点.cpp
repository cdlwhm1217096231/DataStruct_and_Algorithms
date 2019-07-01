#include <iostream>


using namespace std;


// �����нڵ�Ķ���
struct ListNode{
    int val;
    struct ListNode *next;
    ListNode(int x): val(x), next(nullptr){}
};


class Solution{
public:
    ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2){
        // �����һ������Ϊ�գ��򷵻ؽ��Ϊ��
        if(pHead1 == nullptr || pHead2 == nullptr){
            return nullptr;
        }
        // �����������ĳ���
        unsigned int len1 = GetListLength(pHead1);
        unsigned int len2 = GetListLength(pHead2);
        // Ĭ������£�����1������2��
        ListNode* pHeadLong = pHead1;
        ListNode* pHeadShort = pHead2;
        int lenDif = len1 - len2;
        // ���pHead1 �� pHead2
        if(len1 < len2){
            ListNode* pHeadLong = pHead2;
            ListNode* pHeadShort = pHead1;
            int lenDif = len2 - len1;
        }
        // ����һ��������ƶ���ͷָ�룬ʹ��������ȳ�
        for(int i=0; i < lenDif; ++i){
            pHeadLong = pHeadLong->next;
        }

        while(pHeadLong != nullptr && pHeadShort != nullptr && pHeadLong != pHeadShort){
            pHeadLong = pHeadLong->next;
            pHeadShort = pHeadShort->next;
        }
        return pHeadLong;
    }

private:
    // �������ĳ���
    unsigned int GetListLength(ListNode* pHead){
        if(pHead == nullptr){
            return 0;
        }
        unsigned int len = 1;
        while(pHead->next != nullptr){
            pHead = pHead->next;
            len++;
        }
        return len;
    }
};