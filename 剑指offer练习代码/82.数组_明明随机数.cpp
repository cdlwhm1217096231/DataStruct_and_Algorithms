#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
    
    int n=0, num=0;

    while(cin >> n){
        vector<int> vec;
        for(int i=0; i < n; i++){
            cin >> num;
            vec.push_back(num);
        }

        sort(vec.begin(), vec.end());
        // vector»•÷ÿ
        auto end_unique = unique(vec.begin(), vec.end());
        vec.erase(end_unique, vec.end());

        for(auto&x: vec){
            cout << x << endl;
        }
    }
    return 0;
}