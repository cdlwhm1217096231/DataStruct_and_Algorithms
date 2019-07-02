#include <iostream>

using namespace std;

// �������нڵ�Ķ���
struct BinaryTreeNode{
    int val;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
};


class Solution{
public:
    // ����1���ظ���α���
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

// ����2��ֻ����һ��(ʹ�ú���������ȱ���ĳ���ڵ�������������õ�������������ȡ����õ���ǰ�ڵ��diffֵ)
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