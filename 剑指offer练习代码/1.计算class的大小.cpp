#include <iostream>

class Base{
    
};

class Derived{
    public:
        Derived(){}
        ~Derived(){}
        virtual void show(){
            std::cout << "�麯��\n";
        }
};


class Shape{
    public:
        double pii(){
            return 3.14;
        }
};

class AA{
    public:
        void show(){
            std::cout << "��ʾ����\n";
        }
};

class BB{
    public:
        int a;
        char c;
        int d;
};


class CC{
    public:
        static int aa;
};

// ��̬���ݳ�Ա��ʼ��
int CC::aa=100;

class DD{
    public:
        virtual void show(){
            std::cout << "��ʾ����\n";
        }
        virtual void display(){
            std::cout << "��ʾ����\n";
        }
};



int main(){
    std::cout << "������ռ���ֽ���:" ;
    std::cout << sizeof(Base) << std::endl;

    std::cout << "���麯�������������캯��������ռ���ֽ���:" ;
    std::cout << sizeof(Derived) << std::endl;

    std::cout << "������ͨ��Ա����(�з���ֵ)������ռ���ֽ���:";
    std::cout << sizeof(Shape) << std::endl;

    std::cout << "������ͨ��Ա����(�޷���ֵ)������ռ���ֽ���:";
    std::cout << sizeof(AA) << std::endl;

    std::cout << "������ͨ��Ա����������ռ���ֽ���:";
    std::cout << sizeof(BB) << std::endl;

    std::cout << "���о�̬��Ա����������ռ���ֽ���:";
    std::cout << sizeof(CC) << std::endl;

    std::cout << "���ж���麯��������ռ���ֽ���:";
    std::cout << sizeof(DD) << std::endl;

    return 0;
}