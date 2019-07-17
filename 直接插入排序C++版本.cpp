#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


// ��������˼·:
    // 1.�ӵ�һ��Ԫ�ؿ�ʼ����Ԫ�ؿ�����Ϊ�Ѿ�������
    // 2.ȡ����һ��Ԫ�أ����Ѿ������Ԫ�������дӺ���ǰɨ��
    // 3.�����Ԫ�أ������򣩴�����Ԫ�أ�����Ԫ���Ƶ���һλ��
    // 4.�ظ�����3��ֱ���ҵ��������Ԫ��С�ڻ��ߵ�����Ԫ�ص�λ��
    // 5.����Ԫ�ز��뵽��λ�ú�
    // 6. �ظ�����2~5


void InsertSort(vector<int>& v){
    int n = v.size();
    for(int i=1; i < n; ++i){  
        int temp = v[i]; // ��Ԫ��
        for(int j = i-1; j>=0; --j){  // �������Ԫ��v[j]�Ӻ���ǰɨ��
            if(v[j] > temp){
                v[j+1] = v[j];
                v[j] = temp;
            }
            else{
                break;
            }
        }
    }
}

// ��ӡԪ��
void PrintV(vector<int>& v){
    for(auto &e: v){
        cout << e << ' ';
    }
    cout << endl;
}

int main(){
    vector<int> v{7, 30, 16, 4, 1, 2, 9};
    cout << "ֱ�Ӳ�������ǰ: ";
    PrintV(v);
    InsertSort(v);
    cout << "ֱ�Ӳ��������: ";
    PrintV(v);
    return 0;
}
