#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int GetNumberOfK(vector<int> data, int k){
        int len = data.size();
        if(len == 0){
            return 0;
        }
        int first = GetFirstK(data, k, 0, len-1);
        int last = GetLastK(data, k, 0, len-1);
        if(first != -1 && last != -1){
            return last - first + 1;  // �����ظ�����k���ֵĴ���
        }
        return 0;
    }
private:
    // ���ڶ��ַ��ĵݹ鷽ʽ���ҳ���һ�γ�������K��λ��
    int GetFirstK(vector<int> data, int k, int begin, int end){
        if(begin > end){
            return -1;
        }
        int midIndex = (begin + end) >> 1;
        int midData = data[midIndex];
        // �м����־�������K�������м����ֵ�ǰһ�����ֲ�����k��˵����һ�γ���k��λ�þ����м�λ��
        if(midData == k){
            if((midIndex > 0 && data[midIndex-1] != k) || midIndex == 0){  // midIndex==0��ʾ�ݹ���ֹ������
                return midIndex;
            }else{   // �м����־�������K�������м����ֵ�ǰһ�����ֵ���k��˵����һ�γ���k��λ������������
                end = midIndex - 1;
            }
        }
        else if(midData > k){  // �м����ִ�������k����ʾ����k��һ�γ��ֵ�λ��λ����������
            end = midIndex - 1;
        }else{  // �м�����С������k����ʾ����k��һ�γ��ֵ�λ��λ���Ұ������
            begin = midIndex + 1;
        }
        return GetFirstK(data, k, begin, end);  
    }
    // ���ڶ��ַ��ĵݹ鷽ʽ���ҳ����һ�γ�������K��λ��
    int GetLastK(vector<int> data, int k, int begin, int end){
        int len = data.size();
        int midIndex = (begin + end) >> 1;
        int midData = data[midIndex];
        while(begin <= end){
            if(midData == k){  // �м����־�������K�������м����ֵĺ�һ�����ֲ�����k��˵�����һ�γ���k��λ�þ����м�λ��
                if((midIndex < len-1 && data[midIndex + 1] != k) || midIndex == len - 1){   // midIndex==len-1��ʾ�ݹ���ֹ������ 
                    return midIndex;
                }else{  // �м����־�������K�������м����ֵĺ�һ�����ֵ���k��˵�����һ�γ���k��λ�����Ұ������
                    begin = midIndex + 1;
                }
            }
            else if(midData > k){   // �м����ִ�������k����ʾ����k���һ�γ��ֵ�λ��λ����������
                end = midIndex - 1;
            }else{    // �м�����С������k����ʾ����k���һ�γ��ֵ�λ��λ���Ұ������
                begin = midIndex + 1;
            }
            midIndex = (begin + end) >> 1;
            midData = data[midIndex];
        }
        return -1;
    }
};