#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct BinaryTreeNode{
    int m_pVal;
    BinaryTreeNode *m_pLeft;
    BinaryTreeNode *m_pRight;
};


class Solution{
public:
    vector<vector<int> > Print(BinaryTreeNode *pRoot){
        vector<vector<int> > result;
        if(pRoot == nullptr){
            return result;
        }
        queue<BinaryTreeNode*> nodes[2];
        nodes[0].push(pRoot);  // �Ƚ��������ĸ��ڵ���ӣ�
        while(!nodes[0].empty() || !nodes[1].empty()){
            vector<int> v[2];
            /*-------------------------------------------------------------*/
            while(!nodes[0].empty()){
                v[0].push_back(nodes[0].front()->m_pVal);   // ����һ�������еĶ�ͷԪ�ط���v[0]һά������
                if(nodes[0].front->m_pLeft != nullptr){  // ��������
                    nodes[1].push(nodes[0].front()->m_pLeft);  // ����һ�������еĶ�ͷָ��ָ���������β������ڶ�������
                }
                if(nodes[0].front()->m_pRight != nullptr){  // ��������
                    nodes[1].push(nodes[0].front()->m_pRight); // ����һ�������еĶ�ͷָ��ָ���������β������ڶ�������
                }
                nodes[0].pop();  // ��һ�����н��г���
            }
            if(!v[0].empty()){
            result.push_back(v[0]);
            }
            /*-------------------------------------------------------------*/
            while(!nodes[1].empty()){
                v[1].push_back(nodes[1].front()->m_pVal);
                if(nodes[1].front()->m_pLeft != nullptr){
                    nodes[0].push(nodes[1].front()->m_pLeft);
                }
                if(nodes[1].front()->m_pRight != nullptr){
                    nodes[0].push(nodes[1].front()->m_pRight);
                }
                nodes[1].pop();
            }
            if(!v[1].empty()){
                result.push_back(v[1]);
            }
        }
        return result;
    } 
};

