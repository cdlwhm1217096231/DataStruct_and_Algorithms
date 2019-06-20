#include <iostream>
#include <stack>
#include <vector>


using namespace std;

class Solution{
public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV){
        // pushV��ѹ�����У�popV�ǵ�������
        if(pushV.size()  == 0){
            return false;
        }
        for(int i = 0, j=0; i < pushV.size(); ++i){
            stackData.push(pushV[i]);  // �Ƚ�ѹ�������е�ÿ��Ԫ����һѹ�븨��ջ��
            while(j < popV.size() && stackData.top() == popV[j]){  // ����ջ�е�ջ��Ԫ���ǵ��������е�Ԫ�أ��򵯳�ջ��Ԫ��
                stackData.pop();
                j++;
            }
        }
        return stackData.empty();  // �������ջΪ�գ���˵����������ʱջ�ĵ���˳�򣻷��򵯳����в���ջ�ĵ���˳��
    }

private:
    stack<int> stackData;   // ����ջ
};
