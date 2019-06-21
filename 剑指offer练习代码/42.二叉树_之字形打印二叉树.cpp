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
        stack<BinaryTreeNode*> s[2];   // 使用两个栈进行存储，一个栈用来存储偶数层；一个栈用来存储奇数层
        s[0].push(pRoot);  // 当前层
        while(!s[0].empty() || !s[1].empty()){  // 当两个栈中还有元素时，说明没有元素没有打印出来，继续循环
            vector<int> v[2];
            // 当前层是奇数层
            while(!s[0].empty()){
                v[0].push_back(s[0].top()->m_pVal);

                if(s[0].top->left != nullptr){  // 先用第二栈保存下一层的左子节点，再保存下一层的右子节点
                    s[1].push(s[0].top()->m_pLeft);
                }

                if(s[0].top()->m_pRight != nullptr){
                    s[1].push(s[0].top()->m_pRight);
                }
                s[0].pop();  // 打印当前层栈中的元素
            }
            
            if(!v[0].empty()){
                result.push_back(v[0]);
            }


            // 当前层是偶数层
            while(!s[1].empty()){  
                v[1].push_back(s[1].top()->m_pVal);

                if(s[1].top()->m_pRight != nullptr){   // 先用第一栈保存下一层的右子节点，再保存下一层的左子节点
                    s[0].push(s[1].top()->m_pRight);
                }

                if(s[1].top()->m_pLeft != nullptr){
                    s[0].push(s[1].top()->m_pLeft);
                }
                s[1].pop();   // 打印当前层栈中的元素
            }
            if(!v[1].empty()){
                result.push_back(v[1]);
            }
        }
        return result;
    }
};