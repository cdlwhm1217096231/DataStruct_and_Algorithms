#include "iostream"

using namespace std;

int fib(int i);

// 普通方法实现
int main(){
    int a[40];
    a[0] = 0;  // f(0) = 0;
    a[1] = 1; // f(1) = 1; 
    for(int i = 2; i < 40; i++){
        a[i] = a[i-1] + a[i-2];
        cout << "a[" << i << "] = " << a[i] << endl;
    } 
    cout << "-----------------------------------------\n";
    // 递归函数实现
    for(int i = 0; i < 40; i++)
        cout << "fib(" << i << ") = " << fib(i) << endl;
    return 0;
}
// 斐波那契函数
int fib(int i){
    if(i < 2)
        return i == 0 ?0: 1;
    return fib(i-1) + fib(i-2);
}
