#include <iostream>

using namespace std;


// 二叉排序树中的节点--------中序遍历进行搜索，比根节点大的放在右边，比根节点小的放在左边
struct BinaryTreeNode{
    int val;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
};


class Solution{
public:
    BinaryTreeNode* KthNode(BinaryTreeNode* pRoot, int k){
        if(pRoot == nullptr || k == 0){
            return nullptr;
        }
        return KthNodeCore(pRoot, k);    // 递归方法实现中序遍历
    }
private:
    BinaryTreeNode* KthNodeCore(BinaryTreeNode* pRoot, int& k){
        BinaryTreeNode* target = nullptr;
        // 先遍历左子树
        if(pRoot->left != nullptr){
            target = KthNodeCore(pRoot->left, k);
        }
        // 如果没有找到target,则继续减小k;如果k等于1，表示找到了第k个大的数
        if(target == nullptr){
            if(k == 1){
                target = pRoot;
            }
            k--;
        }
        // 如果没有找到target，则继续找右子树
        if(pRoot->right != nullptr && target == nullptr){
            target = KthNodeCore(pRoot->right, k);
        }
        return target;
    }
};