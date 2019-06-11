#include <iostream>
#include <cstring>

using namespace std;

class CMyString
{
  public:
    // ���캯��
    CMyString(char *p = NULL);
    // �������캯��
    CMyString(const CMyString &str);
    // ��������
    ~CMyString();
    // ���ظ�ֵ�����
    CMyString& operator=(const CMyString &str); 
    void Print();

  private:
    char *m_p; // С��ʾ����Ա��������ʱ������mǰ��
};
// ���ظ�ֵ=����� CMyString &(����ֵ����)CMyString(��������)::operator=(const CMyString &str)
CMyString& CMyString::operator=(const CMyString &str)
{
    if (this == &str) // �жϴ����ʵ�������뵱ǰ����*this�Ƿ���ͬһ��ʵ����
        return *this;
    delete[] m_p;  // �ڷ������ڴ�ǰ���ͷ��������еĿռ䣬������������ڴ�й©��
    m_p = NULL; // �˾䲻���٣�

    m_p = new char[strlen(str.m_p) + 1]; // ����һ���µ��ڴ棡
    strcpy(m_p, str.m_p);
    return *this;
}

// ���캯������
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

// �������캯��
CMyString::CMyString(const CMyString &str){
    int len = strlen(str.m_p);
    m_p = new char [len + 1];
    strcpy(m_p, str.m_p);
}

// ��������
CMyString::~CMyString(){
    delete [] m_p;
} 

// ��ͨ��Ա��������
void CMyString::Print(){
    cout << m_p << endl;
}

// ȫ�ֺ���
void Test1(){
    cout << "Test1 Start......\n";
    char *text = "hello world";
    CMyString str1(text);
    CMyString str2;
    str2 = str1;  // ����͵��������ظ�ֵ�����
    cout << "�������:" << text << endl;
    cout << "ʵ�ʽ��:";
    str2.Print();
}

// ��ֵ���Լ�
void Test2(){
    cout << "Test2 Start......\n";
    char *test = "hello world";
    CMyString str1(test);
    str1 = str1;
    cout << "�������:" << test << endl;
    cout << "ʵ�ʽ��: ";
    str1.Print();
}

// ������ֵ
void Test3(){
    cout << "Test3 Start......\n";
    char *text = "hello world";
    CMyString str1(text);
    CMyString str2;
    CMyString str3;
    str3 = str2 = str1;
    cout << "�������:" << text << endl;
    cout << "ʵ�ʽ��: ";
    str2.Print();
    cout << "�������:" << text << endl;
    cout << "ʵ�ʽ��: ";
    str3.Print();
}

int main(){
    Test1();
    Test2();
    Test3();
    return 0;
}