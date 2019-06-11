#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int rows = array.size();
        int cols = array[0].size();
        if(!array.empty() && rows > 0 && cols > 0){
            int row_index = 0;
            int col_index = cols - 1;
            while(row_index < rows && col_index >= 0){
                if(array[row_index][col_index] == target){
                    return true;
                }
                else if(array[row_index][col_index] > target){
                    --col_index;
                }
                else{
                    ++row_index;
                }
            }
        }
        return false;
    }
};



int main(){
    Solution s;
    vector<vector<int> > array1;
    int target = 3;
    cout << s.Find(target, array1) << endl;

    vector<vector<int> > array2 = {{1, 2, 3, 4}, {5, 6, 7, 8}};
    cout <<s.Find(target, array2) << endl;
    return 0;
}