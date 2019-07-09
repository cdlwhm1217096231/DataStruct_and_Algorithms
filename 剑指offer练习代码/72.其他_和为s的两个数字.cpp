#include <iostream>
#include <vector>


using namespace std;


class Solution{
public:
    vector<int> FindNumberWithSum(vector<int> array, int sum){
        vector<int> result;
        int length = array.size();
        if(length < 1){
            return result;
        }
        int pright = length - 1;
        int pleft = 0;

        while(pright > pleft){
            int curSum = array[pleft] + array[pright];
            if(curSum == sum){
                result.push_back(array[pleft]);
                result.push_back(array[pright]);
                break;
            }
            else if(curSum < sum){
                pleft++;
            }
            else{
                pright--;
            }

        }
        return result;
    }
};
