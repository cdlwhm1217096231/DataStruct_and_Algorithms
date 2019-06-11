#include <iostream>

using namespace std;


class A{
    private:
        int value;
    public:
    // 构造函数
        A (int n){
            value = n;
        }
        // 拷贝构造函数
        A (const A &other){  // 此处的传参必须是传引用方式const A &other，不能是传值方式A other！因为采用传值方式
        // 形参复制到实参会调用拷贝构造函数，就会导致在拷贝构造函数中调用拷贝构造函数，形成无限递归导致栈溢出！
            value = other.value;
        }
        void show(){
            cout << value << endl;
        }
};

int main(){
    A a(10);
    A b = a;  // 执行拷贝构造函数，不会执行重载赋值运算符，因为是初始化操作
    b.show();
    return 0;
}
