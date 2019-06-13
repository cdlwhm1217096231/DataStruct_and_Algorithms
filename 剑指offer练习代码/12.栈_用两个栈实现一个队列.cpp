#include <iostream>
#include <stack>
#include <vector>


using namespace std;

class Solution{
    public:
        void push(int node){
            stack1.push(node);   // stack1元素入栈
        }
        int pop(){  // stack2元素出栈
            if(stack2.empty()){
                while(stack1.size() > 0){
                    int data = stack1.top();   // stack1的栈顶元素
                    stack1.pop();
                    stack2.push(data);
                }
            }
            int pop_element = stack2.top();  // stack2的栈顶元素，实际上是stack1中的栈底元素
            stack2.pop();
            return pop_element;   // 打印出stack2的栈顶元素，从而实现队列的功能---FIFO
        }
    private:
        stack<int> stack1;
        stack<int> stack2;
}