#include <iostream>
#include <vector>

using namespace std;

// 解题思路:
/*

首先，将数组的元素依次从从到尾进行异或，结果不为0
然后，观察结果的二进制表示中哪一位是1，以此位是否为1将原数组进行划分成左右两个子数组，出现的两次的数字一定在同一个子数组中
最后，对两个子数组再进行异或运算，得到最终的结果
*/

class Solution{
public:
    void FindNumsAppearOnce(vector<int> data, int* num1, int* num2){
        if(data.size() < 2) return;
        *num1 = *num2 = 0;
        int tmp = 0;
        for(auto a:data){
            tmp = tmp ^ a;   // 将数组data中的所有数组从头到尾依次异或运算，因为相同的数字进行异或运算，结果为0
        }
        if(tmp == 0) return;
        int posi = 0;
        while(posi < 8*sizeof(int)){  // 这里进行一个判断，即posi的大小不能大于int的位数大小
            if(tmp & 0x1){  // 最低位是1，跳出循环
                break;
            }
            tmp = tmp >> 1;  // 最低位不是1，执行循环，向右移动一位
            posi++;
        }

        int scale = 1 << posi;
        for(auto a: data){
            if(a & scale){  // 根据scale中的某一位是否是1对原数组中的元素进行划分，划分成两个子数组
                *num1 = (*num1) ^ a;  // 子数组1
            }else{
                *num2 = (*num2) ^ a;  // 子数组2
            }
        }
    }
};


int main(){
    vector<int> data{2, 4, 3, 6, 3, 2, 5, 5};
    int num1, num2;
    Solution s;
    s.FindNumsAppearOnce(data, &num1, &num2);
    cout << num1 << endl;
    cout << num2 << endl;
    return 0;
}