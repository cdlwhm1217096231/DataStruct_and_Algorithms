#include <iostream>
#include <vector>

using namespace std;

// ����˼·:
/*

���ȣ��������Ԫ�����δӴӵ�β������򣬽����Ϊ0
Ȼ�󣬹۲����Ķ����Ʊ�ʾ����һλ��1���Դ�λ�Ƿ�Ϊ1��ԭ������л��ֳ��������������飬���ֵ����ε�����һ����ͬһ����������
��󣬶������������ٽ���������㣬�õ����յĽ��
*/

class Solution{
public:
    void FindNumsAppearOnce(vector<int> data, int* num1, int* num2){
        if(data.size() < 2) return;
        *num1 = *num2 = 0;
        int tmp = 0;
        for(auto a:data){
            tmp = tmp ^ a;   // ������data�е����������ͷ��β����������㣬��Ϊ��ͬ�����ֽ���������㣬���Ϊ0
        }
        if(tmp == 0) return;
        int posi = 0;
        while(posi < 8*sizeof(int)){  // �������һ���жϣ���posi�Ĵ�С���ܴ���int��λ����С
            if(tmp & 0x1){  // ���λ��1������ѭ��
                break;
            }
            tmp = tmp >> 1;  // ���λ����1��ִ��ѭ���������ƶ�һλ
            posi++;
        }

        int scale = 1 << posi;
        for(auto a: data){
            if(a & scale){  // ����scale�е�ĳһλ�Ƿ���1��ԭ�����е�Ԫ�ؽ��л��֣����ֳ�����������
                *num1 = (*num1) ^ a;  // ������1
            }else{
                *num2 = (*num2) ^ a;  // ������2
            }
        }
    }
};


int main(){
    vector<int> data{2, 4, 3, 6, 3, 2, 5, 5};
    int num1, num2;
    Solution s;
    s.FindNumsAppearOnce(data, &num1, &num2);
    cout << num1 << endl;
    cout << num2 << endl;
    return 0;
}