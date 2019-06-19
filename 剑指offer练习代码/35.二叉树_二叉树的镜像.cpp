#include <iostream>

using namespace std;

// �������ڵ�Ķ���


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
            return;  // �ݹ�ֹͣ��������������Ҷ�ӽڵ㣬���ٽ��б���
        }
        // ��ʼ������Ҷ�ӽڵ���������������ĸ��ڵ�
        BinaryTreeNode *pTemp = pNode->m_pLeft;
        pNode->m_pLeft = pNode->m_pRight;
        pNode->m_pRight = pTemp;
        if(pNode->m_pLeft){
            mirrorRecursively(pNode->m_pLeft);  // �ݹ������ߵ�����
        }
        if(pNode->m_pRight){
            mirrorRecursively(pNode->m_pRight);  // �ݹ�����ұߵ�����
        }
    }
};