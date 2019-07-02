#include <iostream>

using namespace std;


// �����������еĽڵ�--------������������������ȸ��ڵ��ķ����ұߣ��ȸ��ڵ�С�ķ������
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
        return KthNodeCore(pRoot, k);    // �ݹ鷽��ʵ���������
    }
private:
    BinaryTreeNode* KthNodeCore(BinaryTreeNode* pRoot, int& k){
        BinaryTreeNode* target = nullptr;
        // �ȱ���������
        if(pRoot->left != nullptr){
            target = KthNodeCore(pRoot->left, k);
        }
        // ���û���ҵ�target,�������Сk;���k����1����ʾ�ҵ��˵�k�������
        if(target == nullptr){
            if(k == 1){
                target = pRoot;
            }
            k--;
        }
        // ���û���ҵ�target���������������
        if(pRoot->right != nullptr && target == nullptr){
            target = KthNodeCore(pRoot->right, k);
        }
        return target;
    }
};