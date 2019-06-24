#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int MoreThanHalfNum_Solution(vector<int> numbers){
        if(numbers.empty()){
            return 0;
        }
        // 遍历每一个元素，记录两个值：数组中的数字和数字出现的次数times,如果数字与上一个数字相同，则次数加1，否则次数减一
        int result = numbers[0];
        int times = 1;
        for(int i = 1; i < numbers.size(); ++i){
            if(times == 0){  // 如果次数为0，更新result的值为当前元素，并置次数为1
                result = numbers[i];
                times = 1;
            }else if(numbers[i] == result){
                times++;
            }else{
                times--;
            }
        }
        // 判断result是否符合条件：出现的次数是否超过数组长度的一半
        times = 0;
        for(int i = 0;i<numbers.size();++i){
            if(numbers[i] == result){
                times++;
            }
        }
        return (times > (numbers.size() >> 1))? result:0;  // 右移一位相当于除以2
    }
};