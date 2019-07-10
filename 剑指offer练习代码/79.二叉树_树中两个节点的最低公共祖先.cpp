#include <iostream>
#include <list>


using namespace std;

// 二叉排序树
struct BinaryTreeNode{
    int val;
    BinaryTreeNode *pLeft;
    BinaryTreeNode *pRight;
};

// 普通树，但节点中有指向父节点的指针
struct TreeNode{
    int val;
    TreeNode *pLeft;
    TreeNode *pRight;
    TreeNode *parent;
};


// 普通树
struct TreeNode1{
    int val;
    TreeNode1 *left;
    TreeNode1 *right;
};



class Solution{
public:
    // 1.树是二叉搜索树
    BinaryTreeNode* getClosestCommonAncestor(BinaryTreeNode* node1, BinaryTreeNode* node2, BinaryTreeNode* root){
        if(node1 == nullptr || node2 == nullptr){
            return nullptr;
        }

        while(root != nullptr){
            if(root->val > node1->val && root->val > node2->val){  // 两个节点的值小于根节点，则在左子树中进行搜索
                root = root->pLeft;
            }
            else if(root->val < node1->val && root->val < node2->val){ // 两个节点的值大于根节点，则在右子树中进行搜索
                root = root->pRight;
            }
            else{
                return root;
            }
        }
        return root;
    }
    // 2.普通树，但节点中有指向父节点的指针
    // 解法：如果树中有指向父结点的指针，就可以从给定的两个结点开始往回追溯，找到回溯路径中第一个公共结点。这个问题就可以转化为求两个链表的第一个公共结点。
    TreeNode* getClosestCommonAncestor2(TreeNode* node1, TreeNode* node2, TreeNode* root){
        if(node1 == nullptr || node2 == nullptr || root == nullptr){
            return nullptr;
        }
        int node1Length = 0;
        int node2Length = 0;
        int diffLength = 0;

        TreeNode* node1Temp = node1;
        TreeNode* node2Temp = node2;

        // 分别计算两个节点到根节点的路径长度
        while(node1Temp != nullptr){
            node1Temp = node1Temp->parent;
            node1Length++;
        }
        while(node1Temp != nullptr){
            node2Temp = node2Temp->parent;
            node2Length++;
        }

        node1Temp = node1;
        node2Temp = node2;

        // 让路径较长的节点先走
        if(node1Length >= node2Length){
            diffLength = node1Length - node2Length;
            while(diffLength != 0){
                node1Temp = node1Temp->parent;
            }
        }
        else if(node1Length < node2Length ){
            diffLength = node2Length - node1Length;
            while(diffLength != 0){
                node2Temp = node2Temp->parent;
            }
        }

        // 同步向前进，找到第一个节点
        while(node1Temp != nullptr && node2Temp != nullptr){
            if(node1Temp == node2Temp){
                break;
            }
            else{
                node1Temp = node1Temp->parent;
                node2Temp = node2Temp->parent;
            }
        }
        return node1Temp;
    }

    // 3.普通树
    // 解法：利用两个辅助list，在遍历树的时候，分别保存从根节点到输入的两个节点的路径，然后将其转化为两个链表求公共结点问题
    TreeNode1* GetLastCommonParent(TreeNode1* root, int val1, int val2){
        if(root == nullptr){
            return nullptr;
        }
        list<TreeNode1*> path1;
        GetNodePath(root, val1, path1);

        list<TreeNode1*> path2;
        GetNodePath(root,val2, path2);

        return GetLastCommonNode(path1, path2);
    }

private:
     // 得到从根节点root开始到达节点pNode的路径，保存在path中
    bool GetNodePath(TreeNode1* root, int val, list<TreeNode1*>& path){
        if(root == nullptr){
            return false;
        }

        path.push_back(root);

        if(root->val == val){
            return true;
        }
        else{
            bool found;
            found = GetNodePath(root->left, val, path);

            if(!found){
                found = GetNodePath(root->right, val, path);
            }

            if(!found){
                path.pop_back();
            }
            return found;
        }
    }

    // 得到两个path的最后一个公共节点
    TreeNode1* GetLastCommonNode(const list<TreeNode1*>& path1, const list<TreeNode1*>& path2){
        list<TreeNode1*>::const_iterator p1 = path1.begin();
        list<TreeNode1*>::const_iterator p2 = path2.begin();

        TreeNode1* pLast = nullptr;

        while(p1 != path1.end() && p2 != path2.end()){
            if(*p1 == *p2){
                pLast = *p1;
            }
            p1++;
            p2++;
        }
        return pLast;
    }
};