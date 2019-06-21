#include <iostream>
#include <vector>

using namespace std;

// 输入一个数组，数组中无重复的元素，判断此数组是否是二叉排序树/二叉搜索树的后序遍历！

class Solution{
public:
    bool VerifySequenceOfBST(vector<int> sequence){
        return bst(sequence, 0, sequence.size()-1);   // 用递归的方法进行判断左右子树是否是二叉搜索树
    }

private:
    bool bst(vector<int> seq, int begin, int end){
        if(seq.empty() == 0 || begin > end){
            return false;
        }
        // seq:表示输入的数组，begin的第一个元素， end:数组的最后一个元素，由于是后序遍历，所以此元素是二叉搜索树的根节点
        int root = seq[end];
        // 在二叉搜索树的左子树中的元素，都小于根节点
        int i = begin;
        for(; i < end; ++i){
            if(seq[i] > root){
                break;
            }
        }
        // 在二叉搜索树的右子树中的元素，都大于根节点
        for(int j = i; j < end; ++j){
            if(seq[j] < root){
                return false;
            }
        }

        // 递归的方法，判断左子树是不是二叉搜索树
        bool left = true;
        if(i > begin){
            left = bst(seq, begin, i-1);
        }

        // 递归的方法，判断左子树是不是二叉搜索树
        bool right = true;
        if(i < end-1){
            right = bst(seq, i, end-i);
        }
        return left && right;
    }
}