#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int MoreThanHalfNum_Solution(vector<int> numbers){
        if(numbers.empty()){
            return 0;
        }
        // ����ÿһ��Ԫ�أ���¼����ֵ�������е����ֺ����ֳ��ֵĴ���times,�����������һ��������ͬ���������1�����������һ
        int result = numbers[0];
        int times = 1;
        for(int i = 1; i < numbers.size(); ++i){
            if(times == 0){  // �������Ϊ0������result��ֵΪ��ǰԪ�أ����ô���Ϊ1
                result = numbers[i];
                times = 1;
            }else if(numbers[i] == result){
                times++;
            }else{
                times--;
            }
        }
        // �ж�result�Ƿ�������������ֵĴ����Ƿ񳬹����鳤�ȵ�һ��
        times = 0;
        for(int i = 0;i<numbers.size();++i){
            if(numbers[i] == result){
                times++;
            }
        }
        return (times > (numbers.size() >> 1))? result:0;  // ����һλ�൱�ڳ���2
    }
};