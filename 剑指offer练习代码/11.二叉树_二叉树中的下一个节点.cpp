#include <iostream>
#include <vector>

using namespace std;

struct TreeLinkNode{
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x):val(x), left(NULL), right(NULL), next(NULL){}
};


 /*
    给定一个节点的值，查找中序遍历中下一个节点。查找规律如下：
    1.如果给定的节点有右子节点，则右子节点的最左边节点是此节点的下一个节点
    2.如果给定的节点无右子节点，但是该节点是其父节点的左子节点，则父节点是该节点的下一个节点
    3.如果给定的节点无右子节点，但是该节点是其父节点的右子节点，则向上遍历，直到满足当前遍历到的节点是其父节点的左子节点时停止，
    下一个节点就是当前遍历到的节点的父节点。
*/


class Solution{
public:
    TreeLinkNode *getNext(TreeLinkNode *pNode){
        if(pNode == nullptr)
            return nullptr;
        TreeLinkNode *res = nullptr;
        if(pNode->right != nullptr){  // 情况1
            TreeLinkNode *node_right = pNode->right;
            while(node_right->left != nullptr) // 情况2
                node_right = node_right->left;
            res = node_right;
        }else if(pNode->next != nullptr){ // 情况3
            TreeLinkNode *current = pNode;  // 当前节点
            TreeLinkNode *parent = pNode->next;  // 当前节点的父节点
            while(parent != nullptr && current == parent->right){
                current = parent;
                parent = parent->next;
            }
            res = parent;
        }
        return res;
    }
};