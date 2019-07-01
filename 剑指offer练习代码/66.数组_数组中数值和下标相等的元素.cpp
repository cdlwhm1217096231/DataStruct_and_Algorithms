#include <iostream>

using namespace std;

class Solution{
public:
    int GetNumberSameAsIndex(const int* data, int length){
        if(data == nullptr || length <= 0){
            return 0;
        }
        int left = 0;
        int right = length - 1;
        while(left <= right){
            int midIndex = (left + right) >> 1;
            if(data[midIndex] == midIndex){
                return midIndex;
            }

            if(data[midIndex] > midIndex){
                right = midIndex - 1;
            }else{
                left = midIndex + 1;
            }
        }
        return -1;
    }
};