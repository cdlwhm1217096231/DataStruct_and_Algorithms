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