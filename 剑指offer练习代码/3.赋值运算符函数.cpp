#include <iostream>
#include <cstring>

using namespace std;

class CMyString
{
  public:
    // 构造函数
    CMyString(char *p = NULL);
    // 拷贝构造函数
    CMyString(const CMyString &str);
    // 析构函数
    ~CMyString();
    // 重载赋值运算符
    CMyString& operator=(const CMyString &str); 
    void Print();

  private:
    char *m_p; // 小提示，成员函数命名时，加上m前标
};
// 重载赋值=运算符 CMyString &(返回值类型)CMyString(作用域名)::operator=(const CMyString &str)
CMyString& CMyString::operator=(const CMyString &str)
{
    if (this == &str) // 判断传入的实例对象与当前对象*this是否是同一个实例？
        return *this;
    delete[] m_p;  // 在分配新内存前先释放自身已有的空间，否则程序会出现内存泄漏！
    m_p = NULL; // 此句不能少！

    m_p = new char[strlen(str.m_p) + 1]; // 分配一个新的内存！
    strcpy(m_p, str.m_p);
    return *this;
}

// 构造函数定义
CMyString::CMyString(char *p)
{
    if (p == NULL)
    {
        m_p = new char[1];
        m_p[0] = '\0';
    }
    else
    {
        int len = strlen(p);
        m_p = new char[len + 1];
        strcpy(m_p, p);
    }
}

// 拷贝构造函数
CMyString::CMyString(const CMyString &str){
    int len = strlen(str.m_p);
    m_p = new char [len + 1];
    strcpy(m_p, str.m_p);
}

// 析构函数
CMyString::~CMyString(){
    delete [] m_p;
} 

// 普通成员函数定义
void CMyString::Print(){
    cout << m_p << endl;
}

// 全局函数
void Test1(){
    cout << "Test1 Start......\n";
    char *text = "hello world";
    CMyString str1(text);
    CMyString str2;
    str2 = str1;  // 这里就调用了重载赋值运算符
    cout << "期望结果:" << text << endl;
    cout << "实际结果:";
    str2.Print();
}

// 赋值给自己
void Test2(){
    cout << "Test2 Start......\n";
    char *test = "hello world";
    CMyString str1(test);
    str1 = str1;
    cout << "期望结果:" << test << endl;
    cout << "实际结果: ";
    str1.Print();
}

// 连续赋值
void Test3(){
    cout << "Test3 Start......\n";
    char *text = "hello world";
    CMyString str1(text);
    CMyString str2;
    CMyString str3;
    str3 = str2 = str1;
    cout << "期望结果:" << text << endl;
    cout << "实际结果: ";
    str2.Print();
    cout << "期望结果:" << text << endl;
    cout << "实际结果: ";
    str3.Print();
}

int main(){
    Test1();
    Test2();
    Test3();
    return 0;
}