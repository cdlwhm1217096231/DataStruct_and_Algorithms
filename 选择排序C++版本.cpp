#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ѡ������˼·��
// 1. ��δ�����������ҵ���С����Ԫ�أ���ŵ��������е���ʼλ��
// 2. ��ʣ��δ����Ԫ���м���Ѱ����С����Ԫ�أ�Ȼ��ŵ����������е�ĩβ
// 3. �Դ����ƣ�ֱ������Ԫ�ؾ��������


// ��ӡԪ��
void PrintV(vector<int>& v){
    for(auto &e: v){
        cout << e << ' ';
    }
    cout << endl;
}

// ѡ������
void SelectSort(vector<int>& v){
    int n = v.size();
    for(int i=0; i < n-1;++i){
        int min = i;
        for(int j=i+1; j < n; ++j){
            if(v[j] < v[min]){
                min = j;
            }
        }

        if(i != min){
            swap(v[i], v[min]);
        }

    }
}


// ����ģ��ʵ��
template <typename T>
void SelectSort1(vector<T>& arr){
    int n = arr.size();
    for(int i=0; i < n-1; ++i){
        int min = i;
        for(int j=i+1; j < n; ++j){
            if(arr[j] < arr[min]){
                min = j;
            }
        }

        if(i != min){
            swap(arr[i], arr[min]);
        }
    }
}


int main(){
    vector<int> v{7, 30, 16, 4, 1, 2, 9};
    cout << "ѡ������ǰ: ";
    PrintV(v);
    SelectSort(v);
    cout << "ѡ�������: ";
    PrintV(v);
    return 0;
}