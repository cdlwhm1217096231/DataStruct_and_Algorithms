#include <iostream>
#include <vector>

using namespace std;


class Solution{
public:
    int maxProductAfterCutting(int length){
        if(length < 2)
            return 0;
        if(length == 2)
            return 1;
        if(length == 3)
            return 2;
        vector<int> products={0, 1, 2, 3};  // 保留每个子问题的最优结果
        for(int i = 4;i<=length;++i){
            int max = 0;
            for(int j = 1; j<=i/2;++j){
                int product = products[j] * products[i-j];
                if(max < product)
                    max = product;
            }
            products.push_back(max);
        }
        return products[length];
    }
};