#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// ���������еĽڵ㶨��
struct ListNode{
    int m_value;
    ListNode *m_pNext;
};

// ���������ĩβ���һ���ڵ�
void addNode(ListNode **pHead, int value){
    ListNode *pNew = new ListNode();   // ����ӵ�һ���ڵ�pNew
    pNew->m_value = value;
    pNew->m_pNext = nullptr;
    if(*pHead == nullptr){  // ������������ǿ�������ͷָ��ָ��nullptr
        *pHead = pNew;
    }else{
        ListNode *pNode = *pHead;  // ������������Ƿǿ�������pNodeָ��ͷָ��
        while(pNode->m_pNext != nullptr)
            pNode = pNode->m_pNext;
        pNode->m_pNext = pNew;
    }
}

// �ҵ���һ������ĳֵ�Ľڵ㣬��ɾ���ýڵ�
void removeNode(ListNode **pHead, int value){
    if(pHead == nullptr || *pHead == nullptr)
        return;
    ListNode *pDeleteNode = nullptr;  // ָ��Ҫɾ���ڵ��ָ���ʼ��
    if((*pHead)->m_value == value){  // Ҫɾ����ֵ��ͷ�ڵ���
        pDeleteNode = *pHead;
        *pHead = (*pHead)->m_pNext;
    }else{  // Ҫɾ����ֵ����ͷ�ڵ���
        ListNode *pNode = *pHead;  // pNodeָ��ָ�������ͷ�ڵ�
        while(pNode != nullptr && pNode->m_pNext->m_value != value)  // ͷ�ڵ����һ���ڵ���û����Ҫɾ����ֵ��pNode�ƶ�����һ��λ��
            pNode = pNode->m_pNext;
        if(pNode->m_pNext != nullptr && pNode->m_pNext->m_value == value){ // ͷ�ڵ����һ���ڵ�������Ҫɾ����ֵ��pDeleteNodeָ��Ҫɾ���Ľڵ�
            pDeleteNode = pNode->m_pNext;
            pNode->m_pNext = pNode->m_pNext->m_pNext; // ͬʱ�ı���һ���ڵ��ָ��ָ��
        }
    }
    if(pDeleteNode != nullptr){  // �ͷ��ڴ���Դ�������٣�
        delete pDeleteNode;
        pDeleteNode = nullptr;
    }

}

/*--------------������Ԥ��֪ʶ-------------*/

struct listNode{
    int val;
    struct listNode *next;
    listNode(int x):
        val(x), next(NULL){}
};

// ʹ��ջ�����ݽṹ������ȳ���ͬʱ���ı�����Ľṹ��
class Solution{
    public:
        vector<int> printListFromTailToHead(listNode *head){
            stack<int> nodes;
            vector<int> result;
            listNode *node = head;
            while(node != nullptr){
                nodes.push(node->val);  // ��ջ
                node = node->next;
            }
            while(!nodes.empty()){  // ջ���ǿ�ʱ��
                result.push_back(nodes.top());  // nodes.top()��ջ��Ԫ�أ�push_back()β�����뵽result��
                nodes.pop();  // ��ջ
            }
            return result;
        }
};

// �ݹ鷽ʽʵ��
void printListFromTailToHead_byRecursive(listNode *pHead){
    if(pHead != nullptr){
        if(pHead->next != nullptr){
            printListFromTailToHead_byRecursive(pHead->next);
        }
        cout << pHead->val << endl;
    }
}