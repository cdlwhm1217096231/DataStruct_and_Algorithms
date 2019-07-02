#include <iostream>
#include <queue>

using namespace std;

// ����������ȣ��Ӹ��ڵ㵽Ҷ�ӽڵ���·������Ӧ�ĳ��ȣ�

// �������нڵ�Ķ���
struct BinaryTreeNode{
    int val;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
};


class Solution{
public:
    // ����:1��ʹ��DFS(���������������������ǰ�������ʵ��)���ݹ鷽��
    int TreeDepth(BinaryTreeNode* pRoot){  
        if(pRoot == nullptr){
            return 0;
        }
        int left = TreeDepth(pRoot->left);
        int right = TreeDepth(pRoot->right);
        return (left > right) ? (left + 1):(right + 1);
    }


    // ����2��ʹ��BFS����������������������Ĳ��������ʵ�֣�������ʵ��
    int TreeDepth1(BinaryTreeNode* pRoot){
        if(pRoot == nullptr){
            return 0;
        }

        queue<BinaryTreeNode*> que;
        int depth = 0;
        que.push(pRoot);   // ���ڵ���ӣ�
        while(!que.empty()){  // que.empty()���ص���һ��boolֵ���������ǿ�ʱ������true�����򣬷���false.
            int size = que.size();
            depth++;
            for(int i=0; i < size; ++i){
                BinaryTreeNode* node = que.front();  // ����queue�е�һ��Ԫ�ص�����
                que.pop();  // ���Ӳ�����
                if(node->left){
                    que.push(node->left);   // �������ڵ����
                }
                if(node->right){
                    que.push(node->right);  // �������ڵ����
                }
            }
        }
        return depth;
    }
};