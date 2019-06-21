#include <iostream>
#include <vector>


using namespace std;

struct BinaryTreeNode{
    int m_pVal;
    BinaryTreeNode *m_pLeft;
    BinaryTreeNode *m_pRight;
};

// �������������������DFS����ǰ�������result�����洢�������tmp�����洢��ʱ���
// ÿ�α���ʱ���Ƚ�root��ֵѹ��tmp�У�Ȼ���жϵ�ǰ��root�Ƿ�ͬʱ�����������������:
    // �������ֵ���Ϊ0
    // ������Ϊ��
    // ������Ϊ��
// ��������������ͽ�tmpѹ��result�С��������α�������������
// ע�⣺��������������ʱ��ȫ�ֱ���tmp�ǲ���յģ�ֱ�˻ص����������tmp
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
        // ����������
        FindPath(root->m_pLeft, expectNumber - root->m_pVal);
        // ����������
        FindPath(root->m_pRight, expectNumber - root->m_pVal);
        tmp.pop_back();
        return result;
    }

private:
    vector<vector<int> > result;
    vector<int> tmp;
};