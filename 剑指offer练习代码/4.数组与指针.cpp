#include <iostream>

using namespace std;

int getSize(int data[]){
    return sizeof(data);   // 尽管data是一个数组，但是它会退化成一个指针！
}


int main(){
    int nums[] = {1, 2, 3, 4, 5};
    int size_nums = sizeof(nums);  // nums是一个数组，求的是数组的大小
    cout << "sizeof(nums) = " << size_nums << endl;
    
    int *m_ptr = nums;  // m_ptr指向的是nums的首地址，是一个指针
    int size_m_ptr = sizeof(size_m_ptr);
    cout << "sizeof(size_m_ptr) = " << size_m_ptr << endl;

    int size_data = sizeof(getSize(nums)); // 数组作为函数的参数进行传递时，数组自动退化成指针
    cout << "sizeof(getSize(nums)) = " << size_data << endl;
    return 0;
}