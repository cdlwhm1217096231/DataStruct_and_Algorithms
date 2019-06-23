#include <iostream>
#include <vector>

using namespace std;


// �������нڵ�Ķ���
struct BinaryTreeNode{
    int m_pVal;
    BinaryTreeNode *m_pLeft;
    BinaryTreeNode *m_pRight;
};

class Solution{
public:
    BinaryTreeNode * Convert(BinaryTreeNode *pRootOfTree){
        // pLastNodeListָ��ָ��˫�������β�ڵ㣬��Ҫ����ͷ���
        BinaryTreeNode *pLastNodeInList = nullptr;
        // ��ʼת���ڵ�
        ConvertNode(pRootOfTree, &pLastNodeInList);
        // ��pLastNodeInListָ��˫�������β�ڵ�ʱ����Ҫ���·���ͷ�ڵ�
        BinaryTreeNode *pHeadOfList = pLastNodeInList;
        while(pHeadOfList != nullptr && pHeadOfList->m_pLeft != nullptr){
            pHeadOfList = pHeadOfList->m_pLeft;
        }
        return pHeadOfList;
    }

    void ConvertNode(BinaryTreeNode *pNode, BinaryTreeNode **pLastNodeInList){
        // Ҷ�ӽڵ�ֱ�ӷ���
        if(pNode == nullptr){
            return;
        }
        BinaryTreeNode *pCurrent = pNode;
        // �ݹ�������
        if(pCurrent->m_pLeft != nullptr){
            ConvertNode(pCurrent->m_pLeft, pLastNodeInList);
        }

        // ��ָ��
        pCurrent->m_pLeft = *pLastNodeInList;
        // ��ָ��
        if(*pLastNodeInList != nullptr){
            (*pLastNodeInList)->m_pRight = pCurrent;
        }
        // ����˫������β���ڵ�
        *pLastNodeInList = pCurrent;
        // �ݹ�������
        if(pCurrent->m_pRight != nullptr){
            ConvertNode(pCurrent->m_pRight, pLastNodeInList);
        }
    }
};