#include <iostream>

using namespace std;

// 二叉树节点的定义
struct BinaryTreeNode{
    int m_pVal;
    BinaryTreeNode *m_pLeft;
    BinaryTreeNode *m_pRight;
};


class Solution{
public:
    bool isSymmetrical(BinaryTreeNode *pRoot){
        if(pRoot == nullptr){
            return true;
        }
        return isSymmtriacalCor(pRoot, pRoot);
    }
private:
    bool isSymmtriacalCor(BinaryTreeNode *pRoot1, BinaryTreeNode *pRoot2){
        if(pRoot1 == nullptr && pRoot2 == nullptr){
            return true;
        }
        if(pRoot1 == nullptr || pRoot2 == nullptr){
            return false;
        }
        if(pRoot1->m_pVal != pRoot2->m_pVal){
            return false;
        }
        return isSymmtriacalCor(pRoot1->m_pLeft, pRoot2->m_pRight) && isSymmtriacalCor(pRoot1->m_pRight, pRoot2->m_pLeft);
    }
};