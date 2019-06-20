#include <iostream>
#include <stack>


using namespace std;

class Solution{
public:
    void push(int value){
        Data.push(value);
        if(Min.empty()){
            Min.push(value);
        }
        // 辅助栈中的栈顶元素不是最小元素，此时需要进行更新辅助栈的栈顶元素即最小值
        if(Min.top() > value){
            Min.push(value);
        }
    }
    void pop(){
        if(Data.top() == Min.top()){
            Min.pop();
        }
        Data.pop();
    }
    int top(){
        return Data.top();
    }

    int min(){
        return Min.top();
    }
private:
    stack<int> Data;   // 数据栈
    stack<int> Min;   // 辅助栈
};