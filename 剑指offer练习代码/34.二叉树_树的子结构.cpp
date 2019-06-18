#include <iostream>

using namespace std;


// 二叉树中的节点
struct BinaryTreeNode{
    double m_val;
    BinaryTreeNode *m_pLeft;
    BinaryTreeNode *m_pRight;
};

class Solution{
public:
    bool HasSubTree(BinaryTreeNode *pRoot1, BinaryTreeNode *pRoot2){
        bool result = false;
        if(pRoot1 != nullptr && pRoot2 != nullptr){  // 保证其不是空树
            if(Equal(pRoot1->m_val, pRoot2->m_val)){
                result = DoesTree1HasTree2(pRoot1, pRoot2);
            }  // 第一步：第一棵树中含有第二棵树的根节点，继续下一步子树的判断
               
            if(!result){
                result = HasSubTree(pRoot1->m_pLeft, pRoot2);  // 递归遍历
            }  
            if(!result){
                result = HasSubTree(pRoot1->m_pRight, pRoot2);
            }      
        }
        return result;
    }
private:
    // 下面的代码具体一般性，用来比较两个浮点数是否相等，记忆！
    bool Equal(double num1, double num2){
        if((num1-num2)> -0.0000001 && (num1-num2) < 0.0000001){
            return true;
        }else{
            return false;
        } 
    }
    // 判断进行第二步判断：在第一棵树中，以第二棵树中节点为是否存在包含第二棵树的子树
    bool DoesTree1HasTree2(BinaryTreeNode *pRoot1, BinaryTreeNode *pRoot2){
        if(pRoot2 == nullptr){
            return true;
        }  // 第二棵树没有子树
        
        if(pRoot1 == nullptr){
            return false;  // 第一棵树仅存在和第二棵树相同的根节点，但是没有子树，返回false
        }
           
        if(!Equal(pRoot1->m_val, pRoot2->m_val)){
            return false;
        }
        // 递归遍历
        return DoesTree1HasTree2(pRoot1->m_pLeft, pRoot2->m_pLeft) && DoesTree1HasTree2(pRoot1->m_pRight, pRoot2->m_pRight);
    }   
};