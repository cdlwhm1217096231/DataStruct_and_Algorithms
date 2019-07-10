#include <iostream>
#include <deque>
#include <vector>

using namespace std;


class Solution{
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size){
        vector<int> maxInWindows;  // ������Ľ��
        // ����Ĵ�СҪ���ڵ��ڴ��ڴ�С�����Ҵ��ڴ�СҪ���ڵ���1
        if(num.size() >= size && size >= 1){
            deque<int> index;   // �����д�ŵ������±�
            for(unsigned int i=0; i < size; i++){  // ע��˴���i��ֹ����������
                // ���index�ǿգ���������ӵ����ִ��ڵ��ڶ�������С�����֣���ɾ����������С������
                while(!index.empty() && num[i] >= num[index.back()] ){  // index.back()����deque�е����һ��Ԫ��
                    index.pop_back();    // β��ɾ����С�����ֺ����������ӵ�����
                }
                index.push_back(i);    // β������µ���������Ӧ���±�
            }

            for(unsigned int i=size; i < num.size(); i++){  // ע��˴���i��ֹ����������
                maxInWindows.push_back(num[index.front()]);   // index.front()����deque�еĵ�һ��Ԫ�أ�����ͷλ��ʼ�մ�����ֵ
                while(!index.empty() && num[i] >= num[index.back()]){
                    index.pop_back();
                }
                // ���ƴ��ڴ�С��size
                if(!index.empty() && index.front() <= int(i-size)){  // ��һ�����ֵ��±�index.front()�뵱ǰ������±�i֮����ڵ���sizeʱ�������־�Ҫ�Ӷ�����ɾ����
                    index.pop_front();   // ͷ��ɾ������֤���ֶ���size������
                }
                index.push_back(i);   // β�����������ֶ�Ӧ���±�
            }
            maxInWindows.push_back(num[index.front()]);
        }
        return maxInWindows;
    }
};