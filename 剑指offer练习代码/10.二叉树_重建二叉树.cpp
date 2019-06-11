#include <iostream>
#include <vector>

using namespace std;

// 要求：已知一棵树的前序和中序遍历，重建这棵树！

// 二叉树的节点结构
struct BinaryTreeNode{
    int val;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    BinaryTreeNode(int x):val(x), left(NULL),right(NULL){}
};

class Solution{
    public:
        BinaryTreeNode *reConstructBinaryTree(vector<int> preoder, vector<int> midorder){
            if(preoder.size() == 0)
                return NULL;
            vector<int> left_preorder, right_preorder, left_midorder, right_midorder; 
            // 前序遍历第一节点一定是根节点
            BinaryTreeNode *head = new BinaryTreeNode(preoder[0]);
            // 找到中序遍历中的根节点位置
            int root = 0;
            // 遍历找到根节点在中序遍历中的索引值
            for(int i = 0;i<preoder.size();++i){
                if(preoder[0] == midorder[i]){
                    root = i;
                    break;
                }
            }
            // 利用中序遍历找到的根节点位置，对二叉树节点进行分割，分割成左右两部分的子树
            for(int i = 0; i < root; ++i){
                left_midorder.push_back(midorder[i]);  // 中序遍历中的左子树
                left_preorder.push_back(preoder[i+1]); // 前序遍历中的左子树
            }
            for(int i = root+1; i < preoder.size();++i){  
                right_midorder.push_back(midorder[i]);  // 中序遍历中的右子树
                right_preorder.push_back(preoder[i]);   // 前序遍历中的右子树
            }
            // 再递归上面的操作
            head->left = reConstructBinaryTree(left_preorder, left_midorder);
            head->right = reConstructBinaryTree(right_preorder, right_midorder);
            return head;
        }
};