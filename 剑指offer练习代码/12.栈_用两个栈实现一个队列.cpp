#include <iostream>
#include <stack>
#include <vector>


using namespace std;

class Solution{
    public:
        void push(int node){
            stack1.push(node);   // stack1Ԫ����ջ
        }
        int pop(){  // stack2Ԫ�س�ջ
            if(stack2.empty()){
                while(stack1.size() > 0){
                    int data = stack1.top();   // stack1��ջ��Ԫ��
                    stack1.pop();
                    stack2.push(data);
                }
            }
            int pop_element = stack2.top();  // stack2��ջ��Ԫ�أ�ʵ������stack1�е�ջ��Ԫ��
            stack2.pop();
            return pop_element;   // ��ӡ��stack2��ջ��Ԫ�أ��Ӷ�ʵ�ֶ��еĹ���---FIFO
        }
    private:
        stack<int> stack1;
        stack<int> stack2;
}