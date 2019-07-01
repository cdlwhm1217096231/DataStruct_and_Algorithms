#include <iostream>


using namespace std;


// 链表中节点的定义
struct ListNode{
    int val;
    struct ListNode *next;
    ListNode(int x): val(x), next(nullptr){}
};


class Solution{
public:
    ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2){
        // 如果有一个链表为空，则返回结果为空
        if(pHead1 == nullptr || pHead2 == nullptr){
            return nullptr;
        }
        // 获得两个链表的长度
        unsigned int len1 = GetListLength(pHead1);
        unsigned int len2 = GetListLength(pHead2);
        // 默认情况下，链表1比链表2长
        ListNode* pHeadLong = pHead1;
        ListNode* pHeadShort = pHead2;
        int lenDif = len1 - len2;
        // 如果pHead1 比 pHead2
        if(len1 < len2){
            ListNode* pHeadLong = pHead2;
            ListNode* pHeadShort = pHead1;
            int lenDif = len2 - len1;
        }
        // 将长一点的链表，移动其头指针，使两个链表等长
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
    // 获得链表的长度
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