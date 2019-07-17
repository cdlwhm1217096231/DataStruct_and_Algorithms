#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


// ð������˼·��
// 1. �Ƚ����ڵ�Ԫ�ء������һ���ȵڶ����󣬾ͽ�������������
// 2. ��ÿһ������Ԫ����ͬ���Ĺ������ӿ�ʼ��һ�Ե���β�����һ�ԡ��ⲽ���������Ԫ�ػ�����������
// 3. ������е�Ԫ���ظ����ϵĲ��裬�������һ����
// 4. ����ÿ�ζ�Խ��Խ�ٵ�Ԫ���ظ�����Ĳ��裬ֱ��û���κ�һ��������Ҫ�Ƚϡ�


// ��ӡԪ��
void PrintV(vector<int>& v){
    for(auto &e: v){
        cout << e << ' ';
    }
    cout << endl;
}


// ð����������汾
void BubbleSort(vector<int>& v){
    int n = v.size();
    for(int i=0; i < n-1; ++i){
        for(int j=0; j < n-1-i; ++j){
            if(v[j] > v[j+1]){
                swap(v[j], v[j+1]);
            }
        }
    }
}

// ����ģ����ʵ��
template<typename T>   // ģ��ͷ
void BubbleSort1(T arr[], int len){
    for(int i=0; i < len-1; ++i){
        for(int j=0; j < len-1-i; ++j){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}



// ð�������Ż��汾
void BubbleSort2(vector<int>& v){
    int n = v.size();
    bool flag = false;  // flag��־����ʾ�����Ƿ�����
    for(int i=0; i < n-1 && !flag; ++i){
        flag = true;
        for(int j=0; j < n-1-i; ++j){
            if(v[j] > v[j+1]){
                flag = false;  // �����������Է�����
                swap(v[j], v[j+1]);
            }
        }
    }
}



// �Լ�ʵ���������Ľ���
void Swap(int& a, int& b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}


int main(){
    vector<int> v{7, 30, 16, 4, 1, 2, 9};
    cout << "ð������ǰ: ";
    PrintV(v);
    BubbleSort2(v);
    cout << "ð�������: ";
    PrintV(v);
    return 0;
}