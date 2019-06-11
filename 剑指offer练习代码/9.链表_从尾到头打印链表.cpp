#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// 单向链表中的节点定义
struct ListNode{
    int m_value;
    ListNode *m_pNext;
};

// 向单向链表的末尾添加一个节点
void addNode(ListNode **pHead, int value){
    ListNode *pNew = new ListNode();   // 新添加的一个节点pNew
    pNew->m_value = value;
    pNew->m_pNext = nullptr;
    if(*pHead == nullptr){  // 如果单向链表是空链表，即头指针指向nullptr
        *pHead = pNew;
    }else{
        ListNode *pNode = *pHead;  // 如果单向链表是非空链表，即pNode指向头指针
        while(pNode->m_pNext != nullptr)
            pNode = pNode->m_pNext;
        pNode->m_pNext = pNew;
    }
}

// 找到第一个含有某值的节点，并删除该节点
void removeNode(ListNode **pHead, int value){
    if(pHead == nullptr || *pHead == nullptr)
        return;
    ListNode *pDeleteNode = nullptr;  // 指向要删除节点的指针初始化
    if((*pHead)->m_value == value){  // 要删除的值在头节点中
        pDeleteNode = *pHead;
        *pHead = (*pHead)->m_pNext;
    }else{  // 要删除的值不在头节点中
        ListNode *pNode = *pHead;  // pNode指针指向链表的头节点
        while(pNode != nullptr && pNode->m_pNext->m_value != value)  // 头节点的下一个节点中没有需要删除的值，pNode移动到下一个位置
            pNode = pNode->m_pNext;
        if(pNode->m_pNext != nullptr && pNode->m_pNext->m_value == value){ // 头节点的下一个节点中有需要删除的值，pDeleteNode指向要删除的节点
            pDeleteNode = pNode->m_pNext;
            pNode->m_pNext = pNode->m_pNext->m_pNext; // 同时改变下一个节点的指针指向
        }
    }
    if(pDeleteNode != nullptr){  // 释放内存资源，不能少！
        delete pDeleteNode;
        pDeleteNode = nullptr;
    }

}

/*--------------上面是预备知识-------------*/

struct listNode{
    int val;
    struct listNode *next;
    listNode(int x):
        val(x), next(NULL){}
};

// 使用栈的数据结构，后进先出，同时不改变链表的结构！
class Solution{
    public:
        vector<int> printListFromTailToHead(listNode *head){
            stack<int> nodes;
            vector<int> result;
            listNode *node = head;
            while(node != nullptr){
                nodes.push(node->val);  // 入栈
                node = node->next;
            }
            while(!nodes.empty()){  // 栈不是空时！
                result.push_back(nodes.top());  // nodes.top()是栈顶元素，push_back()尾部插入到result中
                nodes.pop();  // 出栈
            }
            return result;
        }
};

// 递归方式实现
void printListFromTailToHead_byRecursive(listNode *pHead){
    if(pHead != nullptr){
        if(pHead->next != nullptr){
            printListFromTailToHead_byRecursive(pHead->next);
        }
        cout << pHead->val << endl;
    }
}