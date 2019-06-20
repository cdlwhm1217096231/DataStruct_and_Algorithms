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
        // ����ջ�е�ջ��Ԫ�ز�����СԪ�أ���ʱ��Ҫ���и��¸���ջ��ջ��Ԫ�ؼ���Сֵ
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
    stack<int> Data;   // ����ջ
    stack<int> Min;   // ����ջ
};