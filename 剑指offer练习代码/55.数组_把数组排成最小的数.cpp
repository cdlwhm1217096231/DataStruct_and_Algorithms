#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// ����һ�����飬�������е����е�����ƴ�ӳ�һ����С����

class Solution{
public:
    string PrintMinNumber(vector<int> numbers){
        int len = numbers.size();
        if(len == 0){
            return "";
        }
        sort(numbers.begin(), numbers.end(), cmp);
        string res;
        for(int i=0; i < len; ++i){
            res += to_string(numbers[i]);
        }
        return res;
    }

private:
// ��������ƴ�ӳ�ab��ba��ת�����ַ���,���Ž��бȽϣ�������С���ַ���
    static bool cmp(int a, int b){
        string A = to_string(a) + to_string(b);  
        string B = to_string(b) + to_string(a);
        return A < B; 
    } 
};