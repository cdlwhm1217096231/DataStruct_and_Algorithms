#include <iostream>
#include <vector>

using namespace std;


// 二叉树中节点的定义
struct BinaryTreeNode{
    int m_pVal;
    BinaryTreeNode *m_pLeft;
    BinaryTreeNode *m_pRight;
};

class Solution{
public:
    BinaryTreeNode * Convert(BinaryTreeNode *pRootOfTree){
        // pLastNodeList指针指向双向链表的尾节点，需要返回头结点
        BinaryTreeNode *pLastNodeInList = nullptr;
        // 开始转换节点
        ConvertNode(pRootOfTree, &pLastNodeInList);
        // 当pLastNodeInList指向双向链表的尾节点时，需要重新返回头节点
        BinaryTreeNode *pHeadOfList = pLastNodeInList;
        while(pHeadOfList != nullptr && pHeadOfList->m_pLeft != nullptr){
            pHeadOfList = pHeadOfList->m_pLeft;
        }
        return pHeadOfList;
    }

    void ConvertNode(BinaryTreeNode *pNode, BinaryTreeNode **pLastNodeInList){
        // 叶子节点直接返回
        if(pNode == nullptr){
            return;
        }
        BinaryTreeNode *pCurrent = pNode;
        // 递归左子树
        if(pCurrent->m_pLeft != nullptr){
            ConvertNode(pCurrent->m_pLeft, pLastNodeInList);
        }

        // 左指针
        pCurrent->m_pLeft = *pLastNodeInList;
        // 右指针
        if(*pLastNodeInList != nullptr){
            (*pLastNodeInList)->m_pRight = pCurrent;
        }
        // 更新双向链表尾部节点
        *pLastNodeInList = pCurrent;
        // 递归右子树
        if(pCurrent->m_pRight != nullptr){
            ConvertNode(pCurrent->m_pRight, pLastNodeInList);
        }
    }
};