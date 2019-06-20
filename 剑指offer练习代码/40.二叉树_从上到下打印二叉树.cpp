#include <iostream>
#include <vector>
#include <queue>  // �������

using namespace std;


// ����������еĽڵ�ṹ
struct BinaryTreeNode{
    int m_pVal;
    BinaryTreeNode *m_pLeft;
    BinaryTreeNode *m_pRight;
};


class Solution{
public:
    vector<int> PrintFromTopToBottom(BinaryTreeNode *pRoot){
        BinaryTreeNode *pNode;
        if(pRoot == nullptr){
            return result;
        }
        que.push(pRoot);  // ������β�����в���������ĸ��ڵ�
        while(!que.empty()){
            pNode = que.front();   // pNodeָ��ָ���ͷ
            result.push_back(pNode->m_pVal);  
            if(pNode->m_pLeft != nullptr){
                que.push(pNode->m_pLeft);  // ��ӣ�β�����в���
            }
            if(pNode->m_pRight != nullptr){
                que.push(pNode->m_pRight);
            }
            que.pop();  // ����,ͷ������ɾ����
        }
        return result;
    }

private:
    vector<int> result;   // ��ų���Ԫ�أ�����������Ľ��
    queue<BinaryTreeNode*> que; 
};