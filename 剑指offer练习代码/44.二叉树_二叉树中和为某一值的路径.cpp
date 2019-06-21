#include <iostream>
#include <vector>


using namespace std;

struct BinaryTreeNode{
    int m_pVal;
    BinaryTreeNode *m_pLeft;
    BinaryTreeNode *m_pRight;
};

// 采用树的深度优先搜索DFS，即前序遍历。result用来存储最后结果，tmp用来存储临时结果
// 每次遍历时，先将root的值压入tmp中，然后判断当前的root是否同时满足下面的三个条件:
    // 与给定数值相减为0
    // 左子树为空
    // 右子树为空
// 如果满足条件，就将tmp压入result中。否则，依次遍历左右子树。
// 注意：遍历左右子树的时候，全局变量tmp是不清空的，直退回到根结点才清空tmp
class Solution{
public:
    vector<vector<int> > FindPath(BinaryTreeNode *root, int expectNumber){
        if(root == nullptr){
            return result;
        }
        tmp.push_back(root->m_pVal);
        if((expectNumber - root->m_pVal == 0) && root->m_pLeft == nullptr && root->m_pRight == nullptr){
            result.push_back(tmp);
        }
        // 遍历左子树
        FindPath(root->m_pLeft, expectNumber - root->m_pVal);
        // 遍历右子树
        FindPath(root->m_pRight, expectNumber - root->m_pVal);
        tmp.pop_back();
        return result;
    }

private:
    vector<vector<int> > result;
    vector<int> tmp;
};