#include <iostream>
#include <stack>
#include <vector>


using namespace std;

class Solution{
public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV){
        // pushV是压入序列，popV是弹出序列
        if(pushV.size()  == 0){
            return false;
        }
        for(int i = 0, j=0; i < pushV.size(); ++i){
            stackData.push(pushV[i]);  // 先将压入序列中的每个元素逐一压入辅助栈中
            while(j < popV.size() && stackData.top() == popV[j]){  // 辅助栈中的栈顶元素是弹出序列中的元素，则弹出栈顶元素
                stackData.pop();
                j++;
            }
        }
        return stackData.empty();  // 如果辅助栈为空，则说明弹出序列时栈的弹出顺序；否则弹出序列不是栈的弹出顺序
    }

private:
    stack<int> stackData;   // 辅助栈
};
