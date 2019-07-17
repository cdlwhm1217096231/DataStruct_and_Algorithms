#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

//  ϣ������ÿһ�ְ������Ⱦ����ļ�����в������򣬼����������С�����һ��һ��Ҫ��1��



// ��ӡԪ��
void PrintV(vector<int>& v){
    for(auto &e: v){
        cout << e << ' ';
    }
    cout << endl;
}


// ϣ������
void ShellSort(vector<int>& v){
    int n = v.size();
    int h = 1;   // ���

    while(h < n / 3){
        h = 3 * h + 1;
    }

    while(h >= 1){
        for(int i=h; i < n; ++i){
            for(int j=i; j >= h && v[j] < v[j-h]; j-=h){
                swap(v[j], v[j-h]);
            }
        }
        h = h / 3;
    }
}



int main(){
    vector<int> v{7, 30, 16, 4, 1, 2, 9};
    cout << "ϣ������ǰ: ";
    PrintV(v);
    ShellSort(v);
    cout << "ϣ�������: ";
    PrintV(v);
    return 0;
}