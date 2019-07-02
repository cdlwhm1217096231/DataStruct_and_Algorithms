#include <iostream>
#include <queue>

using namespace std;

// 二叉树的深度：从根节点到叶子节点的最长路径所对应的长度！

// 二叉树中节点的定义
struct BinaryTreeNode{
    int val;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
};


class Solution{
public:
    // 方法:1：使用DFS(深度优先搜索，借助树的前序遍历来实现)。递归方法
    int TreeDepth(BinaryTreeNode* pRoot){  
        if(pRoot == nullptr){
            return 0;
        }
        int left = TreeDepth(pRoot->left);
        int right = TreeDepth(pRoot->right);
        return (left > right) ? (left + 1):(right + 1);
    }


    // 方法2：使用BFS（广度优先搜索，借助树的层序遍历来实现）。队列实现
    int TreeDepth1(BinaryTreeNode* pRoot){
        if(pRoot == nullptr){
            return 0;
        }

        queue<BinaryTreeNode*> que;
        int depth = 0;
        que.push(pRoot);   // 根节点入队！
        while(!que.empty()){  // que.empty()返回的是一个bool值，当队列是空时，返回true；否则，返回false.
            int size = que.size();
            depth++;
            for(int i=0; i < size; ++i){
                BinaryTreeNode* node = que.front();  // 返回queue中第一个元素的引用
                que.pop();  // 出队操作！
                if(node->left){
                    que.push(node->left);   // 左子树节点入队
                }
                if(node->right){
                    que.push(node->right);  // 右子树节点入队
                }
            }
        }
        return depth;
    }
};