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
    ����һ���ڵ��ֵ�����������������һ���ڵ㡣���ҹ������£�
    1.��������Ľڵ������ӽڵ㣬�����ӽڵ������߽ڵ��Ǵ˽ڵ����һ���ڵ�
    2.��������Ľڵ������ӽڵ㣬���Ǹýڵ����丸�ڵ�����ӽڵ㣬�򸸽ڵ��Ǹýڵ����һ���ڵ�
    3.��������Ľڵ������ӽڵ㣬���Ǹýڵ����丸�ڵ�����ӽڵ㣬�����ϱ�����ֱ�����㵱ǰ�������Ľڵ����丸�ڵ�����ӽڵ�ʱֹͣ��
    ��һ���ڵ���ǵ�ǰ�������Ľڵ�ĸ��ڵ㡣
*/


class Solution{
public:
    TreeLinkNode *getNext(TreeLinkNode *pNode){
        if(pNode == nullptr)
            return nullptr;
        TreeLinkNode *res = nullptr;
        if(pNode->right != nullptr){  // ���1
            TreeLinkNode *node_right = pNode->right;
            while(node_right->left != nullptr) // ���2
                node_right = node_right->left;
            res = node_right;
        }else if(pNode->next != nullptr){ // ���3
            TreeLinkNode *current = pNode;  // ��ǰ�ڵ�
            TreeLinkNode *parent = pNode->next;  // ��ǰ�ڵ�ĸ��ڵ�
            while(parent != nullptr && current == parent->right){
                current = parent;
                parent = parent->next;
            }
            res = parent;
        }
        return res;
    }
};