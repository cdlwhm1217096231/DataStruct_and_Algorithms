#include <iostream>
#include <vector>
#include <deque>

using namespace std;

// ʹ��˫�����deque���������飬������ǰ����룬ż���ں������

class Solution{
public:
    void reOrderArray(vector<int> &array){
        deque<int> result;
        int num = array.size();
        for(int i =0; i < num; ++i){
            if(array[num-i-1] % 2 == 1)
                result.push_front(array[num-i-1]);
            if(array[i] % 2 == 0)
                result.push_back(array[i]);
        }
        array.assign(result.begin(), result.end());  // ���ʹ��assign����ʵ�ֲ�ͬ���������ݵ����͸�ֵ��
    }

};