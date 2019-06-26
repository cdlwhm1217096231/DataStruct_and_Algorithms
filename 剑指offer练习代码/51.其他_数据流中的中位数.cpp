#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 最大堆  |   最小堆

class Solution{
public:
    void Insert(int num){
        // 如果数据总个数是偶数，则新的数据插入到最小堆中
        if(((max.size() + min.size()) & 1) == 0){
            // 如果新插入的数据小于最大堆中的最大值，则直接插入最大堆中。然后将最大堆中的最大值插入到最小堆中。这样保证了最小堆中的数据始终是大于最大堆中的数据
            if(max.size() > 0 && num < max[0]){
                // 将新的数据插入到最大堆中
                max.push_back(num);
                // 调整最大堆
                push_heap(max.begin(), max.end(), less<int>());
                // 拿出最大堆中的最大值
                num = max[0];
                // 删除最大堆中的堆顶元素
                pop_heap(max.begin(), max.end(), less<int>());
                max.pop_back();
            }
            // 将数据插入到最小堆中
            min.push_back(num);
            // 调整最小堆
            push_heap(min.begin(), min.end(), greater<int>());
        }
        // 如果数据总数是奇数，则将新的数据插入到最大堆中
        else{
            if(min.size() > 0 && num > min[0]){
                // 将数据插入到最小堆中
                min.push_back(num);
                // 调整最小堆
                push_heap(min.begin(), min.end(), greater<int>());
                // 拿出最小堆中的最小值
                num = min[0];
                // 删除最小堆中的堆顶元素
                pop_heap(min.begin(), min.end(), greater<int>());
                min.pop_back();
            }
            // 将数据插入到最大堆中
            max.push_back(num);
            push_heap(max.begin(), max.end(), less<int>());
        }
    }

    double GetMedian(){
        // 统计数据大小
        int size = min.size() + max.size();
        if(size == 0){
            return 0;
        }
        // 如果数据是偶数
        if((size & 1) == 0){
            return (min[0] + max[0]) / 2.0;
        }else{  // 奇数
            return min[0];
        }

    }


private:
// 使用vector建立最小堆min和最大堆max数组
    vector<int> min;
    vector<int> max;
};