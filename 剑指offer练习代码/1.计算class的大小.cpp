#include <iostream>

class Base{
    
};

class Derived{
    public:
        Derived(){}
        ~Derived(){}
        virtual void show(){
            std::cout << "虚函数\n";
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
            std::cout << "显示函数\n";
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

// 静态数据成员初始化
int CC::aa=100;

class DD{
    public:
        virtual void show(){
            std::cout << "显示函数\n";
        }
        virtual void display(){
            std::cout << "显示函数\n";
        }
};



int main(){
    std::cout << "空类所占的字节数:" ;
    std::cout << sizeof(Base) << std::endl;

    std::cout << "有虚函数和析构、构造函数的类所占的字节数:" ;
    std::cout << sizeof(Derived) << std::endl;

    std::cout << "含有普通成员函数(有返回值)的类所占的字节数:";
    std::cout << sizeof(Shape) << std::endl;

    std::cout << "含有普通成员函数(无返回值)的类所占的字节数:";
    std::cout << sizeof(AA) << std::endl;

    std::cout << "含有普通成员变量的类所占的字节数:";
    std::cout << sizeof(BB) << std::endl;

    std::cout << "含有静态成员变量的类所占的字节数:";
    std::cout << sizeof(CC) << std::endl;

    std::cout << "含有多个虚函数的类所占的字节数:";
    std::cout << sizeof(DD) << std::endl;

    return 0;
}