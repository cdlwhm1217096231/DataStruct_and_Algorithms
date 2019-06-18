#include <iostream>
#include <vector>
#include <deque>

using namespace std;

// 使用双向队列deque，遍历数组，奇数在前面插入，偶数在后面插入

class Solution{
public:
    void reOrderArray(vector<int> &array){
        deque<int> result;
        int num = array.size();
        for(int i =0; i < num; ++i){
            if(array[num-i-1] % 2 == 1)
                result.push_front(array[num-i-1]);
            if(array[i] % 2 == 0)
                result.push_back(array[i]);
        }
        array.assign(result.begin(), result.end());  // 最后使用assign方法实现不同容器但相容的类型赋值。
    }

};


// 方法2：使用指针
void ReOrderOddEven(int *pData, unsigned int length){
    if(pData == nullptr || length == 0)
        return;
    int *pBegin = pData;
    int *pEnd = pData + length - 1;
    while(pBegin < pEnd){
        while(pBegin < pEnd && (*pBegin & 0x1) != 0){  // *pBegin此时是奇数，不进行交换操作，向后移动一个位置
            pBegin++;
        }
        while(pBegin < pEnd && (*pEnd & 0x1) == 0){   // *pEnd此时是偶数，不进行交换操作，向前移动一个位置
            pEnd--;
        }
        if(pBegin < pEnd){  // 开始交换的时间：pBegin此时指向偶数，pEnd此时指向奇数
            int temp = *pBegin;
            *pBegin = *pEnd;
            *pEnd = temp;
        }
    }
}