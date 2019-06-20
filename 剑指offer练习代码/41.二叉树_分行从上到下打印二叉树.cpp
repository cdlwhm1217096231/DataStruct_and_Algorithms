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
        nodes[0].push(pRoot);  // 先将二叉树的根节点入队！
        while(!nodes[0].empty() || !nodes[1].empty()){
            vector<int> v[2];
            /*-------------------------------------------------------------*/
            while(!nodes[0].empty()){
                v[0].push_back(nodes[0].front()->m_pVal);   // 将第一个队列中的队头元素放入v[0]一维数组中
                if(nodes[0].front->m_pLeft != nullptr){  // 有左子树
                    nodes[1].push(nodes[0].front()->m_pLeft);  // 将第一个队列中的队头指针指向的左子树尾部插入第二个队列
                }
                if(nodes[0].front()->m_pRight != nullptr){  // 有右子树
                    nodes[1].push(nodes[0].front()->m_pRight); // 将第一个队列中的队头指针指向的右子树尾部插入第二个队列
                }
                nodes[0].pop();  // 第一个队列进行出队
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

