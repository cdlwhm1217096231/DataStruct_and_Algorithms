#include <iostream>

using namespace std;

int getSize(int data[]){
    return sizeof(data);   // ����data��һ�����飬���������˻���һ��ָ�룡
}


int main(){
    int nums[] = {1, 2, 3, 4, 5};
    int size_nums = sizeof(nums);  // nums��һ�����飬���������Ĵ�С
    cout << "sizeof(nums) = " << size_nums << endl;
    
    int *m_ptr = nums;  // m_ptrָ�����nums���׵�ַ����һ��ָ��
    int size_m_ptr = sizeof(size_m_ptr);
    cout << "sizeof(size_m_ptr) = " << size_m_ptr << endl;

    int size_data = sizeof(getSize(nums)); // ������Ϊ�����Ĳ������д���ʱ�������Զ��˻���ָ��
    cout << "sizeof(getSize(nums)) = " << size_data << endl;
    return 0;
}