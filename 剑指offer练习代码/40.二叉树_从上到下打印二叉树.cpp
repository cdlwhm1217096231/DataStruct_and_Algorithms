#include <iostream>
#include <vector>
#include <queue>  // 单向队列

using namespace std;


// 定义二叉树中的节点结构
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
        que.push(pRoot);  // 队列在尾部进行插入二叉树的根节点
        while(!que.empty()){
            pNode = que.front();   // pNode指针指向队头
            result.push_back(pNode->m_pVal);  
            if(pNode->m_pLeft != nullptr){
                que.push(pNode->m_pLeft);  // 入队，尾部进行插入
            }
            if(pNode->m_pRight != nullptr){
                que.push(pNode->m_pRight);
            }
            que.pop();  // 出队,头部进行删除！
        }
        return result;
    }

private:
    vector<int> result;   // 存放出队元素，即层序遍历的结果
    queue<BinaryTreeNode*> que; 
};