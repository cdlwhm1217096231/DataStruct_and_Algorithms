#include <iostream>
#include <stack>
#include <vector>

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
        stack<BinaryTreeNode*> s[2];   // ʹ������ջ���д洢��һ��ջ�����洢ż���㣻һ��ջ�����洢������
        s[0].push(pRoot);  // ��ǰ��
        while(!s[0].empty() || !s[1].empty()){  // ������ջ�л���Ԫ��ʱ��˵��û��Ԫ��û�д�ӡ����������ѭ��
            vector<int> v[2];
            // ��ǰ����������
            while(!s[0].empty()){
                v[0].push_back(s[0].top()->m_pVal);

                if(s[0].top->left != nullptr){  // ���õڶ�ջ������һ������ӽڵ㣬�ٱ�����һ������ӽڵ�
                    s[1].push(s[0].top()->m_pLeft);
                }

                if(s[0].top()->m_pRight != nullptr){
                    s[1].push(s[0].top()->m_pRight);
                }
                s[0].pop();  // ��ӡ��ǰ��ջ�е�Ԫ��
            }
            
            if(!v[0].empty()){
                result.push_back(v[0]);
            }


            // ��ǰ����ż����
            while(!s[1].empty()){  
                v[1].push_back(s[1].top()->m_pVal);

                if(s[1].top()->m_pRight != nullptr){   // ���õ�һջ������һ������ӽڵ㣬�ٱ�����һ������ӽڵ�
                    s[0].push(s[1].top()->m_pRight);
                }

                if(s[1].top()->m_pLeft != nullptr){
                    s[0].push(s[1].top()->m_pLeft);
                }
                s[1].pop();   // ��ӡ��ǰ��ջ�е�Ԫ��
            }
            if(!v[1].empty()){
                result.push_back(v[1]);
            }
        }
        return result;
    }
};