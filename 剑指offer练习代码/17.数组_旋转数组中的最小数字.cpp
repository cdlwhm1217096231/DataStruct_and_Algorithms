#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int minNumberInRotateArray(vector<int> rotateArray){
        int size = rotateArray.size();
        if(size == 0)
            return 0;
        int low = 0;
        int high = size - 1;
        int mid = 0;
        while(rotateArray[low] >= rotateArray[high]){
            if(high - low == 1){  // 左右指针相邻，返回右指针
                mid = high;
                break;
            }
            mid = low + (high - low) / 2;
            // 特殊情况：rotateArray数组中第一个，最后一个，中间元素全部相等，无法确定最小元素在前面的递增数组还是在后面的递增数组中
            // 只能使用顺序查找，二分查找失败
            if(rotateArray[low] == rotateArray[high] && rotateArray[mid] == rotateArray[low])
                return MinInOrder(rotateArray, low, high);
            // 中间元素位于前面的递增数组中，此时最小元素在后面
            if(rotateArray[mid] >= rotateArray[low])
                low = mid;
            else  // 中间元素位于后面的递增数组中，此时最小的元素在前面
                high = mid;
        }
        return rotateArray[mid];
    }
private:  // 顺序查找最小值
    int MinInOrder(vector<int> &num, int low, int high){
        int result = num[low];
        for(int i = low + 1; i<high;++i){
            if(num[i] < result)
                result = num[i];
        }
        return result;
    }
};