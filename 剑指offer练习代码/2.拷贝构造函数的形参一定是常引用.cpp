#include <iostream>

using namespace std;


class A{
    private:
        int value;
    public:
    // ���캯��
        A (int n){
            value = n;
        }
        // �������캯��
        A (const A &other){  // �˴��Ĵ��α����Ǵ����÷�ʽconst A &other�������Ǵ�ֵ��ʽA other����Ϊ���ô�ֵ��ʽ
        // �βθ��Ƶ�ʵ�λ���ÿ������캯�����ͻᵼ���ڿ������캯���е��ÿ������캯�����γ����޵ݹ鵼��ջ�����
            value = other.value;
        }
        void show(){
            cout << value << endl;
        }
};

int main(){
    A a(10);
    A b = a;  // ִ�п������캯��������ִ�����ظ�ֵ���������Ϊ�ǳ�ʼ������
    b.show();
    return 0;
}
