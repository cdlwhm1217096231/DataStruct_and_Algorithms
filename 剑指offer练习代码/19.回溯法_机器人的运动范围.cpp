#include <iostream>
#include <memory.h>

using namespace std;


class Solution{
public:
    int movingCount(int k, int rows, int cols){
        int count = 0;
        if(k < 1 || rows < 1 || cols < 1)
            return count;
        bool *visited = new bool[rows * cols];
        memset(visited, 0, rows*cols);
        count = movingCountCore(k, rows, cols, 0, 0, visited);
        delete[] visited;
        return count;
    }
private:
    int movingCountCore(int k, int rows, int cols, int row, int col, bool *visited){
        int count = 0;
        // if语句里面的是约束条件！
        if(row >= 0 && row < rows && col >=0 && col < cols && getDigitSum(row) + getDigitSum(col) <= k && !visited[row*cols+col]){
            visited[row*cols+col] = true;
            count = 1 + movingCountCore(k, rows, cols, row-1, col, visited)   // 递归方法实现回溯
            + movingCountCore(k, rows, cols, row+1, col, visited)
            + movingCountCore(k, rows, cols, row, col-1, visited)
            + movingCountCore(k, rows, cols, row, col+1, visited);
        }
        return count;
    }
    // 这个代码是求某个数各位的和代码，具体一般性，记忆！
    int getDigitSum(int num){
        int sum = 0;
        while(num){
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
};