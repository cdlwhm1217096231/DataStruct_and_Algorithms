#include <iostream>
#include <vector>

using namespace std;

// Ҫ����֪һ������ǰ�������������ؽ��������

// �������Ľڵ�ṹ
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
            // ǰ�������һ�ڵ�һ���Ǹ��ڵ�
            BinaryTreeNode *head = new BinaryTreeNode(preoder[0]);
            // �ҵ���������еĸ��ڵ�λ��
            int root = 0;
            // �����ҵ����ڵ�����������е�����ֵ
            for(int i = 0;i<preoder.size();++i){
                if(preoder[0] == midorder[i]){
                    root = i;
                    break;
                }
            }
            // ������������ҵ��ĸ��ڵ�λ�ã��Զ������ڵ���зָ�ָ�����������ֵ�����
            for(int i = 0; i < root; ++i){
                left_midorder.push_back(midorder[i]);  // ��������е�������
                left_preorder.push_back(preoder[i+1]); // ǰ������е�������
            }
            for(int i = root+1; i < preoder.size();++i){  
                right_midorder.push_back(midorder[i]);  // ��������е�������
                right_preorder.push_back(preoder[i]);   // ǰ������е�������
            }
            // �ٵݹ�����Ĳ���
            head->left = reConstructBinaryTree(left_preorder, left_midorder);
            head->right = reConstructBinaryTree(right_preorder, right_midorder);
            return head;
        }
};