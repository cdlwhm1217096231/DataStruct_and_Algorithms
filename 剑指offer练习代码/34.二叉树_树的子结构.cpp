#include <iostream>

using namespace std;


// �������еĽڵ�
struct BinaryTreeNode{
    double m_val;
    BinaryTreeNode *m_pLeft;
    BinaryTreeNode *m_pRight;
};

class Solution{
public:
    bool HasSubTree(BinaryTreeNode *pRoot1, BinaryTreeNode *pRoot2){
        bool result = false;
        if(pRoot1 != nullptr && pRoot2 != nullptr){  // ��֤�䲻�ǿ���
            if(Equal(pRoot1->m_val, pRoot2->m_val)){
                result = DoesTree1HasTree2(pRoot1, pRoot2);
            }  // ��һ������һ�����к��еڶ������ĸ��ڵ㣬������һ���������ж�
               
            if(!result){
                result = HasSubTree(pRoot1->m_pLeft, pRoot2);  // �ݹ����
            }  
            if(!result){
                result = HasSubTree(pRoot1->m_pRight, pRoot2);
            }      
        }
        return result;
    }
private:
    // ����Ĵ������һ���ԣ������Ƚ������������Ƿ���ȣ����䣡
    bool Equal(double num1, double num2){
        if((num1-num2)> -0.0000001 && (num1-num2) < 0.0000001){
            return true;
        }else{
            return false;
        } 
    }
    // �жϽ��еڶ����жϣ��ڵ�һ�����У��Եڶ������нڵ�Ϊ�Ƿ���ڰ����ڶ�����������
    bool DoesTree1HasTree2(BinaryTreeNode *pRoot1, BinaryTreeNode *pRoot2){
        if(pRoot2 == nullptr){
            return true;
        }  // �ڶ�����û������
        
        if(pRoot1 == nullptr){
            return false;  // ��һ���������ں͵ڶ�������ͬ�ĸ��ڵ㣬����û������������false
        }
           
        if(!Equal(pRoot1->m_val, pRoot2->m_val)){
            return false;
        }
        // �ݹ����
        return DoesTree1HasTree2(pRoot1->m_pLeft, pRoot2->m_pLeft) && DoesTree1HasTree2(pRoot1->m_pRight, pRoot2->m_pRight);
    }   
};