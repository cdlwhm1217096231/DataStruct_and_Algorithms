#include <iostream>

using namespace std;

// 二叉树节点的定义


struct BinaryTreeNode{
    int m_val;
    BinaryTreeNode *m_pLeft;
    BinaryTreeNode *m_pRight;
};


class Solution{
public:
    void mirrorRecursively(BinaryTreeNode *pNode){
        if(pNode == nullptr){
            return;
        }
        if(pNode->m_pLeft == nullptr && pNode->m_pRight == nullptr){
            return;  // 递归停止的条件，到达了叶子节点，不再进行遍历
        }
        // 开始交换非叶子节点的左右两个子树的根节点
        BinaryTreeNode *pTemp = pNode->m_pLeft;
        pNode->m_pLeft = pNode->m_pRight;
        pNode->m_pRight = pTemp;
        if(pNode->m_pLeft){
            mirrorRecursively(pNode->m_pLeft);  // 递归遍历左边的子树
        }
        if(pNode->m_pRight){
            mirrorRecursively(pNode->m_pRight);  // 递归遍历右边的子树
        }
    }
};