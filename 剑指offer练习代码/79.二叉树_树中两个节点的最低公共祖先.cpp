#include <iostream>
#include <list>


using namespace std;

// ����������
struct BinaryTreeNode{
    int val;
    BinaryTreeNode *pLeft;
    BinaryTreeNode *pRight;
};

// ��ͨ�������ڵ�����ָ�򸸽ڵ��ָ��
struct TreeNode{
    int val;
    TreeNode *pLeft;
    TreeNode *pRight;
    TreeNode *parent;
};


// ��ͨ��
struct TreeNode1{
    int val;
    TreeNode1 *left;
    TreeNode1 *right;
};



class Solution{
public:
    // 1.���Ƕ���������
    BinaryTreeNode* getClosestCommonAncestor(BinaryTreeNode* node1, BinaryTreeNode* node2, BinaryTreeNode* root){
        if(node1 == nullptr || node2 == nullptr){
            return nullptr;
        }

        while(root != nullptr){
            if(root->val > node1->val && root->val > node2->val){  // �����ڵ��ֵС�ڸ��ڵ㣬�����������н�������
                root = root->pLeft;
            }
            else if(root->val < node1->val && root->val < node2->val){ // �����ڵ��ֵ���ڸ��ڵ㣬�����������н�������
                root = root->pRight;
            }
            else{
                return root;
            }
        }
        return root;
    }
    // 2.��ͨ�������ڵ�����ָ�򸸽ڵ��ָ��
    // �ⷨ�����������ָ�򸸽���ָ�룬�Ϳ��ԴӸ�����������㿪ʼ����׷�ݣ��ҵ�����·���е�һ��������㡣�������Ϳ���ת��Ϊ����������ĵ�һ��������㡣
    TreeNode* getClosestCommonAncestor2(TreeNode* node1, TreeNode* node2, TreeNode* root){
        if(node1 == nullptr || node2 == nullptr || root == nullptr){
            return nullptr;
        }
        int node1Length = 0;
        int node2Length = 0;
        int diffLength = 0;

        TreeNode* node1Temp = node1;
        TreeNode* node2Temp = node2;

        // �ֱ���������ڵ㵽���ڵ��·������
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

        // ��·���ϳ��Ľڵ�����
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

        // ͬ����ǰ�����ҵ���һ���ڵ�
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

    // 3.��ͨ��
    // �ⷨ��������������list���ڱ�������ʱ�򣬷ֱ𱣴�Ӹ��ڵ㵽����������ڵ��·����Ȼ����ת��Ϊ���������󹫹��������
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
     // �õ��Ӹ��ڵ�root��ʼ����ڵ�pNode��·����������path��
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

    // �õ�����path�����һ�������ڵ�
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