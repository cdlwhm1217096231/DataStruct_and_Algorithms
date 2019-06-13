#include <iostream>
#include <memory.h>

using namespace std;

// 回溯法

/*
首先，在矩阵中查找与字符串第一个字符相同的矩阵元素b
然后，遍历矩阵元素b的上下左右四个字符，如果有和字符串下一个字符相同的矩阵元素f，则遍历矩阵元素f的上下左右四个字符，如果
没有和字符串下一个字符相同的矩阵元素f，则退回到上一个字符，重新遍历。为了避免路径重复，需要一个辅助矩阵来记录路径。
*/

// 返回值：是否存在这样的路径
class Solution{
public:
    bool hasPath(char *matrix, int rows, int cols, char *str){
        if(matrix == nullptr || rows < 1 || cols < 1 || str == nullptr)
            return false;
        bool *visited = new bool[rows * cols];   // 创建路径数组，判断某个元素是否已经遍历过了
        memset(visited, 0, rows * cols);  // 为新申请的内存做初始化操作,清空路径数组
        int pathLength = 0;   // 字符下标
        int row = 0;  // 矩阵行下标
        int col = 0;  // 矩阵列下标
        for(int row=0;row < rows;++row){  // 遍历矩阵
            for(int col=0;col < cols;++col){
                if(hasPathCore(matrix, rows, cols, row, col, str, pathLength, visited))
                    return true;
            }
        }
        delete[] visited;  // 销毁路径数组
        return false;
    }
private:
    // 递归实现回溯法
    bool hasPathCore(char *matrix, int rows, int cols, int row, int col, char *str, int &pathLength, bool *visited){
        // 矩阵存在字符串路径
        if(str[pathLength] == '\0')
            return true;
        bool hasPath = false;
        if(row >= 0 && row < rows && col >= 0 && col < cols && matrix[row*cols+col] == str[pathLength] && !visited[row*cols+col]){
            ++pathLength;  // 矩阵中找到元素str[pathLength],下面应该找下一个元素str[pathLength+1]
            visited[row*cols + col] = true;  // 标记此元素已经遍历过了

            // 查找矩阵坐标(row，col)上下左右是否存在与str[pathLength+1]相同的元素
            hasPath = hasPathCore(matrix, rows, cols, row-1, col, str, pathLength, visited) || hasPathCore(matrix, rows, cols, row+1, col, str, pathLength, visited)
                  || hasPathCore(matrix, rows, cols, row, col-1, str, pathLength, visited)
                  || hasPathCore(matrix, rows, cols, row, col+1, str, pathLength, visited);
            
            // 矩阵坐标(row，col)上下左右不存在与str[pathLength+1]相同的元素
            if(!hasPath){
                --pathLength;  // 条件不符合，还原为str[pathLength]
                visited[row*cols + col] = false;  // 条件不符合，标记数组标记row*cols+col为未被标记
            }
        }
        return hasPath;
    }
};