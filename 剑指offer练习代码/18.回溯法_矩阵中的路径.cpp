#include <iostream>
#include <memory.h>

using namespace std;

// ���ݷ�

/*
���ȣ��ھ����в������ַ�����һ���ַ���ͬ�ľ���Ԫ��b
Ȼ�󣬱�������Ԫ��b�����������ĸ��ַ�������к��ַ�����һ���ַ���ͬ�ľ���Ԫ��f�����������Ԫ��f�����������ĸ��ַ������
û�к��ַ�����һ���ַ���ͬ�ľ���Ԫ��f�����˻ص���һ���ַ������±�����Ϊ�˱���·���ظ�����Ҫһ��������������¼·����
*/

// ����ֵ���Ƿ����������·��
class Solution{
public:
    bool hasPath(char *matrix, int rows, int cols, char *str){
        if(matrix == nullptr || rows < 1 || cols < 1 || str == nullptr)
            return false;
        bool *visited = new bool[rows * cols];   // ����·�����飬�ж�ĳ��Ԫ���Ƿ��Ѿ���������
        memset(visited, 0, rows * cols);  // Ϊ��������ڴ�����ʼ������,���·������
        int pathLength = 0;   // �ַ��±�
        int row = 0;  // �������±�
        int col = 0;  // �������±�
        for(int row=0;row < rows;++row){  // ��������
            for(int col=0;col < cols;++col){
                if(hasPathCore(matrix, rows, cols, row, col, str, pathLength, visited))
                    return true;
            }
        }
        delete[] visited;  // ����·������
        return false;
    }
private:
    // �ݹ�ʵ�ֻ��ݷ�
    bool hasPathCore(char *matrix, int rows, int cols, int row, int col, char *str, int &pathLength, bool *visited){
        // ��������ַ���·��
        if(str[pathLength] == '\0')
            return true;
        bool hasPath = false;
        if(row >= 0 && row < rows && col >= 0 && col < cols && matrix[row*cols+col] == str[pathLength] && !visited[row*cols+col]){
            ++pathLength;  // �������ҵ�Ԫ��str[pathLength],����Ӧ������һ��Ԫ��str[pathLength+1]
            visited[row*cols + col] = true;  // ��Ǵ�Ԫ���Ѿ���������

            // ���Ҿ�������(row��col)���������Ƿ������str[pathLength+1]��ͬ��Ԫ��
            hasPath = hasPathCore(matrix, rows, cols, row-1, col, str, pathLength, visited) || hasPathCore(matrix, rows, cols, row+1, col, str, pathLength, visited)
                  || hasPathCore(matrix, rows, cols, row, col-1, str, pathLength, visited)
                  || hasPathCore(matrix, rows, cols, row, col+1, str, pathLength, visited);
            
            // ��������(row��col)�������Ҳ�������str[pathLength+1]��ͬ��Ԫ��
            if(!hasPath){
                --pathLength;  // ���������ϣ���ԭΪstr[pathLength]
                visited[row*cols + col] = false;  // ���������ϣ����������row*cols+colΪδ�����
            }
        }
        return hasPath;
    }
};