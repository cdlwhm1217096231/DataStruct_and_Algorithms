#include <iostream>
#include <algorithm>


using namespace std;

class Solution{
public:
    int getMaxValue(const int* values, int rows, int cols){
        if(values == nullptr || rows <= 0 || cols <=0){
            return 0;
        }
        // �����ڴ�
        int** maxValues = new int* [rows];   // ����һ����ά����
        // ��ά�����ʼ��
        for(int i=0; i < rows; ++i){
            maxValues[i] = new int[cols];
        }
        for(int i=0; i < rows; ++i){
            for(int j=0; j < cols; ++j){
                int left = 0;
                int up = 0;

                if (i > 0){
                    up = maxValues[i-1][j];
                }
                if(j > 0){
                    left = maxValues[i][j-1];
                }
                maxValues[i][j] = max(left, up) + values[i * cols + j];  //  values[i * cols + j]��(i,j)�����������ֵ
            }
        }
        int maxValue = maxValues[rows-1][cols-1];
        // �ͷ��ڴ棡
        for(int i=0; i < rows; ++i){
            delete[] maxValues[i];
        }
        delete[] maxValues;
        return maxValue;
    }
};