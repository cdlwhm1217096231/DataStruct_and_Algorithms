#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution{
public:

    // 记录用的数组
    int cnt[70] = {1, 1};  // 初始化f(0)=1, f(1)=1
    int getTranslationCount(int number){
        if(number < 0)
            return 0;
        // 转化成字符串来处理
        string numStr = to_string(number);
        int numSize = numStr.size();
        // 从i=1开始，即从左到右的第2个数字开始进行计算
        for(int i=1; i != numSize; ++i){
            // 如果前一个数字是1.那么和当前的数字总能合并翻译,即f(i) = f(i-1) + f(i-2)
            if(numStr[i-1] == '1'){
                cnt[i+1] = cnt[i] + cnt[i-1];
            }
            else if(numStr[i-1] == '2'){ // 如果前一个数字是2，那么只有当前数字是0-5时才能合并翻译
                if(numStr[i] >= '0' && numStr[i] <= '5'){
                    cnt[i+1] = cnt[i] + cnt[i-1];
                }else{
                    cnt[i+1] = cnt[i];
                }
            }
            else{  // 前一个数字是其他数字,不能合并翻译
                cnt[i+1] = cnt[i];
            }
        }
        return cnt[numSize];
    }
};


int main(){
    cout << "please enter a integer: ";
    int test;
    while( cin >> test){
        Solution s;
        cout << "The translation counts are: " << s.getTranslationCount(test) << endl;
    }
    return 0;
}