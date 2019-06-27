#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution{
public:

    // ��¼�õ�����
    int cnt[70] = {1, 1};  // ��ʼ��f(0)=1, f(1)=1
    int getTranslationCount(int number){
        if(number < 0)
            return 0;
        // ת�����ַ���������
        string numStr = to_string(number);
        int numSize = numStr.size();
        // ��i=1��ʼ���������ҵĵ�2�����ֿ�ʼ���м���
        for(int i=1; i != numSize; ++i){
            // ���ǰһ��������1.��ô�͵�ǰ���������ܺϲ�����,��f(i) = f(i-1) + f(i-2)
            if(numStr[i-1] == '1'){
                cnt[i+1] = cnt[i] + cnt[i-1];
            }
            else if(numStr[i-1] == '2'){ // ���ǰһ��������2����ôֻ�е�ǰ������0-5ʱ���ܺϲ�����
                if(numStr[i] >= '0' && numStr[i] <= '5'){
                    cnt[i+1] = cnt[i] + cnt[i-1];
                }else{
                    cnt[i+1] = cnt[i];
                }
            }
            else{  // ǰһ����������������,���ܺϲ�����
                cnt[i+1] = cnt[i];
            }
        }
        return cnt[numSize];
    }
};


int main(){
    cout << "please enter a integer: ";
    int test;
    while( cin >> test){
        Solution s;
        cout << "The translation counts are: " << s.getTranslationCount(test) << endl;
    }
    return 0;
}