#include <iostream>

using namespace std;

// 二叉树中节点的定义
struct BinaryTreeNode{
    int val;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
};


class Solution{
public:
    // 方法1：重复多次遍历
    bool IsBalanced(BinaryTreeNode *pRoot){
        if(pRoot == nullptr){
            return true;
        }
        int left = TreeDepth(pRoot->left);
        int right = TreeDepth(pRoot->right);
        int diff = left - right;

        if(diff > 1 || diff < -1){
            return false;
        }
        return IsBalanced(pRoot->left) && IsBalanced(pRoot->right);
    }
private:
    int TreeDepth(BinaryTreeNode* pRoot){
        if(pRoot == nullptr){
            return 0;
        }

        int left = TreeDepth(pRoot->left);
        int right = TreeDepth(pRoot->right);
        return left > right ? (left + 1):(right + 1);
    }

};

// 方法2：只遍历一次(使用后序遍历，先遍历某个节点的左右子树，得到左右子树的深度。最后得到当前节点的diff值)
class Solution1{
public:
    bool IsBalanced(BinaryTreeNode* pRoot){
        int depth = 0;
        return IsBalancedCore(pRoot, &depth);
    }
private:
    bool IsBalancedCore(BinaryTreeNode* pRoot, int* depth){
        if(pRoot == nullptr){
            *depth = 0;
            return true;
        }

        int left, right;
        if(IsBalancedCore(pRoot->left, &left) && (IsBalancedCore(pRoot->right, &right))){
            int diff = left - right;
            if(diff <= 1 && diff >= -1){
                *depth = 1 + (left > right ? left : right);
                return true;
            }
        }
        return false;
    }
}