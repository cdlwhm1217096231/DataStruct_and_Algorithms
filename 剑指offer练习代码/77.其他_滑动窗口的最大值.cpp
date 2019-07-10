#include <iostream>
#include <deque>
#include <vector>

using namespace std;


class Solution{
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size){
        vector<int> maxInWindows;  // 存放最后的结果
        // 数组的大小要大于等于窗口大小，并且窗口大小要大于等于1
        if(num.size() >= size && size >= 1){
            deque<int> index;   // 数组中存放的数字下标
            for(unsigned int i=0; i < size; i++){  // 注意此处的i终止条件！！！
                // 如果index非空，并且新添加的数字大于等于队列中最小的数字，则删除队列中最小的数字
                while(!index.empty() && num[i] >= num[index.back()] ){  // index.back()返回deque中的最后一个元素
                    index.pop_back();    // 尾部删除最小的数字后，则插入新添加的数字
                }
                index.push_back(i);    // 尾部添加新的数字所对应的下标
            }

            for(unsigned int i=size; i < num.size(); i++){  // 注意此处的i终止条件！！！
                maxInWindows.push_back(num[index.front()]);   // index.front()返回deque中的第一个元素，即队头位置始终存放最大值
                while(!index.empty() && num[i] >= num[index.back()]){
                    index.pop_back();
                }
                // 控制窗口大小是size
                if(!index.empty() && index.front() <= int(i-size)){  // 当一个数字的下标index.front()与当前处理的下标i之差大于等于size时，此数字就要从队列中删除了
                    index.pop_front();   // 头部删除，保证数字都在size窗口内
                }
                index.push_back(i);   // 尾部插入新数字对应的下标
            }
            maxInWindows.push_back(num[index.front()]);
        }
        return maxInWindows;
    }
};